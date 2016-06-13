#ifndef ATOMEMANAGER_H
#define ATOMEMANAGER_H
//------- pre-forward------
#include "atome.h"
#include "calcexception.h"
#include "item.h"
#include "calc.h"
#include<QString>
class Pile;
class Atome;

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

    struct Handler{
        AtomeManager* instance;
        Handler():instance(nullptr){}
        // destructeur appel顠 la fin du programme
        ~Handler(){ delete instance; }
    };
    static Handler handler;
public:
    void addAtome(QString v, Litterale* l);
    void removeAtome(Atome& e);
    static AtomeManager& getInstance();
    static void libererInstance();

    class Iterator {
        friend class AtomeManager;
        Atome** currentlit;
        unsigned int nbRemain;
        Iterator(Atome** u, unsigned nb):currentlit(u),nbRemain(nb){}
    public:
        Iterator():currentlit(nullptr),nbRemain(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw CalcException("error, next on an iterator which is done");
            nbRemain--;
            currentlit++;
        }
        Atome& current() const {
            if (isDone())
                throw CalcException("error, indirection on an iterator which is done");
            return **currentlit;
        }
    };

    Iterator getIterator() {
        return Iterator(ats,nb);
    }

    class iterator {
        Atome** current;
        iterator(Atome** u):current(u){}
        friend class AtomeManager;
    public:
        iterator():current(0){}
        Atome& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(ats); }
    iterator end() { return iterator(ats+nb); }

    class const_iterator {
        Atome** current;
        const_iterator(Atome** u):current(u){}
        friend class AtomeManager;
    public:
        const_iterator():current(0){}
        Atome& operator*() const { return **current; }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ ++current; return *this; }
    };
    const_iterator begin() const { return const_iterator(ats); }
    const_iterator end() const { return const_iterator(ats+nb); }
};

#endif // ATOMEMANAGER_H
