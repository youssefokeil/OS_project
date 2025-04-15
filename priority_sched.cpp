#include "process_class.h"


bool sortByArrivalTime(const Process &a, const Process &b) {
    return a.getArrivalTime() < b.getArrivalTime();
}

struct CompareByArrival{
    bool operator()(const Process &a, const Process &b){
        return a.getArrivalTime() < b.getArrivalTime();

    }
};

//bool sortByPriority(const Process &a, const Process &b) {
  //  return a.get_priority() < b.get_priority();
//}
struct CompareByPriority{
    bool operator()(const Process &a, const Process &b){
        return a.get_priority() < b.get_priority();

    }
};

Output Priority_Sched_preemptive( vector<Process> p ){ 

    

    Output output;
    
    int time=0;
    int completed_processes=0;
    int total_processes=p.size(); // counter to trace no of.. 
    // vector<Process>ready_queue; //Priority queue --- modify
    priority_queue<Process, std::vector<Process>, CompareByPriority> Processes;


    while(completed_processes<total_processes){
     
        for(int i=0;i<total_processes;i++){ // time 0 --> {P1 1, P2 4, P3 0, P5 5, P6 0}
            
            if (p[i].getArrivalTime() == time){ 
                Processes.push(p[i]);
            }
        } 
        

        if(!Processes.empty()){
            
            Process current_process=Processes.top();
            current_process.updateRemainingTime(1); // remaining time -1
            output.ganttChart.push_back(Processes.top().getID());

            if(current_process.getRemainingTime()==0){ // it finished execution
                
                current_process.setFinishTime(time+1);
                current_process.calc_turnaround_time();
                current_process.calc_waiting_time();   
                output.avg_waiting_time+= current_process.getWaitingTime();
                output.avg_turnaround_time+= current_process.getTurnaroundTime();
                Processes.pop();
                completed_processes++;

            }

        }   
        else{
           
            output.ganttChart.push_back("x");
           
        }  

        ++time;
    }
    

    output.avg_waiting_time/=total_processes;
    output.avg_turnaround_time/=total_processes;

    return output;
}


Output Priority_Sched_non_preemptive( vector<Process> p ){ 

    Output output;

    sort(p.begin(),p.end(),sortByArrivalTime); // sort by arrival time
    
    int time=0;
    int completed_processes=0;
    int total_processes=p.size(); // counter to trace no of.. 
    while(completed_processes<total_processes){
        
        int next_proc_index=-1;

        for(int i=0;i<total_processes;i++){
                if (p[i].getArrivalTime() <= time && p[i].getRemainingTime() > 0){ 
                    if(next_proc_index==-1 || p[i].get_priority()<p[next_proc_index].get_priority()){
                        next_proc_index=i;
                    }
                }

        }    
        if(next_proc_index!=-1){
            // Process &current_process=p[next_proc_index]; //  process to be executed 
            
            time=time+p[next_proc_index].getBurstTime(); // process executed
            p[next_proc_index].setFinishTime(time);
            p[next_proc_index].calc_turnaround_time();
            p[next_proc_index].calc_waiting_time();

            for (int i = 0; i < p[next_proc_index].getBurstTime(); i++)
                output.ganttChart.push_back(p[next_proc_index].getID());

            output.avg_waiting_time+= p[next_proc_index].getWaitingTime();
            output.avg_turnaround_time+=p[next_proc_index].getTurnaroundTime();

            p[next_proc_index].setRemainingTime(0);
            completed_processes++;
        }
        else{
            output.ganttChart.push_back("x");
            ++time;
        }
        
        //add sleep 
    }
    
    
        

    output.avg_waiting_time/=total_processes;
    output.avg_turnaround_time/=total_processes;

    return output;

}

void printOutput(const Output& output, const string& title) {
    cout << "\n=== " << title << " ===\n";
    cout << "Gantt Chart: ";
    for (const string& id : output.ganttChart) {
        cout << id << " ";
    }
    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << output.avg_waiting_time;
    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2) << output.avg_turnaround_time << "\n";
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0);


    // string scheduler_type;
    // cin>>scheduler_type;
    // for(auto &ch: scheduler_type) ch=toupper(ch); // capitalize the string completely 


    // if(scheduler_type =="SJF"){

    // }
    // else if(scheduler_type=="PRIORITY")
    // {
    //     string type;
    //     cin>>type; // n for non preemptive .... p for preemptive 

    //     if(type=="p"){
            
    //     }
    //     else if(type=="n"){

    //     }

    // }

    // else if(scheduler_type=="RR"){

    // }
    // else if(scheduler_type=="FCFS"){

    // }
    
    vector<Process> processes = {
        Process("P1", 0, 5, 2),
        Process("P2", 1, 3, 1),
        Process("P3", 2, 8, 4),
        Process("P4", 3, 6, 3)
    };

    vector<Process> forPreemptive = processes;       // Clone for fair testing
    vector<Process> forNonPreemptive = processes;

    auto preemptiveOutput = Priority_Sched_preemptive(forPreemptive);
    auto nonPreemptiveOutput = Priority_Sched_non_preemptive(forNonPreemptive);

    printOutput(preemptiveOutput, "Preemptive Priority Scheduling");
    printOutput(nonPreemptiveOutput, "Non-Preemptive Priority Scheduling");
   
    return 0;


}