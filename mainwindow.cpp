#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "users.h"
#include "ui_users.h"
#include "logindlg.h"
#include "ui_logindlg.h"
#include "selflearning.h"
#include "ui_selflearning.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    //###########################
    //######### 绝对地址 #########
    //###########################
    //this->setStyleSheet("QWidget{border-image: url(/Users/ctl/Desktop/home.png);}");

    ui->setupUi(this);
    QPixmap bkgnd("/Users/maoyiru/Year_two/hackthon/hack2/src/home.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->label_3->setStyleSheet("color:white;");
    ui->label_5->setStyleSheet("color:white;");
    ui->label_6->setStyleSheet("color:white;");
    ui->label_hour->setStyleSheet("color:white;");
    ui->label_name->setStyleSheet("color:white;");
    ui->label_hello->setStyleSheet("color:white;");
    ui->label_score->setStyleSheet("color:white;");
    ui->pushButton_4->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton_2->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton_3->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    init_user();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init_user(){
    time_hello();
    ifstream user_information;
    user_information.open("",ios::in);


    //name
    QString name = "游客1";
    ui->label_name->setText(name);



    //score
    int score = 200;
    QString score_s = QString::number(score);
    ui->label_score->setText(score_s);


    //hour
    int hour = 20;
    QString hour_s = QString::number(hour);
    ui->label_hour->setText(hour_s);


    user_information.close();
}
void MainWindow::time_hello(){
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    if( (ltm->tm_hour > 5)&&(ltm->tm_hour<11)){
        ui->label_hello->setText("早上好，");
    } else if(ltm->tm_hour >= 11 && (ltm->tm_hour < 13)){
        ui->label_hello->setText("中午好，");
    } else if(ltm->tm_hour >= 13 && (ltm->tm_hour < 18)){
        ui->label_hello->setText("下午好，");
    } else if(ltm->tm_hour >=18 && (ltm->tm_hour < 24)){
        ui->label_hello->setText("晚上好，");
    } else if(ltm->tm_hour>=0 &&(ltm->tm_hour <=5)){
        ui->label_hello->setText("晚安，");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    Bottle *new_bottle = new Bottle();
    new_bottle->setWindowTitle("bottle");
    new_bottle->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QDialog *dlg = new Users(this);
    dlg->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    QDialog *dlg = new LoginDlg(this);
    dlg->show();
    this->hide();
}

void MainWindow::on_pushButton_clicked()
{
    QWidget *dlg = new selfLearning(this);
    dlg->show();
    this->hide();
}
