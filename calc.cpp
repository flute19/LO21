#include "calc.h"

QCalc::QCalc(QWidget* parent):QWidget (parent)
{
    pile=new Pile();

    message= new QLineEdit(this) ;
    vuePile= new QTableWidget(pile->getNbItemsToAffiche(),1,this);
    commande= new QLineEdit(this);
    QVBoxLayout* couche= new QVBoxLayout;

    couche->addWidget(message);
    couche->addWidget(vuePile);
    couche->addWidget(commande);
    setLayout(couche)
    ;

    pile= new Pile();
    controleur = new Controleur(
                LitteraleManager::getInstance(), *pile);
    setWindowTitle("UTCalc");

   //can't rewrite windows message
    message->setReadOnly(true);//can't
    message->setText("coucou");//specify message to print
    message->setStyleSheet("background: blake;color:white"); //have fun

    vuePile->horizontalHeader()->setVisible(false);
    QStringList nombres;

    for(unsigned int i=pile->getNbItemsToAffiche(); i>0; i--)
    {
        QString str=QString::number(i);
        str+=":";
        nombres<<str;
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
