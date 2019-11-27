#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
using namespace std;

class Management
{
private:
    static Management *instance;
    Management();
    vector<Client> clienti;
public:
    ~Management();
    static Management* getInstance();
    void meniu();
    void meniu_adaugare();
    void meniu_cautare();
    void adaugare();
    void stergere_ID(int);
    void stergere_nume(string);
    void regasire_nume(string);
    void regasire_ID(int);
    void cautare(int);
};

#endif // MANAGEMENT_H
