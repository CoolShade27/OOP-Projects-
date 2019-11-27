#include "Client.h"

Client::Client() {}

void Client::getInfoText(string text,string nume)
{
    Informatie *inf=new InfoText(text,nume);
    if(informatii.empty())
    {
        informatii.push_back(inf);
        cout<<"Informatie adaugata!"<<endl;
        cout<<"ID="<<inf->getID();
        return;
    }
    else
    {
        for(unsigned int i=0; i<informatii.size(); i++)
        {
            if(typeid(informatii[i])==typeid(InfoText))
            {
                InfoText *it=dynamic_cast<InfoText*>(informatii[i]);
                string aux=it->get_data();
                aux.append(text);
                it->set_data(aux);
            }
            else
            {
                informatii.push_back(inf);
                cout<<"Informatie adaugata!"<<endl;
                cout<<"ID="<<inf->getID();
            }
        }
    }
}

void Client::getInfoMatematic(complex<double> c,string nume)
{
    Informatie *inf=new InfoMatematic(c,nume);
    if(informatii.empty())
    {
        informatii.push_back(inf);
        cout<<"Informatie adaugata!"<<endl;
        cout<<"ID="<<inf->getID();
        return;
    }
    else
    {
        for(unsigned int i=0; i<informatii.size(); i++)
        {
            if(typeid(informatii[i])==typeid(InfoMatematic))
            {
                InfoMatematic *im=dynamic_cast<InfoMatematic*>(informatii[i]);
                complex<double> aux=im->get_matematic();
                aux=aux+c;
                im->set_matematic(aux);
            }
            else
            {
                informatii.push_back(inf);
                cout<<"Informatie adaugata!"<<endl;
                cout<<"ID="<<inf->getID();
            }
        }
    }
}

void Client::getInfoAdresa(tuple<string,string,string,string,int> adr,string nume)
{
    Informatie *inf=new InfoAdresa(adr,nume);
    if(informatii.empty())
    {
        informatii.push_back(inf);
        cout<<"Informatie adaugata!"<<endl;
        cout<<"ID="<<inf->getID();
        return;
    }
    else
    {
        for(int i=0; i<informatii.size(); i++)
        {
            if(typeid(informatii[i])==typeid(InfoAdresa))
            {
                cout<<"Eroare! Adresa deja introdusa!"<<endl;
            }
            else
            {
                informatii.push_back(inf);
                cout<<"Informatie adaugata!"<<endl;
                cout<<"ID="<<inf->getID();
            }
        }
    }
}

void Client::getInfoNumar(unsigned int numar,string nume)
{
    Informatie *inf=new InfoNumar(numar,nume);
    if(informatii.empty())
    {
        informatii.push_back(inf);
        cout<<"Informatie adaugata!"<<endl;
        cout<<"ID="<<inf->getID()<<endl;
        return;
    }
    else
    {
        for(unsigned int i=0; i<informatii.size(); i++)
        {
            if(typeid(informatii[i])==typeid(InfoNumar))
            {
                InfoNumar *im=dynamic_cast<InfoNumar*>(informatii[i]);
                unsigned int aux=im->get_nr();
                aux=aux+numar;
                im->set_nr(aux);
                break;
            }
            else
            {
                informatii.push_back(inf);
                cout<<"Informatie adaugata!"<<endl;
                cout<<"ID="<<inf->getID();
                break;
            }
        }
    }
}

vector<Informatie*> Client::get_informatii()
{
    return informatii;
}
