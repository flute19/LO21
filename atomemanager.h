#ifndef ATOMEMANAGER_H
#define ATOMEMANAGER_H
//------- pre-forward------
#include "atome.h"
#include "calcexception.h"
#include "item.h"
#include "calc.h"
#include "litterale.h"
#include<QString>

class Pile;
class Atome;
class Litterale;

//---------------Class definition --------------
class AtomeManager {

    Atome** ats;
    unsigned int nb;
    unsigned int nbMax;

    //instances
    AtomeManager():ats(nullptr),nb(0),nbMax(0){}
    ~AtomeManager();
    AtomeManager(const AtomeManager& m);
    AtomeManager& operator=(const AtomeManager& m);

    //management
    void agrandissementCapacite();

    struct Handlerat{
        AtomeManager* instance;
        Handlerat():instance(nullptr){}
        // destructeur appel顠 la fin du programme
        ~Handlerat(){ delete instance; }
    };
    static Handlerat handleratom;
public:
    Atome& getAtome(QString s) const;
    bool existe(QString s) const;
    void addAtome(QString v, Litterale* l);
    void removeAtome(Atome& e);
    static AtomeManager& getInstanceAtome();

    static void libererInstanceAtome();

    class Iterator {
        friend class AtomeManager;
        Atome** currentat;
        unsigned int nbRemain;
        Iterator(Atome** u, unsigned nb):currentat(u),nbRemain(nb){}
    public:
        Iterator():currentat(nullptr),nbRemain(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw CalcException("error, next on an iterator which is done");
            nbRemain--;
            currentat++;
        }
        Atome& current() const {
            if (isDone())
                throw CalcException("error, indirection on an iterator which is done");
            return **currentat;
        }
    };

    Iterator getIterator() {
        return Iterator(ats,nb);
    }
};

#endif // ATOMEMANAGER_H
