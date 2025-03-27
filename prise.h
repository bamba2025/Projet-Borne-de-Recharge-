#ifndef PRISE_H
#define PRISE_H

#include <donnees_borne.h>
#include <memoire_borne.h>

class Prise {

public:
    Prise();
    void initialiser();
    void verrouiller_trappe();
    void deverrouiller_trappe();
    void set_prise(led color);
};

#endif