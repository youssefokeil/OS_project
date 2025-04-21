#include "process_class.h"

// Default Constructor
Process::Process() {
    id = 0;
    arrival_time = 0;
    burst_time = 0;
    waiting_time = 0;
    turnaround_time = 0;
    finish_time = 0;
    start_time = -1;
    remaining_time = 0;
    priority = 0;

}

// Constructor for all scheduling algorithms, all unused variables equal zero
Process::Process(int id, int arrival_time, int burst_time, int priority){

    waiting_time = 0;
    turnaround_time = 0;
    finish_time = 0;
    start_time = -1;
    this->id=id;
    this->arrival_time=arrival_time;
    this->burst_time=burst_time;
    remaining_time=burst_time;
    this->priority = priority;
}

// Setters
void Process::setFinishTime(int finish_time) {
    this->finish_time = finish_time;
}

void Process::setBurstTime(int burst_time) {
    this->burst_time = burst_time;
}

void Process::setStartTime(int start) {
    start_time = start;
}

void Process::setRemainingTime(int time) {
    remaining_time = time;
}

void Process::set_priority(int priority) {
    this->priority = priority;
}

void Process::setRrId(int rrId) {
    rr_id = rrId;
}


// Getters
int Process::get_priority() const {
    return priority;
}

int Process::getArrivalTime() const {
    return arrival_time;
}

int Process::getBurstTime() const {
    return burst_time;
}

int Process::getFinishTime() const {
    return finish_time;
}

int Process::getWaitingTime() const {
    return waiting_time;
}

int Process::getTurnaroundTime() const {
    return turnaround_time;
}

int Process::getID() const {
    return id;
}

int Process::getRemainingTime() const {
    return remaining_time;
}

int Process::getRrId() const {
    return rr_id;
}

// Calculations
int Process::calc_waiting_time() {
    waiting_time = turnaround_time - burst_time;
    return waiting_time;
}

int Process::calc_turnaround_time() {
    turnaround_time = finish_time - arrival_time;
    return turnaround_time;
}

void Process::updateRemainingTime(int timeUsed) {
    remaining_time -= timeUsed;
}





