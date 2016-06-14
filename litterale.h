#ifndef LITTERALE_H
#define LITTERALE_H

#include "include.h"
#include "calcexception.h"


//superclass of object identical to Item but not destroyed when pile is.
class Litterale{
public:
    void affiche();
    Litterale(){}
    virtual ~Litterale(){}
    virtual QString toString() const=0;
};



#endif // LITTERALE_H
