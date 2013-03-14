#include <QApplication>
#include "controleur/controleur.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controleur c;
    c.run();


    return a.exec();
}
