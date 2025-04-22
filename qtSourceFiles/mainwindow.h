#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<QTableWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // mainwindow.h
    QHBoxLayout* getHorizontalLayout() const;
    void clearLayout(QLayout* layout);
    double getMinOfColumn(QTableWidget* table, int column);

    
private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_5_clicked();

    void processSchedulerStep();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
     QTimer* schedulerTimer;
};
#endif // MAINWINDOW_H
