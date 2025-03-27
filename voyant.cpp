// File: voyant.cpp

#include "voyant.h"
#include "timer.h"


entrees* io_vy;
int shmid_vy;
// Constructor
Voyant::Voyant(){}

// Method to initialize the Voyant
void Voyant::voyant_init() {
    io_vy = acces_memoire(&shmid_vy);
}

// Method to set the charge LED color
void Voyant::set_charge(led color) {
    io_vy->led_charge = color;
}

// Method to set the dispo LED color
void Voyant::set_dispo(led color) {
    io_vy->led_dispo = color;
}

// Method to blink the charge LED
void Voyant::blink_charge(led color) {
    int time1 = Timer().timer_valeur();
    int time2 = time1;
    while ((time2 - time1) <= 8) {
        if ((time2 - time1) % 2 == 0)
            io_vy->led_charge = color;
        else
            io_vy->led_charge = OFF;
        time2 = Timer().timer_valeur();
    }
}

// Method to blink the default LED
void Voyant::blink_default(led color) {
    int time1 = Timer().timer_valeur();
    int time2 = time1;
    while ((time2 - time1) <= 8) {
        if ((time2 - time1) % 2 == 0)
            io_vy->led_defaut = color;
        else
            io_vy->led_defaut = OFF;
        time2 = Timer().timer_valeur();
    }
}