#include "users.h"
#include "ui_users.h"
#include "QPalette"
#include "QPixmap"
#include "account_info.h"
#include "ui_account_info.h"
#include "gv.h"
#include "account_create.h"
#include "ui_account_create.h"


Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);

    ui->textEdit_email->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit_email->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    ui->textEdit_password->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit_password->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
//    this->setAttribute(Qt::WA_StyledBackground,true);
//    this->setStyleSheet("background-color: rgb(47,79,79)");
//    QPalette pal = this->palette();
//    pal.setBrush(QPixmap("/Users/maoyiru/Year_two/hackthon/hack/src/2.jpg"));
    this->setStyleSheet("QDialog{border-image: url(/Users/maoyiru/Year_two/hackthon/hack/src/2.jpg);}");
//    ui->widget_back1->setAttribute(Qt::WA_StyledBackground,true);
//    ui->widget_back1->setStyleSheet("background-color: rgb(47,79,79)");

    ui->widget_back1->setAutoFillBackground(true);
    QPalette palette = ui->widget_back1->palette();
    palette.setColor(QPalette::Background, QColor(100,100,100,50));
    ui->widget_back1->setPalette(palette);
    palette = ui->textEdit_email->palette();
    palette.setColor(QPalette::Base,QColor(255,255,255,80));
    ui->textEdit_email->setPalette(palette);

    palette = ui->textEdit_password->palette();
    palette.setColor(QPalette::Base,QColor(255,255,255,80));
    ui->textEdit_password->setPalette(palette);



    ui->commandLinkButton->setStyleSheet("background-color: rgb(255, 255, 255, 60);");

    ui->label->setStyleSheet("color:white;");
    ui->label_email->setStyleSheet("color:white;");
    ui->label_password->setStyleSheet("color:white;");
    ui->commandLinkButton->setStyleSheet("color:white;");
    ui->commandLinkButton->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton_back->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
//    ui->pushButton_back->setStyleSheet(tr("background-image: url(/Users/maoyiru/Year_two/hackthon/hack/src/1.jpg);"));
    ui->pushButton_login->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
//    palette = ui->pushButton_login->palette();
//    palette.setColor(QPalette::Base,QColor(255,255,255,80));
//    ui->pushButton_login->setPalette(palette);

}

Users::~Users()
{
    delete ui;
}


void Users::on_pushButton_login_clicked()
{
    QDialog *dlg = new Account_info(this);
    dlg->show();
    this->hide();
}

void Users::on_pushButton_back_clicked()
{
    this->parentWidget()->show();
    delete this;
}

void Users::on_commandLinkButton_clicked()
{
    QDialog *dlg = new Account_create(this);
    dlg->show();
    this->hide();
}
