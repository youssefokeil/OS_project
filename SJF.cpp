#include "process_class.h"
#include "CompareStructs.h"
#include "Scheduler.h"

using namespace std;


int main(){
    //  min heaps initialization, one sorted by arrival time, and one sorted by burst time.
    priority_queue<Process, std::vector<Process>, CompareByArrivalTime> ArrivalBuffer;
    vector<string> gantt_chart;

    // number of processes in initial
    cout<<"Number of Processes:"<<flush;
    int n;
    cin>>n;
    string s;
    cout<<"Enter Type: ";
    cin>>s;
    int quantum=1;
    if(s=="ROUND-ROBIN") {
        cout << "Enter Quantum: ";
        cin >> quantum;
    }

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
        p.setRrId(art);
        ArrivalBuffer.push(p);
        cout<<p.getID()<<" "<<p.getArrivalTime()<<" "<<p.getRemainingTime()<<endl;
    }

    // SJF preemptive
    Scheduler SJF_scheduler = Scheduler(s, false);
int q=quantum;
    // the main while loop should be changed to take flag stop or stth from GUI
    for (int i = 0;i < 30;i++) {
        SJF_scheduler.run_scheduler_once(ArrivalBuffer,q);
        q--;
        if(q==0)q=quantum;
    }
    cout<<"\navgTurnAround "<<SJF_scheduler.getAvgTurnAround()/n<<endl;
    cout<<"avgWaitingTime "<<SJF_scheduler.getAvgWaitingTime()/n<<endl;

}
