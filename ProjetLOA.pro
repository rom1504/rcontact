#-------------------------------------------------
#
# Project created by QtCreator 2013-03-13T09:53:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetLOA
TEMPLATE = app


SOURCES += main.cpp\
        vue/mainwindow.cpp \
    modele/contacts.cpp \
    modele/contact.cpp \
    vue/listecontacts.cpp \
    vue/affichercontact.cpp \
    vue/editercontact.cpp \
    modele/champ.cpp \
    modele/texte.cpp \
    modele/modelelistecontacts.cpp \
    modele/modeleaffichercontact.cpp \
    controleur/controleur.cpp \
    modele/structure.cpp \
    modele/url.cpp \
    modele/card.cpp \
    modele/loc.cpp \
    modele/timestamp.cpp \
    modele/enum.cpp \
    vue/locedit.cpp \
    vue/enumedit.cpp

HEADERS  += vue/mainwindow.h \
    modele/contacts.h \
    modele/contact.h \
    controleur/controleur.h \
    vue/listecontacts.h \
    vue/affichercontact.h \
    vue/editercontact.h \
    modele/champ.h \
    modele/texte.h \
    modele/modelelistecontacts.h \
    modele/modeleaffichercontact.h \
    controleur/controleur.h \
    modele/structure.h \
    modele/url.h \
    modele/card.h \
    modele/loc.h \
    modele/timestamp.h \
    modele/enum.h \
    vue/locedit.h \
    vue/enumedit.h

FORMS    += vue/mainwindow.ui \
    vue/listecontacts.ui \
    vue/affichercontact.ui \
    vue/editercontact.ui \
    vue/locedit.ui
