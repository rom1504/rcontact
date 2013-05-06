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

void ModeleListeContacts::charger(QString nomFichier,QString type)
{
    disconnect(&mContacts,SIGNAL(dataChanged()),this,SLOT(trier()));
    beginResetModel();
    mContacts.charger(nomFichier,type);
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

void ModeleListeContacts::vider()
{

    beginResetModel();
    mContacts.vider();
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


Personne * ModeleListeContacts::ajouterPersonne()
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    Personne * c=mContacts.ajouterPersonne();
    endInsertRows();
    return c;
}



Organisme * ModeleListeContacts::ajouterOrganisme()
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    Organisme * c=mContacts.ajouterOrganisme();
    endInsertRows();
    return c;
}
