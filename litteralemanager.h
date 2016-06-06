#ifndef LITTERALEMANAGER_H
#define LITTERALEMANAGER_H

//#include "litterale.h"
#include "include.h"
#include "litteraleCalculable.h"
#include "pile.h"
#include "calc.h"
#include "entier.h"
#include "auxiliaire.h"

class Litterale{
public:
    void affiche();
    Litterale(){}
    virtual ~Litterale();
};

class LitteraleManager {
    Litterale** exps;
    unsigned int nb;
    unsigned int nbMax;
    void agrandissementCapacite();
    LitteraleManager():exps(nullptr),nb(0),nbMax(0){}
    ~LitteraleManager();
    LitteraleManager(const LitteraleManager& m);
    LitteraleManager& operator=(const LitteraleManager& m);

    struct Handler{
        LitteraleManager* instance;
        Handler():instance(nullptr){}
        // destructeur appel顠 la fin du programme
        ~Handler(){ delete instance; }
    };
    static Handler handler;
public:
    Litterale& addLitterale();
    void removeLitterale(Litterale& e);
    static LitteraleManager& getInstance();
    static void libererInstance();

    class Iterator {
        friend class LitteraleManager;
        Litterale** currentExp;
        unsigned int nbRemain;
        Iterator(Litterale** u, unsigned nb):currentExp(u),nbRemain(nb){}
    public:
        Iterator():currentExp(nullptr),nbRemain(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw CalcException("error, next on an iterator which is done");
            nbRemain--;
            currentExp++;
        }
        Litterale& current() const {
            if (isDone())
                throw CalcException("error, indirection on an iterator which is done");
            return **currentExp;
        }
    };

    Iterator getIterator() {
        return Iterator(exps,nb);
    }

    class iterator {
        Litterale** current;
        iterator(Litterale** u):current(u){}
        friend class LitteraleManager;
    public:
        iterator():current(0){}
        Litterale& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(exps); }
    iterator end() { return iterator(exps+nb); }

    class const_iterator {
        Litterale** current;
        const_iterator(Litterale** u):current(u){}
        friend class LitteraleManager;
    public:
        const_iterator():current(0){}
        Litterale& operator*() const { return **current; }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ ++current; return *this; }
    };
    const_iterator begin() const { return const_iterator(exps); }
    const_iterator end() const { return const_iterator(exps+nb); }
};

class Controleur {
    LitteraleManager& expMng;
    Pile& expAff;
public:
    Controleur(LitteraleManager& m, Pile& v):expMng(m), expAff(v){}
    void commande(const QString& c);

};

#endif // LITTERALEMANAGER_H
