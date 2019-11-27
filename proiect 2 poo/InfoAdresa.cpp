#include "InfoAdresa.h"

InfoAdresa::InfoAdresa(tuple<string,string,string,string,int> adresa, string nume):Informatie(nume),adresa(adresa) {};

tuple<string,string,string,string,int> InfoAdresa::get_adresa()
{
    return adresa;
}

void InfoAdresa::set_adresa(tuple<string,string,string,string,int> a)
{
    adresa=a;
}

istream& InfoAdresa::operator>>(istream &in)
{
    string s1,s2,s3,s4;
    int n;
    in>>s1>>s2>>s3>>s4;
    in>>n;
    adresa=make_tuple(s1,s2,s3,s4,n);
    return in;
}

ostream& InfoAdresa::operator<<(ostream &out)
{
    out<<get<0>(adresa)<<" "<<get<1>(adresa)<<" "<<get<2>(adresa)<<" "<<get<3>(adresa)<<" "<<get<4>(adresa);
    return out;
}
