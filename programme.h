#ifndef PROGRAMME_H
#define PROGRAMME_H


#include <QTextStream>
#include <QString>
#include <QStack>
#include <QChar>

#include "litteraleCalculable.h"
#include "controleur.h"
#include "calc.h"

class Pile;
class Controleur;

class Programme : public Litterale{
    QString value;
public :
    Programme(const QString& s = "") : value(s){}
    ~Programme(){}
    inline QString toString() const{return value;}
    //operation unaire
    QStringList eval() const;

    //data
};



#endif // PROGRAMME_H
