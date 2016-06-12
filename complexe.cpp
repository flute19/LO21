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

