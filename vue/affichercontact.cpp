#include "affichercontact.h"
#include "ui_affichercontact.h"

AfficherContact::AfficherContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherContact)
{
    ui->setupUi(this);
}

AfficherContact::~AfficherContact()
{
    delete ui;
}