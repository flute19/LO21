#ifndef ITEM_H
#define ITEM_H

#include "include.h"
#include "litteralemanager.h"

class Litterale;

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
