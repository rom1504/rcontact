#-------------------------------------------------
#
# Project created by QtCreator 2013-03-13T09:53:57
#
#-------------------------------------------------

QT       += core gui network xml widgets

TARGET = bin/rcontact
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
    modele/search.cpp \
    vue/structureoutexteedit.cpp \
    modele/nom.cpp \
    modele/structureoutexte.cpp \
    modele/tel.cpp \
    modele/adresse.cpp \
    modele/email.cpp \
    modele/image.cpp \
    vue/dateedit.cpp \
    modele/membre.cpp \
    vue/imageedit.cpp \
    modele/grandtexte.cpp \
    vue/grandtexteedit.cpp

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
    modele/search.h \
    vue/structureoutexteedit.h \
    modele/nom.h \
    modele/structureoutexte.h \
    modele/tel.h \
    modele/adresse.h \
    modele/email.h \
    modele/image.h \
    vue/dateedit.h \
    modele/membre.h \
    vue/imageedit.h \
    modele/grandtexte.h \
    vue/grandtexteedit.h

FORMS    += vue/mainwindow.ui \
    vue/listecontacts.ui \
    vue/affichercontact.ui \
    vue/editercontact.ui \
    vue/locedit.ui \
    vue/structureedit.ui \
    vue/ajouterchamp.ui \
    vue/criterestri.ui \
    vue/rechercher.ui \
    vue/structureoutexteedit.ui \
    vue/imageedit.ui


TRANSLATIONS = rcontact_en.ts

CODECFORTR = UTF-8

RESOURCES += \
    ressources.qrc

QMAKE_CXXFLAGS += -std=c++11

