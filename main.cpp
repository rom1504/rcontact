#include <QApplication>
#include <QTextCodec>
#include "controleur/controleur.h"
#include <QTranslator>
#include <QLibraryInfo>
#include <iostream>
#include <QNetworkProxy>
#include <QProcess>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    QString locale = QLocale::system().name();
    //locale="fr_FR";
    locale="en";

    // cette partie semble ne pas marcher
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + locale,QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&qtTranslator);


     QTranslator translator;
     translator.load(QString(":/ProjetLOA_") + locale);
     QApplication::installTranslator(&translator);
     QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

     QStringList environment = QProcess::systemEnvironment();
     QString proxy="";
     for(int i=0;i<environment.size();i++)
     {
         QStringList l=environment[i].split("=");
         if(l[0]=="http_proxy") proxy=l.length()>=2 ? l[1] : "";
     }
     if(proxy!="")
     {
         QStringList l2=proxy.split(":");
         QNetworkProxy::setApplicationProxy (QNetworkProxy(QNetworkProxy::HttpProxy,l2[0],l2.length()>=2 ? l2[1].toInt() : 3128));
     }

     Controleur c(locale,&translator);
      c.run();


    return a.exec();
}
