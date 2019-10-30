#include "Lista_circulara.h"

Lista_circulara::Lista_circulara()
{
    prim=NULL;
    lungime=0;
}

void Lista_circulara::afisare()
{
    Nod *p=new Nod;
    p=prim;
    if(p==NULL)
        cout<<"Lista este vida"<<endl;
    else
    {
        do
        {
            cout<<p->info<<" ";
            p=p->next;
        }
        while(p!=prim);
        cout<<endl;
    }
}

void Lista_circulara::adaugare_prim_element(int nr)
{

    prim=new Nod(nr);
    prim->next=prim;
    lungime++;

}

void Lista_circulara::adaugare_sfarsit(int nr)
{
    if(prim==NULL)
        adaugare_prim_element(nr);
    else
    {
        Nod *temp=new Nod(nr);
        Nod *p=prim;
        while(p->next!=prim)
            p=p->next;
        temp->next=prim;
        p->next=temp;
    }
    lungime++;

}

void Lista_circulara::adaugare_pozitie(int poz,int x)
{
    if(prim==NULL&&poz==1)
    {
        adaugare_prim_element(x);
    }
    else if(poz>lungime+1)
        cout<<"Pozitia depaseste lungimea listei"<<endl;
    else if(poz==lungime)
        adaugare_sfarsit(x);

    else
    {
        Nod* temp=new Nod(x);
        Nod *p=prim;
        for(int i=1; i<=poz-2; i++)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
        lungime++;

    }
}

void Lista_circulara::inversare()
{
    Nod *curent=prim,*anterior=NULL,*urmator;
    if(prim==NULL)
        return;
    do
    {
        urmator=curent->next;
        curent->next=anterior;
        anterior=curent;
        curent=urmator;
    }
    while(curent!=prim);
    prim->next=anterior;
    prim=anterior;
}

void Lista_circulara::stergere_k(int k)
{
    Nod *curent=prim;
    Nod *anterior=prim;
    int nr_pasi=1;
    if(prim==NULL)
        return;
    if(k==1)
    {
        while(prim!=NULL)
            stergere_pozitie(1);
    }
    while(nr_pasi!=k)
    {
        if(lungime==1)
        {
            cout<<"A fost sters elementul "<<anterior->info<<endl;
            prim=NULL;
            break;
        }
        anterior=curent;
        curent=curent->next;
        nr_pasi++;
        if(nr_pasi==k)
        {
            anterior->next=curent->next;
            cout<<"A fost sters elementul "<<curent->info<<endl;
            delete curent;
            curent=anterior->next;
            anterior=anterior->next;
            nr_pasi=1;
            lungime--;

        }


    }

}

void Lista_circulara::stergere_lista()
{
    if(prim==NULL)
    {
        cout<<"Lista este deja vida"<<endl;
        return;
    }
    while(prim!=NULL)
    {
        stergere_pozitie(1);
    }
    prim=NULL;
}

istream& operator>>(istream &in, Lista_circulara &l)
{
    int nr,val;
    cout<<"Introduceti numarul de elemente:"<<endl;
    in>>nr;
    cout<<"Introduceti elementele:"<<endl;
    for(int i=1; i<=nr; i++)
    {
        in>>val;
        l.adaugare_pozitie(i,val);
    }
    return in;
}

void Lista_circulara::stergere_pozitie(int poz)
{
    if(prim==NULL)
    {
        cout<<"Lista este vida"<<endl;
        return;
    }
    if(poz>lungime)
    {
        cout<<"Pozitia depaseste lungimea listei"<<endl;
        return;
    }
    if(poz==1)
    {
        if(lungime==1)
        {
            cout<<"A fost sters primul element: "<<prim->info<<endl;
            prim=NULL;
        }
        else
        {

            Nod *p=prim,*q=prim;
            while(q->next!=prim)
                q=q->next;
            q->next=q->next->next;
            prim=prim->next;
            cout<<"A fost sters primul element: "<<p->info<<endl;
            delete p;
            lungime--;
        }

    }
    else
    {
        Nod *p=prim;
        for(int i=1; i<=poz-2; i++)
            p=p->next;
        cout<<"A fost sters al "<<poz<<"-lea element: "<<p->next->info<<endl;
        p->next=p->next->next;
        p=p->next;
        delete p;
        lungime--;
    }
}

ostream& operator<<(ostream &out,Lista_circulara &l)
{
    l.afisare();
    return out;
}

Lista_circulara& Lista_circulara::operator=(const Lista_circulara &lista)
{
    if(this==&lista||lista.prim==NULL)
        return *this;
    this->stergere_lista();
    adaugare_prim_element(lista.prim->info);
    Nod *p=lista.prim->next;
    while(p!=lista.prim)
    {
        adaugare_sfarsit(p->info);
        p=p->next;
    }
    return *this;

}

Lista_circulara Lista_circulara::operator+(const Lista_circulara &lista)
{
     Lista_circulara rez;
    if(this->prim==NULL)
        return lista;
    if(lista.prim==NULL)
        return *this;
    Nod *temp=this->prim;
    rez.adaugare_prim_element(temp->info);
    temp=temp->next;
    while(temp!=this->prim)
    {
        rez.adaugare_sfarsit(temp->info);
        temp=temp->next;
    }
    rez.adaugare_sfarsit(lista.prim->info);
    temp=lista.prim->next;
    while(temp!=lista.prim)
    {
        rez.adaugare_sfarsit(temp->info);
        temp=temp->next;
    }
    return rez;

}





