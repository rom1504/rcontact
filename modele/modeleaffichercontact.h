#ifndef MODELEAFFICHERCONTACT_H
#define MODELEAFFICHERCONTACT_H

#include <QAbstractTableModel>
#include "contact.h"

class ModeleAfficherContact : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModeleAfficherContact(Contact * contact,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole ) ; // utilisé pour l'édition (changer le nom de ce fichier/classe ?)
    int rowCount ( const QModelIndex & = QModelIndex() ) const;
    int columnCount (const QModelIndex & = QModelIndex()) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    bool removeRows (int row, int count, const QModelIndex & parent = QModelIndex());
    void rendreEditable();
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    bool insertRows ( int row, int count, const QModelIndex & parent  );
    
signals:
    
public slots:

private:
   Contact * mContact;
   bool mEditable;
    
};

#endif // MODELEAFFICHERCONTACT_H
