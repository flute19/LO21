#include "controleur.h"

void Controleur::commande(const QString& c){
    if (estUnNombre(c)){
        litAff.push(litMng.addLitterale(c.toInt()));
    }else{
        if (estUnOperateur(c)){
            int type = getArite(c);

            switch (type){
                case 2:
                    if (litAff.taille()>=2) {

                        Litterale& v2 = litAff.top();
                        litMng.removeLitterale(litAff.top());
                        litAff.pop();
                        const LitteraleCalculable& val2 = dynamic_cast<const LitteraleCalculable&>(v2);


                        Litterale& v1 = litAff.top();
                        litMng.removeLitterale(litAff.top());
                        litAff.pop();
                        LitteraleCalculable& val1 = dynamic_cast<LitteraleCalculable&>(v1);

                        LitteraleCalculable* res;
                        if (c=="+") *res = val1+val2;


                        LitteraleCalculable& ref = *res;
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
                    }else{
                        litAff.setMessage("Erreur : pas assez d'arguments");
                    }
                break;
                case 1:if (litAff.taille()>=1) {
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
                                }else{
                                    litAff.setMessage("Erreur : pas assez d'arguments");
                                }
                break;
            }
        }else litAff.setMessage("Erreur : commande inconnue");
    }
}

int getArite(QString c){
    if (c == "+" || c == "-" || c == "*" || c == "/"){
        return 2;
    }
    return 0;
}

