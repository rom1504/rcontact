#ifndef URL_H
#define URL_H

#include "texte.h"

class Url : public Texte
{
public:
    Url(const QString value);
    bool fromString(const QString s);
    void setValue(const QString value);
};

#endif // URL_H
