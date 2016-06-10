#ifndef CALC_H
#define CALC_H

#include "pile.h"

// class forward
class Pile;
class Controleur;

//class declaration
class QCalc : public QWidget{
Q_OBJECT
QLineEdit* message;
QTableWidget* vuePile;
QLineEdit* commande;
QVBoxLayout* couche;
Pile* pile;
Controleur* controleur;

//--------- Button creation -----------------

//--- digits 1-9 -----
QPushButton* un;
QPushButton* deux;
QPushButton* trois;
QPushButton* quatre;
QPushButton* cinq;
QPushButton* six;
QPushButton* sept;
QPushButton* huit;
QPushButton* neuf;

//--- numeric pad ----
QGridLayout* grille;
QPushButton* zero ;
QPushButton* point ;
QPushButton* dollar ;

QGridLayout* opCol;
QPushButton* add ;
QPushButton* diff ;
QPushButton* mult ;
QPushButton* quotient ;
QPushButton* entree ;

//--------- Interfaces creation--------------
QHBoxLayout* blockP;





public:
explicit QCalc(QWidget *parent = 0);
public slots:
void refresh();
void getNextCommande();
}; //end of declaration




#endif // CALC_H
