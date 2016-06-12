#include "expression.h"


QString Expression::eval() const {
    if (value.contains(QRegExp("([a-zA-Z]+)"))){
        return value;
    }
    else{

        // On sépare les éléments de l'expression en enlevant les espaces
        /*QStringList listeLitterales = value.split(" ");
        QStringList::iterator it;
        Pile *pile = new Pile();
        for (it=listeLitterales.begin();it!=listeLitterales.end();it++){
           Controleur *controleur = new Controleur(LitteraleManager::getInstance(),*pile);
           controleur->commande(QString(*it));*/

        QString expr=value;
        expr[0]='(';
        expr[expr.size()]=')';
        expr=InfixToPostfix(expr);
        QStringList listeLitterales = expr.split(" ");
        QStringList::iterator it=listeLitterales.begin();
        Pile *pile= new Pile();
        Controleur *controleur = new Controleur(LitteraleManager::getInstance(),*pile);
        while (it!=listeLitterales.end()){
            controleur->commande(QString(*it));
            it++;
        }
        QString res=pile->top().toString();

        return res;
            }
    return "'erreur'";
}
QString InfixToPostfix(QString exp){
    QStack<QChar> S;
    QString postfix="";
    for (int i=0;i<exp.length();i++){
        if (exp[i]==' ' || exp[i]==',') continue;
        else
            if(estUnOperateur(QString(exp[i]))){
            while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),exp[i]))
            {
                postfix+= ' '+S.top();
                S.pop();
            }
            S.push(exp[i]);
            }
            else
                if (estUnNombre(QString(exp[i]))==0 || estUnNombre(QString(exp[i]))==1){
                    postfix+= exp[i];
                    if (!(estUnNombre(QString(exp[i+1]))==0 || estUnNombre(QString(exp[i+1]))==1))
                        postfix+= ' ';
                }
                else
                    if (exp[i] == '('){
                        S.push(exp[i]);
                    }

                    else
                        if(exp[i] == ')'){
                            while(!S.empty() && S.top() !=  '(') {
                                postfix += ' '+S.top();
                                S.pop();
                            }
                            S.pop();
                        }
                        //else (throw CalcException("Eval d'une expression non évaluable"));
        }

        while(!S.empty()) {
                postfix += ' '+S.top();
                S.pop();
        }

        return postfix;
}

int GetOperatorWeight(char op)
{
    int weight = -1;
    switch(op)
    {
    case '+':
    case '-':
        weight = 1;
    case '*':
    case '/':
        weight = 2;
    case '$':
        weight = 3;
    }
    return weight;
}

int HasHigherPrecedence(QChar op1, QChar op2)
{
    int op1Weight = GetOperatorWeight(op1.toLatin1());
    int op2Weight = GetOperatorWeight(op2.toLatin1());

    // If operators have equal precedence, return true if they are left associative.
    // if operator is left-associative, left one should be given priority.

    return op1Weight > op2Weight ?  true: false;
}


LitteraleCalculable& Expression::addition(const LitteraleCalculable& l)const{
    Expression* res = new Expression(getValue().remove(getValue().size()-1,1)+"+"+l.toString()+"'");
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Expression::diff(const LitteraleCalculable& l)const{
    Expression* res = new Expression(getValue().remove(getValue().size()-1,1)+"-"+l.toString()+"'");
    LitteraleCalculable& ref = *res;
    return ref;
}
LitteraleCalculable& Expression::mult(const LitteraleCalculable& l)const{
    Expression* res = new Expression("'("+getValue().remove(getValue().size()-1,1).remove(0,1)+")*"+l.toString()+"'");
    LitteraleCalculable& ref = *res;
    return ref;
}

LitteraleCalculable& Expression::quotient(const LitteraleCalculable& l)const{
    Expression* res = new Expression("'("+getValue().remove(getValue().size()-1,1).remove(0,1)+")/"+l.toString()+"'");

    LitteraleCalculable& ref = *res;
    return ref;
}

//------------- Operateur unaires ----------
LitteraleCalculable& Expression::oppose() const{
    QString s = "-("+value;
    s.append(")");

    Expression* res = new Expression(s);
    LitteraleCalculable& ref = *res;
    return ref;
}
