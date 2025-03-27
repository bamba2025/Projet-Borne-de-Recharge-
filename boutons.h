#ifndef BOUTONS_H
#define BOUTONS_H

#include <donnees_borne.h>
#include <memoire_borne.h>

class Boutons {
public:
    Boutons();
    void initialiser();
    void btn_dispo_off();
    int btn_attente_charge();
    int bouton_stop();
};

#endif // BOUTONS_H