#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <cctype>

using namespace std;

class Masina
{
protected:
    string nume;
    double pret;
public:
    virtual void afisare()=0;
    virtual void afisare_expozitie()=0;
    Masina(string nume,double pret):nume(nume),pret(pret) {};
    double get_pret()
    {
        return pret;
    }
    string get_nume()
    {
        return nume;
    }
    virtual ~Masina()
    {

    }


};

class HOT_HATCH:public Masina
{
public:
    HOT_HATCH(string nume,double pret):Masina(nume,pret) {};
    void afisare()
    {
        cout<<"Masina de tip HOT-HATCH"<<endl;
        cout<<"Nume: "<<nume<<endl;
        cout<<"Pret: "<<pret<<endl;
    }
    void afisare_expozitie()
    {
        cout<<"Nume: "<<nume<<endl;
        cout<<"Pret: "<<pret<<endl;
    }
    friend ostream& operator<<(ostream &out,HOT_HATCH &h)
    {
        h.afisare();
        return out;
    }
};

class CABRIO:public Masina
{
public:
    CABRIO(string nume,double pret):Masina(nume,pret) {};
    void afisare()
    {
        cout<<"Masina de tip CABRIO"<<endl;
        cout<<"Nume: "<<nume<<endl;
        cout<<"Pret: "<<pret<<endl;
    }
    void afisare_expozitie()
    {
        cout<<"Nume: "<<nume<<endl;
        cout<<"Pret: "<<pret<<endl;
    }
    friend ostream& operator<<(ostream &out,CABRIO &c)
    {
        c.afisare();
        return out;
    }
};

class COUPE:public Masina
{
public:
    COUPE(string nume,double pret):Masina(nume,pret) {};
    void afisare_expozitie()
    {
        cout<<"Nume: "<<nume<<endl;
        cout<<"Pret: "<<pret<<endl;
    }
    void afisare()
    {
        cout<<"Masina de tip COUPE"<<endl;
        cout<<"Nume: "<<nume<<endl;
        cout<<"Pret: "<<pret<<endl;
    }
    friend ostream& operator<<(ostream &out,COUPE &c)
    {
        c.afisare();
        return out;
    }
};

class SUPERSPORT:public Masina
{
public:
    SUPERSPORT(string nume,double pret):Masina(nume,pret) {};
    void afisare_expozitie()
    {
        cout<<"Nume: "<<nume<<endl;
        cout<<"Pret: "<<pret<<endl;
    }
    void afisare()
    {
        cout<<"Masina de tip SUPERSPORT"<<endl;
        cout<<"Nume: "<<nume<<endl;
        cout<<"Pret: "<<pret<<endl;
    }
    string get_nume() const
    {
        return this->nume;
    }
    double get_pret() const
    {
        return this->pret;
    }
    friend ostream& operator<<(ostream &out,SUPERSPORT &ss)
    {
        ss.afisare();
        return out;
    }
};

template<class T>
class Expozitie
{
protected:
    vector<T> cars;
    static int nr;
public:
    void add_car(T ob)
    {
        string name=ob.get_nume();
        try
        {
            for(unsigned int i=0;i<name.size();i++)
            {
                if(isspace(name[i]))
                    throw name;
            }
        }
        catch(string str)
        {
            cout<<"Numele nu poate contine spatii!"<<endl;
            for(unsigned int i=0;i<str.size();i++)
            {
                if(isspace(str[i]))
                    str.replace(str.begin()+i,str.begin()+i+1,"_");
            }
            cout<<"Noul nume: "<<str<<endl;
        }
        cars.push_back(ob);
        nr++;
    }
    void afisare()
    {
        string type=typeid(T).name();
        for(unsigned int i=0;i<type.size();i++)
        {
            if(isdigit(type[i]))
                type.erase(type.begin()+i);
        }
        cout<<"Masini de tipul "<<type<<endl;
        cout<<"Numar masini in stoc: "<<nr<<endl;
        cout<<"Masinile din stoc: "<<endl;
        typename vector<T>::iterator it;
        for(it=cars.begin(); it!=cars.end(); it++)
            it->afisare_expozitie();
    }
    ~Expozitie()
    {
        cars.clear();
    }
};

