#include "controleur.h"

void Controleur::commande(const QString& s){
    if(estUnNombre(s)==5 || estUnNombre(s)==6 || estUnNombre(s)==3 || estUnNombre(s)==10){ //Expression, Programme ou Atome
        if (estUnNombre(s)==6){ //Programme
            Programme* prog= new Programme(s);
            QStringList listeLitterales=prog->eval();
            QStringList::iterator it=listeLitterales.begin();
            while (it!=listeLitterales.end()){
                commande(QString(*it));
                it++;
            }
        }
        else if(estUnNombre(s)==5){ //Création d'atome
            QStringList str=s.split(' ');
            if (estUnOperateur(str[2])) litAff.setMessage("Le nom de la variable ne peut pas être un opérateur");
            else {
                if(str[2]==str[1])litAff.setMessage("Un atome ne peut pas se contenir lui même");
                else {
                    litAff.setMessage("Variable "+str[2]+"->"+str[1]);
                    Litterale* value= &litMng.addLitterale(str[1]);
                    if(atMng.existe(str[2])) atMng.getAtome(str[2]).setValue(value);
                    else atMng.addAtome(str[2], value);

                }

            }
        }
        else if(estUnNombre(s)==3){ // Expression
            QString expr=s;
            expr.remove(" ");
            litAff.push(litMng.addLitterale(expr));
        }
        else litAff.setMessage("Format invalide");
    }
    else{
    //traitement opérande par opérande
    QStringList saisie = s.split(" ");

    for(int i = 0; i < saisie.size(); i++){
        QString c = saisie.at(i);

        switch (estUnNombre(c)){
            case 0:
                litAff.push(litMng.addLitterale(c));
            break;
            case 1:
                litAff.push(litMng.addLitterale(c));
                break;
            case 2:
                litAff.push(litMng.addLitterale(c));
                break;
            case 4:
                litAff.push(litMng.addLitterale(c));
                break;
            case 7:
                if(atMng.existe(c))
                litAff.push(atMng.getAtome(c));
                else
                    litAff.setMessage("Tentative d'ajout d'un Atome non déclaré dans la pile");
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

//                                    bool ok = checkDiv(val2);
//                                    if(ok) litAff.setMessage("ok");
//                                    if(ok){
                                        LitteraleCalculable& res = val1 / val2;

                                        Litterale& e = litMng.addLitterale(res.toString());
//                                        litAff.pop();
//                                        litAff.pop();
                                        litAff.push(e);
//                                    }else litAff.setMessage("erreur : division par 0 impossible");

                                }
                            if (c == "MOD") {//s'applique uniquement aux entiers

                                Entier* v1 = dynamic_cast<Entier*>(&val1);
                                Entier* v2 = dynamic_cast<Entier*>(&val2);

                                if(v1 !=0 && v2 != 0){//entiers ok
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
                                Entier* v1 = dynamic_cast<Entier*>(&val1);
                                Entier* v2 = dynamic_cast<Entier*>(&val2);

                                if(v1 !=0 && v2 != 0){//entiers ok
                                    Entier& va1 = dynamic_cast<Entier&>(val1);
                                    Entier& va2 = dynamic_cast<Entier&>(val2);

                                    Entier& res = va1.div(va2);

                                    Litterale& e = litMng.addLitterale(res.toString());
                                    litAff.push(e);
                                }else{
                                    litAff.setMessage("erreur de type. Doit etre un entier.");
                                }

                            }
                            if (c == "$") {
                                    NonComplexe& va1 = dynamic_cast<NonComplexe&>(val1);
                                    NonComplexe& va2 = dynamic_cast<NonComplexe&>(val2);

                                    Complexe* res = new Complexe(va1, va2);
                                    Litterale& e = litMng.addLitterale(res->Complexe::toString());
                                    litAff.push(e);
                                }
                            litMng.removeLitterale(v1);
                            litMng.removeLitterale(v2);

                        }else{
                                    litAff.setMessage("Erreur : pas assez d'arguments");
                                }
                    break;

                    case 1:
                        if (litAff.taille()>=1) {
                            int test=0;
                            Litterale& v1 = litAff.top();

                            if (c == "NEG"){

                                LitteraleCalculable& val1 = dynamic_cast<LitteraleCalculable&>(v1);
                                litAff.pop();
                                LitteraleCalculable& res = val1.neg();
                                Litterale& e = litMng.addLitterale(res.toString());
                                litAff.push(e);
                            }
                            if (c == "RE"){

                                LitteraleCalculable& val1 = dynamic_cast<LitteraleCalculable&>(v1);
                                litAff.pop();
                                const LitteraleCalculable& res = val1.partieReel();
                                Litterale& e = litMng.addLitterale(res.toString());
                                litAff.push(e);
                            }
                            if (c == "IM"){

                                LitteraleCalculable& val1 = dynamic_cast<LitteraleCalculable&>(v1);
                                litAff.pop();
                                const LitteraleCalculable& res = val1.partieIm();
                                Litterale& e = litMng.addLitterale(res.toString());
                                //litAff.pop();
                                litAff.push(e);
                            }
                            if (c == "EVAL"){
                                if(estUnNombre(v1.toString())==3){
                                    Expression* exp=dynamic_cast<Expression*>(&v1);
                                        litAff.pop();
                                        Litterale& e = litMng.addLitterale(exp->eval());
                                        litAff.push(e);
                                }
                                else {
                                    if(estUnNombre(v1.toString())==7){
                                        Atome* at=dynamic_cast<Atome*>(&v1);
                                        litAff.pop();
                                        litAff.push(*at->getValue());
                                    }
                                    else{
                                        litAff.setMessage("Erreur, Litterale non expression ni atome");
                                        test=1;
                                    }
                                }
                            }
                            if (test == 0)
                                litMng.removeLitterale(v1);
                        }else{
                            litAff.setMessage("Erreur : pas assez d'arguments");
                        }
                    break;

                    default:
                    litAff.setMessage("Erreur: Commande inconnue");
                    break;
                   }
            }
            else{litAff.setMessage("Erreur: Commande inconnue");}
            default:
            break;
        }

    }

    }
}


