#ifndef GENERATEURSAVE_H
#define GENERATEURSAVE_H

#include <donnees_borne.h>
#include <memoire_borne.h>

class Generateur {

public:
    Generateur();
    void generateur_initialiser();       // Remplace generateur_initialiser()
    void charger();
    void generer_PWM(pwm tension);
    void ouvrir_AC();
    void fermer_AC();
    float tension();
    void deconnecter();
    void mef();
};

#endif // GENERATEURSAVE_H