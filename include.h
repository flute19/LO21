#ifndef INCLUDE_H
#define INCLUDE_H

/* This file contains all other files references.
 * Make sure it is included in all other file.*/

#include <QString>
#include <QApplication>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QHeaderView>
#include <iostream>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include <QPushButton>
#include <QGridLayout>

using namespace std;


// auxiliary functions' prototypes
bool estUnOperateur(const QString s);
bool estUnNombre(const QString s);

#endif // INCLUDE_H
