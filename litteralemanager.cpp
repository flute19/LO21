#include "litteralemanager.h"
#include "expression.h"

void LitteraleManager::agrandissementCapacite() {
    Litterale** newtab=new Litterale*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=lits[i];
    Litterale**  old = lits;
    lits = newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}

Litterale& LitteraleManager::addLitterale(QString v){
    switch (estUnNombre(v)){
        case 0:
            if (nb == nbMax) agrandissementCapacite();
            lits[nb++] = new Entier(v.toInt());
            return *lits[nb-1];
        break;
        case 1:
            if (nb == nbMax) agrandissementCapacite();
            lits[nb++] = new Reel(v.toFloat());
            return *lits[nb-1];
        break;
        case 3:
            if (nb == nbMax) agrandissementCapacite();
            lits[nb++] = dynamic_cast<Litterale*>(new Expression(v));
            return *lits[nb-1];
        break;
        default: throw CalcException("Erreur, ceci n'est pas une litterale calculable.");
        break;
   }
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
