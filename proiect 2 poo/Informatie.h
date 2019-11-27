#ifndef INFORMATIE_H
#define INFORMATIE_H

#include <iostream>

using namespace std;

class Informatie
{
private:
    static int global_ID;
protected:
    string nume;
    int ID;
    Informatie();
    Informatie(string);
public:
    virtual istream& operator >>(istream &in)=0;
    virtual ostream& operator <<(ostream &out)=0;
    string getNume();
    int getID();
};



#endif // INFORMATIE_H
