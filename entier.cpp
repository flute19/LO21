#include "entier.h"

/**Definition of Entier's method**/

//-----------------Operations ----------------------------

// ----- Addition -----
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
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);
            if (ptReel!=0){
                // Entier + Reel
                Reel* res= new Reel(value+ptReel->getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Entier* res = new Entier();
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}

// ----- Soustraction -----
LitteraleCalculable& Entier::diff(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Entier - Entier
        Entier* res = new Entier(value - ptEntier->getValue());
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);
        if (ptRationnel!= 0){
            // Entier - Rationnel
            Entier num = (value*ptRationnel->getDen().getValue()-ptRationnel->getNum().getValue());
            Entier den = (ptRationnel->getDen().getValue());
            Rationnel* res = new Rationnel(num,den);
            res->simplifier();
            LitteraleCalculable& ref = *res;
            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);
            if (ptReel!=0){
                // Entier - Reel
                Reel* res= new Reel(value-ptReel->getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Entier* res = new Entier();
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}

// ----- Multiplication -----

LitteraleCalculable& Entier::mult(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Entier * Entier
        Entier* res = new Entier(value * ptEntier->getValue());
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

        if (ptRationnel!= 0){
            // Entier * Rationnel
            Entier num = (value * ptRationnel->getNum().getValue());
            Entier den = (ptRationnel->getDen().getValue());
            Rationnel* res = new Rationnel(num,den);

            res->simplifier();
            LitteraleCalculable& ref = *res;
            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);
            if (ptReel!=0){
                // Entier * Reel
                Reel* res= new Reel(value * ptReel->getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Entier* res = new Entier();
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}

// ----- Division -----

LitteraleCalculable& Entier::quotient(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Entier / Entier
        if(ptEntier->getValue() == 0) throw CalcException("division par 0 impossible");

        Entier* res = new Entier(value / ptEntier->getValue());
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

        if (ptRationnel!= 0){
            // Entier / Rationnel
            if(ptRationnel->getNum().getValue() == 0) throw CalcException("dividion par 0 impossible");

            Entier num = (value * ptRationnel->getDen().getValue());
            Entier den = (ptRationnel->getNum().getValue());
            Rationnel* res = new Rationnel(num, den);

            res->simplifier();
            LitteraleCalculable& ref = *res;
            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);

            if (ptReel!=0){
                // Entier / Reel
                if(ptReel->getValue() == 0) throw CalcException("division par 0 impossible");


                Reel* res = new Reel(value / ptReel->getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Entier* res = new Entier();
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}

//------------- Operation unaires------------
//LitteraleCalculable& Entier::oppose()const{
//    Entier* res = new Entier(- value);
//    LitteraleCalculable& ref = *res;
//    return ref;
//}



//end of file
