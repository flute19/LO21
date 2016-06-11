#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QTextStream>
#include <QString>

#include "litteraleCalculable.h"

class Expression : LitteraleCalculable{
    QString value;
public :
    Expression(const QString& s = "") : value(s){}
    void eval() const;
    LitteraleCalculable& addition(const LitteraleCalculable& l)const;
    LitteraleCalculable& diff(const LitteraleCalculable& l)const;
    LitteraleCalculable& mult(const LitteraleCalculable& l)const;
    LitteraleCalculable& quotient(const LitteraleCalculable& l)const;
    inline QString toString() const{return value;}
};





#endif // EXPRESSION_H
