#include "modelelistecontacts.h"

ModeleListeContacts::ModeleListeContacts(Contacts & contacts,QObject *parent) :
    QAbstractListModel(parent),mContacts(contacts)
{
    connect(&mContacts,SIGNAL(dataChanged(int,int)),this,SLOT(dataChanged_(int,int)));
}

QVariant ModeleListeContacts::data(const QModelIndex & index,int role) const
{
    if (!index.isValid())
         return QVariant();

     if (index.row() >= mContacts.nombre())
         return QVariant();

     if (role == Qt::DisplayRole)
         return mContacts[index.row()].nom();
     else
         return QVariant();
}

int ModeleListeContacts::rowCount ( const QModelIndex & parent) const
{
    return mContacts.nombre();
}

void ModeleListeContacts::dataChanged_(const int debut,const int fin)
{
    emit dataChanged(createIndex(debut,0),createIndex(fin,0));
}
