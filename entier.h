#ifndef ENTIER_H
#define ENTIER_H


#include "litteraleCalculable.h"
#include "rationnel.h"
#include "reel.h"

class Rationnel;
class Reel;


class Entier:public LitteraleCalculable {
int value;
public:
    //object management
    Entier(int x=0):value(x){}

    //data
    int getValue()const{return value;}
    inline QString toString() const;

    //operations
    LitteraleCalculable& addition(const LitteraleCalculable &l) const;
    LitteraleCalculable& diff(const LitteraleCalculable &l) const;

};

inline QString Entier::toString() const {
    QString str;
    str.setNum(value);
    return str;
}

#endif // ENTIER_H
