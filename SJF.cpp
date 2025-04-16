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


int main()
{

    //  min heaps initialization, one sorted by arrival time, and one sorted by burst time.
    priority_queue<Process, std::vector<Process>, CompareByArrival> ProcessesByArrival;
    priority_queue<Process, std::vector<Process>, CompareByRemainingTime> ProcessesByRemainingTime; //preemptive
    priority_queue<Process, std::vector<Process>, CompareByBurstTime> ProcessesByBurstTime; //for nonpreemptive

    vector<string> gantt_chart;

    cout<<"Number of Processes:"<<flush;
    int n;
    cin>>n;
bool preemptive=1;

    for(int i=1; i<=n; i++){
            int art=0,bt;
            cout<<"Arrival time:";
            cin>>art;
            cout<<"Burst time:";
            cin>>bt;

            Process  p(i,art,bt);
            ProcessesByArrival.push(p);
            cout<<p.getID()<<" "<<p.getArrivalTime()<<" "<<p.getRemainingTime()<<endl;


    }

    int counter=0;
    while(!ProcessesByArrival.empty()||!ProcessesByRemainingTime.empty()){


            if(preemptive==0){

            }






        Process newProcess;


        while(!ProcessesByArrival.empty()){
            // top of arrived processes
            newProcess=ProcessesByArrival.top();
            if(newProcess.getArrivalTime()<=counter){
                    // push arrived process
                ProcessesByRemainingTime.push(newProcess);
                // update buffer
                ProcessesByArrival.pop();
            }else
                break;
        }

        auto start = chrono::high_resolution_clock::now();


        cout<< "\ncounter : " << counter<<endl;

        Process currentProcess;
        if(!ProcessesByRemainingTime.empty())
        // current process from burst time
            currentProcess=ProcessesByRemainingTime.top();
        else
            currentProcess=Process(0,0,0);

        this_thread::sleep_for(chrono::milliseconds(1000));

        // update burst time
        if(currentProcess.getRemainingTime()){



            currentProcess.updateRemainingTime(1);

            // print current element
            gantt_chart.push_back("P"+to_string(currentProcess.getID())+ " | " );

            // update top element
            ProcessesByRemainingTime.pop();
            if(currentProcess.getRemainingTime())
            ProcessesByRemainingTime.push(currentProcess);

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
