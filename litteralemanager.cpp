#include "litteralemanager.h"
#include "expression.h"
#include <QStringList>

void LitteraleManager::agrandissementCapacite() {
    Litterale** newtab=new Litterale*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=lits[i];
    Litterale**  old = lits;
    lits = newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}

Litterale& LitteraleManager::addLitterale(QString v){
bool ok = true;

    switch (estUnNombre(v)){
        case 0:
            if (nb == nbMax) agrandissementCapacite();
            lits[nb++] = new Entier(v.toInt());
            return *lits[nb-1];
        break;
        case 1:
            if (nb == nbMax) agrandissementCapacite();
            lits[nb++] = new Reel(v.toDouble());
            return *lits[nb-1];
        break;
        case 2:
            if(ok){
                if (nb == nbMax) agrandissementCapacite();

                QStringList l = v.split("/");

                lits[nb++] = new Rationnel(l.at(0).toInt(), l.at(1).toInt());
                return *lits[nb-1];
            }
        break;
        case 3:
            if (nb == nbMax) agrandissementCapacite();
            lits[nb++] = dynamic_cast<Litterale*>(new Expression(v));
            return *lits[nb-1];
        break;
        case 4:
            if(ok){
            if (nb == nbMax) agrandissementCapacite();

            QStringList l = v.split("$");
            NonComplexe* re;
            NonComplexe* im;

            if(l.at(0).toInt()){
                re = new Entier(l.at(0).toInt());
            }else{
                if(l.at(0).toDouble()){
                    re = new Reel(l.at(0).toDouble());
                }else{
                    if(l.at(0).contains(QRegExp("([0-9]+)/([0-9]+)"))){
                        QStringList l2 = l.at(0).split("/");
                        re = new Rationnel(l2.at(0).toInt(), l2.at(1).toInt());
                    }
                }
            }

            if(l.at(1).toInt()){
                im = new Entier(l.at(1).toInt());
            }else{
                if(l.at(1).toDouble()){
                    im = new Reel(l.at(1).toDouble());
                }else{
                    if(l.at(1).contains(QRegExp("([0-9]+)/([0-9]+)"))){
                        QStringList l2= l.at(1) .split("/");
                        im = new Rationnel(l2.at(1).toInt(), l2.at(1).toInt());
                    }
                }
            }

            lits[nb++] = new Complexe(*re, *im);
            return *lits[nb-1];
            }
        break;
        default: throw CalcException("Erreur, ceci n'est pas une litterale calculable.");
        break;

   }
    Entier* e = new Entier();
    Litterale& l = *e;
    return l;
}

void LitteraleManager::removeLitterale(Litterale& e){
    unsigned int i=0;
    while(i<nb && lits[i]!=&e) i++;
    if (i==nb) throw CalcException("elimination d'une Litterale inexistante");
    delete lits[i];
    i++;
    while(i<nb) { lits[i-1]=lits[i]; i++; }
    nb--;
}

LitteraleManager& LitteraleManager::getInstance(){
    if (handler.instance==nullptr) handler.instance=new LitteraleManager;
    return *handler.instance;
}

LitteraleManager::~LitteraleManager(){
    for(unsigned int i=0; i<nb; i++) delete lits[i];
    delete[] lits;
}
