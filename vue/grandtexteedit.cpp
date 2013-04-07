#include "grandtexteedit.h"

GrandTexteEdit::GrandTexteEdit(QWidget *parent) :
    QTextEdit(parent)
{
}

GrandTexte * GrandTexteEdit::grandTexte() const
{
    return new GrandTexte(toPlainText());
}

void GrandTexteEdit::setGrandTexte(GrandTexte *g)
{
    setPlainText(g->value());
}
