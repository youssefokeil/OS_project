/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QTableWidget *tableWidget_2;
    QComboBox *comboBox;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QLabel *label_6;
    QPushButton *pushButton_4;
    QLabel *label_12;
    QSpinBox *spinBox_2;
    QWidget *page_4;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        stackedWidget->setFont(font);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        tableWidget_2 = new QTableWidget(page_3);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(410, 170, 331, 401));
        sizePolicy.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy);
        tableWidget_2->setFont(font);
        tableWidget_2->setColumnCount(3);
        comboBox = new QComboBox(page_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 170, 260, 30));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setFont(font);
        label = new QLabel(page_3);
        label->setObjectName("label");
        label->setGeometry(QRect(35, 220, 120, 30));
        spinBox = new QSpinBox(page_3);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(200, 220, 50, 30));
        spinBox->setValue(1);
        pushButton = new QPushButton(page_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 350, 80, 30));
        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 70, 281, 71));
        QFont font1;
        font1.setPointSize(32);
        label_6->setFont(font1);
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 350, 80, 30));
        label_12 = new QLabel(page_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(35, 270, 120, 30));
        spinBox_2 = new QSpinBox(page_3);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(200, 270, 50, 30));
        spinBox_2->setValue(1);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_2 = new QLabel(page_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 29, 181, 31));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        label_2->setFont(font2);
        label_4 = new QLabel(page_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 80, 101, 20));
        label_5 = new QLabel(page_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 120, 70, 20));
        pushButton_2 = new QPushButton(page_4);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 160, 91, 29));
        pushButton_3 = new QPushButton(page_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(50, 160, 83, 29));
        spinBox_3 = new QSpinBox(page_4);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(220, 80, 61, 29));
        spinBox_4 = new QSpinBox(page_4);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setGeometry(QRect(220, 120, 61, 29));
        horizontalLayoutWidget = new QWidget(page_4);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 460, 781, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(page_4);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(450, 110, 121, 41));
        QFont font3;
        font3.setPointSize(18);
        pushButton_5->setFont(font3);
        pushButton_6 = new QPushButton(page_4);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(610, 110, 121, 41));
        pushButton_6->setFont(font3);
        label_3 = new QLabel(page_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 249, 71, 31));
        QFont font4;
        font4.setPointSize(16);
        label_3->setFont(font4);
        label_7 = new QLabel(page_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(80, 290, 51, 31));
        label_7->setFont(font4);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(page_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(460, 240, 261, 41));
        label_8->setFont(font4);
        label_9 = new QLabel(page_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(190, 240, 211, 41));
        label_9->setFont(font4);
        label_10 = new QLabel(page_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(270, 290, 51, 31));
        label_10->setFont(font4);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_11 = new QLabel(page_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(560, 290, 51, 31));
        label_11->setFont(font4);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page_4);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Arrival time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Burst time", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Preemptive SJF", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Non Preemptive SJF", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Preemptive Priority", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Non Preemptive Priority", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Round Robin", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "No of processes", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Visualize", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "CPU Scheduler", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Quantum", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Add new process", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Burst time", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Time:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Avg Turnaround time:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Avg waiting time:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
