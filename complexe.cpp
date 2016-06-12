#include "complexe.h"

//------------------ Constructeur------------------
Complexe::Complexe(const NonComplexe& l1, const NonComplexe& l2){

    // re initialisation
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l1);

    if (ptEntier != 0){
                re = new Entier(ptEntier->getValue());
    }else{
        const Rationnel* ptRa = dynamic_cast<const Rationnel*>(&l1);

        if(ptRa != 0){
            re = new Rationnel(ptRa->getNum().getValue(), ptRa->getDen().getValue());
        }else{
            const Reel* ptRe = dynamic_cast<const Reel*>(&l1);

            if(ptRe != 0){
                re = new Reel(ptRe->getValue());
            }else{re = new Entier();}
        }
    }

    // im initialisation
    const Entier* ptEntier2 = dynamic_cast<const Entier*>(&l2);

    if (ptEntier2 != 0){
                im = new Entier(ptEntier2->getValue());
    }else{
        const Rationnel* ptRa2 = dynamic_cast<const Rationnel*>(&l2);

        if(ptRa2 != 0){
            im = new Rationnel(ptRa2->getNum().getValue(), ptRa2->getDen().getValue());
        }else{
            const Reel* ptRe2 = dynamic_cast<const Reel*>(&l2);

            if(ptRe2 != 0){
                im = new Reel(ptRe2->getValue());
            }else{im = new Entier();}
        }
    }
}

//---------------------------- Affichage ----------------------------------
QString Complexe::toString() const {
    QString s;

    QString sre;
    const Entier* ptEn = dynamic_cast<const Entier*>(this->re);

    if(ptEn !=0){
       sre = ptEn->Entier::toString();
   }else{
        const Reel* ptRe = dynamic_cast<const Reel*>(this->re);

        if(ptRe !=0){
           sre = ptRe->Reel::toString();
        }else{
             const Rationnel* ptRa = dynamic_cast<const Rationnel*>(this->re);

            if(ptRa !=0){
               sre = ptRa->Rationnel::toString();
            }
        }
    }
    s = sre;
    s.append("$");

    QString sim;
    const Entier* ptEn2 = dynamic_cast<const Entier*>(this->im);

    if(ptEn2 !=0){
       sim = ptEn2->Entier::toString();
   }else{
        const Reel* ptRe2 = dynamic_cast<const Reel*>(this->im);

        if(ptRe2 !=0){
           sim = ptRe2->Reel::toString();
        }else{
             const Rationnel* ptRa2 = dynamic_cast<const Rationnel*>(this->im);

            if(ptRa2 !=0){
               sim = ptRa2->Rationnel::toString();
            }
        }
    }

   s.append(sim);
   return s;
}

//-------------------- Operateur binaire --------------------

