#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "litteraleCalculable.h"
#include "entier.h"
#include "reel.h"

class Reel;
class Entier;

class Rationnel:public LitteraleCalculable{
const Entier* num;
const Entier* den;
public:
    //object management
    Rationnel(int n=0, int d=1);
    Rationnel(const Entier& n, const Entier& d);
    Rationnel(const LitteraleCalculable& n, const LitteraleCalculable& d);

    //data
    const Entier& getNum()const{return *num;}
    const Entier& getDen()const{return *den;}
    inline QString toString() const;

    //operations
    LitteraleCalculable& addition(const LitteraleCalculable &l) const;
    LitteraleCalculable& diff(const LitteraleCalculable &l) const;
    LitteraleCalculable& mult(const LitteraleCalculable &l) const;
    LitteraleCalculable& quotient(const LitteraleCalculable &l) const;

    void simplifier();

};

inline QString Rationnel::toString() const {
    QString strnum,strden;
    //strnum.setNum(num->getValue());
    //strden.setNum(den->getValue());
    return QString(strnum+"/"+strden);
}

#endif // RATIONNEL_H
