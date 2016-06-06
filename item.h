#ifndef ITEM_H
#define ITEM_H
//superclass of object on stack (interface with stack).
class Item {
    Litterale* exp;
public:
    //management
    Item():exp(nullptr){}
    void raz() { exp=0; }//set exp to 0

    //data
    Litterale& getLitterale() const;
    void setLitterale(Litterale& e) { exp=&e; }//redefined exp value
};

#endif // ITEM_H
