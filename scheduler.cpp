#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <thread>
#include <queue>
#include <string>

#include "process_class.h"
#include "CompareStructs.h"
#include "Scheduler.h"

using namespace std;

// ArrivalBuffer should be checked every second, doesn't make sense 
Scheduler::Scheduler(string scheduler_type, bool preemptive) {
    this->scheduler_type = scheduler_type;
    this->preemptive = preemptive;


    // re-declaration of MainQueue depending on Scheduler Type
    if (scheduler_type == "SJF")
        // main priority queue is compared by remaining time
        priority_queue<Process, std::vector<Process>, CompareByRemainingTime> MainQueue;
    else if (scheduler_type == "FCFS")
        // main priority queue is compared by Arrival time
        priority_queue<Process, std::vector<Process>, CompareByArrivalTime> MainQueue;
    else if (scheduler_type == "PRIORITY")
        // main p0riority queue by priority 
        priority_queue<Process, std::vector<Process>, CompareByPriority> MainQueue;
    else
        return;
}
    
void Scheduler::run_scheduler_once(priority_queue<Process, std::vector<Process>, CompareByArrivalTime> &PassedArrivalBuffer) {


    while (!PassedArrivalBuffer.empty()) {

        // top of arrived processes
        newProcess = PassedArrivalBuffer.top();

        // update only if preemptive or no process is executing
        if ((newProcess.getArrivalTime() <= counter) && (!processExecuting || this->preemptive)) {
            // push arrived process
            this->MainQueue.push(newProcess);
            // update buffer
            PassedArrivalBuffer.pop();
        }
        else
            break;
    }

    auto start = chrono::high_resolution_clock::now();

    cout << "\ncounter : " << counter << endl;

    if (!MainQueue.empty()) {
        // current process from burst time
        currentProcess = this->MainQueue.top();
        this->processExecuting = 1;
    }
    else 
        currentProcess = Process(0, 0, 0);
   


    this_thread::sleep_for(chrono::milliseconds(1000));


    if (currentProcess.getRemainingTime()) {
        // update burst time
        currentProcess.updateRemainingTime(1);

        // print current element
        gantt_chart.push_back("P" + to_string(currentProcess.getID()) + " | ");

        // pop top element
        this->MainQueue.pop();


        // push top element if process not ended
        if (currentProcess.getRemainingTime()) {
            this->MainQueue.push(currentProcess);
        }
        else {
            // process remainingTime=0, process ended
            this->processExecuting = 0;
        }
    }
    else
        gantt_chart.push_back("__ | ");

    // after every second the counter adds 1
    counter++;


    // Accessing and printing elements
    for (const string& str : gantt_chart)
        cout << str;
}



