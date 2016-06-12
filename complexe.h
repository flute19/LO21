#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "entier.h"

class Complexe{
    NonComplexe* re;
    NonComplexe* im;

public:
    //object management
    Complexe(const NonComplexe& l1, const NonComplexe& l2);

    //data
    const NonComplexe& getRe()const{return *re;}
    const NonComplexe& getIm()const{return *im;}

    QString toString() const;

};
#endif // COMPLEXE_H
