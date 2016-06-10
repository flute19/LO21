#include "controleur.h"

void Controleur::commande(const QString& c){
    if (estUnNombre(c)){
        litAff.push(litMng.addLitterale(c.toInt()));
    }//else{

//        if (estUnOperateur(c)){
//            if (litAff.taille()>=2) {
//                Litterale v2=litAff.top().toString();
//                litMng.removeLitterale(litAff.top());
//                litAff.pop();
//                Litterale v1=litAff.top().toString();
//                litMng.removeLitterale(litAff.top());
//                litAff.pop();
//                int res;
//                if (c=="+") res=v1+v2;
//                if (c=="-") res=v1-v2;
//                if (c=="*") res=v1*v2;
//                if (c=="/") {
//                    if (v2!=0) res=v1/v2;
//                    else {
//                        litAff.setMessage("Erreur : division par zéro");
//                        res=v1;
//                    }
//                }
//                Litterale& e=litMng.addLitterale(res);
//                litAff.push(e);
//            }else{
//                litAff.setMessage("Erreur : pas assez d'arguments");
//            }
//        }else litAff.setMessage("Erreur : commande inconnue");
//    }
}
