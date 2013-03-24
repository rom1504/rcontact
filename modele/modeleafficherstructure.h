#ifndef MODELEAFFICHERSTRUCTURE_H
#define MODELEAFFICHERSTRUCTURE_H

#include <QAbstractTableModel>
#include "structure.h"

class ModeleAfficherStructure : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModeleAfficherStructure(Structure * structure,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole ) ;
    int rowCount ( const QModelIndex & = QModelIndex() ) const;
    int columnCount (const QModelIndex & = QModelIndex()) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    bool removeRows (int row, int count, const QModelIndex & parent = QModelIndex());
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

signals:

public slots:

private:
   Structure * mStructure;
    
};

#endif // MODELEAFFICHERSTRUCTURE_H
