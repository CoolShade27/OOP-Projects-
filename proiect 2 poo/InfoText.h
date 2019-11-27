#ifndef INFOTEXT_H
#define INFOTEXT_H

#include "Informatie.h"
#include <string>


class InfoText : public Informatie
{
protected:
    string data;
public:
    InfoText(string,string);
    void set_data(string);
    string get_data();
    istream& operator>>(istream&);
    ostream& operator<<(ostream&);
};

#endif // INFOTEXT_H
