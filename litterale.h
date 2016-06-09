#ifndef LITTERALE_H
#define LITTERALE_H

#include "include.h"


//superclass of object identical to Item but not destroyed when pile is.
class Litterale{
public:
    void affiche();
    Litterale(){}
    ~Litterale(){}
    virtual QString toString() const=0;
};



#endif // LITTERALE_H
