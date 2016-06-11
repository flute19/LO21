#include "expression.h"


void Expression::eval() const {
    if (value.isEmpty())
        throw CalcException("Impossible d'évaluer une expression vide");
    else{

        // On sépare les éléments de l'expression en enlevant les espaces
        QStringList listeLitterales = value.split(" ");
        QStringList::iterator it;
        Pile *pile = new Pile();
        for (it=listeLitterales.begin();it!=listeLitterales.end();it++){
           Controleur *controleur = new Controleur(LitteraleManager::getInstance(),*pile);
           controleur->commande(QString(*it));
        }
    }
}


LitteraleCalculable& Expression::addition(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value+"+"+l.toString());
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Expression::diff(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value +"-"+ l.toString());
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Expression::mult(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value+"*"+l.toString());
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Expression::division(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value+"/"+l.toString());
    LitteraleCalculable& ref = *res;
    return ref;
}
