#include "Management.h"

Management* Management::instance=0;

Management* Management::getInstance()
{
    if(instance==0)
    {
        instance=new Management();
    }
    return instance;
}

Management::Management() {}

Management::~Management()
{
    clienti.clear();
}

void Management::meniu_cautare()
{
    cout<<"Tipuri de date:"<<endl;
    cout<<"1.Text"<<endl;
    cout<<"2.Numar natural"<<endl;
    cout<<"3.Matematic(numar complex)"<<endl;
    cout<<"4.Adresa"<<endl;
}

void Management::meniu()
{
    cout<<"Introduceti optiunea:"<<endl;
    cout<<"1.Adaugare informatii"<<endl;
    cout<<"2.Regasire dupa ID"<<endl;
    cout<<"3.Regasire dupa nume"<<endl;
    cout<<"4.Stergere dupa ID"<<endl;
    cout<<"5.Stergere dupa nume"<<endl;
    cout<<"6.Cautare informatii"<<endl;
    cout<<"7.Iesire"<<endl;
}

void Management::meniu_adaugare()
{
    cout<<"Tipuri de date:"<<endl;
    cout<<"1.Text"<<endl;
    cout<<"2.Numar natural"<<endl;
    cout<<"3.Matematic(numar complex)"<<endl;
    cout<<"4.Adresa"<<endl;
    cout<<"5.Iesire"<<endl;
}

void Management::adaugare()
{
    bool ok=true;
    int op;
    Management::meniu_adaugare();
    Client c;
    string nume;
    while(ok)
    {
        cout<<"Introduceti tipul de date/optiunea:"<<endl;
        cin>>op;
        switch(op)
        {
        case 1:
        {
            nume.clear();
            string text;
            cout<<"Introduceti textul:"<<endl;
            cin>>text;
            cout<<"Dati-i un nume:"<<endl;
            cin>>nume;
            c.getInfoText(text,nume);
            break;
        }
        case 2:
        {
            nume.clear();
            unsigned int numar;
            cout<<"Introduceti numarul:"<<endl;
            cin>>numar;
            cout<<"Dati-i un nume:"<<endl;
            cin>>nume;
            c.getInfoNumar(numar,nume);
            break;
        }
        case 3:
        {
            nume.clear();
            double a,b;
            cout<<"Introduceti partea reala:"<<endl;
            cin>>a;
            cout<<"Introduceti partea imaginara:"<<endl;
            cin>>b;
            complex<double> cpx(a,b);
            cout<<"Dati-i un nume:"<<endl;
            cin>>nume;
            c.getInfoMatematic(cpx,nume);
            break;
        }
        case 4:
        {
            nume.clear();
            string tara,judet,oras,strada;
            int numar;
            cout<<"Introduceti adresa:"<<endl;
            cin>>tara>>judet>>oras>>strada>>numar;
            cout<<"Dati-i un nume:"<<endl;
            cin>>nume;
            tuple<string,string,string,string,int> adr(tara,judet,oras,strada,numar);
            c.getInfoAdresa(adr,nume);
            break;
        }
        case 5:
        {
            ok=false;
            clienti.push_back(c);
            break;
        }
        default:
        {
            ok=false;
            cout<<"Optiune invalida"<<endl;
            break;
        }

        }
    }
}

void Management::regasire_ID(int ID)
{
    bool found=false;
    for(unsigned int i=0; i<clienti.size(); i++)
    {
        vector<Informatie*> info=clienti[i].get_informatii();
        if(info.empty())
        {
            cout<<"Clientul nu a oferit informatii"<<endl;
            return;
        }
        for(unsigned int j=0; j<info.size(); j++)
        {
            if(info[j]->getID()==ID)
            {
                found=true;
                cout<<"Pentru ID-ul "<<ID<<" a fost gasita informatia "<<info[j]<<" cu numele "<<info[j]->getNume()<<endl;
            }
        }
    }
    if(found==false)
    {
        cout<<"Nu a fost gasita nicio informatie cu ID-ul respectiv!"<<endl;
    }
}

void Management::regasire_nume(string nume)
{
    bool found=false;
    for(unsigned int i=0; i<clienti.size(); i++)
    {
        vector<Informatie*> info=clienti[i].get_informatii();
        if(info.empty())
        {
            cout<<"Clientul nu a oferit informatii"<<endl;
            return;
        }
        for(unsigned int j=0; j<info.size(); j++)
        {
            if(info[j]->getNume().compare(nume)==0)
            {
                found=true;
                cout<<"Pentru numele "<<nume<<" a fost gasita informatia "<<info[j]<<" cu ID-ul "<<info[j]->getID()<<endl;
            }
        }
    }
    if(found==false)
    {
        cout<<"Nu a fost gasita nicio informatie cu numele respectiv!"<<endl;
    }
}

