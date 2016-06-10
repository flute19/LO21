#include "include.h"
#include "calc.h"

int main(int argc, char* argv[]){

    QApplication app(argc, argv);

    //---------- window settings ----------------
    QCalc fenetre;
    fenetre.setFixedSize(500, 500);
    fenetre.setWindowTitle(QApplication::translate("toplevel", "Accueil widget"));

    Entier c1(1);
    Entier c2(3);
    Entier* res = new Entier(c1.getValue()+c2.getValue());

    //res.affiche();
//    fenetre.setLayout(&layout);
    fenetre.show();
return app.exec();
}
