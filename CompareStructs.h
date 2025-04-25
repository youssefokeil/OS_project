#pragma once

#include "process_class.h"


struct CompareByArrivalTime {
    bool operator()(const Process& a, const Process& b) {
        if (a.getArrivalTime() == b.getArrivalTime())
        {
            if (a.getRemainingTime() == b.getRemainingTime())
                return a.getID() > b.getID();

            return a.getRemainingTime() > b.getRemainingTime();

        }
        return a.getArrivalTime() > b.getArrivalTime();

    }
};



struct DynamicComparator {
    const string* scheduler_type_ptr;

    // Constructor takes a pointer to the scheduler's type string
    DynamicComparator(const string* type_ptr) : scheduler_type_ptr(type_ptr) {}

    // Default constructor for when it's needed
    DynamicComparator() : scheduler_type_ptr(nullptr) {}

    bool operator()(const Process& a, const Process& b) {
        // Shortest Job First
            // Make sure we have a valid pointer
        if (!scheduler_type_ptr) {
            return a.getID() > b.getID(); // Default behavior
        }

        const string& scheduler_type = *scheduler_type_ptr;
        if (scheduler_type == "SJF") {
            if (a.getRemainingTime() != b.getRemainingTime())
                return a.getRemainingTime() > b.getRemainingTime();
            if (a.getArrivalTime() != b.getArrivalTime())
                return a.getArrivalTime() > b.getArrivalTime();
            return a.getID() > b.getID();
        }
        // priority comparator
        else if (scheduler_type == "PRIORITY") {
            if (a.get_priority() != b.get_priority())
                return a.get_priority() > b.get_priority();
            if (a.getArrivalTime() != b.getArrivalTime())
                return a.getArrivalTime() > b.getArrivalTime();
            return a.getID() > b.getID();
        }
        // first-come first-served
        else if (scheduler_type == "FCFS") {
            if (a.getArrivalTime() != b.getArrivalTime())
                return a.getArrivalTime() > b.getArrivalTime();
            return a.getID() > b.getID();
        }
         // round-robin
        else if(scheduler_type=="ROUNDROBIN")
        {
            if (a.getRrId() != b.getRrId())
                return a.getRrId() > b.getRrId();
            if(a.getRrId()==b.getRrId()){
                if(a.getBurstTime()-a.getRemainingTime() == b.getBurstTime()-b.getRemainingTime())
                    return a.getID() > b.getID();
                return a.getBurstTime()-a.getRemainingTime() > b.getBurstTime()-b.getRemainingTime();
            }
            return a.getID() > b.getID();

        }

        // default case
        return a.getID() > b.getID();
    }
};
