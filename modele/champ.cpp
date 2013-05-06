#include "champ.h"
#include <QTextDocument>

Champ::~Champ() {}

Champ::Champ(QObject * parent) : QObject(parent)
{

}

QVariant Champ::toVariant()
{
    return toString();
}

bool Champ::fromVariant(const QVariant v)
{
    return fromString(v.toString());
}

QVariant Champ::image() const
{
    return QVariant();
}

QString unParseString(QString s);

QString Champ::toVCard() const
{
    return ":"+unParseString(toString());
}

void Champ::essayerEncore()
{

}

QString Champ::toXML() const
{
    return toString().toHtmlEscaped();
}
