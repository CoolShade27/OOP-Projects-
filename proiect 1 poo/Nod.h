#ifndef NOD_H
#define NOD_H


class Nod
{
    int info;
    Nod *next;
public:
    Nod();
    Nod(int val);
    Nod(const Nod &);
    ~Nod();
    friend class Lista_circulara;
};

#endif // NOD_H
