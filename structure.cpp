#include "entier.h"
#include "litteralemanager.h"

/**definition of Litterale's method **/
void Litterale::affiche(){
    cout<<"coucou"<<endl;
}

/**Definition of Item's method**/
Litterale& Item::getLitterale() const {
        if (exp==nullptr) throw CalcException("Item : tentative d'acces a une Litterale inexistante");
        return *exp;
}


/**Definition of Entier's method**/
Entier& Entier::operator+ (Entier& e){
    Entier res = Entier(e.value+value);
    return res;
}

