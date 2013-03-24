#include "modeleafficherstructure.h"
#include <QPair>

ModeleAfficherStructure::ModeleAfficherStructure(Structure * structure,QObject *parent) :
    QAbstractTableModel(parent),mStructure(structure)
{

}

int ModeleAfficherStructure::rowCount ( const QModelIndex &) const
{
    return mStructure->nombreValeurs();
}

int ModeleAfficherStructure::columnCount ( const QModelIndex &) const
{
    return 2;
}

bool ModeleAfficherStructure::removeRows (int row, int , const QModelIndex & parent)
{
    beginRemoveRows(parent,row,row);
    bool r=mStructure->supprimerChamp(row)==1;
    endRemoveRows();
    return r;
}


QVariant ModeleAfficherStructure::data(const QModelIndex & index,int role) const
{
    if (!index.isValid())
         return QVariant();

     if( index.row() >= mStructure->nombreValeurs() || index.column()>=2 )
         return QVariant();

     if (role == Qt::DisplayRole)
         return index.column()==0 ? (*mStructure)[index.row()].first : (*mStructure)[index.row()].second->toString();
     else if (role == Qt::EditRole)
         return index.column()==0 ? (*mStructure)[index.row()].first : (*mStructure)[index.row()].second->toVariant();
     else
         return QVariant();
}


bool ModeleAfficherStructure::setData ( const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
         if(index.column()==0) return false;
         else
         {
             if((*mStructure)[index.row()].second->fromVariant(value))
             {
                 emit dataChanged(index, index);
                 return true;
             }
             else return false;
         }
    }
    return false;
}

Qt::ItemFlags ModeleAfficherStructure::flags ( const QModelIndex & index ) const
{
    return index.column()==1 ? Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable : Qt::ItemIsEnabled|Qt::ItemIsSelectable;
}

QVariant ModeleAfficherStructure::headerData ( int section, Qt::Orientation orientation, int role) const
{
    return role != Qt::DisplayRole ? QVariant() : (orientation == Qt::Horizontal ?( section==0 ? "Champ" : "Valeur") : QString::number(section));
}
