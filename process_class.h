#pragma once

#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <thread>
#include <queue>
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
    int rr_id;


public:    


    // Constructor
    Process();

    // Constructor for priority scheduling
    Process(int id,int arrival_time,int burst_time,int priority);

    // setters
    void setFinishTime(int finish_time);
    void setBurstTime(int burst_time);
    void setStartTime(int start);
    void setRemainingTime(int time);
    void setRrId(int rrId);

    // getters
    int getArrivalTime() const;
    int getBurstTime() const;
    int getFinishTime() const;
    int getWaitingTime() const;
    int getTurnaroundTime() const;
    int getID() const;
    int getRemainingTime() const ;
    int getRrId() const;

    // Priority scheduling
    int get_priority() const;

    // calculation
    int calc_waiting_time();
    int calc_turnaround_time();
    void updateRemainingTime(int timeUsed);

    // Priority scheduling
    int get_priority() const;

    
};

struct Output {

    double avg_waiting_time=0;
    double avg_turnaround_time=0;
    vector<string> ganttChart;

};
