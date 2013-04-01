#include "dateedit.h"

DateEdit::DateEdit(QWidget *parent) :
    QDateTimeEdit(parent)
{
    setCalendarPopup(true);
}
