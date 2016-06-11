#ifndef REEL_H
#define REEL_H

#include "litteraleCalculable.h"
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
    float getValue()const{return value;}
    inline QString toString() const;
    LitteraleCalculable& addition(const LitteraleCalculable &l) const;

};

inline QString Reel::toString() const {
    QString str;
    str.setNum(value);
    return str;
}

#endif // REEL_H
