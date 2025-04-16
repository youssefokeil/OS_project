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


using namespace std;

struct CompareByBurstTime{
    bool operator()(const Process &a, const Process &b){
        if(a.getBurstTime()==b.getBurstTime())
            {
           if(a.getArrivalTime()==b.getArrivalTime())
                        return a.getID() >b.getID() ;

            return a.getArrivalTime() >b.getArrivalTime();

               }
        return a.getBurstTime() > b.getBurstTime();

    }
};
struct CompareByRemainingTime{
    bool operator()(const Process &a, const Process &b){
        if(a.getRemainingTime()==b.getRemainingTime())
            {
           if(a.getArrivalTime()==b.getArrivalTime())
                        return a.getID() >b.getID() ;

            return a.getArrivalTime() >b.getArrivalTime();

               }
        return a.getRemainingTime() > b.getRemainingTime();

    }
};

struct CompareByArrival{
        bool operator()(const Process &a, const Process &b){
            if(a.getArrivalTime()==b.getArrivalTime())
               {
           if(a.getRemainingTime()==b.getRemainingTime())
                        return a.getID() >b.getID() ;

                return a.getRemainingTime() >b.getRemainingTime();

               }
            return a.getArrivalTime() > b.getArrivalTime();

        }
};

struct CompareByPriority {
    bool operator()(const Process& a, const Process& b) {
        return a.get_priority() > b.get_priority();

    }
};


int main()
{

    //  min heaps initialization, one sorted by arrival time, and one sorted by burst time.
    priority_queue<Process, std::vector<Process>, CompareByArrival> ProcessesByArrival;
    priority_queue<Process, std::vector<Process>, CompareByPriority> MainQueue; 
    
 
    vector<string> gantt_chart;


    // number of processes in initial
    cout<<"Number of Processes:"<<flush;
    int n;
    cin>>n;

    // default is preemptive, no process executing
    bool preemptive=1, processExecuting=0; 


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
            ProcessesByArrival.push(p);
            cout<<p.getID()<<" "<<p.getArrivalTime()<<" "<<p.getRemainingTime()<<endl;
    }

    // initialization
    int counter=0;
    Process newProcess, currentProcess;
    
    // the main while loop should be changed to take flag stop or stth from GUI
    while(!ProcessesByArrival.empty()||!MainQueue.empty()){        
        while(!ProcessesByArrival.empty()){
            // top of arrived processes
            newProcess=ProcessesByArrival.top();

            // update only if preemptive or no process is executing
            if(newProcess.getArrivalTime()<=counter && (!processExecuting || preemptive)){
                // push arrived process
                MainQueue.push(newProcess);
                // update buffer
                ProcessesByArrival.pop();
            }else
                break;
        }

        auto start = chrono::high_resolution_clock::now();


        cout<< "\ncounter : " << counter<<endl;

        Process currentProcess;
        if (!MainQueue.empty()) {
            // current process from burst time
            currentProcess = MainQueue.top();
            processExecuting = 1;
        }
        else
            currentProcess=Process(0,0,0);

        this_thread::sleep_for(chrono::milliseconds(1000));

        
        if(currentProcess.getRemainingTime()){
            // update burst time
            currentProcess.updateRemainingTime(1);

            // print current element
            gantt_chart.push_back("P"+to_string(currentProcess.getID())+ " | " );

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
        cout << str ;

}
}
