#pragma once
#include"mainwindow.h"
#include "process_class.h"
#include"CompareStructs.h"
using namespace std;

class Scheduler {
private:
    // initialization
    Process newProcess, currentProcess;

    // declare scheduler type
    string scheduler_type;

    // process executing flag default is false, default is preemptive
    bool processExecuting = false, preemptive = true;

    int counter = 0;

    vector<string> gantt_chart;

    double avgTurnAround=0,avgWaitingTime=0;
    priority_queue<Process, std::vector<Process>, DynamicComparator> MainQueue;
public:

    Scheduler(string , bool );

    void run_scheduler_once(priority_queue<Process, std::vector<Process>, CompareByArrivalTime> &,MainWindow *mainWindow,int &q);

    vector<std::string>& getGanttChart();

    std::priority_queue<Process, std::vector<Process>, DynamicComparator>& getMainQueue();

    int getcounter();

    double getAvgTurnAround() const;

    void setAvgTurnAround(double avgTurnAround);

    double getAvgWaitingTime() const;

    void setAvgWaitingTime(double avgWaitingTime);

    void setScheduler_type(string scheduler_type);

    void setPreemptive(bool preemptive)  ;

};
