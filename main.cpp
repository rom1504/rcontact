#include <QApplication>
#include <QTextCodec>
#include "controleur/controleur.h"
#include <QTranslator>
#include <QLibraryInfo>
#include <iostream>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    QString locale = QLocale::system().name();
    //locale="fr_FR";

    // cette partie semble ne pas marcher
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + locale,QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);


     QTranslator translator;
     translator.load(QString(":/ProjetLOA_") + locale);
     a.installTranslator(&translator);
     QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    Controleur c;
    c.run();


    return a.exec();
}
