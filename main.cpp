#include <QApplication>
#include <QTextCodec>
#include "controleur/controleur.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);

    Controleur c;
    c.run();


    return a.exec();
}
