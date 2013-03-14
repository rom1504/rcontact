#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include "champ.h"
#include <QMultiMap>
#include <QString>
#include <QPair>

class Contact : public QObject
{
    Q_OBJECT
public:
    explicit Contact(QObject *parent = 0);
    Contact(const Contact & c,QObject *parent=0);
    ~Contact();
    void ajouterChamp(const QString & nomChamp,Champ * valeurChamp);
    void supprimerChamp(const QString & nomChamp);
    int nombreValeurs() const;

    QString nom() const;

    bool operator==(const Contact & c) const;
    const QPair<QString,Champ*> operator[](const int n) const;


signals:
    void dataChanged(int debut,int fin);

private:
    QMultiMap<QString,Champ*> mChamps;


};

#endif // CONTACT_H
