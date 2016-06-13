#include "rationnel.h"


//----------------Constructeurs ------------------------

Rationnel::Rationnel(const Entier &n, const Entier &d) {
    if (d.getValue()==0){
        throw CalcException("Rationnel : Impossible de construire le rationnel (Denominateur nul)");
    }
    else {
        num=new Entier(n.getValue());
        den=new Entier(d.getValue());
    }
}

Rationnel::Rationnel(const LitteraleCalculable& n,const LitteraleCalculable& d) {
    const Entier* tmpNum = dynamic_cast<const Entier*>(&n);
    const Entier* tmpDen = dynamic_cast<const Entier*>(&d);
    if (tmpNum==0 || tmpDen==0){
        throw CalcException("Rationnel : Impossible de construrie le rationnel (Les deux Littérales ne sont pas des Entiers)");
    }
    else {
        if (tmpDen->getValue()==0){
            throw CalcException("Rationnel : Impossible de construire le rationnel (Denominateur nul)");
        }
        else {
            num=new Entier(tmpNum->getValue());
            den=new Entier(tmpDen->getValue());
        }
    }
}

Rationnel::Rationnel(int n, int d) {
    if (d==0){
        throw CalcException("Rationnel : Impossible de construire le rationnel (Denominateur nul)");
    }
    else {
        num=new Entier(n);
        den=new Entier(d);
    }
}

//-----------------------------Affichage -----------------------------

 QString Rationnel::toString() const {

    QString str = num->Entier::toString();
    str.append("/");

    QString tamp = den->Entier::toString();
    str.append(tamp);

    return str;
}

//-----------------Operations binaires -------------------------

// ----- Addition -----
LitteraleCalculable& Rationnel::addition(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Rationnel + Entier
        LitteraleCalculable& ref = ptEntier->addition(*this);
        return ref;
    }
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

        if (ptRationnel!=0){
            // Rationnel + Rationnel
            Entier n = Entier((num->getValue()*ptRationnel->getDen().getValue())+(den->getValue()*ptRationnel->getNum().getValue()));
            Entier d = Entier(den->getValue()*ptRationnel->getDen().getValue());
            Rationnel* res = new Rationnel(n,d);

            //res->simplifier();
            LitteraleCalculable& ref = *res;
            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);

            if (ptReel != 0){
                //Rationnel + Reel
                LitteraleCalculable& ref = ptReel->addition(*this);
                return ref;
            }else{
                const Expression* ptExpression = dynamic_cast<const Expression*>(&l);

                if (ptExpression != 0){
                        // Rationnel + Expression
                        LitteraleCalculable& ref = ptExpression->addition(*this);
                        return ref;
                   }else{
                    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);

                    if (ptComplexe!=0){
                            // Rationnel + Complexe
                            LitteraleCalculable& ref = ptExpression->addition(*this);
                            return ref;
                       }
                }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Rationnel* res = new Rationnel(0,1);
    LitteraleCalculable& ref = *res;
    return ref;
}

// ----- Soustraction ---
LitteraleCalculable& Rationnel::diff(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Rationnel - Entier
        LitteraleCalculable& ref = ptEntier->diff(*this);
        return ref;
    }
    else{
        const Rationnel* ptRationnel=dynamic_cast<const Rationnel*>(&l);
        if (ptRationnel!=0){
            // Rationnel - Rationnel
            Entier n= Entier((num->getValue()*ptRationnel->getDen().getValue())-(den->getValue()*ptRationnel->getNum().getValue()));
            Entier d= Entier(den->getValue()*ptRationnel->getDen().getValue());
            Rationnel* res= new Rationnel(n,d);

           // res->simplifier();
            LitteraleCalculable& ref =*res;
            return ref;
        }
        else {
            const Reel* ptReel=dynamic_cast<const Reel*>(&l);
            if (ptReel!=0){
                //Rationnel - Reel
                LitteraleCalculable& ref = ptReel->diff(*this);
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Rationnel - Expression
                        LitteraleCalculable& ref = ptExpression->diff(*this);
                        return ref;
                   }else{
                    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);

                        if (ptComplexe!=0){
                                // Rationnel - Complexe
                                LitteraleCalculable& ref = ptExpression->addition(*this);
                                return ref;
                        }

                }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Rationnel* res = new Rationnel(0,1);
    LitteraleCalculable& ref = *res;
    return ref;
}

// ----- Multiplication ---
LitteraleCalculable& Rationnel::mult(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Rationnel * Entier
        LitteraleCalculable& ref = ptEntier->mult(*this);
        return ref;
    }
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

        if (ptRationnel != 0){
            // Rationnel * Rationnel
            Entier n = Entier((num->getValue() * ptRationnel->getNum().getValue()));
            Entier d = Entier(den->getValue() * ptRationnel->getDen().getValue());
            Rationnel* res = new Rationnel(n,d);

           // res->simplifier();
            LitteraleCalculable& ref = *res;
            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);

            if (ptReel != 0){
                //Rationnel * Reel
                LitteraleCalculable& ref = ptReel->diff(*this);
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Rationnel * Expression
                        LitteraleCalculable& ref = ptExpression->mult(*this);
                        return ref;
                   }else{
                    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&l);

                        if (ptComplexe!=0){
                                // Rationnel * Complexe
                                LitteraleCalculable& ref = ptExpression->mult(*this);
                                return ref;
                           }
                  }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Rationnel* res = new Rationnel(0,1);
    LitteraleCalculable& ref = *res;
    return ref;
}

// ----- Division ---
LitteraleCalculable& Rationnel::quotient(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Rationnel / Entier
        Entier n = (num->getValue());
        Entier d = (den->getValue() * ptEntier->getValue());
        Rationnel* res = new Rationnel(n, d);

       // res->simplifier();
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

        if (ptRationnel != 0){
            // Rationnel / Rationnel
            Entier n = Entier((num->getValue() * ptRationnel->getDen().getValue()));
            Entier d = Entier(den->getValue() * ptRationnel->getNum().getValue());


            int type = simplifier(n,d);

            if (type == 0){//non simplifiable
                Rationnel* res = new Rationnel(n, d);

                LitteraleCalculable& ref = *res;
                return ref;
            }
            if (type == 1) {
                Entier* res = new Entier(n.getValue() / d.getValue());
                LitteraleCalculable& ref = *res;
                return ref;
            }

//            LitteraleCalculable& ref = *res;
//            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);

            if (ptReel != 0){
                //Rationnel / Reel
                Reel* res = new Reel(num->getValue() /(den->getValue() * ptReel->getValue()));
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                const Expression* ptExpression=dynamic_cast<const Expression*>(&l);
                if (ptExpression!=0){
                        // Rationnel / Expression
                        LitteraleCalculable& ref = ptExpression->quotient(*this);
                        return ref;
                   }
            }
        }
    }
    throw CalcException("le type de l'argument 2 n'est pas reconnu");
    Rationnel* res = new Rationnel(0,1);
    LitteraleCalculable& ref = *res;
    return ref;
}

//---------------Operations unaires -------------

LitteraleCalculable& Rationnel::oppose()const{
    Entier n = (- num->getValue());
    Entier d = (den->getValue());
    Rationnel* res = new Rationnel(n, d);

    LitteraleCalculable& ref = *res;
    return ref;
}

//--- re ---
const LitteraleCalculable& Rationnel::partieReel() const {

    const Rationnel* res = this;
    const LitteraleCalculable& ref = *res;
    return ref;
}

//--- im ---
const LitteraleCalculable& Rationnel::partieIm() const {

    Entier* res = new Entier();
    const LitteraleCalculable& ref = *res;
    return ref;
}
