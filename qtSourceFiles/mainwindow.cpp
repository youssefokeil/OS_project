#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include "process_class.h"
#include "CompareStructs.h"
#include "Scheduler.h"
#include"process_class.h"
#include <limits>
#include "ui_mainwindow.h"
#include<qtimer.h>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMessageBox>

//  min heaps initialization, one sorted by arrival time, and one sorted by burst time.
priority_queue<Process, std::vector<Process>, CompareByArrivalTime> ArrivalBuffer;
vector<string> gantt_chart;
int n;
Scheduler myScheduler=Scheduler("SJF", false);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_2->setRowCount(1);
    schedulerTimer = new QTimer(this);
    connect(schedulerTimer, &QTimer::timeout, this, &MainWindow::processSchedulerStep);

    ui->label_12->hide();
    ui->spinBox_2->hide();
    ui->spinBox_2->setMinimum(1);
    ui->spinBox->setMinimum(1);

    QTableWidgetItem *item = ui->tableWidget_2->item(0, 2);
    if (!item) {
        item = new QTableWidgetItem("0");
        ui->tableWidget_2->setItem(0, 2, item);
    }
    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
}
MainWindow::~MainWindow()
{
    delete ui;
}

QHBoxLayout* MainWindow::getHorizontalLayout() const {
    return ui->horizontalLayout;
}
QTableWidget* MainWindow::getTableWidget() const{
    return ui->tableWidget;
}
/**
 * @brief Checks if all cells in a QTableWidget contain valid numbers
 * @param table The QTableWidget to validate
 * @return true if ALL cells contain numbers, false otherwise
 */
bool validateAllCellsContainNumbers(QTableWidget* table) {
    if (!table) return false;  // Safety check

    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            QTableWidgetItem* item = table->item(row, col);

            // Check if cell exists and isn't empty
            if (!item || item->text().isEmpty()) {
                return false;
            }

            // Try to convert to number
            bool ok;
            item->text().toDouble(&ok);  // Works for both ints and floats

            if (!ok) {
                return false;
            }
        }
    }
    return true;  // All cells contain numbers
}
void MainWindow::on_pushButton_clicked()//visualize button
{
    if(validateAllCellsContainNumbers(ui->tableWidget_2)){
    n=ui->spinBox->value();
        // input receival from terminal
        for(int i=0; i<n; i++){
            int art = 0, bt=0, priority=0;

            art=ui->tableWidget_2->item(i,0)->text().toInt();

            bt=ui->tableWidget_2->item(i,1)->text().toInt();

            ui->tableWidget->setRowCount(n);
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(bt));
            ui->tableWidget->setItem(i,0,item);

            if(ui->comboBox->currentText()=="Non Preemptive Priority"||ui->comboBox->currentText()=="Preemptive Priority")
            priority=ui->tableWidget_2->item(i,2)->text().toInt();

            Process  p(i+1, art, bt, priority);
            ArrivalBuffer.push(p);
        }

        ui->stackedWidget->setCurrentIndex(1);
    }else{
        QMessageBox::critical(this, "Error", "Please complete all process details in the table");
    }

}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget_2->setRowCount(arg1);
    if(ui->comboBox->currentText()!="Non Preemptive Priority" && ui->comboBox->currentText()!="Preemptive Priority"){
        if (!ui->tableWidget_2 || 2 < 0 || 2 >= ui->tableWidget_2->columnCount()) {
            return;
        }

        // Fill column with zeros and make read-only
        for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
            QTableWidgetItem* item = ui->tableWidget_2->item(row, 2);
            if (!item) {
                item = new QTableWidgetItem("0");  // Pre-fill with zero
                ui->tableWidget_2->setItem(row, 2, item);
            } else {
                item->setText("0");  // Ensure value is zero
            }
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);  // Disable editing
        }
    }
}


// Usage:
 // Assuming you have a layout pointer
void MainWindow::clearLayout(QLayout* layout) {
    if (!layout) return;

    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget(); // Delete the widget
        }
        delete item; // Delete the layout item
    }
}


