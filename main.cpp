#include "structure.h"
#include "include.h"
#include "calc.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QCalc fenetre;

    fenetre.show();
    fenetre.setWindowTitle(QApplication::translate("toplevel", "Accueil widget"));

    Entier c1(1);
    Entier c2(3);
    Entier res = c1+c2;

    //res.affiche();
return app.exec();
}
