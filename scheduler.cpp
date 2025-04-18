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

// Set Scheduler Type and whether it is preemptive
Scheduler::Scheduler(string scheduler_type, bool preemptive) {
    this->scheduler_type = scheduler_type;
    this->preemptive = preemptive;

    // Initialize the class member MainQueue, not a local variable
    this->MainQueue = priority_queue<Process, std::vector<Process>, DynamicComparator>(
            DynamicComparator(&this->scheduler_type));

}

void Scheduler::run_scheduler_once(priority_queue<Process, std::vector<Process>, CompareByArrivalTime> &PassedArrivalBuffer) {


    while (!PassedArrivalBuffer.empty()) {

        // top of arrived processes
        newProcess = PassedArrivalBuffer.top();

        // update only if preemptive or no process is executing
        if ((newProcess.getArrivalTime() <= counter) && (!processExecuting || this->preemptive)) {
            // push arrived process
            MainQueue.push(newProcess);
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
        currentProcess = MainQueue.top();
        this->processExecuting = 1;
    }
    else
        currentProcess = Process(0, 0, 0);



    this_thread::sleep_for(chrono::milliseconds(1000));


    // after every second the counter adds 1
    counter++;


    if (currentProcess.getRemainingTime()) {
        // update burst time
        currentProcess.updateRemainingTime(1);

        // print current element
        gantt_chart.push_back("P" + to_string(currentProcess.getID()) + " | ");

        // pop top element
        MainQueue.pop();


        // push top element if process not ended
        if (currentProcess.getRemainingTime()) {
            MainQueue.push(currentProcess);
        }
        else {
            // process remainingTime=0, process ended
            this->processExecuting = 0;
        }
    }
    else
        gantt_chart.push_back("__ | ");



    // Accessing and printing elements
    for (const string& str : gantt_chart)
        cout << str;
}











int Scheduler::roundRobin(priority_queue<Process, std::vector<Process>, CompareByArrivalTime> &PassedArrivalBuffer,int quantum) {

int flag=0;

    while (!PassedArrivalBuffer.empty()) {

        // top of arrived processes
        newProcess = PassedArrivalBuffer.top();

        // update only if preemptive or no process is executing
        if ((newProcess.getArrivalTime() <= counter) ) {
            // push arrived process
            RRQueue.push(newProcess);
            // update buffer
            PassedArrivalBuffer.pop();
        }
        else
            break;
    }


    auto start = chrono::high_resolution_clock::now();

    cout << "\ncounter : " << counter << endl;

    if (RRQueue.empty())RRQueue.front()= Process(0, 0, 0);



    this_thread::sleep_for(chrono::milliseconds(1000));


    // after every second the counter adds 1
    counter++;


    if ( RRQueue.front().getRemainingTime()) {

        // update burst time
        RRQueue.front().updateRemainingTime(1);

        // print current element
        gantt_chart.push_back("P" + to_string(RRQueue.front().getID()) + " | ");


        if(!RRQueue.empty()   &&   RRQueue.front().getRemainingTime()  &&   quantum==0) {
            // push top element if process not ended
            // pop top element
             RRQueue.push(RRQueue.front());
             RRQueue.pop();

         }else if(RRQueue.front().getRemainingTime() ==0) {
            // pop top element
            RRQueue.pop();
            flag=1;
        }


    }
    else
        gantt_chart.push_back("__ | ");



    // Accessing and printing elements
    for (const string& str : gantt_chart)
        cout << str;

    return flag;
}


