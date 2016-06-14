#include "atomemanager.h"
#include "expression.h"
#include <QStringList>

Atome& AtomeManager::getAtome(QString s) const{
    unsigned int i=0;
    while (i<nb && ats[i]->getId()!=s){
        i++;
    }
    if(i!= nb)
        return *ats[i];
    Entier* e = new Entier();
    Atome* res = new Atome("erreurInitialisation", e);
    Atome& ref = *res;
    return ref;
}

bool AtomeManager::existe(QString s) const{
    unsigned int i=0;
    while (i<nb && ats[i]->getId()!=s){
        i++;
    }
    if(i!=nb)
        return true;
    return false;
}

void AtomeManager::agrandissementCapacite() {
    Atome** newtab=new Atome*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=ats[i];
    Atome**  old = ats;
    ats = newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}

void AtomeManager::addAtome(QString v, Litterale* l){
    unsigned int i=0;
    while(i<nb && ats[i]->getId()!=v){
        i++;
    }
    if (i!=nb)
        ats[i]->setValue(l);

    else{
        if(nb==nbMax) agrandissementCapacite();
        ats[nb++]= new Atome(v,l);
    }
}

void AtomeManager::removeAtome(Atome& e){
    unsigned int i=0;
    while(i<nb && ats[i]!=&e) i++;
    if (i==nb) throw CalcException("elimination d'une Atome inexistante");
    delete ats[i];
    i++;
    while(i<nb) { ats[i-1]=ats[i]; i++; }
    nb--;
}

AtomeManager& AtomeManager::getInstanceAtome(){
    if (!handleratom.instance) handleratom.instance=new AtomeManager;
    return *handleratom.instance;
}

AtomeManager::~AtomeManager(){
    for(unsigned int i=0; i<nb; i++) delete ats[i];
    delete[] ats;
}
