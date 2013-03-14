#ProjetLOA
Gestionnaire de contacts

Organisation en vue/modèle

Pour lier la vue au modèle on utilise des modèles Qt : 
des classes qui héritent de QAbstractItemModel ( ou de qabstractlistmodel par exemple)

##Vue
###AfficherContact

###EditerContact

###ListeContacts
Afficher les contacts

###MainWindow
Affiche ListeContacts, EditerContact et AfficherContact ainsi que le menu

##Modele
###Contacts
Stocke les contacts et fait les opérations sur ceux-ci

####Contact
Stocke les valeurs des champs du contact et permet de récupéré certaine information à partir de ces valeurs
(le nom par exemple)

#####Champ
Classe générique qu'il faut hériter pour définir les types de champs

######Texte
Simple champ pour stocker du texte

###ModeleListeContacts
Ce modèle Qt fait le lien entre Contacts et la QListView présente dans ListeContacts
