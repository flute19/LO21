#ifndef CALC_H
#define CALC_H

#include "include.h"
#include "pile.h"

class Pile;
class Controleur;

class QCalc : public QWidget{
Q_OBJECT
QLineEdit* message;
QTableWidget* vuePile;
QLineEdit* commande;
QVBoxLayout* couche;
Pile* pile;
Controleur* controleur;

public:
explicit QCalc(QWidget *parent = 0);
public slots:
void refresh();
void getNextCommande();
};

#endif // CALC_H
