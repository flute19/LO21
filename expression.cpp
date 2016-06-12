#include "expression.h"


void Expression::eval() const {
    if (value.isEmpty())
        throw CalcException("Impossible d'évaluer une expression vide");
    else{

        // On sépare les éléments de l'expression en enlevant les espaces
        /*QStringList listeLitterales = value.split(" ");
        QStringList::iterator it;
        Pile *pile = new Pile();
        for (it=listeLitterales.begin();it!=listeLitterales.end();it++){
           Controleur *controleur = new Controleur(LitteraleManager::getInstance(),*pile);
           controleur->commande(QString(*it));*/

        QString exp=value;
        exp.remove(QChar(' '));
        exp[0]='(';
        exp[exp.size()]=')';
        QString::Iterator it;
        Pile* pile = new Pile();
        LitteraleManager& litMng= LitteraleManager::getInstance();
        for (it=exp.begin();it!=exp.end();it++){
            if(estUnNombre(*it) || estUnOperateur(*it)){
                if (estUnNombre(*it)){
                    QString nb=*it;
                    while (estUnNombre(*(++it))){
                        nb+=*it;
                    }
                    pile->push(litMng.addLitterale(nb));
                }
                else {
                    pile->push(litMng.addLitterale(*it));
                }
            }
            else{
                if(*it!='(' || *it!=')'){
                    delete pile;
                    throw CalcException("Expression non conforme au format");
                }
                else
                    if(*it==')'){

                    }
            }
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

LitteraleCalculable& Expression::quotient(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value + " " + l.toString() + " /");

    LitteraleCalculable& ref = *res;
    return ref;
}

//------------- Operateur unaires ----------
LitteraleCalculable& Expression::oppose() const{
    QString s = "-("+value;
    s.append(")");

    Expression* res = new Expression(s);
    LitteraleCalculable& ref = *res;
    return ref;
}
