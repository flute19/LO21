#ifndef LITTERALECALCULABLE_H
#define LITTERALECALCULABLE_H

#include "include.h"
#include "item.h"
//#include "litterale.h"
#include "litteraleCalculable.h"
#include "pile.h"
#include "structure.h"
#include "calc.h"
#include "entier.h"
#include "litteralemanager.h"

//superclass of Litteral object you can use in arithmetic.
class LitteraleCalculable: public Litterale{
public:
    virtual LitteraleCalculable& operator+ (LitteraleCalculable & l) =0;
};


#endif // LITTERALECALCULABLE_H
