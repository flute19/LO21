#ifndef LITTERALEMANAGER_H
#define LITTERALEMANAGER_H

#include "litterale.h"
#include "calcexception.h"
#include "item.h"
#include "calc.h"
#include "entier.h"
#include "reel.h"
#include "complexe.h"



//------- pre-forward------
class Pile;
class Litterale;

class LitteraleManager {

    Litterale** lits;
    unsigned int nb;
    unsigned int nbMax;

    //instances
    LitteraleManager():lits(nullptr),nb(0),nbMax(0){}
    ~LitteraleManager();
    LitteraleManager(const LitteraleManager& m);
    LitteraleManager& operator=(const LitteraleManager& m);

    //management
    void agrandissementCapacite();

    struct Handler{
        LitteraleManager* instance;
        Handler():instance(nullptr){}
        // destructeur appel顠 la fin du programme
        ~Handler(){ delete instance; }
    };
    static Handler handler;
public:
    Litterale& addLitterale(QString v);
    void removeLitterale(Litterale& e);
    static LitteraleManager& getInstance();
    static void libererInstance();

    class Iterator {
        friend class LitteraleManager;
        Litterale** currentlit;
        unsigned int nbRemain;
        Iterator(Litterale** u, unsigned nb):currentlit(u),nbRemain(nb){}
    public:
        Iterator():currentlit(nullptr),nbRemain(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw CalcException("error, next on an iterator which is done");
            nbRemain--;
            currentlit++;
        }
        Litterale& current() const {
            if (isDone())
                throw CalcException("error, indirection on an iterator which is done");
            return **currentlit;
        }
    };

    Iterator getIterator() {
        return Iterator(lits,nb);
    }
};


#endif // LITTERALEMANAGER_H
