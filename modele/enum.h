#ifndef ENUM_H
#define ENUM_H

#include "champ.h"
#include <QMap>
#include <QStringList>

/**
 * @brief La classe Enum représente un champ dont on doit sélectionner la valeur dans une liste prédéfinie (comme dans une liste déroulante)
 */
class Enum : public Champ
{
public:
    /**
     * @brief Le contructeur de la classe
     * @param s La valeur par défaut (utilise fromString pour convertir la QString en le type approprié)
     */
    Enum(const QString s="");

    Enum(const int enum_,const int valeur);
    /**
     * @brief L'opérateur d'égalité
     */
    bool operator==(const Enum & c) const;
    /**
     * @brief toString convertis l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertis un QString en Enum
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);
    ~Enum();

    QStringList valeursPossibles() const;

    int valeur() const;
    int getEnum() const;

    /**
     * @brief remplirEnums initialise les énumérations
     * Elle est appelée une seul et unique fois, au début du programme, pour remplir mEnumTypeListe et mEnumListe des valeurs qu'on souhaite qu'elles prennent.
     */
    static void remplirEnums();

    QVariant toVariant() const;
    bool fromVariant(const QVariant v);

private:
    /**
     * @brief mEnumTypeListe est la liste des noms énumérations impémentées.
     * Elle est initialisée dans remplirEnums()
     */
    static QStringList mEnumTypeListe;
    /**
     * @brief mEnumListe est la liste des noms des valeurs des énumérations décrites dans nEmunTypeListe.
     * Les index de mEnumTypeListe et de mEnumListe correspondent (mEnumListe[i] est la liste des valeurs de l'énumération appellée mEnumTypeListe[i])
     * Elle est initialisée dans remplirEnums()
     */
    static QList<QStringList> mEnumListe;
    /**
     * @brief mEnum contient l'index du nom de l'énumération du champ actuel (dans mEnumTypeListe)
     */
    int mEnum;
    /**
     * @brief mValeur contient l'index du nom de la valeur prise par le champ actuel (dans mEnumListe[mEnum])
     */
    int mValeur;
};

Q_DECLARE_METATYPE (Enum)

#endif // ENUM_H
