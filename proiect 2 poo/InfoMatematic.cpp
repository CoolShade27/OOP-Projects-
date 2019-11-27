#include "InfoMatematic.h"

InfoMatematic::InfoMatematic(complex<double> nr,string nume):Informatie(nume),nr(nr) {};

complex<double> InfoMatematic::get_matematic()
{
    return nr;
}

void InfoMatematic::set_matematic(complex<double> z)
{
    nr=z;
}

istream& InfoMatematic::operator>>(istream& in)
{
    complex<double> z;
    in>>z;
    set_matematic(z);
    return in;
}

ostream& InfoMatematic::operator<<(ostream &out)
{
    out<<nr;
    return out;
}
