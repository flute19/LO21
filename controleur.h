#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <QString>

#include "litteralemanager.h"
#include "pile.h"
#include "expression.h"
#include "atomemanager.h"
#include "programme.h"

//------- Class Forward ------------
class AtomeManager;
class LitteraleManager;
class Pile;

//------- Controler declaration ----
class Controleur {
    friend class QCalc;
    LitteraleManager& litMng;
    AtomeManager& atMng;
    Pile& litAff;
public:
    Controleur(LitteraleManager& m, Pile& v, AtomeManager& a):litMng(m), litAff(v), atMng(a){}
    void commande(const QString& c);

};

#endif // CONTROLEUR_H
