#ifndef ATOME_H
#define ATOME_H

#include<QString>
#include "litterale.h"

class Atome : public Litterale{
    QString id;
    Litterale* value;
public:
    Atome(QString i="",Litterale* v=nullptr):id(i),value(v){}
    QString getId() const{return id;}
    Litterale* getValue() const{return value;}
    QString toString(){return value->toString();}
    void setValue(Litterale* l){value=l;}
};

#endif // ATOME_H
