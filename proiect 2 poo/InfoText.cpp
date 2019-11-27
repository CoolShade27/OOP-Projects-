#include "InfoText.h"

InfoText::InfoText(string text,string nume):Informatie(nume),data(text) {};

void InfoText::set_data(string n)
{
    data=n;
}

string InfoText::get_data()
{
    return data;
}

istream& InfoText::operator>>(istream &in)
{
    string s;
    cout<<"Introduceti text:"<<endl;
    in>>s;
    data.append(s);
    return in;
}

ostream& InfoText::operator<<(ostream& out)
{
    out<<data;
    return out;
}