int getArite(QString c){
    if (c == "+" || c == "-" || c == "*" || c == "/" || c == "DIV" || c == "MOD"
            || c == "$"){
        return 2;
    }
    if (c == "NEG" || c == "EVAL" || c == "RE" || c == "IM"){
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
    if (s == "RE") return true;
    if (s == "IM") return true;

    return false;
}

int estUnNombre(const QString s){


   bool ok = false;

   if(s.toInt(&ok) || s == "0") return 0;
   if(s.toDouble(&ok)) return 1;
   if(s.contains(QRegExp("^'([^']+)'$"))&& !s.contains(QRegExp("([0-9\\+\\-\\(\\*/\\'][a-z]+)"))) return 3; //Expression au dessus de 2 car '4/3' évalué comme un rationnel
   if(s.contains(QRegExp("^(STO)\\s([a-zA-Z0-9\\.\\$/]+)\\s([A-Z])([a-zA-Z0-9]*)$"))) return 5;//Création d'atome
   if(s.contains(QRegExp("^([A-Z])([a-zA-Z0-9]*)$")) && !estUnOperateur(s)) return 7; // Il peut s'agir d'un atome
   if(s.contains(QRegExp("^(STO)"))) return 10;
   if(s.contains(QRegExp("^\\[(.+)\\]$"))) return 6; // Programme
   if(s.contains(QRegExp("([0-9]+)/([0-9]+)"))) return 2;//rationnel

   if(s.contains(QRegExp("([0-9]+)\\$([0-9]+)"))) return 4;//complexe

   return -1;
}

bool checkDiv(const LitteraleCalculable& val2){

    const Entier* ptEntier = dynamic_cast<const Entier*>(&val2) ;

    if(ptEntier->getValue() == 0) return false;
    else{
        const Rationnel* ptRa = dynamic_cast<const Rationnel*>(&val2) ;

        if(ptRa->getNum().getValue() == 0) return false;
        else{
            const Reel* ptReel = dynamic_cast<const Reel*>(&val2) ;

            if(ptReel->getValue() == 0) return false;
            else{
                const Complexe* ptCo = dynamic_cast<const Complexe*>(&val2) ;

                const Entier* ptEn2 = dynamic_cast<const Entier*>(&ptCo->getRe()) ;
                const Rationnel* ptRa2 = dynamic_cast<const Rationnel*>(&ptCo->getRe()) ;
                const Reel* ptRe2 = dynamic_cast<const Reel*>(&ptCo->getRe()) ;

                if(ptEn2 != 0 && ptEn2->getValue() == 0) return false;
                if(ptRe2 != 0 && ptRe2->getValue() == 0) return false;
                if(ptRa2 != 0 && ptRa2->getNum().getValue() == 0) return false;
            }
        }
    }
    return true;
}
