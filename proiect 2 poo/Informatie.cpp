#include "Informatie.h"

int Informatie::global_ID=1;

Informatie::Informatie()
{
    this->ID=global_ID;
    global_ID++;
}

Informatie::Informatie(string n):nume(n) {};

string Informatie::getNume()
{
    return nume;
}

int Informatie::getID()
{
    return ID;
}