LitteraleCalculable& Complexe::addition(const LitteraleCalculable &l) const{
    const Entier* ptEntier = dynamic_cast<const Entier*>(&l);

    if (ptEntier != 0){
        // Complexe + Entier
        const Entier& v = *ptEntier;
        const NonComplexe& r = dynamic_cast <const NonComplexe&> (v.addition(*re));
        Complexe* res = new Complexe(r, *im);
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
        const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&l);

        if (ptRationnel!= 0){
            // Complexe + Rationnel
            const Rationnel& v = *ptRationnel;
            const NonComplexe& r = dynamic_cast <const NonComplexe&> (v.addition(*re));

           Complexe* res = new Complexe(r,*im);

            LitteraleCalculable& ref = *res;
            return ref;
        }
        else {
            const Reel* ptReel = dynamic_cast<const Reel*>(&l);

            if (ptReel!=0){
                // Complexe + Reel
                const Reel& v = *ptReel;
                const NonComplexe& r = dynamic_cast <const NonComplexe&> (v.addition(*re));

                Complexe* res = new Complexe(r, *im);
                LitteraleCalculable& ref = *res;
                return ref;
            }else{
                // Complexe + Complexe
                const Complexe* ptCo = dynamic_cast<const Complexe*>(&l);

                if(ptCo != 0){
                    const Entier& v = *ptEntier;
                    const NonComplexe& r = dynamic_cast <const NonComplexe&> (v.addition(*re));

                    const NonComplexe& r2 = ptCo->getRe();
                    const Entier* ptEntier2 = dynamic_cast<const Entier*>(&r2);

                    if (ptEntier2 != 0){
                        // Complexe + Entier en partie reelle

                        const NonComplexe& r31 = ptCo->getIm();
                        const Entier* ptEntier3 = dynamic_cast<const Entier*>(&r31);

                        if (ptEntier3 != 0){//entier en partie imaginaire

                            const Entier& v1 = *ptEntier2;
                            const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                            const Entier& v2 = *ptEntier3;
                            const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                            Complexe* res = new Complexe(r, i);
                            LitteraleCalculable& ref = *res;
                            return ref;
                        }
                        const NonComplexe& r32 = ptCo->getIm();
                        const Reel* ptRe3 = dynamic_cast<const Reel*>(&r32);

                        if (ptRe3 != 0){//reel en partie imaginaire

                            const Entier& v1 = *ptEntier2;
                            const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                            const Reel& v2 = *ptRe3;
                            const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                            Complexe* res = new Complexe(r, i);
                            LitteraleCalculable& ref = *res;
                            return ref;
                        }
                        const NonComplexe& r33 = ptCo->getIm();
                        const Rationnel* ptRa3 = dynamic_cast<const Rationnel*>(&r33);

                        if (ptRa3 != 0){//rationnel en partie imaginaire

                            const Entier& v1 = *ptEntier2;
                            const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                            const Rationnel& v2 = *ptRa3;
                            const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                            Complexe* res = new Complexe(r, i);
                            LitteraleCalculable& ref = *res;
                            return ref;
                        }
                    }
                    else{
                        const NonComplexe& r2 = ptCo->getRe();
                        const Rationnel* ptRationnel2 = dynamic_cast<const Rationnel*>(&r2);

                        if (ptRationnel2!= 0){
                            // Complexe + Rationnel en partie reelle

                            const NonComplexe& r31 = ptCo->getIm();
                            const Entier* ptEntier3 = dynamic_cast<const Entier*>(&r31);
                            if (ptEntier3 != 0){//entier en partie imaginaire

                                const Rationnel& v1 = *ptRationnel2;
                                const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                                const Entier& v2 = *ptEntier3;
                                const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                                Complexe* res = new Complexe(r, i);

                                LitteraleCalculable& ref = *res;
                                return ref;
                            }
                            const NonComplexe& r32 = ptCo->getIm();
                            const Reel* ptRe3 = dynamic_cast<const Reel*>(&r32);
                            if (ptRe3 != 0){//reel en partie imaginaire

                                const Rationnel& v1 = *ptRationnel2;
                                const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                                const Reel& v2 = *ptRe3;
                                const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                                Complexe* res = new Complexe(r, i);
                                LitteraleCalculable& ref = *res;
                                return ref;
                            }
                            const NonComplexe& r33 = ptCo->getIm();
                            const Rationnel* ptRa3 = dynamic_cast<const Rationnel*>(&r33);

                            if (ptRa3 != 0){//rationnel en partie imaginaire

                                const Rationnel& v1 = *ptRationnel2;
                                const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                                const Rationnel& v2 = *ptRa3;
                                const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                                Complexe* res = new Complexe(r, i);
                                LitteraleCalculable& ref = *res;
                                return ref;
                           }
                        }else {
                            const NonComplexe& r2 = ptCo->getRe();
                            const Reel* ptReel2 = dynamic_cast<const Reel*>(&r2);

                            if (ptReel2 != 0){
                                // Complexe + Reel en partie reelle


                                const NonComplexe& r31 = ptCo->getIm();
                                const Entier* ptEntier3 = dynamic_cast<const Entier*>(&r31);
                                if (ptEntier3 != 0){//entier en partie imaginaire

                                    const Reel& v1 = *ptReel2;
                                    const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                                    const Entier& v2 = *ptEntier3;
                                    const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                                    Complexe* res = new Complexe(r, i);
                                    LitteraleCalculable& ref = *res;
                                    return ref;
                                }
                                const NonComplexe& r32 = ptCo->getIm();
                                const Reel* ptRe3 = dynamic_cast<const Reel*>(&r32);

                                if (ptRe3 != 0){//reel en partie imaginaire

                                    const Reel& v1 = *ptReel2;
                                    const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                                    const Reel& v2 = *ptRe3;
                                    const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                                    Complexe* res = new Complexe(r, i);
                                    LitteraleCalculable& ref = *res;
                                    return ref;
                                }
                                const NonComplexe& r33 = ptCo->getIm();
                                const Rationnel* ptRa3 = dynamic_cast<const Rationnel*>(&r33);

                                if (ptRa3 != 0){//rationnel en partie imaginaire

                                    const Reel& v1 = *ptReel2;
                                    const NonComplexe& r = dynamic_cast <const NonComplexe&> (v1.addition(*re));

                                    const Rationnel& v2 = *ptRa3;
                                    const NonComplexe& i = dynamic_cast <const NonComplexe&> (v2.addition(*im));

                                    Complexe* res = new Complexe(r, i);
                                    LitteraleCalculable& ref = *res;
                                    return ref;
                               }
                            }
                        }
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

//--- Soustraction
LitteraleCalculable& Complexe::diff(const LitteraleCalculable &l) const{
    Entier* res = new Entier();
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Complexe::mult(const LitteraleCalculable &l) const{
    Entier* res = new Entier();
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Complexe::quotient(const LitteraleCalculable &l) const{
    Entier* res = new Entier();
    LitteraleCalculable& ref = *res;
    return ref;
}


//------------------- Operateur unaire ----------------------
//operations unaires
LitteraleCalculable& Complexe::oppose() const{

    Entier* res = new Entier();
    LitteraleCalculable& ref = *res;
    return ref;

}





