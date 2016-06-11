#include "controleur.h"

void Controleur::commande(const QString& c){

    switch (estUnNombre(c)){
        case 0:
            litAff.push(litMng.addLitterale(c.toInt()));
            break;
        case 1:
            litAff.push(litMng.addLitterale(c.toFloat()));
            break;
        case -1:
//        if (estUnOperateur(c)){
//            int type = getArite(c);

//            switch (type){
//                case 2:
//                    if (litAff.taille()>=2) {

//                        Litterale& v2 = litAff.top();
//                        litMng.removeLitterale(litAff.top());
//                        litAff.pop();
//                        const LitteraleCalculable& val2 = dynamic_cast<const LitteraleCalculable&>(v2);


//                        Litterale& v1 = litAff.top();
//                        litMng.removeLitterale(litAff.top());
//                        litAff.pop();
//                        LitteraleCalculable& val1 = dynamic_cast<LitteraleCalculable&>(v1);

//                        LitteraleCalculable* res;
//                        if (c == "+") *res = val1 + val2;


//                        Litterale& ref = *res;
        //                if (c=="-") res=v1-v2;
        //                if (c=="*") res=v1*v2;
        //                if (c=="/") {
        //                    if (v2!=0) res=v1/v2;
        //                    else {
        //                        litAff.setMessage("Erreur : division par zéro");
        //                        res=v1;
        //                    }
        //                }
                      //  Litterale& e = litMng.addLitterale(res);
        //                litAff.push(e);
//                    }else{
//                        litAff.setMessage("Erreur : pas assez d'arguments");
//                    }
//                break;
//                case 1:if (litAff.taille()>=1) {
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
//                                }else{
//                                    litAff.setMessage("Erreur : pas assez d'arguments");
//                                }
//                break;
//            }
//        }else litAff.setMessage("Erreur : commande inconnue");

    default: break;
    }
}

int getArite(QString c){
    if (c == "+" || c == "-" || c == "*" || c == "/"){
        return 2;
    }
    return 0;
}

bool estUnOperateur(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    return false;
}

int estUnNombre(const QString s){
   bool ok = false;

   if(s.toInt(&ok)) return 0;
   if(s.toFloat(&ok)) return 1;

   return -1;
}

