#ifndef LITERALLE_H
#define LITERALLE_H

#include "include.h"

//superclass of object identical to Item but not destroyed when pile is.
class Litterale{
public:
    void affiche();
    virtual Litteralle()=0;
    ~virtual Litteralle()=0;
};



#endif // LITERALLE_H
