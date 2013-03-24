#ifndef URL_H
#define URL_H

#include "texte.h"

/**
 * @brief La classe Url représente un champ contenant une url, c'est à dire un texte sous un certain format
 */
class Url : public Texte
{
public:
    /**
     * @brief Le constructeur par défaut
     * @param s La valeur par défaut (utilise fromString pour convertir la QString en le type approprié)
     */
    Url(const QString value="");
    /**
     * @brief fromString convertis un QString en Url
     * Elle vérifie que l'url est bien valide.
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);
    /**
     * @brief setValue modifie l'url stockée
     * @param value la nouvelle valeur de l'url
     */
    void setValue(const QString value);
};

#endif // URL_H
