#include "entier.h"
#include "litteralemanager.h"

/**Definition of Item's method**/
Litterale& Item::getLitterale() const {
        if (exp==nullptr) throw CalcException("Item : tentative d'acces a une Litterale inexistante");
        return *exp;
}


/**Definition of Entier's method**/
Entier& Entier::operator+ (Entier& e){
                Entier res(e.value+value);
            return res;
}

