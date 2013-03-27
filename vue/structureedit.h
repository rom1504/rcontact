#ifndef STRUCTUREEDIT_H
#define STRUCTUREEDIT_H

#include <QWidget>
#include "../modele/structure.h"
#include <QModelIndex>

namespace Ui {
class StructureEdit;
}

class StructureEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Structure* structure READ structure WRITE setStructure USER true)
    
public:
    explicit StructureEdit(QWidget *parent = 0);
    Structure * structure() const;
    void setStructure(Structure *s);
    ~StructureEdit();
    QSize sizeHint() const;

private slots:
    void redimensionner(QModelIndex index);
    
private:
    Ui::StructureEdit *ui;
    Structure * mStructure;
};

int max(int a,int b);

#endif // STRUCTUREEDIT_H
