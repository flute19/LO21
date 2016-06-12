#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "litteraleCalculable.h"
#include "entier.h"
#include "reel.h"

class Reel;
class Entier;

class Rationnel:public NonComplexe{
 Entier* num;
 Entier* den;

public:
    //object management
    Rationnel(int n=0, int d=1);
    Rationnel(const Entier& n, const Entier& d);
    Rationnel(const LitteraleCalculable& n, const LitteraleCalculable& d);
    //~Rationnel(){delete(num); delete(den);}

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

#endif // RATIONNEL_H
