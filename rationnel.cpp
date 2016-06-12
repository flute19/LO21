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
        const Rationnel* ptRationnel=dynamic_cast<const Rationnel*>(&l);
        if (ptRationnel!=0){
            // Rationnel + Rationnel
            Entier n= Entier((num->getValue()*ptRationnel->getDen().getValue())+(den->getValue()*ptRationnel->getNum().getValue()));
            Entier d= Entier(den->getValue()*ptRationnel->getDen().getValue());
            Rationnel* res= new Rationnel(n,d);

            res->simplifier();
            LitteraleCalculable& ref =*res;
            return ref;
        }
        else {
            const Reel* ptReel=dynamic_cast<const Reel*>(&l);
            if (ptReel!=0){
                //Rationnel + Reel
                LitteraleCalculable& ref = ptReel->addition(*this);
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Rationnel* res = new Rationnel(0,1);
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
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

            res->simplifier();
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
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Rationnel* res = new Rationnel(0,1);
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
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

            res->simplifier();
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
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Rationnel* res = new Rationnel(0,1);
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}

// ----- Division ---
LitteraleCalculable& Rationnel::quotient(const LitteraleCalculable& l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Rationnel / Entier
        Entier n = (num->getValue());
        Entier d = (den->getValue() * ptEntier->getValue());
        Rationnel* res = new Rationnel(n, d);

        res->simplifier();
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

        if (ptRationnel != 0){
            // Rationnel / Rationnel
            Entier n = Entier((num->getValue() * ptRationnel->getDen().getValue()));
            Entier d = Entier(den->getValue() * ptRationnel->getDen().getValue());
            Rationnel* res = new Rationnel(n,d);

            res->simplifier();
            LitteraleCalculable& ref = *res;
            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);

            if (ptReel != 0){
                //Rationnel / Reel
                Reel* res = new Reel(num->getValue() /(den->getValue() * ptReel->getValue()));
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                throw CalcException("le type de l'argument 2 n'est pas reconnu");
                Rationnel* res = new Rationnel(0,1);
                LitteraleCalculable& ref = *res;
                return ref;
            }
        }
    }
}

//---------------Operations unaires -------------

LitteraleCalculable& Rationnel::oppose()const{
    Entier n = (- num->getValue());
    Entier d = (den->getValue());
    Rationnel* res = new Rationnel(n, d);

    LitteraleCalculable& ref = *res;
    return ref;
}

// -------------- Simplification ----------------
Entier pgcd(const Entier& a, const Entier& b){
        Entier x(a.getValue());
        Entier y(b.getValue());
        if ((y.getValue())==0){
            return x;
        }
        else {
            return pgcd(Entier(y.getValue()),Entier(x.getValue() % y.getValue()));
        }
}

void Rationnel::simplifier() {
   //     Entier pgcd = pgcd(getNum(),getDen());
  //      num=num/pgcd;
 //       den=den/pgcd;
}
