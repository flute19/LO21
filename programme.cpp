#include "programme.h"


QString Programme::eval() const{
        QString expr=value;
        QStringList listeLitterales = expr.split(" ");
        QStringList::iterator it=listeLitterales.begin();
        Pile *pile= new Pile();
        Controleur *controleur = new Controleur(LitteraleManager::getInstance(),*pile);
        while (it!=listeLitterales.end()){
            controleur->commande(QString(*it));
            it++;
        }
        QString res=pile->top().toString();

        return res;
}