template<>
class Expozitie<SUPERSPORT>
{
private:
    static int sold;
    static int total;
    vector<SUPERSPORT> cars_in_stock;
    vector<SUPERSPORT> sold_cars;
public:
    static int get_sold()
    {
        return sold;
    }
    static int get_total()
    {
        return total;
    }
    void add_car(string nume,double pret)
    {
        try
        {
            for(unsigned int i=0;i<nume.size();i++)
            {
                if(isspace(nume[i]))
                    throw nume;
            }
        }
        catch(string str)
        {
            cout<<"Numele nu poate contine spatii!"<<endl;
            for(unsigned int i=0;i<str.size();i++)
            {
                if(isspace(str[i]))
                    str.replace(str.begin()+i,str.begin()+i+1,"_");
            }
            cout<<"Noul nume: "<<str<<endl;
        }
        SUPERSPORT *ss=new SUPERSPORT(nume,pret);
        cars_in_stock.push_back(*ss);
        total++;
        delete ss;
    }
    void sell(string nume)
    {
        if(cars_in_stock.empty())
        {
            cout<<"Nu exista masini in stoc!"<<endl;
            return;
        }
        bool found=false;
        for(unsigned int i=0;i<cars_in_stock.size();i++)
        {
            if(nume.compare(cars_in_stock[i].get_nume())==0)
            {
                found=true;
                sold_cars.push_back(cars_in_stock[i]);
                cars_in_stock.erase(cars_in_stock.begin()+i);
                sold++;
                total--;
            }
        }
        if(found==false)
            cout<<"Masina nu exista in stoc!"<<endl;
    }
    void afisare()
    {
        cout<<"Numar masini in stoc: "<<get_total()<<endl;
        cout<<"Numar masini vandute: "<<get_sold()<<endl;
        cout<<"Masinile din stoc: "<<endl;
        vector<SUPERSPORT>::iterator it;
        for(it=cars_in_stock.begin(); it!=cars_in_stock.end(); it++)
            it->afisare_expozitie();
        cout<<"Masinile vandute: "<<endl;
        for(it=sold_cars.begin(); it!=sold_cars.end(); it++)
            it->afisare_expozitie();
    }
    Expozitie<SUPERSPORT>* operator-=(string s)
    {
        sell(s);
        return this;
    }
};

class Showroom
{
private:
    vector<pair<Masina*,double>> cars;
public:
    ~Showroom()
    {
        for(unsigned int i=0;i<cars.size();i++)
        {
            delete cars[i].first;
        }
    }
    void add_car(string nume,double pret,int op)
    {
        switch(op)
        {
        case 1:
            cars.push_back(make_pair(new CABRIO(nume,pret),-1));
        case 2:
            cars.push_back(make_pair(new COUPE(nume,pret),-1));
        case 3:
            cars.push_back(make_pair(new HOT_HATCH(nume,pret),-1));
        case 4:
            cars.push_back(make_pair(new SUPERSPORT(nume,pret),-1));
        default:
            cout<<"Invalid type"<<endl;
        }
    }
    void sell(string nume)
    {
        if(cars.empty())
        {
            cout<<"Nu exista masini in stoc!"<<endl;
            return;
        }
        bool found=false;
        for(unsigned int i=0;i<cars.size();i++)
        {
            if(nume.compare(cars[i].first->get_nume())==0)
            {
                found=true;
                cars[i].second=cars[i].first->get_pret();
            }
        }
        if(found==false)
            cout<<"Masina nu exista in stoc!"<<endl;
    }
    void afisare()
    {
        if(cars.empty())
        {
            cout<<"Nu exista masini in showroom!"<<endl;
            return;
        }
        cout<<"Masinile din showroom:"<<endl;
        for(unsigned int i=0;i<cars.size();i++)
        {
            cars[i].first->afisare();
            if(cars[i].second!=-1)
                cout<<"Vandut"<<endl;
            else cout<<"In stoc"<<endl;
        }
    }
};
template<class T>
class Management
{
private:
    static Management *instance;
    Management() {}
    Showroom s;
    Expozitie<T> e;
public:
    Management* get_instance()
    {
        if(instance==0)
        {
            instance=new Management();
        }
        return instance;
    }
    ~Management()
    {
        s.~Showroom();
        e.~Expozitie();
    }

};

template<class T>
int Expozitie<T>::nr=0;

int Expozitie<SUPERSPORT>::sold=0;
int Expozitie<SUPERSPORT>::total=0;

int main()
{
    /*ifstream f("date.txt");
    Expozitie<SUPERSPORT> e;
    int n;
    f>>n;
    string nume;
    double pret;
    for(int i=0;i<n;i++)
    {
        nume.erase();
        f>>nume;
        f>>pret;
        e.add_car(nume,pret);
    }*/
    /*e.afisare();
    e-="xd";
    e-="Audi_R8";
    e-="Lexus_TF";
    e-="Bugatti_Veyron";
    e-="xd";
    e.afisare();
    e.add_car("Honda_NSX",420000);
    e.afisare();
    /*Expozitie<CABRIO> c;
    c.afisare();
    CABRIO *c1=new CABRIO("Porsche_718",30000);
    CABRIO *c2=new CABRIO("BMW_Z4",45000);
    c.add_car(*c1);
    c.add_car(*c2);
    c.afisare();*/


    /*cout<<"Alegeti tipul masinii: "<<endl;
        cout<<"1.COUPE"<<endl;
        cout<<"2.CABRIO"<<endl;
        cout<<"3.HOT-HATCH"<<endl;
        cout<<"4.SUPERSPORT"<<endl;
        int op;
        cin>>op;*/

    /*Showroom s;
    s.add_car("a",1,1);
    s.add_car("b",2,4);
    s.add_car("c",3,2);
    s.sell("a");
    s.afisare();*/
    Expozitie<SUPERSPORT> es;
    es.add_car("Audi R8",100000);

    return 0;
}
