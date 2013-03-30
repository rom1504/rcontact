#ifndef CONTACT_H
#define CONTACT_H

#include "champ.h"
#include <QMultiMap>
#include <QString>
#include <QPair>
#include "card.h"
#include "enum.h"
#include "loc.h"
#include "structure.h"
#include "texte.h"
#include "timestamp.h"
#include "url.h"

/**
 * @brief La classe Contact représente un contact enregistré, c'est à dire un multimap de champs.
 */
class Contact : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Le constructeur par défaut de la classe
     */
    explicit Contact(QObject * parent=0);
    /**
     * @brief Le constructeur de copie
     * @param c le Contact a copier
     */
    Contact(const Contact & c, QObject *parent);

    ~Contact();

    /**
     * @brief ajouterChamp ajoute le champs libelé nomChamp avec la valeur valeurChamp
     * @param nomChamp Le nom du champ à ajouter (ex : "nom", "téléphone", ...)
     * @param valeurChamp La valeur du champ à ajouter
     */
    void ajouterChamp(const QString & nomChamp, Champ* valeurChamp);

    /**
     * @brief creerChamp créé un champ à partir de son nom et son type, et l'ajoute
     * @param nomChamp Le nom du champ à créer
     * @param type Le type du champ à créer
     */
    virtual void creerChamp(const QString & nomChamp, const QString& type)=0;


    /**
     * @brief supprimerChamp supprime le champ libelé nomChamp qui a la valeur valeurChamp
     * @param nomChamp Le nom du champ à supprimer
     * @param valeurChamp La valeur du champ à supprimer
     * @return le nombre de valeurs supprimées
     */
    int supprimerChamp(const QString & nomChamp, Champ * valeurChamp);

    /**
     * @brief supprimerChamp supprime le champ à l'index indiqué
     * @param index L'index du champ à supprimer
     * @return le nombre de valeurs supprimées (0 ou 1 donc)
     */
    int supprimerChamp(const int index);

    /**
     * @brief nombreValeurs
     * @return le nombre de valeur totales
     */
    int nombreValeurs() const;

    /**
     * @brief nom
     * @return Le nom du contact
     */
    QString nom() const;

    /**
     * @brief aNom permet de vérifier si le contact a un nom (car ce champ est obligatoire)
     * @return true si le contact possède un champ libelé "nom", false sinon
     */
    bool aNom() const;

    /**
     * @brief L'opérateur d'égalité
     */
    bool operator==(const Contact & c) const; // problème : ne sera pas utilisé dans le QMultiMap car ce sont des pointeurs qui sont stockés... : à vérifier...

    /**
     * @brief opérateur d'accès qui utilise l'index
     * Cet opérateur utilise l'index, ce qui est très brut comme accès
     * @param n L'index auquel on veut accéder
     * @return Une paire dont le premier membre est le nom du champ (on ne le connait pas forcément, il n'est pas passé en paramètre) et dont le second est sa valeur.
     */
    const QPair<QString,Champ*> operator[](const int n) const;

    /**
     * @brief operator d'accès qui utilise le nom du champ
     * @param s Le nom du champ à accéder
     * @return Un pointeur vers le premier Champ qui porte le nom passé en paramètre.
     */
    const Champ* operator[](const QString s) const;

    void remplacer(QString s,Champ * c);

    /**
     * @brief tel créé un champ sensé décrire un tel de Contact initialisé avec les valeurs passées en paramètre
     * @param numero Le paramètre "numero" du champ
     * @param type Le paramètre "type" du champ
     * @param typeTel Le paramètre "typeTel" du champ
     * @param typeDonnees Le paramètre "typeDonnees" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* tel(const QString numero="",const QString type=tr("work"),const QString typeTel=tr("fixe"),const QString typeDonnees=tr("voice"));

    /**
     * @brief adresse créé un champ sensé décrire une adresse de Contact initialisé avec les valeurs passées en paramètre
     * @param rue Le paramètre "rue" du champ
     * @param zipcode Le paramètre "zipcode" du champ
     * @param localite Le paramètre "localité" du champ
     * @param region Le paramètre "region" du champ
     * @param pays Le paramètre "pays" du champ
     * @param type Le paramètre "type" du champ
     * @param geo Le paramètre "geo" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* adresse(const QString rue="",const QString zipcode="",const QString localite="",const QString region="",const QString pays="",const QString type=tr("home"),Loc * geo=new Loc());

    /**
     * @brief email créé un champ sensé décrire une adresse e-mail de Contact initialisé avec les valeurs passées en paramètre
     * @param nom Le paramètre "nom" du champ
     * @param domaine Le paramètre "domaine" du champ
     * @param extension Le paramètre "extension" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* email(const QString nom="nom",const QString domaine="domaine",const QString extension="ext");

    /**
     * @brief site créé un champ sensé décrire une url de site de Contact initialisé avec les valeurs passées en paramètre
     * @param url Le paramètre "url" du champ
     * @param type Le paramètre "type" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* site(const QString url="",const QString type=tr("web"));

    /**
     * @brief gtype créé un champ sensé décrire un type de Contact initialisé avec la valeur passée en paramètre
     * @param type La valeur initiale du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* gtype(const QString type="");

    /**
     * @brief date créé un champ sensé décrire la date de dernière modification d'un Contact initialisé avec la valeur passée en paramètre
     * @param timestamp La valeur initiale du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* date(const QString timestamp="");

    /**
     * @brief note créé un champ sensé décrire une note de Contact initialisé avec la valeur passée en paramètre
     * @param note La valeur initiale du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* note(const QString note="");

    /**
     * @brief url créé un champ sensé décrire une url de Contact initialisé avec la valeur passée en paramètre
     * @param texte La valeur initiale du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* url(const QString texte="");


signals:
    /**
     * @brief dataChanged est un signal déclenché quand un donnée du contact a été modifiées
     */
    void dataChanged();

private:
    /**
     * @brief mChamps est un multimap associant des libelés de champs (les QString) à des valeurs (les *Champ)
     */
    QMultiMap<QString,Champ*> mChamps;

protected:

    /**
     * @brief creerChampFromType créé un champ de base à partir du type passé en paramètre.
     * Utilisée uniquement dans la méthod créerChamp
     * @param type Le type du champ à créer
     * @return Le champ créé
     */
    static Champ* creerChampFromType(const QString& type);


};

#endif // CONTACT_H
