#ifndef REEL_H
#define REEL_H


#include "rationnel.h"
#include "entier.h"

class Entier;
class Rationnel;


class Reel:public LitteraleCalculable
{
float value;
public:
    //object management
    Reel(float x =0.0): value(x){}

    //data
    float getValue()const{return value;}
    inline QString toString() const;

    //operations binaires
    LitteraleCalculable& addition(const LitteraleCalculable &l) const;
    LitteraleCalculable& diff(const LitteraleCalculable &l) const;
    LitteraleCalculable& mult(const LitteraleCalculable &l) const;
    LitteraleCalculable& quotient(const LitteraleCalculable &l) const;

    //operations unaires
    //LitteraleCalculable& oppose() const;

};

inline QString Reel::toString() const {
    QString str;
    str.setNum(value);
    return str;
}

#endif // REEL_H
