#include "modelelistecontacts.h"
#include "structure.h"
#include "texte.h"

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
         return mContacts[index.row()]->nom();
     else
         return QVariant();
}

int ModeleListeContacts::rowCount ( const QModelIndex & ) const
{
    return mContacts.nombre();
}

void ModeleListeContacts::dataChanged_(const int debut,const int fin)
{
    emit dataChanged(createIndex(debut,0),createIndex(fin,0));
}

bool ModeleListeContacts::removeRows (int row, int count, const QModelIndex & parent)
{
    beginRemoveRows(parent,row,row+count-1);
    for(int i=0;i<count;i++) mContacts.supprimerContact(row+i);
    endRemoveRows();
    return true;
}

bool ModeleListeContacts::insertRows ( int row, int count, const QModelIndex & parent  )
{
    beginInsertRows (parent,row,row+count-1);
    for(int i=0;i<count;i++)
    {
        Contact * nouveau=new Contact();
        Structure * nom=new Structure();
        nom->ajouterChamp("Nom",new Texte("Nom"));
        nom->ajouterChamp("Prénom",new Texte("Prénom"));
        nouveau->ajouterChamp("nom",nom);
        mContacts.ajouterContact(nouveau);
    }
    endInsertRows ();
    return true;
}
