#include "include.h"
#include <algorithm>
#include "calc.h"
#include "litteralemanager.h"
#include "atomemanager.h"

LitteraleManager::Handler LitteraleManager::handler=LitteraleManager::Handler();
AtomeManager::Handlerat AtomeManager::handleratom=AtomeManager::Handlerat();

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
    connect(un, SIGNAL(clicked()),this,SLOT(affUn()));
    deux = new QPushButton("2",this);
    connect(deux, SIGNAL(clicked()),this,SLOT(affDeux()));
    trois = new QPushButton("3",this);
    connect(trois, SIGNAL(clicked()),this,SLOT(affTrois()));
    quatre = new QPushButton("4",this);
    connect(quatre, SIGNAL(clicked()),this,SLOT(affQuatre()));
    cinq = new QPushButton("5",this);
    connect(cinq, SIGNAL(clicked()),this,SLOT(affCinq()));
    six = new QPushButton("6",this);
    connect(six, SIGNAL(clicked()),this,SLOT(affSix()));
    sept = new QPushButton("7",this);
    connect(sept, SIGNAL(clicked()),this,SLOT(affSept()));
    huit = new QPushButton("8",this);
    connect(huit, SIGNAL(clicked()),this,SLOT(affHuit()));
    neuf = new QPushButton("9",this);
    connect(neuf, SIGNAL(clicked()),this,SLOT(affNeuf()));

    zero = new QPushButton("0",this);
    connect(zero, SIGNAL(clicked()),this,SLOT(affZero()));
    point = new QPushButton(".", this);
    connect(point, SIGNAL(clicked()),this,SLOT(affPoint()));
    dollar = new QPushButton("$", this);
    connect(dollar, SIGNAL(clicked()),this,SLOT(affDollar()));

    grille = new QGridLayout(this); //struc to place them


    //---- Operators ----

    add = new QPushButton("+",this) ;
 //   connect(add, SIGNAL(clicked()),this,SLOT(affPlus()));
    connect(add, SIGNAL(clicked()),this,SLOT(affPlus()));
    diff = new QPushButton("-",this);
    connect(diff, SIGNAL(clicked()),this,SLOT(affMoins()));
    mult = new QPushButton("*",this);
    connect(mult, SIGNAL(clicked()),this,SLOT(affEtoile()));
    quotient = new QPushButton("/",this) ;
    connect(quotient, SIGNAL(clicked()),this,SLOT(affDiviser()));
    entree = new QPushButton("go",this);
    connect(entree,SIGNAL(clicked()),this,SLOT(enter()));
    raz = new QPushButton("CLEAR",this);
    connect(raz,SIGNAL(clicked()),this,SLOT(remiseazero()));
    neg = new QPushButton("NEG",this);
    connect(neg,SIGNAL(clicked()),this,SLOT(affNeg()));
    re = new QPushButton("RE",this);
    connect(re,SIGNAL(clicked()),this,SLOT(affRe()));
    im = new QPushButton("IM",this);
    connect(im,SIGNAL(clicked()),this,SLOT(affIm()));
    espace = new QPushButton("espace",this);
    connect(espace,SIGNAL(clicked()),this,SLOT(affEspace()));

    opCol = new QGridLayout(this); //struc to place them

    //---- Interfaces ----
    blockP = new QHBoxLayout(this);


    //--------- Object Display -------------------
    //--- Pad---
    grille->addWidget(un,2,0);
    grille->addWidget(deux,2,1);
    grille->addWidget(trois,2,2);

    grille->addWidget(quatre,1,0);
    grille->addWidget(cinq,1,1);
    grille->addWidget(six,1,2);

    grille->addWidget(sept,0,0);
    grille->addWidget(huit,0,1);
    grille->addWidget(neuf,0,2);

    grille->addWidget(zero,3,0);
    grille->addWidget(point,3,1);
    grille->addWidget(dollar,3,2);

    grille->addWidget(neg,4,2);
    grille->addWidget(espace,4,0);


    grille->setVerticalSpacing(0.5);
    grille->setHorizontalSpacing(0.5);


    //--- Extra Pad---
    opCol->addWidget(raz);
    opCol->addWidget(entree);
    opCol->addWidget(add);
    opCol->addWidget(diff);
    opCol->addWidget(mult);
    opCol->addWidget(quotient);
    opCol->addWidget(im);
    opCol->addWidget(re);

    //--- main block--
    blockP->addLayout(grille);
    blockP->addLayout(opCol);

    //--- command ---
    commande->move(140,40);
    commande->setFixedWidth(340);

    //--- global Layout--
    couche->addWidget(message);
    couche->addWidget(vuePile);
    couche->addWidget(commande);
    couche->addLayout(blockP);

    setLayout(couche);

    //-- pile treatment---
    controleur = new Controleur(LitteraleManager::getInstance(), *pile,AtomeManager::getInstanceAtome());

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

void QCalc::remiseazero(){
    while(!pile->estVide()){
        Litterale& v= controleur->litAff.top();
        pile->pop();
        controleur->litMng.removeLitterale(v);
    }
}





