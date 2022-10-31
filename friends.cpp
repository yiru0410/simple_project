#include "friends.h"
#include "ui_friends.h"

Friends::Friends(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Friends)
{
    ui->setupUi(this);
}

Friends::~Friends()
{
//    this->parentWidget()->show();
    delete ui;
}

void Friends::on_pushButton_clicked()
{
//    this->parentWidget()->show();
    this->deleteLater();
}
