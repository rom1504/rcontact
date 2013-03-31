#include "url.h"
#include <QRegExp>
#include <QUrl>

Url::Url(const QString value, QObject *parent) : Texte(value,parent)
{
    if(!fromString(value)) mValue="";
}


bool Url::fromString(const QString s)
{
   // if(!(new QRegExp("((http:\\/\\/|https:\\/\\/)?(www.)?(([a-zA-Z0-9-]){2,}\\.){1,4}([a-zA-Z]){2,6}(\\/([a-zA-Z-_\\/\\.0-9#:?=&;,]*)?)?)"))->exactMatch(s)) return false;
    QUrl url(s);
    if(!(url.isValid())) return false;
    mValue=s;// rajouter file
    emit dataChanged();
    return true;
}


void Url::setValue(const QString value)
{
    if(!fromString(value))
    {
        mValue="";
        emit dataChanged();
    }
}
