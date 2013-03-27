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
    Q_OBJECT
public:
    /**
     * @brief Le contructeur de base de la classe
     * @param s La valeur par défaut (utilise fromString pour convertir la QString en le type approprié)
     */
    Enum(const QString s="",QObject * parent=0);


    Enum(const Enum &e, QObject * parent=0);

    /**
     * @brief Un constructeur qui utilise les index pour initialiser l'enumération
     * @param enum_ L'index de type d'énumération
     * @param valeur L'index de valeur d'énumération
     */
    Enum(const int enum_,const int valeur,QObject * parent=0);

    /**
     * @brief L'opérateur d'égalité
     */
    bool operator==(const Enum & c) const;

    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;

    /**
     * @brief fromString convertit un QString en Enum
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);

    /**
     * @brief valeursPossibles permet de récupérer la liste des valeurs possible pour l'énumération actuelle
     * @return Une QStringList contenant les valeurs que peut prendre l'énumération du type enregistré
     */
    QStringList valeursPossibles() const;

    /**
     * @brief valeur permet de récupérer la valeur dans l'énumération
     * @return L'index de la valeur actuelle
     */
    int valeur() const;

    /**
     * @brief getEnum permet de récupérer le numéro de l'énumération utilisée
     * @return L'index de l'énumération
     */
    int getEnum() const;

    /**
     * @brief remplirEnums initialise les énumérations
     * Elle est appelée une seul et unique fois, au début du programme, pour remplir mEnumTypeListe et mEnumListe des valeurs qu'on souhaite qu'elles prennent.
     */
    static void remplirEnums();

    /**
     * @brief toVariant convertit l'objet en QVariant
     * @return Un QVariant qui décrit exactement l'objet
     */
    QVariant toVariant();

    /**
     * @brief fromVariant convertit un QVariant en Enum
     * @param v Le QVariant à convertir
     * @return true si la conversion a réussi
     */
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

Q_DECLARE_METATYPE (Enum*)

#endif // ENUM_H
