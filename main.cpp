#include "vue/mainwindow.h"
#include <QApplication>

#include "modele/modelelistecontacts.h"
#include "modele/contacts.h"
#include "modele/contact.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Contacts contacts;



    ModeleListeContacts * modeleListeContacts=new ModeleListeContacts(contacts);
    MainWindow vue;
    vue.setModeleListeContacts(modeleListeContacts);
    vue.show();


    Contact contact1;
    Contact contact2;
    contacts.ajouterContact(contact1);
    contacts.ajouterContact(contact2);


    return a.exec();
}
