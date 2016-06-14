#include "entier.h"

/**Definition of Entier's method**/

QString Entier::toString() const{
    QString str;
    str = QString::number(value);
    return str;
}

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

            LitteraleCalculable& ref = *res;
            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);
            if (ptReel!=0){
                // Entier + Reel
                Reel* res= new Reel(double(value)+ptReel->getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Entier + Expression
                        LitteraleCalculable& ref = ptExpression->addition(*this);
                        return ref;
                   }else{
                    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);
                        if (ptComplexe!=0){
                                // Entier / Complexe
                                LitteraleCalculable& ref = ptComplexe->addition(*this);
                                return ref;
                        }
                }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Entier* res = new Entier();
    LitteraleCalculable& ref = *res;
    return ref;
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
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Entier + Expression
                        LitteraleCalculable& ref = ptExpression->diff(*this);
                        return ref;
                   }else{
                    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);
                    if (ptComplexe!=0){
                            // Entier / Complexe
                            LitteraleCalculable& ref = ptComplexe->diff(*this);
                            return ref;
                    }
                }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Entier* res = new Entier();
    LitteraleCalculable& ref = *res;
    return ref;
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

            int type = simplifier(num, den);

            if (type == 0){
                Rationnel* res = new Rationnel(num,den);

                LitteraleCalculable& ref = *res;
                return ref;
            }
            if (type == 1) {
                Entier v = num.div(den);
                Entier* res = new Entier(v.getValue());
                LitteraleCalculable& ref = *res;//spl->simplifier(res);
                return ref;
            }
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);
            if (ptReel!=0){
                // Entier * Reel
                Reel* res= new Reel(value * ptReel->getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Entier * Expression
                        LitteraleCalculable& ref = ptExpression->mult(*this);
                        return ref;
                   }else{
                    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);
                    if (ptComplexe!=0){
                            // Entier * Complexe
                            LitteraleCalculable& ref = ptComplexe->mult(*this);
                            return ref;
                    }
                }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Entier* res = new Entier();
    LitteraleCalculable& ref = *res;
    return ref;
}

//------ Division Entiere & Modulo -----------
Entier& Entier::div(const Entier& e){
    Entier* res = new Entier(value / e.getValue());
    Entier& ref = *res;
    return ref;
}

Entier& Entier::mod(const Entier& e){
    int tamp = value / e.getValue();
    tamp = value - tamp * e.getValue();

    Entier* res = new Entier(tamp);
    Entier& ref = *res;
    return ref;
}

// ----- Division -----

LitteraleCalculable& Entier::quotient(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Entier / Entier
        //if(ptEntier->getValue() == 0)

        int type = simplifier(*this, *ptEntier);

        if (type == 0){//non simplifiable
            Rationnel* res = new Rationnel(value, ptEntier->getValue());

            LitteraleCalculable& ref = *res;
            return ref;
        }
        if (type == 1) {
            Entier* res = new Entier(value / ptEntier->getValue());
            LitteraleCalculable& ref = *res;
            return ref;
        }
    }else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

        if (ptRationnel!= 0){
            // Entier / Rationnel
            if(ptRationnel->getNum().getValue() == 0) throw CalcException("dividion par 0 impossible");

            Entier num = (value * ptRationnel->getDen().getValue());
            Entier den = (ptRationnel->getNum().getValue());
            Rationnel* res = new Rationnel(num, den);

           // res->simplifier();
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
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Entier + Expression
                        LitteraleCalculable& ref = ptExpression->quotient(*this);
                        return ref;
                   }else{
                        const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);
                        if (ptComplexe!=0){
                        // Entier / Complexe
                        LitteraleCalculable& ref = ptComplexe->quotient(*this);
                        return ref;
                        }
                    }
            }
        }
    }



    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Entier* res = new Entier();
    LitteraleCalculable& ref = *res;
    return ref;
}

//------------- Operation unaires------------
//--- neg ----
LitteraleCalculable& Entier::oppose()const{
    Entier* res = new Entier(- value);
    LitteraleCalculable& ref = *res;
    return ref;
}

//---- Re ---
const LitteraleCalculable& Entier::partieReel() const {

    const Entier* res = this;
    const LitteraleCalculable& ref = *res;
    return ref;
}

//--- im ---
const LitteraleCalculable& Entier::partieIm() const {

    Entier* res = new Entier();
    const LitteraleCalculable& ref = *res;
    return ref;
}


// -------------------------------------------------------------------------
//-------------------------- Fonction auxiliaire ---------------------------

int simplifier(Entier a, Entier b){

    Entier& test = a.mod(b);

    if (test.getValue() == 0){
        return 1;
    } else return 0;
}




////end of file
