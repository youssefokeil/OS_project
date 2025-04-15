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
//Default Constructor
    Process(){
    }

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
        if(a.getBurstTime()==b.getBurstTime())
            return a.getArrivalTime() >b.getArrivalTime();

        return a.getBurstTime() > b.getBurstTime();

    }
};

struct CompareByArrival{
        bool operator()(const Process &a, const Process &b){
            if(a.getArrivalTime()==b.getArrivalTime())
                return a.getBurstTime() >b.getBurstTime();
    
            return a.getArrivalTime() > b.getArrivalTime();
    
        }
};



int main()
{

    //  min heaps initialization, one sorted by arrival time, and one sorted by burst time.
    priority_queue<Process, std::vector<Process>, CompareByArrival> ProcessesByArrival;
    priority_queue<Process, std::vector<Process>, CompareByBurst> ProcessesByBurst;
    vector<string> gantt_chart;

    cout<<"Number of Processes:"<<flush;
    int n;
    cin>>n;


    for(int i=1; i<=n; i++){
            int art=0,bt;
            cout<<"Arrival time:";
            cin>>art;
            cout<<"Burst time:";
            cin>>bt;
            
            Process  p(i,art,bt);
            ProcessesByArrival.push(p);
            cout<<p.getID()<<" "<<p.getArrivalTime()<<" "<<p.getBurstTime()<<endl;


    }

    int counter=0;
    while(!ProcessesByArrival.empty()||!ProcessesByBurst.empty()){
        Process newProcess;

                   
        while(!ProcessesByArrival.empty()){
            // top of arrived processes
            newProcess=ProcessesByArrival.top();
            if(newProcess.getArrivalTime()<=counter){
                    // push arrived process
                ProcessesByBurst.push(newProcess);
                // update buffer 
                ProcessesByArrival.pop();
            }else
                break;
        }
        
        auto start = chrono::high_resolution_clock::now();
        
    
        cout<< "\ncounter : " << counter<<endl;
        
        Process currentProcess;
        if(!ProcessesByBurst.empty())
        // current process from burst time
            currentProcess=ProcessesByBurst.top();
        else
            currentProcess=Process(0,0,0);
        
        this_thread::sleep_for(chrono::milliseconds(1000));

        // update burst time
        if(currentProcess.getBurstTime()){
            

          
            currentProcess.setBurstTime(currentProcess.getBurstTime()-1);

            // print current element       
            gantt_chart.push_back("P"+to_string(currentProcess.getID())+ " | " );

            // update top element
            ProcessesByBurst.pop();
            ProcessesByBurst.push(currentProcess);

        }
        else if(!ProcessesByBurst.empty())
            ProcessesByBurst.pop();
        else
            gantt_chart.push_back("__ | ");

        // after every second the counter adds 1
        counter++;

        
    // Accessing and printing elements
    for (const string& str : gantt_chart) 
        cout << str ;
    
    cout<<"\n";
    

}
}
