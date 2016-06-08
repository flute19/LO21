#include "structure.h"
#include "include.h"
#include "calc.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QCalc fenetre;
    fenetre.setFixedSize(500, 500);

    QLineEdit commande(&fenetre); //commande is on fenetre
    commande.move(140,40);
    commande.setFixedWidth(340);

    fenetre.show();
    fenetre.setWindowTitle(QApplication::translate("toplevel", "Accueil widget"));

    Entier c1(1);
    Entier c2(3);
    Entier* res = new Entier(c1.getValue()+c2.getValue());

    //res.affiche();
return app.exec();
}
