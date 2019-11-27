#include <iostream>
#include <cstring>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <complex>
#include <typeinfo>
#include "Informatie.h"
#include "InfoMatematic.h"
#include "Management.h"
#include "InfoAdresa.h"

using namespace std;

int main()
{

    Management *m=Management::getInstance();
    bool ok=true;
    int op;
    while(ok)
    {
        m->meniu();
        cin>>op;
        switch(op)
        {
        case 1:
        {
            m->adaugare();
            break;
        }
        case 2:
        {
            int ID;
            cin>>ID;
            m->regasire_ID(ID);
            break;
        }
        case 3:
        {
            string nume;
            cin>>nume;
            m->regasire_nume(nume);
            break;
        }
        case 4:
        {
            int ID;
            cin>>ID;
            m->stergere_ID(ID);
            break;
        }
        case 5:
        {
            string nume;
            cin>>nume;
            m->stergere_nume(nume);
            break;
        }
        case 6:
        {

            m->meniu_cautare();
            int op_c;
            cin>>op_c;
            m->cautare(op_c);
            break;
        }
        case 7:
        {
            ok=false;
            break;
        }
        }
    }
    m->~Management();

    return 0;
}
