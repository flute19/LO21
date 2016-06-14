#include "expression.h"


QString Expression::eval() const {
    if (value.contains(QRegExp("([0-9\\+\\-\\(\\*/\\'][a-z]+)"))){
        return value;
    }
    else{

        QString expr=value;
        expr[0]='(';
        expr[expr.size()]=')';
        expr=InfixToPostfix(expr);
        QStringList listeLitterales = expr.split(" ");
        QStringList::iterator it=listeLitterales.begin();
        unsigned int i=0;
        Pile *stack= new Pile();
        Controleur *controleur = new Controleur(LitteraleManager::getInstance(),*stack,AtomeManager::getInstanceAtome());
        while (it!=listeLitterales.end()){
            controleur->commande(QString(*it));
            controleur->commande("EVAL");
            i++;
            it++;
        }
        QString res=stack->top().toString();

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
                if (estUnNombre(QString(exp[i]))==0 || estUnNombre(QString(exp[i]))==1 || estUnNombre(QString(exp[i]))==7||exp[i]=='.'){
                    postfix+= exp[i];
                    if (!(exp[i+1].isLetter()||estUnNombre(QString(exp[i+1]))==0)||exp[i+1]=='.')
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
        weight = 1;
        break;
    case '-':
        weight = 1;
        break;
    case '*':
        weight = 2;
        break;
    case '/':
        weight = 2;
        break;
    case '$':
        weight = 3;
        break;
    }
    return weight;
}

int HasHigherPrecedence(QChar op1, QChar op2)
{
    int op1Weight = GetOperatorWeight(op1.toLatin1());
    int op2Weight = GetOperatorWeight(op2.toLatin1());

    // If operators have equal precedence, return true if they are left associative.
    // if operator is left-associative, left one should be given priority.

    return op1Weight < op2Weight ?  true: false;
}


LitteraleCalculable& Expression::addition(const LitteraleCalculable& l)const{
    if(l.toString()[0]=='\''){
        Expression* res = new Expression(getValue().remove(getValue().size()-1,1)+"+"+l.toString().remove(0,1));
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
    Expression* res = new Expression(getValue().remove(getValue().size()-1,1)+"+"+l.toString()+"'");
    LitteraleCalculable& ref = *res;
    return ref;
    }
}
LitteraleCalculable& Expression::diff(const LitteraleCalculable& l)const{
    if(l.toString()[0]=='\''){
        Expression* res = new Expression(getValue().remove(getValue().size()-1,1)+"-"+l.toString().remove(0,1));
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
    Expression* res = new Expression(getValue().remove(getValue().size()-1,1)+"-"+l.toString()+"'");
    LitteraleCalculable& ref = *res;
    return ref;
    }
}
LitteraleCalculable& Expression::mult(const LitteraleCalculable& l)const{
    if(l.toString()[0]=='\''){
        Expression* res = new Expression("'("+getValue().remove(getValue().size()-1,1).remove(0,1)+")*("+l.toString().remove(l.toString().size()-1,1).remove(0,1)+")'");
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
    Expression* res = new Expression("'("+getValue().remove(getValue().size()-1,1).remove(0,1)+")*"+l.toString()+"'");
    LitteraleCalculable& ref = *res;
    return ref;
    }
}

LitteraleCalculable& Expression::quotient(const LitteraleCalculable& l)const{
    if(l.toString()[0]=='\''){
        Expression* res = new Expression("'("+getValue().remove(getValue().size()-1,1).remove(0,1)+")/("+l.toString().remove(l.toString().size()-1,1).remove(0,1)+")'");
        LitteraleCalculable& ref = *res;
        return ref;
    }
    else{
    Expression* res = new Expression("'("+getValue().remove(getValue().size()-1,1).remove(0,1)+")/"+l.toString()+"'");
    LitteraleCalculable& ref = *res;
    return ref;
    }
}

//------------- Operateur unaires ----------
//--- neg ---
LitteraleCalculable& Expression::oppose() const{
    QString s = "-("+value;
    s.append(")");

    Expression* res = new Expression(s);
    LitteraleCalculable& ref = *res;
    return ref;
}

//--- Re---
const LitteraleCalculable& Expression::partieReel() const {

    const Expression* res = this;
    const LitteraleCalculable& ref = *res;
    return ref;
}

//--- im ---
const LitteraleCalculable& Expression::partieIm() const {

    Entier* res = new Entier();
    const LitteraleCalculable& ref = *res;
    return ref;
}

