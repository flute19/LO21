#include "controleur.h"

void Controleur::commande(const QString& c){

    switch (estUnNombre(c)){
        case 0:
            litAff.push(litMng.addLitterale(c));
            break;
        case 1:
            litAff.push(litMng.addLitterale(c));
            break;
        case 2:
           //if(c[0]==QChar('\'') && c[c.size()]==QChar('\'')){
                litAff.push(litMng.addLitterale(c));
           // }
        break;
        case -1:
        if (estUnOperateur(c)){
            int type = getArite(c);

            switch (type){
                case 2:
                    if (litAff.taille()>=2) {

                        Litterale& v2 = litAff.top();
                        litMng.removeLitterale(litAff.top());
                        litAff.pop();
                        LitteraleCalculable& val2 = dynamic_cast<LitteraleCalculable&>(v2);


                        Litterale& v1 = litAff.top();
                        litMng.removeLitterale(litAff.top());
                        litAff.pop();
                        LitteraleCalculable& val1 = dynamic_cast<LitteraleCalculable&>(v1);

                        if (c == "+"){
                           LitteraleCalculable& res = val1 + val2;

                           Litterale& e = litMng.addLitterale(res.toString());
                           litAff.push(e);
                        }
                        if (c == "-") {
                            LitteraleCalculable& res = val1 - val2;

                            Litterale& e = litMng.addLitterale(res.toString());
                            litAff.push(e);
                        }
                        if (c=="*") {
                            LitteraleCalculable& res = val1 * val2;

                            Litterale& e = litMng.addLitterale(res.toString());
                            litAff.push(e);
                        }
                        if (c == "/") {
                                LitteraleCalculable& res = val1 / val2;

                                Litterale& e = litMng.addLitterale(res.toString());
                                litAff.push(e);

                            }                                        
                    } else{
                                litAff.setMessage("Erreur : pas assez d'arguments");
                            }
                break;

                case 1:
                    if (litAff.taille()>=1) {

                        Litterale& v1 = litAff.top();
                        litMng.removeLitterale(litAff.top());
                        litAff.pop();
                        LitteraleCalculable& val1 = dynamic_cast<LitteraleCalculable&>(v1);

                        if (c == "NEG"){

                            LitteraleCalculable& res = val1.neg();
                            Litterale& e = litMng.addLitterale(res.toString());
                            litAff.push(e);
                        }

                    }else{
                        litAff.setMessage("Erreur : pas assez d'arguments");
                    }
                break;

                default: break;
               }
        }else{
                litAff.setMessage("Erreur: Commande inconnue");
            }

        default: break;

        }
    }


int getArite(QString c){
    if (c == "+" || c == "-" || c == "*" || c == "/"){
        return 2;
    }
    if (c == "NEG"){
        return 1;
    }
    return 0;
}

bool estUnOperateur(const QString s){
    if (s == "+") return true;
    if (s == "-") return true;
    if (s == "*") return true;
    if (s == "/") return true;
    if (s == "NEG") return true;

    return false;
}

int estUnNombre(const QString s){


   bool ok = false;
  // QRegExp rx("[/]"); //rationnel


   if(s.toInt(&ok) || s == "0") return 0;
   if(s.toFloat(&ok)) return 1;
  // if(s.contains(&rx)) return 2;


   return -1;
}

