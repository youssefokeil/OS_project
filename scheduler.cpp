#include "process_class.h"
#include "CompareStructs.h"
#include "Scheduler.h"

using namespace std;


double Scheduler::getAvgTurnAround() const {
    return avgTurnAround;
}

void Scheduler::setAvgTurnAround(double avgTurnAround) {
    Scheduler::avgTurnAround = avgTurnAround;
}

double Scheduler::getAvgWaitingTime() const {
    return avgWaitingTime;
}

void Scheduler::setAvgWaitingTime(double avgWaitingTime) {
    Scheduler::avgWaitingTime = avgWaitingTime;
}

// Set Scheduler Type and whether it is preemptive
Scheduler::Scheduler(string scheduler_type, bool preemptive) {
    this->scheduler_type = scheduler_type;
    this->preemptive = preemptive;

    // Initialize the class member MainQueue, not a local variable
    this->MainQueue = priority_queue<Process, std::vector<Process>, DynamicComparator>(
            DynamicComparator(&this->scheduler_type));

}


void Scheduler::run_scheduler_once(priority_queue<Process, std::vector<Process>, CompareByArrivalTime> &PassedArrivalBuffer,int q) {


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


    if (!MainQueue.empty()) {
        // current process from burst time
        currentProcess = MainQueue.top();
        this->processExecuting = true;
    }
    else
        currentProcess = Process(0, 0, 0,0);

    int min_time=min(q,currentProcess.getRemainingTime());

    if (currentProcess.getRemainingTime()) {
        // update burst time
        currentProcess.updateRemainingTime(min_time);

        // print current element
        while(min_time--) {
            //printing for a quantum/once if not round-robin
            this_thread::sleep_for(chrono::milliseconds(1000));
            counter++;
            cout << "\ncounter : " << counter << endl;
            gantt_chart.push_back("P" + to_string(currentProcess.getID()) + " | ");
            for (const string& str : gantt_chart)
                cout << str;
        }

        // after a process finishes a quantum its rr_id is set to current time
        currentProcess.setRrId(counter);

        // pop top element
        MainQueue.pop();


        // push top element if process not ended
        if (currentProcess.getRemainingTime()) {
            MainQueue.push(currentProcess);
        }
        else {
            // process remainingTime=0, process ended
            currentProcess.setFinishTime(counter);
            avgTurnAround+=currentProcess.calc_turnaround_time();
            avgWaitingTime+=currentProcess.calc_waiting_time();
            this->processExecuting = false;
        }
    }
    else {
        // printing in case of idle
        this_thread::sleep_for(chrono::milliseconds(1000));
        counter++;
        cout << "\ncounter : " << counter << endl;
        gantt_chart.push_back("__ | ");
        for (const string& str : gantt_chart)
            cout << str;
    }

}




