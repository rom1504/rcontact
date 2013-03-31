#include "modelelistecontacts.h"
#include "structure.h"
#include "texte.h"
#include <iostream>
#include "contact.h"

ModeleListeContacts::ModeleListeContacts(Contacts & contacts,QObject *parent) :
    QAbstractListModel(parent),mContacts(contacts)
{
    connect(&mContacts,SIGNAL(dataChanged()),this,SLOT(trier()));
}

QVariant ModeleListeContacts::data(const QModelIndex & index,int role) const
{
    if (!index.isValid())
         return QVariant();

     if (index.row() >= mContacts.nombre())
         return QVariant();

     if (role == Qt::DisplayRole)
         return mContacts[index.row()]->nom();
     else if(role == Qt::DecorationRole)
         return mContacts[index.row()]->image();
     else
         return QVariant();
}

void ModeleListeContacts::charger(QString nomFichier)
{
    disconnect(&mContacts,SIGNAL(dataChanged()),this,SLOT(trier()));
    beginResetModel();
    mContacts.charger(nomFichier);
    mContacts.trier();
    endResetModel();
    connect(&mContacts,SIGNAL(dataChanged()),this,SLOT(trier()));
}

void ModeleListeContacts::trier()
{
    beginResetModel();
    mContacts.trier();
    endResetModel();
}

void ModeleListeContacts::changerTri(Comp * comp)
{
    beginResetModel();
    mContacts.changerTri(comp);
    endResetModel();
}

int ModeleListeContacts::rowCount ( const QModelIndex & ) const
{
    return mContacts.nombre();
}


bool ModeleListeContacts::removeRows (int row, int count, const QModelIndex & parent)
{
    beginRemoveRows(parent,row,row+count-1);
    for(int i=0;i<count;i++) mContacts.supprimerContact(row);
    endRemoveRows();
    return true;
}

bool ModeleListeContacts::insertRows ( int row, int count, const QModelIndex &  parent )
{
    beginInsertRows(parent,row,row+count-1);
    for(int i=0;i<count;i++)
    {
        mContacts.ajouterContact();
    }
    endInsertRows();
    return true;
}


Contact * ModeleListeContacts::ajouterContact()
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    Contact * c=mContacts.ajouterContact();
    endInsertRows();
    return c;
}
