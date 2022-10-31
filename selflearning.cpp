#include "selflearning.h"
#include "ui_selflearning.h"
#include "floatpan.h"
#include "ui_floatpan.h"
#include "friends.h"
#include "ui_friends.h"

//selfLearning::selfLearning(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::selfLearning)
//{
//    ui->setupUi(this);
//}

//selfLearning::~selfLearning()
//{
//    delete ui;
//}



selfLearning::selfLearning(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selfLearning)
{
    ui->setupUi(this);
    QPixmap bkgnd("/Users/maoyiru/Year_two/hackthon/hack2/src/qmrrkwlmdao.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->init();
    ui->btn_start->setStyleSheet("background-color: rgba(240,255,255,150)");
    ui->btnBack->setStyleSheet("background-color: rgba(240,255,255,150)");
    QPalette pl = ui->textEdit->palette();
        pl.setBrush(QPalette::Base,QBrush(QColor(175,238,238,70)));
        ui->textEdit->setPalette(pl);

//    QImage *img=new QImage; //新建一个image对象
//    img->load("/Users/ty/Desktop/test/CSC3002project/srcs/653cabb0544a9bf00865fa0ce8b7fb4f.gif"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
//    ui->label->setPixmap(QPixmap::fromImage(*img));
//    QPixmap pixmap = QPixmap::fromImage(*img);

//    int width = ui->label->width();
//    int height = ui->label->height();

//    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充

//    //QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
//    //ui->friend1->setText(showText);
//    ui->label->setPixmap(fitpixmap);

//    QLabel* label = new QLabel(this);
    //ui->label_alive->setGeometry(100,110,300,340);
    QMovie * movie = new QMovie("/Users/maoyiru/Year_two/hackthon/hack2/src/653cabb0544a9bf00865fa0ce8b7fb4f.gif");
    movie->setScaledSize(QSize(300,340));
    movie->start();
    ui->label_alive->setMovie(movie);
}

selfLearning::~selfLearning()
{
    delete this->pTimer;
    delete ui;
}
//初始化
void selfLearning::init()
{
    //默认显示
    this->ui->lcd_play->display("00:00:00");
    this->ui->btn_start->text() = "开始";
    this->pTimer = new QTimer;

    ui->hour->setValue(00);
    ui->min->setValue(00);
    ui->sec->setValue(00);
}

//void showfloatwindow(){
//    Floatpan *widget;
//    widget = new Floatpan();
//    widget->setCustomText(QString::fromLocal8Bit("你确定要退出吗？退出小恐龙会饿死哦～"));
//}

//开始
void selfLearning::on_btn_start_clicked()
{
    //获取当前时间
    this->baseTime = this->baseTime.currentTime();
    this->pTimer->start(1);
    //重置状态
    if(this->ui->btn_start->text() == "开始")
    {
        this->ui->label_alive->show();
        this->ui->btn_start->setText("停止");
        this->ui->btnBack->hide();
        //绑定定时器的信号
        connect(this->pTimer,SIGNAL(timeout()),this,SLOT(updateDisplay()));
    }else if(this->ui->btn_start->text()=="停止")
    {
        int ret = QMessageBox::critical(this, tr("温馨提示"),tr("你确定要退出吗？退出小恐龙会饿死哦～"),
                                        QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        switch (ret) {
            case QMessageBox::No:
                break;
        }
//        connect(ui->label,SIGNAL(show()),this,SLOT(showfloatwindow()));
        this->ui->btn_start->setText("开始");
        this->ui->btnBack->show();
        this->ui->lcd_play->display("00:00:00");
        disconnect(this->pTimer,SIGNAL(timeout()),this,SLOT(updateDisplay()));
        this->ui->hour->setValue(00);
        this->ui->min->setValue(00);
        this->ui->sec->setValue(00);
        ui->label_alive->hide();

        QImage *img=new QImage; //新建一个image对象
        img->load("/Users/maoyiru/Year_two/hackthon/hack2/src/bad.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
        ui->label_die->setPixmap(QPixmap::fromImage(*img));
        QPixmap pixmap = QPixmap::fromImage(*img);
        int width = ui->label_die->width();
        int height = ui->label_die->height();

        QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
        ui->label_die->setPixmap(fitpixmap);

    }

}

//结束
//void selfLearning::on_btn_stop_clicked()
//{
//    if(this->ui->btn_stop->text() == "停止")
//    {
//        this->ui->btn_stop->setText("清空");
//        this->pTimer->stop();
//    }
//    else if(this->ui->btn_stop->text() == "清空")
//    {
//        this->ui->btn_stop->setText("停止");
//        this->ui->tb_display->clear();
//        this->ui->lcd_play->display("00:00:00");
//    }

//}

//更新时间
void selfLearning::updateDisplay()
{
    /*
     * 1.点击开始后获取到当前的时间并且赋值给baseTime
     * 2.启动定时器,间隔1s
     * 3.槽函数中再次获取当前的时间currTime
     * 4.计算两个时间的差值t
     * 5.声明一个showTime对象给他加上t的差值
     * 6.格式化后设置显示
     */
    QTime currTime = QTime::currentTime();
    int t = this->baseTime.msecsTo(currTime);
    QTime showTime( ui->hour->value(),ui->min->value(),ui->sec->value());
    showTime = showTime.addMSecs(-t);
    this->timeStr = showTime.toString("hh:mm:ss");
    this->ui->lcd_play->display(timeStr);
}




void selfLearning::on_pushButton_2_clicked()
{
    Floatpan *fp = new Floatpan();
    fp->setWindowTitle("加入房间");
    fp->setCustomText("...");
    fp->show();
}

void selfLearning::on_pushButton_clicked()
{
    Friends *fri = new Friends();
    fri->setWindowTitle("在线好友");
    fri->show();
}

void selfLearning::on_btnBack_clicked()
{
    this->parentWidget()->show();
    delete this;
}
