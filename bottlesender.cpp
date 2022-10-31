#include "bottlesender.h"
#include "ui_bottlesender.h"
using namespace std;
BottleSender::BottleSender(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottleSender)
{
    ui->setupUi(this);


    //###########################
    //######### 绝对地址 #########
    //###########################
    int width = this->width();
    int height = this->height();



    QPixmap pixmap("/Users/maoyiru/Year_two/hackthon/hack2/src/ice.png");
    QPalette palette;
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    //QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    //ui->friend1->setText(showText);
    palette.setBrush(backgroundRole(), QBrush(fitpixmap));
    setPalette(palette);
    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,255,255,30)));
    ui->textEdit->setPalette(pl);
    ui->label->setStyleSheet("color:white;");



}

BottleSender::~BottleSender()
{
    delete ui;
}

void BottleSender::on_pushButton_clicked()
{
//    fstream open_mq;
//    open_mq.open("/Users/ctl/Desktop/studypool/myquestion.txt",ios::in);
//    string buf;
//    string question;
//    string answer;
//    while(getline(open_mq,buf)){
//        if(buf[0] == 'Q'){
//            question = buf.substr(2);
//        } else if (buf[0] == 'A'){
//            answer = buf.substr(2);
//        }
//    }
    ofstream out_mq;

    //###########################
    //######### 绝对地址 #########
    //###########################

    out_mq.open("/Users/maoyiru/Year_two/hackthon/hack2/src/myquestion.txt",ios::app);
    out_mq<<"\nQ:"<<ui->textEdit->toPlainText().toStdString();
    out_mq<<"\nA:";
    out_mq.close();
    close();
}
