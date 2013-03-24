#include "modeleaffichercontact.h"
#include <QPair>
#include <QSize>
#include "../vue/ajouterchamp.h"

ModeleAfficherContact::ModeleAfficherContact(Contact * contact,QObject *parent) :
    QAbstractTableModel(parent),mContact(contact)
{
    mEditable=false;
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

bool ModeleAfficherContact::removeRows (int row, int , const QModelIndex & parent)
{
    beginRemoveRows(parent,row,row);
    bool r=mContact->supprimerChamp(row)==1;
    endRemoveRows();
    return r;
}


QVariant ModeleAfficherContact::data(const QModelIndex & index,int role) const
{
    if (!index.isValid())
         return QVariant();

     if( index.row() >= mContact->nombreValeurs() || index.column()>=2 )
         return QVariant();

     if (role == Qt::DisplayRole)
         return index.column()==0 ? (*mContact)[index.row()].first : (*mContact)[index.row()].second->toString();
     else if (role == Qt::EditRole)
         return index.column()==0 ? (*mContact)[index.row()].first : (*mContact)[index.row()].second->toVariant();
     else if(role == Qt::ForegroundRole && index.column()==0)
         return QColor("gray");
     else
         return QVariant();
}

bool ModeleAfficherContact::setData ( const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
         if(index.column()==0) return false;
         else
         {
             if((*mContact)[index.row()].second->fromVariant(value))
             {
                 emit dataChanged(index, index);
                 return true;
             }
             else return false;
         }
    }
    return false;
}

bool ModeleAfficherContact::insertRows ( int row, int count, const QModelIndex & parent  )
{
    beginInsertRows(parent,row,row+count-1);
    for(int i=0;i<count;i++)
    {
        QPair<QString,Champ*> p=AjouterChamp::get();
        if(p.second!=NULL) mContact->ajouterChamp(p.first,p.second);
        else
        {
            endInsertRows();
            return false;
        }
    }
    endInsertRows();
    return true;
}

Qt::ItemFlags ModeleAfficherContact::flags ( const QModelIndex & index ) const
{
    return index.column()==1 && mEditable ? Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable : Qt::ItemIsEnabled|Qt::ItemIsSelectable;
}

QVariant ModeleAfficherContact::headerData ( int section, Qt::Orientation orientation, int role) const
{
    return role != Qt::DisplayRole ? QVariant() : (orientation == Qt::Horizontal ?( section==0 ? "Champ" : "Valeur") : QString::number(section));
}
