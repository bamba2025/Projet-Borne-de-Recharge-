// File: timer.cpp

#include "timer.h"
#include <iostream>
#include <cstdio>

entrees* io_t;
int shmid_t;
// Constructor
Timer::Timer() {}

// Method to initialize the timer
void Timer::timer_init() {
    io_t = acces_memoire(&shmid_t);
}

// Method to get the timer value
int Timer::timer_valeur() {
    return io_t->timer_sec;
}

// Method to introduce a delay in seconds
void Timer::delay_sec(int delay) {
    int time1 = timer_valeur();
    int time2 = time1;
    while ((time2 - time1) <= delay) {
        time2 = timer_valeur();
        std::cout << "delay" << std::endl;
    }
}