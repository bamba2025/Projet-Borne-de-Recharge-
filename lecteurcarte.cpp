// File: lecteurcarte.cpp

#include <unistd.h>
#include <iostream>
#include "lecteurcarte.h"
#include "Baseclient.h"
#include "voyant.h"
#include "boutons.h"
#include "timer.h"
#include "generateursave.h"
#include "prise.h"

// Constructor to initialize member variables.
entrees* io_lc;
int shmid_lc;
LecteurCarte::LecteurCarte() {}

void LecteurCarte::initialiser() {
    initialisations_ports();
    io_lc = acces_memoire(&shmid_lc);
}

void LecteurCarte::lire_carte() {
    unsigned short int numero_carte, numero_carte1;
    int flag = 0;
    std::cout << "Veuillez insérer la carte:" << std::endl;
    attente_insertion_carte();

    if (carte_inseree()) {
        numero_carte = lecture_numero_carte();

        if (BaseClient().authentifier(numero_carte)) {
            std::cout << "le numero de carte est " << numero_carte << std::endl;
            std::cout << "authentification réussite" << std::endl;
            Voyant().blink_charge(VERT);
            if (Boutons().btn_attente_charge()) {
                Voyant().set_dispo(OFF);
                flag = 1;
            } else {
                Voyant().set_dispo(VERT);
            }
        } else {
            std::cout << "échec d'authentification" << std::endl;
            Voyant().blink_default(ROUGE);
        }
        std::cout << "Veuillez retirer la carte:" << std::endl;
        attente_retrait_carte();
    }

    if (flag) {
        Generateur().charger();
        std::cout << "Veuillez insérer la carte:" << std::endl;
        attente_insertion_carte();

        if (carte_inseree()) {
            numero_carte1 = lecture_numero_carte();
            std::cout << "Numero de carte " << numero_carte1 << std::endl;
            if ((BaseClient().authentifier(numero_carte1)) && (numero_carte1 == numero_carte)) {
                Generateur().deconnecter();
            } else {
                Voyant().blink_default(ROUGE);
            }
            std::cout << "Veuillez retirer la carte" << std::endl;
            attente_retrait_carte();
        }
    }
}