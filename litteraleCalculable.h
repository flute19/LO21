    #ifndef LITTERALECALCULABLE_H
#define LITTERALECALCULABLE_H

#include "include.h"
#include "litteralemanager.h"

//superclass of Litteral object you can use in arithmetic.
template <class T>
class LitteraleCalculable: public Litterale{
public:
    virtual T& operator+ (T& l) =0;
};


#endif // LITTERALECALCULABLE_H
