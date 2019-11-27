#ifndef CLIENT_H
#define CLIENT_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <complex>
#include <tuple>
#include <typeinfo>
#include "Informatie.h"
#include "InfoText.h"
#include "InfoMatematic.h"
#include "InfoAdresa.h"
#include "InfoNumar.h"


using namespace std;

class Client
{
protected:
    vector<Informatie*> informatii;
public:
    Client();
    void getInfoNumar(unsigned int,string);
    void getInfoMatematic(complex<double>,string);
    void getInfoText(string,string);
    void getInfoAdresa(tuple<string,string,string,string,int>,string);
    vector<Informatie*> get_informatii();
};

#endif // CLIENT_H
