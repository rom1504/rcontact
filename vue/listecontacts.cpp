#include "listecontacts.h"
#include "ui_listecontacts.h"

ListeContacts::ListeContacts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListeContacts)
{
    ui->setupUi(this);
}

ListeContacts::~ListeContacts()
{
    delete ui;
}