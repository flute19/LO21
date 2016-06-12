#ifndef PILE_H
#define PILE_H


#include "item.h"
#include "calc.h"
#include "entier.h"
#include "reel.h"
#include "litteralemanager.h"
#include "calcexception.h"
#include "controleur.h"



//-------- class Forward -------------
class Item;
class Litterale;
class Simplificator;

class Pile : public QObject {
    Q_OBJECT

    //stack attributes
    Item* items;
    unsigned int nb;
    unsigned int nbMax;
    QString message;

    //stack private methods
    void agrandissementCapacite();
    unsigned int nbAffiche;
public:
    //management
    Pile():items(nullptr),nb(0),nbMax(0),message(""),nbAffiche(4){}//constructor
    ~Pile();//destructor
    void setNbItemsToAffiche(unsigned int n) { nb = n; }
    void setMessage(const QString& m) { message = m; modificationEtat(); }//message for user

    //manipulation
    void push(Litterale& e);//add Litteral on pile
    void pop(); //remove item from top of pile
    void affiche(QTextStream& f) const; //display pile on user window
    unsigned int getNbItemsToAffiche() const { return nbAffiche; }
    QString getMessage() const { return message; }

    //data
    unsigned int taille() const { return nb; }
    bool estVide() const { return nb == 0; }//check if empty
    Litterale& top() const;

    /**This part manage Item on pile, as pile is a collection of Item**/
    class iterator {
        Item* current;
        iterator(Item* u):current(u){}
        friend class Pile;
    public:
        iterator():current(nullptr){}
        Litterale& operator*() const { return current->getLitterale(); }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ --current; return *this; }
    };
    iterator begin() { return iterator(items+nb-1); }
    iterator end() { return iterator(items-1); }


    class const_iterator {
        Item* current;
        const_iterator(Item* u):current(u){}
        friend class Pile;
    public:
        const_iterator():current(nullptr){}
        const Litterale& operator*() const { return current->getLitterale(); }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ --current; return *this; }
    };
    const_iterator begin() const { return const_iterator(items+nb-1); }
    const_iterator end() const { return const_iterator(items-1); }

signals:
    void modificationEtat();
};

#endif // PILE_H