void Management::stergere_nume(string nume)
{

    bool found=false;
    for(unsigned int i=0; i<clienti.size(); i++)
    {
        vector<Informatie*> info=clienti[i].get_informatii();
        if(info.empty())
        {
            cout<<"Clientul nu a oferit informatii"<<endl;
            return;
        }
        for(unsigned int j=0; j<info.size(); j++)
        {
            if(info[j]->getNume().compare(nume)==0)
            {
                found=true;
                info.erase(info.begin()+j);
            }
        }
    }
    if(found==false)
        cout<<"Nu a fost gasita nicio informatie cu numele respectiv!"<<endl;
}

void Management::stergere_ID(int ID)
{

    bool found=false;
    for(unsigned int i=0; i<clienti.size(); i++)
    {
        vector<Informatie*> info=clienti[i].get_informatii();
        if(info.empty())
        {
            cout<<"Clientul nu a oferit informatii"<<endl;
            return;
        }
        for(unsigned int j=0; j<info.size(); j++)
        {
            if(info[j]->getID()==ID)
            {
                found=true;
                info.erase(info.begin()+j);
            }
        }
    }
    if(found==false)
        cout<<"Nu a fost gasita nicio informatie cu numele respectiv!"<<endl;
}

void Management::cautare(int op)
{
    Management::meniu_cautare();
    switch(op)
    {
    case 1:
    {
        bool found=false;
        cout<<"Introduceti textul:"<<endl;
        string s;
        cin>>s;
        for(unsigned int i=0; i<clienti.size(); i++)
        {
            vector<Informatie*> info=clienti[i].get_informatii();
            for(unsigned int j=0; j<info.size(); j++)
            {
                if(typeid(info[j])==typeid(InfoText))
                {
                    InfoText *it=dynamic_cast<InfoText*>(info[j]);
                    if(s.compare(it->get_data())==0)
                    {
                        found=true;
                        cout<<"Informatie gasita!"<<endl;
                        cout<<"ID="<<it->getID()<<endl;
                        cout<<"Nume "<<it->getNume()<<endl;
                    }
                }
            }
        }
        if(found==false)
            cout<<"Informatia nu exista"<<endl;
        break;
    }
    case 2:
    {
        bool found=false;
        cout<<"Introduceti numar:"<<endl;
        unsigned int n;
        cin>>n;
        for(unsigned int i=0; i<clienti.size(); i++)
        {
            vector<Informatie*> info=clienti[i].get_informatii();
            for(unsigned int j=0; j<info.size(); j++)
            {
                if(typeid(info[j])==typeid(InfoNumar))
                {
                    InfoNumar *in=dynamic_cast<InfoNumar*>(info[j]);
                    if(in->get_nr()==n)
                    {
                        found=true;
                        cout<<"Informatie gasita!"<<endl;
                        cout<<"ID="<<in->getID()<<endl;
                        cout<<"Nume "<<in->getNume()<<endl;
                    }
                }
            }
        }
        if(found==false)
            cout<<"Informatia nu exista"<<endl;
        break;
    }
    case 3:
        {bool found=false;
        double x,y;
        cout<<"Introduceti partea reala:"<<endl;
        cin>>x;
        cout<<"Introduceti partea imaginara:"<<endl;
        cin>>y;
        complex<double> z(x,y);
        for(unsigned int i=0; i<clienti.size(); i++)
        {
            vector<Informatie*> info=clienti[i].get_informatii();
            for(unsigned int j=0; j<info.size(); j++)
            {
                if(typeid(info[j])==typeid(InfoMatematic))
                {
                    InfoMatematic *im=dynamic_cast<InfoMatematic*>(info[j]);
                    if(z==im->get_matematic())
                    {
                        found=true;
                        cout<<"Informatie gasita!"<<endl;
                        cout<<"ID="<<im->getID()<<endl;
                        cout<<"Nume "<<im->getNume()<<endl;
                    }
                }
            }
        }
        if(found==false)
            cout<<"Informatia nu exista"<<endl;
        break;}

    case 4:
    {
        bool found=false;
        cout<<"Introduceti adresa:"<<endl;
        string tara,judet,oras,strada;
        int nr;
        cin>>tara>>judet>>oras>>strada>>nr;
        tuple<string,string,string,string,int> adresa(tara,judet,oras,strada,nr);
        for(unsigned int i=0; i<clienti.size(); i++)
        {
            vector<Informatie*> info=clienti[i].get_informatii();
            for(unsigned int j=0; j<info.size(); j++)
            {
                if(typeid(info[j])==typeid(InfoAdresa))
                {
                    InfoAdresa *ia=dynamic_cast<InfoAdresa*>(info[j]);
                    if(adresa==ia->get_adresa())
                    {
                        found=true;
                        cout<<"Informatie gasita!"<<endl;
                        cout<<"ID="<<ia->getID()<<endl;
                        cout<<"Nume "<<ia->getNume()<<endl;
                    }
                }
            }
        }
        if(found==false)
            cout<<"Informatia nu exista"<<endl;
        break;
    }
    }

}
