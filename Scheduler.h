#pragma once

#include "process_class.h"

using namespace std;

class Scheduler {
private:
    // initialization
    Process newProcess, currentProcess;
    // declare scheduler type
    string scheduler_type;
    // process executing flag default is false, default is preemptive
    bool processExecuting = false, preemptive = true;
    int counter = 0; // doesn't make sense
    vector<string> gantt_chart;

    priority_queue<Process, std::vector<Process>, DynamicComparator> MainQueue;
    queue<Process>RRQueue;
public:

    Scheduler(string, bool);
    void run_scheduler_once(priority_queue<Process, std::vector<Process>, CompareByArrivalTime> &);


    int roundRobin(priority_queue<Process, std::vector<Process>, CompareByArrivalTime> &PassedArrivalBuffer, int quantum);
};