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
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);
        if (ptRationnel!= 0){
            // Entier + Rationnel
            Entier num = (value*ptRationnel->getDen().getValue()+ptRationnel->getNum().getValue());
            Entier den = (ptRationnel->getDen().getValue());
            Rationnel* res = new Rationnel(num,den);
            res->simplifier();
            LitteraleCalculable& ref = *res;
            return ref;
        }
    }
}

//end of file
