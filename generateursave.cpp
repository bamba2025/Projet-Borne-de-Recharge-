#include "generateursave.h"  // Include the header file for the class declaration
#include "prise.h"
#include "voyant.h"
#include "timer.h"
#include "boutons.h"
#include <cstdio>
#include <iostream>

entrees* io_gs;
int shmid_gs;

// Constructor
Generateur::Generateur() {}

// Method to initialize the generator
void Generateur::generateur_initialiser() {
    io_gs = acces_memoire(&shmid_gs);
}

// Method to generate PWM signal
void Generateur::generer_PWM(pwm tension) {
    io_gs->gene_pwm = tension;
}

// Method to close the AC contactor
void Generateur::fermer_AC() {
    io_gs->contacteur_AC = 1;
}

// Method to open the AC contactor
void Generateur::ouvrir_AC() {
    io_gs->contacteur_AC = 0;
}

// Method to get the voltage
float Generateur::tension() {
    return io_gs->gene_u;
}

// Method to handle the state machine
void Generateur::mef() {
    enum etat { A, B, C, D, E };
    bool Fin = false;
    etat state = A;
    while (true) {
        switch (state) {
            case A:
                Voyant().set_charge(ROUGE);
                Prise().deverrouiller_trappe();
                generer_PWM(DC);
                while (tension() != 9) {
                    std::cout << "attente branchement prise..." << std::endl;
                }
                state = B;
                break;
            case B:
                Prise().set_prise(VERT);
                Prise().verrouiller_trappe();
                generer_PWM(AC_1K);
                state = C;
                break;
            case C:
                if (Boutons().bouton_stop() == 1) { state = E; break; }
                fermer_AC();
                if (Boutons().bouton_stop() == 1) { state = E; break; }
                Timer().delay_sec(1);
                if (Boutons().bouton_stop() == 1) { state = E; break; }
                state = D;
                break;
            case D:
                generer_PWM(AC_CL);
                while ((tension() != 9) && (Boutons().bouton_stop() == 0)) {
                    std::cout << "chargement..." << std::endl;
                }
                state = E;
                break;
            case E:
                ouvrir_AC();
                generer_PWM(DC);
                Voyant().set_charge(VERT);
                Fin = true;
                break;
        }
        if (Fin) break;
    }
}

// Method to start charging
void Generateur::charger() {
    mef();
}

// Method to disconnect the generator
void Generateur::deconnecter() {
    std::cout << "authentification réussite" << std::endl;
    Voyant().blink_charge(VERT);
    Prise().deverrouiller_trappe();
    while (tension() != 12) {
        std::cout << "attente débranchement prise..." << std::endl;
    }
    Prise().verrouiller_trappe();
    Timer().delay_sec(1);
    Voyant().set_charge(OFF);
    Prise().set_prise(OFF);
    Voyant().set_dispo(VERT);
    generer_PWM(STOP);
}