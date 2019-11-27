#ifndef INFONUMAR_H
#define INFONUMAR_H

#include "Informatie.h"


class InfoNumar : public Informatie
{
protected:
    unsigned int nr;
public:
    InfoNumar(unsigned int,string);
    unsigned int get_nr();
    void set_nr(unsigned int);
    istream& operator>>(istream&);
    ostream& operator<<(ostream&);
};

#endif // INFONUMAR_H
