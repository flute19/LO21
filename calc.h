#ifndef CALC_H
#define CALC_H

#include "pile.h"

// class forward
class Pile;
class Controleur;

extern Pile* pile;
//class declaration
class QCalc : public QWidget{
Q_OBJECT
QLineEdit* message;
QTableWidget* vuePile;
QLineEdit* commande;
QVBoxLayout* couche;
Pile* pile;
Controleur* controleur;
//Simplificator* spl;

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
QPushButton* raz;
QPushButton* entree ;

//--------- Interfaces creation--------------
QHBoxLayout* blockP;





public:
explicit QCalc(QWidget *parent = 0);
public slots:
void refresh();
void getNextCommande();

public slots :

//Digits
void affZero(){commande->insert("0");}
void affUn(){commande->insert("1");}
void affDeux(){commande->insert("2");}
void affTrois(){commande->insert("3");}
void affQuatre(){commande->insert("4");}
void affCinq(){commande->insert("5");}
void affSix(){commande->insert("6");}
void affSept(){commande->insert("7");}
void affHuit(){commande->insert("8");}
void affNeuf(){commande->insert("9");}

void affPoint(){commande->insert(".");}
void affDollar(){commande->insert("$");}
void affPlus(){commande->insert("+");}
void affMoins(){commande->insert("-");}
void affEtoile(){commande->insert("*");}
void affDiviser(){commande->insert("/");}
void enter(){commande->returnPressed();}
void remiseazero();

}; //end of declaration


#endif // CALC_H
