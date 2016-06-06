#ifndef LITERALLE_H
#define LITERALLE_H

#include "include.h"
#include "item.h"
#include "litteraleCalculable.h"
#include "pile.h"
#include "structure.h"
#include "calc.h"
#include "entier.h"
#include "litteralemanager.h"

//superclass of object identical to Item but not destroyed when pile is.
class Litterale{
public:
    void affiche();
    Litterale(){}
    virtual ~Litterale();
};



#endif // LITERALLE_H
