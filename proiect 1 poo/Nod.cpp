#include "Nod.h"

Nod::Nod()
{
    info=0;
}

Nod::Nod(int val)
{
    info=val;
}

Nod::~Nod()
{

}

Nod::Nod(const Nod& ob)
{
    this->info=ob.info;
    this->next=ob.next;
}
