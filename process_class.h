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



public:    


// Constructor
Process();

// Constructor for FCFS, RR and SJF scheduling
Process(int id, int arrival_time, int burst_time);


// Constructor for priority scheduling
Process(int id,int arrival_time,int burst_time,int priority);

/* Turn_around=finish_time-arrival_time
   waiting_time=turnaround_time-burst_time
*/

// setters
void setFinishTime(int finish_time);
void setBurstTime(int burst_time);
void setStartTime(int start);
void setRemainingTime(int time);
// Priority scheduling
void set_priority(int priority);

// calculation
int calc_waiting_time();
int calc_turnaround_time();
void updateRemainingTime(int timeUsed);

// getters
int getArrivalTime() const;
int getBurstTime() const;
int getFinishTime() const;
int getWaitingTime() const;
int getTurnaroundTime() const;
int getID() const;
int getRemainingTime() const ;
// Priority scheduling
int get_priority() const;


    
};

struct Output {

    double avg_waiting_time=0;
    double avg_turnaround_time=0;
    vector<string> ganttChart;

};

/*
bool sortByArrivalTime(const Process &a, const Process &b);

bool sortByPriority(const Process &a, const Process &b);

void printOutput(const Output& output, const string& title);*/