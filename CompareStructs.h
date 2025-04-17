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
