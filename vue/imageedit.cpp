#include "imageedit.h"
#include "ui_imageedit.h"
#include <QFileDialog>

ImageEdit::ImageEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageEdit)
{
    setAutoFillBackground(true);
    ui->setupUi(this);
}

ImageEdit::~ImageEdit()
{
    delete ui;
}


Image *ImageEdit::image() const
{
    return new Image(ui->lineEditUrl->text());
}

void ImageEdit::setImage(Image * i)
{
    ui->lineEditUrl->setText(i->avoirChamp("url"));
}

void ImageEdit::on_pushButtonParcourir_clicked()
{
    QString nomFichier;
    if((nomFichier = QFileDialog::getOpenFileName(this, tr("Selectionner une image"),"",tr("Image(*.jpeg *.jpg *.JPG *.JPEG *.PNG *.GIF *.png *.gif)")))!="")
    {
        ui->lineEditUrl->setText("file://"+nomFichier);
    }
}

QSize ImageEdit::sizeHint() const
{
    return QSize(2*ui->pushButtonParcourir->sizeHint().width()+(ui->lineEditUrl->text().length()/17)*ui->lineEditUrl->sizeHint().width(),
                 20+std::max(ui->pushButtonParcourir->sizeHint().height(),ui->lineEditUrl->sizeHint().height()));
}
