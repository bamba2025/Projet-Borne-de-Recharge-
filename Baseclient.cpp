#include "Baseclient.h"

// Define authentifier as a member function of BaseClient
int BaseClient::authentifier(int numero_carte) {
    if (numero_carte < 10000)
        return 1;
    else
        return 0;
}