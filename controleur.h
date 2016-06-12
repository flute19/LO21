#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "include.h"
#include "litteralemanager.h"
#include "pile.h"
#include "expression.h"

//------- Class Forward ------------
class LitteraleManager;
class Pile;

//------- Controler declaration ----
class Controleur {
    friend class QCalc;
    LitteraleManager& litMng;
    Pile& litAff;
public:
    Controleur(LitteraleManager& m, Pile& v):litMng(m), litAff(v){}
    void commande(const QString& c);

};

#endif // CONTROLEUR_H
