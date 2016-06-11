#include "expression.h"
#include "litteralemanager.h"

void Expression::eval() const {
    if (value.isEmpty())
        throw CalcException("Impossible d'évaluer une expression vide");
    else{
        QTextStream cout(stdout, QIODevice::WriteOnly);
        LitteraleManager& litman = LitteraleManager::getInstance();

        QString litterale("");

        // On sépare les éléments de l'expression en enlevant les espaces
        QStringList listeLitterales = value.split(" ");
        QStringList::iterator it;

        for (it=listeLitterales.begin();it!=listeLitterales.end();it++){
        }
    }
}


LitteraleCalculable& Expression::addition(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value + " " + l.toString() + " +");
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Expression::diff(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value + " " + l.toString() + " -");
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Expression::mult(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value + " " + l.toString() + " *");
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Expression::quotient(const LitteraleCalculable& l)const{
    Expression* res = new Expression(value + " " + l.toString() + " /");
    LitteraleCalculable& ref = *res;
    return ref;
}
