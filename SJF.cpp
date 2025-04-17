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


int main()
{

    //  min heaps initialization, one sorted by arrival time, and one sorted by burst time.
    priority_queue<Process, std::vector<Process>, CompareByArrivalTime> ArrivalBuffer;

    
 
    vector<string> gantt_chart;


    // number of processes in initial
    cout<<"Number of Processes:"<<flush;
    int n;
    cin>>n;

    // default is preemptive, no process executing
    bool preemptive=0, processExecuting=0; 

    // scheduler type to be input
    string scheduler_type = "SJF";

    // input receival from terminal
    for(int i=1; i<=n; i++){
        int art = 0, bt, priority;
            cout<<"Arrival time: ";
            cin>>art;
            cout<<"Burst time: ";
            cin>>bt;
            cout << "Priority: ";
            cin >> priority;

            Process  p(i, art, bt, priority);
            ArrivalBuffer.push(p);
            cout<<p.getID()<<" "<<p.getArrivalTime()<<" "<<p.getRemainingTime()<<endl;
    }
    

    // the main while loop should be changed to take flag stop or stth from GUI
   
    // SJF preemptive
    Scheduler SJF_scheduler = Scheduler(scheduler_type, true );



    for (int i = 0;i < 10;i++) {
       SJF_scheduler.run_scheduler_once(ArrivalBuffer);   
    }
        
}
