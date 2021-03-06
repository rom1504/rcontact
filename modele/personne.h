/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef PERSONNE_H
#define PERSONNE_H

#include "contact.h"

/**
 * @brief La classe Personne représente un contact avec le template d'une personne
 */
class Personne : public Contact
{
    Q_OBJECT
public:

    /**
     * @brief Le constructeur par défaut
     */
    Personne(QObject * parent=0);


    /**
     * @brief creerChamp créé et ajoute un champ
     * @param nomChamp le nom du champ à créer
     * @param type Le type du champ à créer
     */
    void creerChamp(const QString& nomChamp, const QString& type);


    /**
     * @brief image
     * @return La photo de la personne
     */
    QVariant image() const;

    /**
     * @brief creerPersonne créer un contact avec des champs caractéristiques d'un personne physique
     * @return Un pointeur vers le contact créé
     */
    static Personne* creerDefaut();

    /**
     * @brief gnom créé un champ sensé décrire un nom de Personne initialisé avec les valeurs passées en paramètre
     * @param nom Le paramètre "nom" du champ
     * @param prenom Le paramètre "prénom" du champ
     * @param prefixe Le paramètre "préfixe" du champ
     * @param surnom Le paramètre "surnom" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* gnom(const QString nom=tr("Nom"),const QString prenom=tr("Prénom"),const QString prefixe="",const QString surnom="");

    /**
     * @brief sexe créé un champ sensé décrire un sexe de Personne initialisé avec la valeur passée en paramètre
     * @param sexe La valeur initiale du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* sexe(const QString sexe=tr("homme"));

    /**
     * @brief photo créé un champ sensé décrire une photo de Personne initialisé avec les valeurs passées en paramètre
     * @param url Le paramètre "url" du champ
     * @param type Le paramètre "type" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* photo(const QString url="",const QString type=tr("JPEG"));

    /**
     * @brief organisation créé un champ sensé décrire une organisation initialisée avec la valeur passée en paramètre
     * @param card Un pointeur vers une Card décrivant l'organisation
     * @return Un pointeur vers le champ créé
     */
    static Champ* organisation(QString card="");

};

#endif // PERSONNE_H
