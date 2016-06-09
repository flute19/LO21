#ifndef CALCEXCEPTION_H
#define CALCEXCEPTION_H

#include "include.h"

/* This file contains auxiliary objects such as Exception Manager.*/

//
class CalcException {
    QString info;
public:
    CalcException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};

#endif // CALCEXCEPTION_H
