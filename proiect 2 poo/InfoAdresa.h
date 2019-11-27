#ifndef INFOADRESA_H
#define INFOADRESA_H

#include "Informatie.h"
#include <tuple>


class InfoAdresa : public Informatie
{
protected:
    tuple<string,string,string,string,int> adresa;
public:
    InfoAdresa(tuple<string,string,string,string,int>,string);
    tuple<string,string,string,string,int> get_adresa();
    void set_adresa(tuple<string,string,string,string,int>);
    istream& operator>>(istream&);
    ostream& operator<<(ostream&);
};

#endif // INFOADRESA_H
