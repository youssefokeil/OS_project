#include "process_class.h"




Output Priority_Sched_preemptive( vector<Process> p ){ 

    Output output;

    sort(p.begin(),p.end(),sortByArrivalTime); // sort by arrival time
    
    int time=0;
    int completed_processes=0;
    int total_processes=p.size(); // counter to trace no of.. 
    vector<Process>ready_queue;

    while(completed_processes<total_processes){
     
        for(int i=0;i<total_processes;i++){ // time 0 --> {P1 1, P2 4, P3 0, P5 5, P6 0}
            
            if (p[i].getArrivalTime() == time){ 
                ready_queue.push_back(p[i]);
            }
        } 
        
        sort(ready_queue.begin(),ready_queue.end(),sortByPriority); // sorts the queue by priority

        if(!ready_queue.empty()){
            
            ready_queue[0].updateRemainingTime(1); // remaining time -1
            output.ganttChart.push_back(ready_queue[0].getID());

            if(ready_queue[0].getRemainingTime()==0){ // it finished execution
                
                ready_queue[0].setFinishTime(time+1);
                ready_queue[0].calc_turnaround_time();
                ready_queue[0].calc_waiting_time();   
                output.avg_waiting_time+= ready_queue[0].getWaitingTime();
                output.avg_turnaround_time+= ready_queue[0].getTurnaroundTime();
                ready_queue.erase(ready_queue.begin());
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

    }

        
        

    output.avg_waiting_time/=total_processes;
    output.avg_turnaround_time/=total_processes;

    return output;

}