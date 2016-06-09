#include "entier.h"

/**Definition of Entier's method**/

LitteraleCalculable& Entier::addition(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Entier + Entier
        Entier* res = new Entier(value + ptEntier->getValue());
        LitteraleCalculable& ref = *res;
        return ref;
    }
}

//end of file
