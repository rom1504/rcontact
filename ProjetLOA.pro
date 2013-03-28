#-------------------------------------------------
#
# Project created by QtCreator 2013-03-13T09:53:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bin/ProjetLOA
TEMPLATE = app
OBJECTS_DIR = temp/
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR


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
    vue/enumedit.cpp \
    modele/modeleafficherstructure.cpp \
    vue/structureedit.cpp \
    vue/ajouterchamp.cpp \
    modele/personne.cpp \
    modele/organisme.cpp \
    vue/criterestri.cpp \
    modele/comp.cpp \
    vue/rechercher.cpp \
    modele/search.cpp

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
    vue/enumedit.h \
    modele/modeleafficherstructure.h \
    vue/structureedit.h \
    vue/ajouterchamp.h \
    modele/organisme.h \
    modele/personne.h \
    vue/criterestri.h \
    modele/comp.h \
    vue/rechercher.h \
    modele/search.h

FORMS    += vue/mainwindow.ui \
    vue/listecontacts.ui \
    vue/affichercontact.ui \
    vue/editercontact.ui \
    vue/locedit.ui \
    vue/structureedit.ui \
    vue/ajouterchamp.ui \
    vue/criterestri.ui \
    vue/rechercher.ui


TRANSLATIONS = ProjetLOA_en.ts

CODECFORTR = UTF-8
