#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QTextStream>
#include <QString>
#include <QStack>
#include <QChar>

#include "litteraleCalculable.h"
#include "controleur.h"
#include "calc.h"

class Pile;
class Controleur;

class Expression : public LitteraleCalculable{
    QString value;
public :
    Expression(const QString& s = "") : value(s){}
    QString getValue()const{return value;}

    //operation binaire
    LitteraleCalculable& addition(const LitteraleCalculable& l)const;
    LitteraleCalculable& diff(const LitteraleCalculable& l)const;
    LitteraleCalculable& mult(const LitteraleCalculable& l)const;
    LitteraleCalculable& quotient(const LitteraleCalculable& l)const;

    //operation unaire
    LitteraleCalculable& oppose() const;
    QString eval() const;

    //data
    inline QString toString() const{return value;}
};

QString InfixToPostfix(QString exp);
int HasHigherPrecedence(QChar op1, QChar op2);
int GetOperatorWeight(QChar op);




#endif // EXPRESSION_H