void MainWindow::on_pushButton_3_clicked()//Close button
{
    this->close();
}

int MainWindow:: getSpinboxValue()const{
    return ui->spinBox_3->value();
}

void MainWindow::on_pushButton_2_clicked()//Add button
{

    int bt = ui->spinBox_3->text().toInt();
    int priority = ui->spinBox_4->text().toInt();
    ui->tableWidget->setRowCount(++n);
    QTableWidgetItem *item = new QTableWidgetItem(QString::number(ui->spinBox_3->value()));
    ui->tableWidget->setItem(n-1,0,item);
    ArrivalBuffer.push(Process(n,myScheduler.getcounter(),bt,priority));

}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{

    if(ui->comboBox->currentText()=="Non Preemptive Priority" || ui->comboBox->currentText()=="Preemptive Priority"){
    for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
        QTableWidgetItem* item = ui->tableWidget_2->item(row, 2);
        if (!item) {
            item = new QTableWidgetItem();  // Create if doesn't exist
            ui->tableWidget_2->setItem(row, 2, item);
        }
        item->setFlags(item->flags() | Qt::ItemIsEditable);  // Enable editing
    }}



    if(ui->comboBox->currentText()=="Round Robin"){
        ui->label_12->show();
        ui->spinBox_2->show();
    }else{
        ui->label_12->hide();
        ui->spinBox_2->hide();
    }



    switch (index){

    case 0:
        myScheduler.setScheduler_type("FCFS");
        myScheduler.setPreemptive(false);
        break;

    case 1:
        myScheduler.setScheduler_type("SJF");
        myScheduler.setPreemptive(true);
        break;

    case 2:
        myScheduler.setScheduler_type("SJF");
        myScheduler.setPreemptive(false);
        break;

    case 3:
        myScheduler.setScheduler_type("PRIORITY");
        myScheduler.setPreemptive(true);
        break;

    case 4:
        myScheduler.setScheduler_type("PRIORITY");
        myScheduler.setPreemptive(false);
        break;

    case 5:
        myScheduler.setScheduler_type("ROUNDROBIN");
        myScheduler.setPreemptive(false);
        break;
    }

}





double MainWindow::getMinOfColumn(QTableWidget* table, int column) {
    double minValue = std::numeric_limits<double>::max();
    bool hasValidValue = false;

    for (int row = 0; row < table->rowCount(); ++row) {
        if (QTableWidgetItem* item = table->item(row, column)) {
            bool ok;
            double value = item->text().toDouble(&ok);
            if (ok) {
                if (value < minValue) {
                    minValue = value;
                }
                hasValidValue = true;
            }
        }
    }

    return hasValidValue ? minValue : 0.0;
};

void MainWindow::on_pushButton_5_clicked()//start
{

    if (!schedulerTimer->isActive()) {
                                      // Start processing
        schedulerTimer->start(1000); // 1000ms = 1 second
    }
}

void MainWindow::on_pushButton_6_clicked()//stop
{
    if (schedulerTimer->isActive()) {
        schedulerTimer->stop();
    }
}
int quantum=1;
int flag=1;

void MainWindow::processSchedulerStep()//event triggered every 1 sec
{   int q=1;
    if(ui->comboBox->currentText()=="Round Robin"){
        q=ui->spinBox_2->value();
        }
    //quantum=q;
    if(flag){
        quantum=q;
        flag=0;
    }
    ui->tableWidget->setRowCount(n);
    myScheduler.run_scheduler_once(ArrivalBuffer,this, quantum);
    quantum--;
    if(quantum==0)quantum=q;
    QString str = QString::number(myScheduler.getcounter());
    ui->label_7->setText(str);

    str=QString::number(myScheduler.getAvgTurnAround()/n,'f',3);
    ui->label_11->setText(str);
    str=QString::number(myScheduler.getAvgWaitingTime()/n,'f',3);
    ui->label_10->setText(str);



}



