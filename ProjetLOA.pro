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
    modele/text.cpp

HEADERS  += vue/mainwindow.h \
    modele/contacts.h \
    modele/contact.h \
    controleur/controleur.h \
    vue/listecontacts.h \
    vue/affichercontact.h \
    vue/editercontact.h \
    modele/champ.h \
    modele/text.h

FORMS    += vue/mainwindow.ui \
    vue/listecontacts.ui \
    vue/affichercontact.ui \
    vue/editercontact.ui
