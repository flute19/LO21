#ifndef ENTIER_H
#define ENTIER_H


#include "litteraleCalculable.h"
#include "rationnel.h"
#include "reel.h"
#include "expression.h"

class Rationnel;
class Reel;
class Expression;



class Entier:public NonComplexe {
int value;
public:
    friend class Rationnel;

    //object management
    Entier(int x=0):value(x){}

    //data
    int getValue()const{return value;}
    QString toString()const;

    //operations binaires
    LitteraleCalculable& addition(const LitteraleCalculable &l) const;
    LitteraleCalculable& diff(const LitteraleCalculable &l) const;
    LitteraleCalculable& mult(const LitteraleCalculable &l) const;
    LitteraleCalculable& quotient(const LitteraleCalculable &l) const;

    Entier& div(const Entier& e);
    Entier& mod(const Entier& e);


    //opérations unaires
    LitteraleCalculable& oppose()const;
   const LitteraleCalculable& partieReel() const;
   const LitteraleCalculable& partieIm()const;

};

int simplifier(Entier a, Entier b);

#endif // ENTIER_H
