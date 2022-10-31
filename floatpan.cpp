#include "floatpan.h"
#include "ui_floatpan.h"

Floatpan::Floatpan(QWidget *parent,QString text) :
    QWidget(parent),
    ui(new Ui::Floatpan)
{
    ui->setupUi(this);
    ui->textEdit->setText(text);
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    ui->textEdit->setFont(font);
}

Floatpan::~Floatpan()
{
    delete ui;
}

void Floatpan::setCustomText(QString text)
{
    ui->textEdit->setText(text);
}
