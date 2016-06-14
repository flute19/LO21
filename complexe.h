#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "entier.h"

class Complexe: public LitteraleCalculable{
    NonComplexe* re;
    NonComplexe* im;

public:
    //object management
    Complexe(const NonComplexe& l1, const NonComplexe& l2);
    ~Complexe(){}

    //data
    const NonComplexe& getRe()const{return *re;}
    const NonComplexe& getIm()const{return *im;}

    QString toString() const;

    //operations binaires
    LitteraleCalculable& addition(const LitteraleCalculable &l) const;
    LitteraleCalculable& diff(const LitteraleCalculable &l) const;
    LitteraleCalculable& mult(const LitteraleCalculable &l) const;
    LitteraleCalculable& quotient(const LitteraleCalculable &l) const;

    //operations unaires
    LitteraleCalculable& oppose() const;
    const LitteraleCalculable& partieReel() const;
    const LitteraleCalculable& partieIm() const;
};
#endif // COMPLEXE_H
