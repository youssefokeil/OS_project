#include <vector>
#include <queue>
#include <string>

#include "process_class.h"
#include "CompareStructs.h"
#include "Scheduler.h"



using namespace std;
vector<string>& Scheduler::getGanttChart()  {
    return gantt_chart;
}
 std::priority_queue<Process, std::vector<Process>, DynamicComparator>& Scheduler::getMainQueue() {
     return MainQueue;
 }


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
 void Scheduler::setScheduler_type(string scheduler_type) {
     Scheduler::scheduler_type = scheduler_type;
 }
 void Scheduler::setPreemptive(bool preemptive){
     Scheduler::preemptive = preemptive;

 }  
int Scheduler::getcounter(){
    return counter;
};


// Set Scheduler Type and whether it is preemptive
Scheduler::Scheduler(string scheduler_type, bool preemptive) {
    this->scheduler_type = scheduler_type;
    this->preemptive = preemptive;
  

    // Initialize the class member MainQueue, not a local variable
    this->MainQueue = priority_queue<Process, std::vector<Process>, DynamicComparator>(
        DynamicComparator(&this->scheduler_type));

}

    
void Scheduler::run_scheduler_once(priority_queue<Process, std::vector<Process>, CompareByArrivalTime> &PassedArrivalBuffer,int &q) {


    while (!PassedArrivalBuffer.empty()) {

        // top of arrived processes
        newProcess = PassedArrivalBuffer.top();

        // update only if preemptive or no process is executing
        if ((newProcess.getArrivalTime() <= counter) && (!processExecuting || this->preemptive)) {
            // push arrived process
            MainQueue.push(newProcess);
            // update buffer
           if(scheduler_type=="ROUNDROBIN")processExecuting=true;
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
        currentProcess = Process(0, 0, 0,0);
   


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
        
        if(currentProcess.getRemainingTime()<q){
            q=currentProcess.getRemainingTime()+1;
        }
        if(q==1){
            currentProcess.setRrId(counter);
            processExecuting=false;
        }else processExecuting=true;


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
    else{
        q=1;  
        gantt_chart.push_back("__ | ");
    }


    // Accessing and printing elements
    for (const string& str : gantt_chart)
        cout << str;
}



