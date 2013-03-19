#ifndef LISTECONTACTS_H
#define LISTECONTACTS_H

#include <QAbstractListModel>
#include "contacts.h"

class ModeleListeContacts : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ModeleListeContacts(Contacts & contacts,QObject *parent=0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    int rowCount (const QModelIndex & = QModelIndex()) const;
    
signals:
    // connecter dataChanged de modeleafficherContact à un slot qui emet le bon dataChanged ici
public slots:

private slots:
    void dataChanged_(const int debut,const int fin);

private:
    Contacts & mContacts;
    
};

#endif // LISTECONTACTS_H
