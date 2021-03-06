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
    Controleur(LitteraleManager& m, Pile& v, AtomeManager& a):litMng(m), atMng(a),litAff(v){}
    void commande(const QString& c);

};

//bool checkDiv(const LitteraleCalculable& val2); would be used to check no division by 0 but doesn't work.
bool estUnOperateur(const QString s);
int estUnNombre(const QString s);
int getArite(QString c);


#endif // CONTROLEUR_H
