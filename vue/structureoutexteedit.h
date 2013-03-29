#ifndef STRUCTUREOUTEXTEEDIT_H
#define STRUCTUREOUTEXTEEDIT_H

#include <QWidget>
#include "../modele/structureoutexte.h"
#include "../modele/nom.h"

namespace Ui {
class StructureOuTexteEdit;
}

class StructureOuTexteEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(StructureOuTexte* structureOuTexte READ structureOuTexte WRITE setStructureOuTexte USER true)
    
public:
    explicit StructureOuTexteEdit(QWidget *parent = 0);
    StructureOuTexte * structureOuTexte() const;
    void setStructureOuTexte(StructureOuTexte *s);
    ~StructureOuTexteEdit();
    QSize sizeHint() const;
    
private slots:
    void on_pushButtonBasculer_clicked();

private:
    Ui::StructureOuTexteEdit *ui;
    StructureOuTexte * mStructureOuTexte;
};

#endif // STRUCTUREOUTEXTEEDIT_H
