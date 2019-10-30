//Tema 1 POO Proiectul nr.9//
#include <iostream>
#include "Lista_circulara.h"
#include "Nod.h"
using namespace std;


class Citire
{
    int n;
    friend class Lista_circulara;
public:
    void citire_n_obiecte();

};


void Citire::citire_n_obiecte()
{
    cin>>n;
    Lista_circulara *v=new Lista_circulara[n];
    for(int i=1; i<=n; i++)
    {
        cout<<"Citire lista nr."<<i<<":"<<endl;
        cin>>v[i];
        cout<<v[i]<<endl;
    }

}

int Lista_circulara::lungime;

int main()
{
    Lista_circulara l1,l2,rezultat;
    cin>>l1;
    /*lista.stergere_pozitie(1);
    lista.afisare();
    lista.stergere_pozitie(2);
    lista.afisare();
    lista.stergere_pozitie(1);
    lista.afisare();/*
    //lista.inversare();*/
    int k;
    cin>>k;
    l1.stergere_k(k);
    cout<<l1;
    //l1=l2;
    /*rezultat=l1+l2;
    cout<<rezultat;
    Citire c;
    c.citire_n_obiecte();*/

    return 0;
}
