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
    void ajouterContact(Contact * contact);
    void supprimerContact(const int n);
    int nombre() const;
    const Contact * operator[](const int n) const;

private:
    QList<Contact*> mContacts;
    
signals:
    void dataChanged(int debut,int fin);
    
public slots:
    
};

#endif // CONTACTS_H
