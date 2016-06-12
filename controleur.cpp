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
        case 3:
            litAff.push(litMng.addLitterale(c));
            break;
        case -1:
        if (estUnOperateur(c)){
            int type = getArite(c);

            switch (type){
                case 2:
                    if (litAff.taille()>=2) {

                        Litterale& v2 = litAff.top();
                        litAff.pop();
                        LitteraleCalculable& val2 = dynamic_cast<LitteraleCalculable&>(v2);


                        Litterale& v1 = litAff.top();
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
                        if (c == "MOD") {
                            bool ok = true;
                            if(ok//val1.toString.toInt(&ok)
                                    ){

                                Entier& va1 = dynamic_cast<Entier&>(val1);
                                Entier& va2 = dynamic_cast<Entier&>(val2);


                                Entier& res = va1.mod(va2);

                                Litterale& e = litMng.addLitterale(res.toString());
                                litAff.push(e);
                            }else{
                                litAff.setMessage("erreur de type. Doit etre un entier.");
                            }
                        }
                        if (c == "DIV") {
                            bool ok = true;
                            if(ok//val1.toString.toInt(&ok)
                                    ){

                                Entier& va1 = dynamic_cast<Entier&>(val1);
                                Entier& va2 = dynamic_cast<Entier&>(val2);


                                Entier& res = va1.div(va2);

                                Litterale& e = litMng.addLitterale(res.toString());
                                litAff.push(e);
                            }else{ litAff.setMessage("erreur de type. Doit etre un entier.");}

                        }
//                        if (c == "$") {
//                                NonComplexe& va1 = dynamic_cast<NonComplexe&>(val1);
//                                NonComplexe& va2 = dynamic_cast<NonComplexe&>(val2);


//                                Complexe* res = new Complexe(va1, va2);

//                                Litterale& e = litMng.addLitterale(res.toString());
//                                litAff.push(e);
//                            }else{
//                                litAff.setMessage("erreur de type. Doit etre un entier.");
//                            }
//                        }
                    litMng.removeLitterale(v1);
                    litMng.removeLitterale(v2);

                    } else{
                                litAff.setMessage("Erreur : pas assez d'arguments");
                            }
                break;

                case 1:
                    if (litAff.taille()>=1) {

                        Litterale& v1 = litAff.top();
                        LitteraleCalculable& val1 = dynamic_cast<LitteraleCalculable&>(v1);

                        if (c == "NEG"){

                            litAff.pop();
                            LitteraleCalculable& res = val1.neg();
                            Litterale& e = litMng.addLitterale(res.toString());
                            litAff.push(e);
                        }
                        if (c == "EVAL"){
                            Expression& exp = dynamic_cast<Expression&>(v1);
                                    if (!(exp.getValue().contains(QRegExp("^'([^']+)'$")))) litAff.setMessage("Erreur, Litterale non expression");
                                    else{
                                        litAff.pop();
                                        Litterale& e = litMng.addLitterale(exp.eval());
                                        litAff.push(e);
                                    }
                        }
                        litMng.removeLitterale(litAff.top());

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
    if (c == "+" || c == "-" || c == "*" || c == "/" || c == "DIV" || c == "MOD"
            || c == "$"){
        return 2;
    }
    if (c == "NEG" || c == "EVAL"){
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
    if (s == "DIV") return true;
    if (s == "MOD") return true;
    if (s == "EVAL") return true;
    if (s == "$") return true;


    return false;
}

int estUnNombre(const QString s){


   bool ok = false;
  // QRegExp rx("[/]"); //rationnel

   if(s.toInt(&ok) || s == "0") return 0;
   if(s.toFloat(&ok)) return 1;
  // if(s.contains(&rx)) return 2;
   if(s.contains(QRegExp("^'([^']+)'$"))) return 3;


   return -1;
}

