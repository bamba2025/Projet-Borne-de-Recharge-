#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include <donnees_borne.h> // Add this if entrees is defined here
#include <memoire_borne.h> // Add this if entrees is defined here

class LecteurCarte
{

  public : 
  LecteurCarte();
	void initialiser();
	void lire_carte();
};

#endif // LECTEURCARTE_H
