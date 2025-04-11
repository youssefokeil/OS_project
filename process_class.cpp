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
