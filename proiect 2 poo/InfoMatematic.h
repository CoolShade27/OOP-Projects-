#ifndef INFOMATEMATIC_H
#define INFOMATEMATIC_H

#include "Informatie.h"
#include <complex>


class InfoMatematic : public Informatie
{
protected:
    complex<double> nr;
public:
    InfoMatematic(complex<double>,string);
    complex<double> get_matematic();
    void set_matematic(complex<double>);
    istream& operator>>(istream&);
    ostream& operator<<(ostream&);
};

#endif // INFOMATEMATIC_H
