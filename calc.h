#ifndef CALC_H
#define CALC_H

#include "include.h"

class QCalc : public QWidget{
Q_OBJECT
QLineEdit* message;
QTableWidget* vuePile;
QLineEdit* commande;
QVBoxLayout* couche;
Pile* pile;
Controleur* controleur;

public:
explicit QComputer(QWidget *parent = 0);
public slots:
void refresh();
void getNextCommande();
};

#endif // CALC_H
