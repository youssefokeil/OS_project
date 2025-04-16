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

// to be put in own header file
struct CompareByBurstTime {
    bool operator()(const Process& a, const Process& b) {
        if (a.getBurstTime() == b.getBurstTime())
        {
            if (a.getArrivalTime() == b.getArrivalTime())
                return a.getID() > b.getID();

            return a.getArrivalTime() > b.getArrivalTime();

        }
        return a.getBurstTime() > b.getBurstTime();

    }
};
struct CompareByRemainingTime {
    bool operator()(const Process& a, const Process& b) {
        if (a.getRemainingTime() == b.getRemainingTime())
        {
            if (a.getArrivalTime() == b.getArrivalTime())
                return a.getID() > b.getID();

            return a.getArrivalTime() > b.getArrivalTime();

        }
        return a.getRemainingTime() > b.getRemainingTime();

    }
};

struct CompareByArrival {
    bool operator()(const Process& a, const Process& b) {
        if (a.getArrivalTime() == b.getArrivalTime())
        {
            if (a.getRemainingTime() == b.getRemainingTime())
                return a.getID() > b.getID();

            return a.getRemainingTime() > b.getRemainingTime();

        }
        return a.getArrivalTime() > b.getArrivalTime();

    }
};

class Scheduler {
private:
    // initialization
    Process newProcess, currentProcess;

    // declare scheduler type
    string scheduler_type
    // process executing flag default is false, default is preemptive
    bool processExecuting=false, preemptive=true;

public:
    Scheduler(string scheduler_type, bool preemptive) {
        this->scheduler_type = scheduler_type;
        this->preemptive = preemptive;
    }
    
    void run_scheduler_once(priority_queue<Process, std::vector<Process>, CompareByArrival> ArrivalBuffer) {
        if (scheduler_type == "SJF")
            // main priority queue is compared by remaining time
            priority_queue<Process, std::vector<Process>, CompareByRemainingTime> MainQueue;
        else
            return;

        while (!ArrivalBuffer.empty()) {
            // top of arrived processes
            newProcess = ArrivalBuffer.top();

            // update only if preemptive or no process is executing
            if (newProcess.getArrivalTime() <= counter && (!processExecuting || preemptive)) {
                // push arrived process
                MainQueue.push(newProcess);
                // update buffer
                ArrivalBuffer.pop();
            }
            else
                break;
        }

        auto start = chrono::high_resolution_clock::now();


        cout << "\ncounter : " << counter << endl;

        Process currentProcess;
        if (!MainQueue.empty()) {
            // current process from burst time
            currentProcess = MainQueue.top();
            processExecuting = 1;
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
            MainQueue.pop();

            // push top element if process not ended
            if (currentProcess.getRemainingTime())
                MainQueue.push(currentProcess);
            else
                // process remainingTime=0, process ended
                processExecuting = 0;
        }
        else
            gantt_chart.push_back("__ | ");

        // after every second the counter adds 1
        counter++;


        // Accessing and printing elements
        for (const string& str : gantt_chart)
            cout << str;
    }

};


