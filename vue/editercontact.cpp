#include "editercontact.h"
#include "ui_editercontact.h"

EditerContact::EditerContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditerContact)
{
    ui->setupUi(this);
}

EditerContact::~EditerContact()
{
    delete ui;
}
