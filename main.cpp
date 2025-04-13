#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <thread>
#include <bits/stdc++.h>


using namespace std;

class Process{

private:

    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int start_time;
    int finish_time;
    int remaining_time; // for scheduling algorithms with preemption (SJF_RR)
    int priority; // for priority scheduling



public:


// Constructor for FCFS, RR and SJF scheduling
    Process(int id, int arrival_time, int burst_time){
        this->id = id;
        this->arrival_time = arrival_time;
        this->burst_time = burst_time;
        this->waiting_time = 0;
        this->turnaround_time = 0;
        this->finish_time = 0;
        this->start_time = -1;
        this->remaining_time = burst_time;
    }


// Constructor for priority scheduling
    Process(){
    }
    Process(int id,int arrival_time,int burst_time,int priority){
        this->id=id;
        this->arrival_time=arrival_time;
        this->burst_time=burst_time;
        this->waiting_time=0;
        this->turnaround_time=0;
        this->finish_time=0;
        this->priority=priority;
        this->start_time = -1;
        this->remaining_time = burst_time;

    }

    /* Turn_around=finish_time-arrival_time
       waiting_time=turnaround_time-burst_time
    */

    void setFinishTime(int finish_time){
        this->finish_time=finish_time;

    }
    void setBurstTime(int burst_time){
        this->burst_time=burst_time;
    }

    void setStartTime(int start) {
        start_time = start;
    }

    int calc_waiting_time(){
        waiting_time=turnaround_time-burst_time;
        return waiting_time;
    }
    int calc_turnaround_time(){
        turnaround_time=finish_time-arrival_time;
        return turnaround_time;
    }

    void updateRemainingTime(int timeUsed) {
        remaining_time -= timeUsed;
    }

    // Priority scheduling
    void set_priority(int priority){
        this->priority=priority;
    }
    int get_priority() const{return priority;}

    // getters
    int getArrivalTime() const { return arrival_time; }
    int getBurstTime() const { return burst_time; }
    int getFinishTime() const { return finish_time; }
    int getWaitingTime() const { return waiting_time; }
    int getTurnaroundTime() const { return turnaround_time; }
    int getID() const { return id; }
    int getRemainingTime() const { return remaining_time; }



};
struct CompareByBurst{
    bool operator()(const Process &a, const Process &b){
            return a.getBurstTime() > b.getBurstTime();

    }
};
struct CompareByArrival{
    bool operator()(const Process &a, const Process &b){

        if(a.getArrivalTime() == b.getArrivalTime()) //if 2 processes arrived at the same time compare burst time
            return a.getBurstTime() > b.getBurstTime();

            return a.getArrivalTime() > b.getArrivalTime();

    }
};


int main()
{

    //  min heap initialization
    priority_queue<Process, std::vector<Process>, CompareByArrival> Processes;

    cout<<"Number of Processes:"<<flush;
    int n;
    cin>>n;


    for(int i=1; i<=n; i++){
             int arrivalTime=0,burstTime=0;
             cout<<"Arrival time:";
             cin>>arrivalTime;
             cout<<"Burst time:";
             cin>>burstTime;
             Process  p(i,arrivalTime,burstTime);
             Processes.push(p);
             cout<<p.getID()<<" "<<p.getArrivalTime()<<" "<<p.getBurstTime()<<endl;
          /*  int art,bt;
            cout<<"Burst time:";
            cin>>bt;
            Process  p(i,0,bt);
            Processes.push(p);
            cout<<p.getID()<<" "<<p.getArrivalTime()<<" "<<p.getBurstTime()<<endl;
          */

    }



    //cout << "Sorted by Burst Time in min heap (ascendingly):\n";
 /*
    for (int i=0; i<n ; i++){
        Process process=Processes.top();
        cout<<"BT:"<<process.getBurstTime()<<endl;
        cout<<"ID:"<<process.getID()<<endl;

        Processes.pop();

    }*/




    // Using regular for loop with decreasing index
    while(!Processes.empty()){

        auto start = chrono::high_resolution_clock::now();

        // get next process in queue
        Process currentProcess=Processes.top();





        // update burst time
        if(currentProcess.getBurstTime()){
            this_thread::sleep_for(chrono::milliseconds(1000));
            currentProcess.setBurstTime(currentProcess.getBurstTime()-1);

            // print current element
            cout<<"P"<<currentProcess.getID()<< " | " ;

            // update top element
            Processes.pop();
            Processes.push(currentProcess);

        }
        else
            Processes.pop();


}







}
