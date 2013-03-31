#include <QApplication>
#include <QTextCodec>
#include "controleur/controleur.h"
#include <QTranslator>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    QString locale = QLocale::system().name();
    //locale="en";

     QTranslator translator;
     translator.load(QString(":/ProjetLOA_") + locale);
     a.installTranslator(&translator);
     QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    Controleur c;
    c.run();


    return a.exec();
}
