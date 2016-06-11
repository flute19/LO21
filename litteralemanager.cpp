#include "litteralemanager.h"

void LitteraleManager::agrandissementCapacite() {
    Litterale** newtab=new Litterale*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=lits[i];
    Litterale**  old = lits;
    lits = newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}

Litterale& LitteraleManager::addLitterale(int v ){

    if (nb==nbMax) agrandissementCapacite();
    lits[nb++] = new Entier(v);
    return *lits[nb-1];
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
