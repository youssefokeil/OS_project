#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <thread>
#include <queue>

#include "process_class.h"


using namespace std;

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
        if(currentProcess.getRemainingTime()){
            

          
            currentProcess.updateRemainingTime(1);

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

}
}
