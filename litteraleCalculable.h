#ifndef LITTERALECALCULABLE_H
#define LITTERALECALCULABLE_H

#include "include.h"

//superclass of Litteral object you can use in arithmetic.
class LitteraleCalculable: public Litterale{
public:
    virtual LitteraleCalculable& operator+ (LitteraleCalculable & l) =0;
};


#endif // LITTERALECALCULABLE_H
