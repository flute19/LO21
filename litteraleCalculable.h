#ifndef LITTERALECALCULABLE_H
#define LITTERALECALCULABLE_H

#include <QString>
#include "litterale.h"


//superclass of Litteral object you can use in arithmetic.
class LitteraleCalculable: public Litterale{
public:
    LitteraleCalculable(){}
    inline LitteraleCalculable & operator+(const LitteraleCalculable& l);
    virtual LitteraleCalculable& addition(const LitteraleCalculable& l) const =0;
    virtual QString toString() const=0;
};

inline LitteraleCalculable & LitteraleCalculable::operator+(const LitteraleCalculable& l){return this->addition(l);}



#endif // LITTERALECALCULABLE_H
