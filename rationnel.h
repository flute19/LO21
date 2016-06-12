#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "litteraleCalculable.h"
#include "entier.h"
#include "reel.h"

class Reel;
class Entier;

class Rationnel:public LitteraleCalculable{
 Entier* num;
 Entier* den;

public:
    //object management
    Rationnel(int n=0, int d=1);
    Rationnel(const Entier& n, const Entier& d);
    Rationnel(const LitteraleCalculable& n, const LitteraleCalculable& d);

    //data
    const Entier& getNum()const{return *num;}
    const Entier& getDen()const{return *den;}
    QString toString() const;

    //operations binaires
    LitteraleCalculable& addition(const LitteraleCalculable &l) const;
    LitteraleCalculable& diff(const LitteraleCalculable &l) const;
    LitteraleCalculable& mult(const LitteraleCalculable &l) const;
    LitteraleCalculable& quotient(const LitteraleCalculable &l) const;

    //operations unaires
    LitteraleCalculable& oppose() const;

};

//inline QString Rationnel::toString() const {
//    //const Entier* n = Entier(num->getValue());
//    QString str = number();
//   //const Entier* pt = &n;


//    //const int nu =pt->getValue();

//   //const QString str = pt->toString();
//    str.append("/");
////    str.append(den->toString());
//    return str;
//}

#endif // RATIONNEL_H
