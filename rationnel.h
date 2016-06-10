#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "litteraleCalculable.h"
#include "entier.h"

class Entier;

class Rationnel:public LitteraleCalculable{
const Entier* num;
const Entier* den;
public:
    //object management
    Rationnel(int n, int d);
    Rationnel(const Entier& n, const Entier& d);
    Rationnel(const LitteraleCalculable& n, const LitteraleCalculable& d);
    const Entier& getNum()const{return *num;}
    const Entier& getDen()const{return *den;}
    inline QString toString() const;
    LitteraleCalculable& addition(const LitteraleCalculable &l) const;
    void simplifier();

};

inline QString Rationnel::toString() const {
    QString strnum,strden;
    //strnum.setNum(num->getValue());
    //strden.setNum(den->getValue());
    return QString(strnum+"/"+strden);
}

#endif // RATIONNEL_H
