#include "modeleaffichercontact.h"
#include <QPair>

ModeleAfficherContact::ModeleAfficherContact(const Contact * contact,QObject *parent) :
    QAbstractTableModel(parent),mContact(contact)
{
    connect(mContact,SIGNAL(dataChanged(int,int)),this,SLOT(dataChanged_(int,int)));
}

int ModeleAfficherContact::rowCount ( const QModelIndex &) const
{
    return mContact->nombreValeurs();
}

int ModeleAfficherContact::columnCount ( const QModelIndex &) const
{
    return 2;
}

QVariant ModeleAfficherContact::data(const QModelIndex & index,int role) const
{
    if (!index.isValid())
         return QVariant();

     if( index.row() >= mContact->nombreValeurs() || index.column()>=2 )
         return QVariant();

     if (role == Qt::DisplayRole)
         return index.column()==0 ? (*mContact)[index.row()].first : (*mContact)[index.row()].second->toString();
     else
         return QVariant();
}



void ModeleAfficherContact::dataChanged_(const int debut,const int fin)
{
    emit dataChanged(createIndex(debut,0),createIndex(fin,1));
}
