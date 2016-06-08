#include "entier.h"
#include "litteralemanager.h"
#include "litteraleCalculable.h"

/**definition of Litterale's method **/
void Litterale::affiche(){
    cout<<"coucou"<<endl;
}

/**Definition of Item's method**/
Litterale& Item::getLitterale() const {
        if (lit==nullptr) throw CalcException("Item : tentative d'acces a une Litterale inexistante");
        return *lit;
}


/**Definition of Entier's method**/
LitteraleCalculable& Entier::addition(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);
    if (ptEntier != 0){
        // Entier + Entier
        Entier* res= new Entier(value + ptEntier->getValue());
        LitteraleCalculable& ref=*res;
        return ref;
    }
}

