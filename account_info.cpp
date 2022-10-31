#include "account_info.h"
#include "ui_account_info.h"

Account_info::Account_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account_info)
{
    ui->setupUi(this);
    ui->widget_account_back->setAutoFillBackground(true);
    QPalette palette = ui->widget_account_back->palette();
    palette.setColor(QPalette::Background, QColor(100,100,100,50));
    ui->widget_account_back->setPalette(palette);
    ui->label->setStyleSheet("color:white;");
    ui->label_2->setStyleSheet("color:white;");
    ui->label_3->setStyleSheet("color:white;");
    ui->label_4->setStyleSheet("color:white;");
    ui->label_5->setStyleSheet("color:white;");
    ui->label_6->setStyleSheet("color:white;");
    ui->label_plan->setStyleSheet("color:white;");
    ui->label_grade->setStyleSheet("color:white;");
    ui->label_hobby->setStyleSheet("color:white;");
    ui->label_major->setStyleSheet("color:white;");
    ui->label_usename->setStyleSheet("color:white;");
    ui->label_credits->setStyleSheet("color:white;");
    ui->pushButton_back->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
}

Account_info::~Account_info()
{
    delete ui;
}

void Account_info::on_pushButton_back_clicked()
{
    this->parentWidget()->parentWidget()->show();
//    delete this->parentWidget();
    delete this;
}
