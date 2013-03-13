#include "vue/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow vue;
    vue.show();

    // Contacts modele=new Contacts();

    // Controleur controleur=new Controleur();

    //QObject::connect(vue,SIGNAL(creationContact(,,,)),controleur,SLOT(creerContact(,,,)));

    return a.exec();
}
