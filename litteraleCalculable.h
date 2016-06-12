#ifndef LITTERALECALCULABLE_H
#define LITTERALECALCULABLE_H

#include <QString>
#include "litterale.h"


//superclass of Litteral object you can use in arithmetic.
class LitteraleCalculable: public Litterale{
public:
    LitteraleCalculable() {}

    //operations binaires
    inline LitteraleCalculable & operator+(const LitteraleCalculable& l);
    virtual LitteraleCalculable& addition(const LitteraleCalculable& l) const =0;

    inline LitteraleCalculable & operator-(const LitteraleCalculable& l);
    virtual LitteraleCalculable& diff(const LitteraleCalculable& l) const =0;

    inline LitteraleCalculable & operator*(const LitteraleCalculable& l);
    virtual LitteraleCalculable& mult(const LitteraleCalculable& l) const =0;

    inline LitteraleCalculable & operator/(const LitteraleCalculable& l);
    virtual LitteraleCalculable& quotient(const LitteraleCalculable& l) const =0;

    //operations unaires
    inline LitteraleCalculable& neg();
    virtual LitteraleCalculable& oppose()const =0;

    //data
    virtual QString toString() const=0;

};

inline LitteraleCalculable & LitteraleCalculable::operator+(const LitteraleCalculable& l){return this->addition(l);}
inline LitteraleCalculable & LitteraleCalculable::operator-(const LitteraleCalculable& l){return this->diff(l);}
inline LitteraleCalculable & LitteraleCalculable::operator*(const LitteraleCalculable& l){return this->mult(l);}
inline LitteraleCalculable & LitteraleCalculable::operator/(const LitteraleCalculable& l){return this->quotient(l);}

inline LitteraleCalculable & LitteraleCalculable::neg(){
    LitteraleCalculable& opp = this->oppose();
    return opp;
}

class NonComplexe: public LitteraleCalculable{

};



#endif // LITTERALECALCULABLE_H
