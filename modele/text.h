#ifndef TEXT_H
#define TEXT_H

#include <QString>
#include "champ.h"

class Text : public Champ
{
public:
    Text(const QString value="");
    void setValue(const QString value);
    QString value() const;

private:
    QString mValue;
};

#endif // TEXT_H
