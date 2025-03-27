#ifndef TIMER_H
#define TIMER_H

#include <donnees_borne.h>
#include <memoire_borne.h>

class Timer {
public:
    Timer();
    void timer_init();         // Remplace timer_init() en C
    int timer_valeur();        // Remplace timer_valeur() en C
    void delay_sec(int delay);
};

#endif // TIMER_H