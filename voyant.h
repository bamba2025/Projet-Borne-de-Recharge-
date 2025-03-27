#ifndef VOYANT_H
#define VOYANT_H

#include <donnees_borne.h>
#include <memoire_borne.h>

class Voyant
{

public : 
Voyant();

void voyant_init(void);
void blink_charge(led color);
void set_dispo(led color);
void set_charge(led color);
void blink_default(led color);
};
#endif //VOYANT_H
