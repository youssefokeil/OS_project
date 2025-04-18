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

    int q,quantum;
    cout<<"Enter Quantum: ";
    cin>>quantum;
    q=quantum;
    string s;
    cout<<"Enter Type: ";
    cin>>s;
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

    // SJF preemptive
    Scheduler SJF_scheduler = Scheduler(s, true);

    // the main while loop should be changed to take flag stop or stth from GUI
    for (int i = 0;i < 30;) {
        if (s=="ROUND-ROBIN") {
        while(quantum--){
                i++;
                if (SJF_scheduler.roundRobin(ArrivalBuffer, quantum))break;
            }
            quantum=q;
        }else {i++; SJF_scheduler.run_scheduler_once(ArrivalBuffer); }
    }

}