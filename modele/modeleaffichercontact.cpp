#include "modeleaffichercontact.h"
#include <QPair>

ModeleAfficherContact::ModeleAfficherContact(const Contact * contact,QObject *parent) :
    QAbstractTableModel(parent),mContact(contact)
{
    mEditable=false;
    connect(mContact,SIGNAL(dataChanged(int,int)),this,SLOT(dataChanged_(int,int)));
}

void ModeleAfficherContact::rendreEditable()
{
    mEditable=true;
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

bool ModeleAfficherContact::setData ( const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
         if(index.column()==0) return false;
         else (*mContact)[index.row()].second->fromString(value.toString());
         emit dataChanged(index, index);
         return true;
    }
    return false;
}

Qt::ItemFlags ModeleAfficherContact::flags ( const QModelIndex & index ) const
{
    return index.column()==1 && mEditable ? Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable : Qt::ItemIsEnabled|Qt::ItemIsSelectable;
}
