#ifndef AUXILIAIRE_H
#define AUXILIAIRE_H

#include "include.h"
#include "item.h"
//#include "litterale.h"
#include "litteraleCalculable.h"
#include "pile.h"
#include "structure.h"
#include "calc.h"
#include "entier.h"
#include "litteralemanager.h"
/* This file contains auxiliary objects such as Exception Manager.*/

//
class CalcException {
    QString info;
public:
    CalcException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};
#endif // AUXILIAIRE_H

class Controleur {
    LitteraleManager& expMng;
    Pile& expAff;
public:
    Controleur(LitteraleManager& m, Pile& v):expMng(m), expAff(v){}
    void commande(const QString& c);

};
