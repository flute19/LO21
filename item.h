#ifndef ITEM_H
#define ITEM_H

#include "litterale.h"
#include "include.h"
#include "calcexception.h"

class Litterale;

//superclass of object on stack (interface with stack).
class Item {
    Litterale* lit;
public:
    //management
    Item():lit(nullptr){}
    void raz() { lit=0; }//set lit to 0#include "include.h"

    //data
    Litterale& getLitterale() const;
    void setLitterale(Litterale& e) {lit = &e; }//redefined lit value
};

#endif // ITEM_H
