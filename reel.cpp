#include "reel.h"

/**Definition of Reel's method**/

//-----------------Operations binaires ----------------------------

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
                Reel* res = new Reel(value + double(ptRationnel->getNum().getValue())/double(ptRationnel->getDen().getValue()));
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Reel + Expression
                        LitteraleCalculable& ref = ptExpression->addition(*this);
                        return ref;
                   }

                else{
                    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);
                    if (ptComplexe!=0){
                            // Reel + Expression
                            LitteraleCalculable& ref = ptComplexe->addition(*this);
                            return ref;
                       }
                }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Reel* res = new Reel();
    LitteraleCalculable& ref = *res;
    return ref;
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
                Reel* res = new Reel(value - double(ptRationnel->getNum().getValue()) / double(ptRationnel->getDen().getValue()));
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Reel - Expression
                        LitteraleCalculable& ref = ptExpression->diff(*this);
                        return ref;
                   }

                else{
                    throw CalcException("le type de l'argument 2 n'est pas reconnu");
                    Reel* res = new Reel();
                    LitteraleCalculable& ref = *res;
                    return ref;
                }
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
                Reel* res = new Reel(value * double(ptRationnel->getNum().getValue()) / double(ptRationnel->getDen().getValue()));
                LitteraleCalculable& ref= *res;
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Reel * Expression
                        LitteraleCalculable& ref = ptExpression->mult(*this);
                        return ref;
                   }

                else{
                    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);
                    if (ptComplexe!=0){
                            // Reel * Complexe
                            LitteraleCalculable& ref = ptComplexe->mult(*this);
                            return ref;
                       }
                }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Reel* res = new Reel();
    LitteraleCalculable& ref = *res;
    return ref;
}

// ----- Division ---------
LitteraleCalculable& Reel::quotient(const LitteraleCalculable& l) const{
    const Reel* ptReel = dynamic_cast<const Reel*>(&l);

    if (ptReel != 0){
        //Reel / Reel

        if(ptReel->getValue() == 0) throw CalcException("dividion par 0 impossible");

        Reel* res = new Reel(value / ptReel->getValue());
        LitteraleCalculable& ref = *res;

        return ref;
    }
    else {
        const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

        if (ptEntier != 0){
            // Reel / Entier
            if(ptEntier->getValue() == 0) throw CalcException("dividion par 0 impossible");

            Reel* res = new Reel(value / ptEntier->getValue());
            LitteraleCalculable& ref = *res;

            return ref;
        }
        else{
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

            if (ptRationnel != 0){
                // Reel / Rationnel
                if(ptRationnel->getNum().getValue() == 0) throw CalcException("dividion par 0 impossible");


                Reel* res = new Reel(value * ptRationnel->getDen().getValue() / ptRationnel->getNum().getValue());
                LitteraleCalculable& ref= *res;
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Reel / Expression
                        LitteraleCalculable& ref = ptExpression->quotient(*this);
                        return ref;
                   }

                else{
                    throw CalcException("le type de l'argument 2 n'est pas reconnu");
                    Reel* res = new Reel();
                    LitteraleCalculable& ref = *res;
                    return ref;
                }
            }
        }
    }
}

//------------- Operation unaires------------
LitteraleCalculable& Reel::oppose()const{

    Reel* res = new Reel(- value);
    LitteraleCalculable& ref = *res;
    return ref;
}

//--- re ---
const LitteraleCalculable& Reel::partieReel() const {

    const Reel* res = this;
    const LitteraleCalculable& ref = *res;
    return ref;
}

//--- im ---
const LitteraleCalculable& Reel::partieIm() const {

    Entier* res = new Entier();
    const LitteraleCalculable& ref = *res;
    return ref;
}


//end of file
