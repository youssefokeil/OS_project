#pragma once

#include "process_class.h"

struct CompareByBurstTime {
    bool operator()(const Process& a, const Process& b) {
        if (a.getBurstTime() == b.getBurstTime())
        {
            if (a.getArrivalTime() == b.getArrivalTime())
                return a.getID() > b.getID();

            return a.getArrivalTime() > b.getArrivalTime();

        }
        return a.getBurstTime() > b.getBurstTime();

    }
};
struct CompareByRemainingTime {
    bool operator()(const Process& a, const Process& b) {
        if (a.getRemainingTime() != b.getRemainingTime())
            return a.getRemainingTime() > b.getRemainingTime();
        if (a.getArrivalTime() != b.getArrivalTime())
            return a.getArrivalTime() > b.getArrivalTime();
        return a.getID() > b.getID();        


    }
};

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

struct CompareByPriority {
    bool operator()(const Process& a, const Process& b) {
        return a.get_priority() > b.get_priority();

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

        // default case
        return a.getID() > b.getID();
    }
};