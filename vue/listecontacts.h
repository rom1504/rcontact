#ifndef LISTECONTACTS_H
#define LISTECONTACTS_H

#include <QWidget>
#include <QAbstractItemModel>
#include "../modele/modelelistecontacts.h"

namespace Ui {
class ListeContacts;
}

class ListeContacts : public QWidget
{
    Q_OBJECT
    
public:
    explicit ListeContacts(QWidget *parent = 0);
    ~ListeContacts();
    void setModel ( ModeleListeContacts * model );
    int indexContactCourant();
    void chargerContacts(QString nomFichier);

signals:
    void contactActive(const int index);
    void contactEdite(const int index);
    
public slots:
    void supprimerContactCourant();
    void editerContactCourant();
    void afficherContactCourant();
    void creerContact();

private slots:
    void afficherContact(const QModelIndex & index);

private:
    Ui::ListeContacts *ui;
   ModeleListeContacts * mModel;
};

#endif // LISTECONTACTS_H
