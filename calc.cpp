#include "include.h"
#include <algorithm>
#include "calc.h"
#include "litteralemanager.h"

LitteraleManager::Handler LitteraleManager::handler=LitteraleManager::Handler();

QCalc::QCalc(QWidget* parent):QWidget (parent)
{
    pile=new Pile();

    //-------- Object instanciation -------------

    message= new QLineEdit(this) ;
    vuePile= new QTableWidget(pile->getNbItemsToAffiche(),1,this);
    commande= new QLineEdit(this);
    couche= new QVBoxLayout(this);

    //---- Digits -------
    un = new QPushButton("1",this);
    deux = new QPushButton("2",this);
    trois = new QPushButton("3",this);
    quatre = new QPushButton("4",this);
    cinq = new QPushButton("5",this);
    six = new QPushButton("6",this);
    sept = new QPushButton("7",this);
    huit = new QPushButton("8",this);
    neuf = new QPushButton("9",this);

    zero = new QPushButton("0",this);
    point = new QPushButton(".", this);
    dollar = new QPushButton("$", this);

    grille = new QGridLayout(this); //struc to place them


    //---- Operators ----

    add = new QPushButton("+",this) ;
    diff = new QPushButton("-",this);
    mult = new QPushButton("*",this);
    quotient = new QPushButton("/",this) ;
    entree = new QPushButton("go",this);

    opCol = new QGridLayout(this); //struc to place them

    //---- Interfaces ----
    blockP = new QHBoxLayout(this);


    //--------- Object Display -------------------
    //--- Pad---
    grille->addWidget(un,3,0);
    grille->addWidget(deux,3,1);
    grille->addWidget(trois,3,2);

    grille->addWidget(quatre,2,0);
    grille->addWidget(cinq,2,1);
    grille->addWidget(six,2,2);

    grille->addWidget(sept,1,0);
    grille->addWidget(huit,1,1);
    grille->addWidget(neuf,1,2);

    grille->addWidget(zero,0,2);
    grille->addWidget(point,0,2);
    grille->addWidget(dollar,0,2);

    grille->setVerticalSpacing(0.5);
    grille->setHorizontalSpacing(0.5);


    //--- Extra Pad
    opCol->addWidget(entree);
    opCol->addWidget(add);
    opCol->addWidget(diff);
    opCol->addWidget(mult);
    opCol->addWidget(quotient);

    //--- main block
    blockP->addLayout(grille);
    blockP->addLayout(opCol);

    couche->addWidget(message);
    couche->addWidget(vuePile);
    couche->addWidget(commande);
    couche->addLayout(blockP);
    setLayout(couche);

    pile= new Pile();
    controleur = new Controleur(LitteraleManager::getInstance(), *pile);
    setWindowTitle("UTCalc");

   //can't rewrite windows message
    message->setReadOnly(true);//can't
    message->setText("coucou");//specify message to print
    message->setStyleSheet("background: grey;color:white"); //have fun

    vuePile->horizontalHeader()->setVisible(false);
    QStringList nombres;

    for(unsigned int i = pile->getNbItemsToAffiche(); i>0; i--)
    {
        QString str=QString::number(i);
        str += ":";
        nombres << str;
    }

    vuePile->setVerticalHeaderLabels(nombres); //align case nb
    vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);//case nb not editable

    connect(commande, SIGNAL(returnPressed()), this, SLOT(getNextCommande()));
    connect(pile, SIGNAL(modificationEtat()), this, SLOT(refresh()));

    for(unsigned int i=0; i<pile->getNbItemsToAffiche();i++)
        vuePile->setItem(i,0,new QTableWidgetItem(""));
}

LitteraleManager& LitteraleManager::getInstance(){
    if (handler.instance==nullptr) handler.instance=new LitteraleManager;
    return *handler.instance;
}

LitteraleManager::~LitteraleManager(){
    for(unsigned int i=0; i<nb; i++) delete lits[i];
    delete[] lits;
}



void QCalc::refresh(){
    //update message
    message->setText(pile->getMessage());

    for (unsigned int i=0; i<pile->getNbItemsToAffiche();i++)
        vuePile->item(i,0)->setText("");

    unsigned int nb=0;
    for (Pile::iterator it=pile->begin(); it!=pile->end() && nb<pile->getNbItemsToAffiche(); ++it)
    {
       vuePile->item(pile->getNbItemsToAffiche()-nb-1,0)
               ->setText((*it).toString());
       nb++;
    }

}

void QCalc::getNextCommande()
{
    pile->setMessage("");
    controleur->commande(commande->text());

    //message still print on screen, can't write next one
    commande->clear();
}

bool estUnOperateur(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    return false;
}

bool estUnNombre(const QString s){
   bool ok=false;
   s.toInt(&ok);
   return ok;
}


void Controleur::commande(const QString& c){
/*    if (estUnNombre(c)){
        litAff.push(litMng.addLitterale(c.toInt()));
    }else{

        if (estUnOperateur(c)){
            if (litAff.taille()>=2) {
                Litterale v2=litAff.top().toString();
                litMng.removeLitterale(litAff.top());
                litAff.pop();
                Litterale v1=litAff.top().toString();
                litMng.removeLitterale(litAff.top());
                litAff.pop();
                int res;
                if (c=="+") res=v1+v2;
                if (c=="-") res=v1-v2;
                if (c=="*") res=v1*v2;
                if (c=="/") {
                    if (v2!=0) res=v1/v2;
                    else {
                        litAff.setMessage("Erreur : division par zéro");
                        res=v1;
                    }
                }
                Litterale& e=litMng.addLitterale(res);
                litAff.push(e);
            }else{
                litAff.setMessage("Erreur : pas assez d'arguments");
            }
        }else litAff.setMessage("Erreur : commande inconnue");
    }
*/}



