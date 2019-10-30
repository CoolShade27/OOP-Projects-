#ifndef LISTA_CIRCULARA_H
#define LISTA_CIRCULARA_H

#include <iostream>
#include "Nod.h"
using namespace std;

class Lista_circulara
{
    Nod* prim;
    static int lungime;
public:
    Lista_circulara();
    void adaugare_sfarsit(int);
    void afisare();
    void stergere_pozitie(int);
    void adaugare_pozitie(int,int);
    void adaugare_prim_element(int);
    void stergere_k(int);
    void stergere_lista();
    void inversare();
    friend istream& operator>>(istream&,Lista_circulara&);
    friend ostream& operator<<(ostream&,Lista_circulara&);
    Lista_circulara operator+(const Lista_circulara&);
    Lista_circulara& operator=(const Lista_circulara&);

};

#endif // LISTA_CIRCULARA_H
