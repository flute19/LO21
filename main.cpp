#include "structure.h"
#include "include.h"
#include "calc.h"

int main(int argc, char* argv[]){

    QApplication app(argc, argv);

    //---------- window settings ----------------
    QCalc fenetre;
    fenetre.setFixedSize(500, 500);
    fenetre.setWindowTitle(QApplication::translate("toplevel", "Accueil widget"));

    //--------- command ligne settings ----------
    QLineEdit commande(&fenetre);
    commande.move(140,40);
    commande.setFixedWidth(340);

    //--------- Button creation -----------------

//    //--- digits 1-9 -----
//    QPushButton un("1",&fenetre);
//    QPushButton deux("2",&fenetre);
//    QPushButton trois("3",&fenetre);
//    QPushButton quatre("4",&fenetre);
//    QPushButton cinq("5",&fenetre);
//    QPushButton six("6",&fenetre);
//    QPushButton sept("7",&fenetre);
//    QPushButton huit("8",&fenetre);
//    QPushButton neuf("9",&fenetre);

    //--------- Numeric Pad settings ------------

    //---- Make ligns ------
//    QHBoxLayout line1;
//    line1.addWidget(&un);
//    line1.addWidget(&deux);
//    line1.addWidget(&trois);

//    QHBoxLayout line2;
//    line2.addWidget(&quatre);
//    line2.addWidget(&cinq);
//    line2.addWidget(&six);

//    QHBoxLayout line3;
//    line3.addWidget(&sept);
//    line3.addWidget(&huit);
//    line3.addWidget(&neuf);

    //---- Make Pad --------
//    QVBoxLayout pave;
//    pave.addLayout(&line1);
//    pave.addLayout(&line2);
//    pave.addLayout(&line3);

    //-------- Numeric Interface Settings ----------
    /******************************************************
    * used to group objects related to numeric functions, *
    * to make it easier to move accross window.           *
    * ****************************************************/

//    QHBoxLayout interface; //horizontal setting
//    interface.addLayout(&pave);

//    QVBoxLayout layout; // vertical setting
//    layout.addLayout(&interface);


    Entier c1(1);
    Entier c2(3);
    Entier* res = new Entier(c1.getValue()+c2.getValue());

    //res.affiche();
//    fenetre.setLayout(&layout);
    fenetre.show();
return app.exec();
}
