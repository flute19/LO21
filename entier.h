#ifndef ENTIER_H
#define ENTIER_H

#include "include.h"
#include "litteraleCalculable.h"


class Entier:public LitteraleCalculable
{
int value;
public:
    //object management
    Entier(int x=0):value(x){}
    int getValue()const{return value;}

    //object capacity
    Entier& operator + (const Entier& e);

};


#endif // ENTIER_H
