#ifndef ITEM_H
#define ITEM_H

#include "include.h"
//#include "litterale.h"
#include "litteraleCalculable.h"
#include "pile.h"
#include "structure.h"
#include "calc.h"
#include "entier.h"
#include "litteralemanager.h"

//superclass of object on stack (interface with stack).
class Item {
    Litterale* exp;
public:
    //management
    Item():exp(nullptr){}
    void raz() { exp=0; }//set exp to 0#include "include.h"

    //data
    Litterale& getLitterale() const;
    void setLitterale(Litterale& e) { exp=&e; }//redefined exp value
};

#endif // ITEM_H
