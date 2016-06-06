#include "structure.h"
#include "include.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QComputer fenetre;

    fenetre.show();
    fenetre.setWindowTitle(QApplication::translate("toplevel", "Accueil widget"));

    Entier c1(1);
    Entier c2(3);
    Entier res = c1+c2;

    res.Affiche();
return app.exec();
}
