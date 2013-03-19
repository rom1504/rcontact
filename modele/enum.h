#ifndef ENUM_H
#define ENUM_H

#include "champ.h"
#include <QMap>
#include <QStringList>

class Enum : public Champ
{
public:
    Enum(const QString s="");
    bool operator==(const Enum & c) const;
    QString toString() const;
    bool fromString(const QString s);
    ~Enum();

    static void remplirEnums();

private:
    static QStringList mEnumTypeListe;
    static QList<QStringList> mEnumListe;
    int mEnum;
    int mValeur;
};

#endif // ENUM_H
