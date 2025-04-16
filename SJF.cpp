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

using namespace std;


int main()
{

    //  min heaps initialization, one sorted by arrival time, and one sorted by burst time.
    priority_queue<Process, std::vector<Process>, CompareByArrival> ArrivalBuffer;
    priority_queue<Process, std::vector<Process>, CompareByArrival> MainQueue; 
    
 
    vector<string> gantt_chart;


    // number of processes in initial
    cout<<"Number of Processes:"<<flush;
    int n;
    cin>>n;

    // default is preemptive, no process executing
    bool preemptive=0, processExecuting=0; 


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

    // initialization
    int counter=0;
    Process newProcess, currentProcess;
    
    // the main while loop should be changed to take flag stop or stth from GUI
    while (!ArrivalBuffer.empty() || !MainQueue.empty()) {
        while(!ArrivalBuffer.empty()){
            // top of arrived processes
            newProcess = ArrivalBuffer.top();

            // update only if preemptive or no process is executing
            if(newProcess.getArrivalTime()<=counter && (!processExecuting || preemptive)){
                // push arrived process
                MainQueue.push(newProcess);
                // update buffer
                ArrivalBuffer.pop();
            }else
                break;
        }

        auto start = chrono::high_resolution_clock::now();


        cout<< "\ncounter : " << counter<<endl;

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
