#ifndef ATOME_H
#define ATOME_H

#include<QString>
#include "litterale.h"
#include "litteralemanager.h"

class Litterale;

class Atome : public Litterale {
    QString id;
    Litterale* value;
public:
    Atome(QString i="",Litterale* v=nullptr):id(i),value(v){}
    ~Atome(){}
    QString getId() const{return id;}
    Litterale* getValue() const{return value;}
    inline QString toString() const;
    void setValue(Litterale* l){value=l;}
};
inline QString Atome::toString() const{
    return "value->toString()";
}

#endif // ATOME_H
