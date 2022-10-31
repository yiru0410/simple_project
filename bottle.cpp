#include "bottle.h"
#include "ui_bottle.h"

Bottle::Bottle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bottle)
{
    //###########################
    //######### 绝对地址 #########
    //###########################
    QPixmap pixmap("/Users/maoyiru/Year_two/hackthon/hack2/src/eat.jpg");
    QPalette palette;

//    int width = this->width();
//        int height = this->height();
//        //QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
//        QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
//        //ui->friend1->setText(showText);
//        palette.setBrush(backgroundRole(), QBrush(fitpixmap));
//        setPalette(palette);
        //QPixmap pixmap(QString::fromUtf8("./icon/background.png"));//当前文件夹下面的图片bai
//        setPalette(palette);


    ui->setupUi(this);
    int width = this->width();
    int height = this->height();
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    //QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    //ui->friend1->setText(showText);
    palette.setBrush(backgroundRole(), QBrush(fitpixmap));
    setPalette(palette);
    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton_2->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton_3->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
}

Bottle::~Bottle()
{
    delete ui;
}

void Bottle::on_pushButton_clicked()
{
    BottleQuestion *bq = new BottleQuestion();
    //connect(bq,SIGNAL(send_question(QString)),this,SLOT(receive_question(QString)));
    bq->setWindowTitle("恐龙带来的信件");
    bq->show();
}


void Bottle::on_pushButton_2_clicked()
{
    BottleSender *bs = new BottleSender();
    bs->setWindowTitle("我的恐龙");
    bs->show();
}

void Bottle::on_pushButton_3_clicked()
{
    MyQuestion *mq = new MyQuestion();
    mq->setWindowTitle("我的信件");
    mq->show();
}
