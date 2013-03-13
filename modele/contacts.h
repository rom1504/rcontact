#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include <QStringListModel>
#include "contact.h"

class Contacts : public QObject
{
    Q_OBJECT
public:
    explicit Contacts(QObject *parent = 0);
    void ajouterContact(const Contact & contact);
    int supprimerContact(const Contact & contact);

private:
    QList<Contact> mContacts;
    QStringListModel mModeleListeContacts;
    
signals:
    
public slots:
    
};

#endif // CONTACTS_H