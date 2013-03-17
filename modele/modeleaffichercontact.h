#ifndef MODELEAFFICHERCONTACT_H
#define MODELEAFFICHERCONTACT_H

#include <QAbstractTableModel>
#include "contact.h"

class ModeleAfficherContact : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModeleAfficherContact(const Contact * contact,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole ) ; // utilisé pour l'édition (changer le nom de ce fichier/classe ?)
    int rowCount ( const QModelIndex & = QModelIndex() ) const;
    int columnCount (const QModelIndex & = QModelIndex()) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    void rendreEditable();
    
signals:
    
public slots:

private slots:
    void dataChanged_(const int debut,const int fin);

private:
   const Contact * mContact;
   bool mEditable;
    
};

#endif // MODELEAFFICHERCONTACT_H
