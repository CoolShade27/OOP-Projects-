#include "InfoNumar.h"

InfoNumar::InfoNumar(unsigned int nr,string nume):Informatie(nume),nr(nr) {};

unsigned int InfoNumar::get_nr()
{
    return nr;
}

void InfoNumar::set_nr(unsigned int x)
{
    nr=x;
}

istream& InfoNumar::operator>>(istream &in)
{
    unsigned int n;
    in>>n;
    set_nr(n);
    return in;
}

ostream& InfoNumar::operator<<(ostream &out)
{
    out<<nr;
    return out;
}
