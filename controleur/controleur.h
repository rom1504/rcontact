#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QObject>
#include "vue/mainwindow.h"
#include "modele/contacts.h"

class Controleur : public QObject
{
    Q_OBJECT
public:
    explicit Controleur(QObject *parent = 0);
    void run();

private:
    MainWindow mVue;
    Contacts mContacts;
    
private slots:
    void afficherContact(int index);
    void editerContact(int index);

signals:
    
public slots:
    
};

#endif // CONTROLEUR_H
