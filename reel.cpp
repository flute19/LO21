#include "reel.h"

/**Definition of Reel's method**/

//-----------------Operations ----------------------------

// ----- Addition -----
LitteraleCalculable& Reel::addition(const LitteraleCalculable& l) const{
    const Reel* ptReel = dynamic_cast<const Reel*>(&l);

    if (ptReel != 0){
        // Reel + Reel
        Reel* res = new Reel(value + ptReel->getValue());
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

        if (ptEntier != 0){
            // Reel + Entier
            LitteraleCalculable& ref = ptEntier->addition(*this);
            return ref;
        }
        else{
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

            if (ptRationnel != 0){
                // Reel + Rationnel
                Reel* res = new Reel(value + ptRationnel->getNum().getValue()/ptRationnel->getDen().getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Reel* res = new Reel();
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}

// ----- Soustraction -----
LitteraleCalculable& Reel::diff(const LitteraleCalculable& l) const{
    const Reel* ptReel = dynamic_cast<const Reel*>(&l);

    if (ptReel != 0){
        //Reel - Reel
        Reel* res = new Reel(value - ptReel->getValue());
        LitteraleCalculable& ref = *res;

        return ref;
    }
    else {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

        if (ptEntier != 0){
            // Reel - Entier
            LitteraleCalculable& ref = ptEntier->diff(*this);
            return ref;
        }
        else{
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

            if (ptRationnel != 0){
                // Reel - Rationnel
                Reel* res = new Reel(value - ptRationnel->getNum().getValue() / ptRationnel->getDen().getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Reel* res = new Reel();
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}

// ----- Multiplication -------
LitteraleCalculable& Reel::mult(const LitteraleCalculable& l) const{
    const Reel* ptReel = dynamic_cast<const Reel*>(&l);

    if (ptReel != 0){
        //Reel * Reel
        Reel* res = new Reel(value * ptReel->getValue());
        LitteraleCalculable& ref = *res;

        return ref;
    }
    else {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

        if (ptEntier != 0){
            // Reel * Entier
            LitteraleCalculable& ref = ptEntier->mult(*this);
            return ref;
        }
        else{
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

            if (ptRationnel != 0){
                // Reel * Rationnel
                Reel* res = new Reel(value * ptRationnel->getNum().getValue() / ptRationnel->getDen().getValue());
                LitteraleCalculable& ref= *res;
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Reel* res = new Reel();
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}


//end of file
