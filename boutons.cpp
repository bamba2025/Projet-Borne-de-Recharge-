// File: boutons.cpp

#include "boutons.h"
#include "voyant.h"
#include "timer.h"
#include <unistd.h>

entrees* io_bt;
int shmid_bt;
// Constructor
Boutons::Boutons() {}

// Method to initialize the Boutons
void Boutons::initialiser() {
    io_bt = acces_memoire(&shmid_bt);
}

// Method to wait for the charge button press
int Boutons::btn_attente_charge() {
    int etat_btn = 0;
    io_bt->bouton_charge = 0;
    int time1 = Timer().timer_valeur();
    int time2 = time1;

    while ((io_bt->bouton_charge == 0) && ((time2 - time1) <= 60)) {
        usleep(100);
        time2 = Timer().timer_valeur();
    }
    etat_btn = io_bt->bouton_charge;
    io_bt->bouton_charge = 0;
    return etat_btn;
}

// Method to handle the stop button
int Boutons::bouton_stop() {
    int etat_btn = io_bt->bouton_stop;
    io_bt->bouton_stop = 0;
    return etat_btn;
}