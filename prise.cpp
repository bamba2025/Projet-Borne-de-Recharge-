// File: prise.cpp

#include "prise.h"

entrees* io_p;
int shmid_p;
// Constructor
Prise::Prise() {}

// Method to initialize the Prise
void Prise::initialiser() {
    io_p = acces_memoire(&shmid_p);
}

// Method to unlock the trap
void Prise::deverrouiller_trappe() {
    io_p->led_trappe = VERT;
}

// Method to lock the trap
void Prise::verrouiller_trappe() {
    io_p->led_trappe = OFF;
}

// Method to set the color of the prise LED
void Prise::set_prise(led color) {
    io_p->led_prise = color;
}
