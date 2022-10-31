#include "logindlg.h"
#include "ui_logindlg.h"
#include "filesys.h"
#include "ui_filesys.h"
#include <QMessageBox>
#include <QTimer>
#include <QPainter>
#include <QPushButton>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog{border-image: url(/Users/maoyiru/Year_two/hackthon/hack2/src/1.jpg);}");
    ad_time =new QTimer(this);
    ad_time->setInterval (5000) ;
    connect(ad_time,SIGNAL(timeout()),this,SLOT(updateAd()));
    ad_time->start();


    QImage *img=new QImage; //新建一个image对象
    img->load("/Users/maoyiru/Year_two/hackthon/hack2/src/aftertitle.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    ui->title->setPixmap(QPixmap::fromImage(*img));
    QPixmap pixmap = QPixmap::fromImage(*img);

    int width = ui->title->width();
    int height = ui->title->height();
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    //QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    //ui->friend1->setText(showText);
    ui->title->setPixmap(fitpixmap);


    QImage *tag1=new QImage;
    tag1->load("/Users/maoyiru/Year_two/hackthon/hack2/src/num1.png");
    ui->friend1->setPixmap(QPixmap::fromImage(*tag1));
    QPixmap tag1pixmap = QPixmap::fromImage(*tag1);
    int width_num = ui->friend1->width();
    int height_num = ui->friend1->height();
    QPixmap fittag1 = tag1pixmap.scaled( width_num,height_num, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->friend1->setPixmap(fittag1);

    QImage *tag2=new QImage;
    tag2->load("/Users/maoyiru/Year_two/hackthon/hack2/src/num2.png");
    ui->friend2->setPixmap(QPixmap::fromImage(*tag2));
    QPixmap tag2pixmap = QPixmap::fromImage(*tag2);
    QPixmap fittag2 = tag2pixmap.scaled( width_num,height_num, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->friend2->setPixmap(fittag2);


    QImage *tag3=new QImage;
    tag3->load("/Users/maoyiru/Year_two/hackthon/hack2/src/num3.png");
    ui->friend3->setPixmap(QPixmap::fromImage(*tag3));
    QPixmap tag3pixmap = QPixmap::fromImage(*tag3);
    QPixmap fittag3 = tag3pixmap.scaled( width_num,height_num, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->friend3->setPixmap(fittag3);


    QImage *tag4 = new QImage;
    tag4->load("/Users/maoyiru/Year_two/hackthon/hack2/src/num4.png");
    ui->friend4->setPixmap(QPixmap::fromImage(*tag4));
    QPixmap tag4pixmap = QPixmap::fromImage(*tag4);
    QPixmap fittag4 = tag4pixmap.scaled( width_num,height_num, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->friend4->setPixmap(fittag4);

    QImage *tag5 = new QImage;
    tag5->load("/Users/maoyiru/Year_two/hackthon/hack2/src/num5.png");
    ui->friend5->setPixmap(QPixmap::fromImage(*tag5));
    QPixmap tag5pixmap = QPixmap::fromImage(*tag5);
    QPixmap fittag5 = tag5pixmap.scaled( width_num,height_num, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->friend5->setPixmap(fittag5);

    QImage *friendlist =new QImage; //新建一个image对象
    friendlist->load("/Users/maoyiru/Year_two/hackthon/hack2/src/friendlist.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    ui->friendlist->setPixmap(QPixmap::fromImage(*friendlist));
    QPixmap friendlistpixmap = QPixmap::fromImage(*friendlist);
    QPixmap fitfriendlist = friendlistpixmap.scaled(ui->friendlist->width(), ui->friendlist->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    //QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    //ui->friend1->setText(showText);
    ui->friendlist->setPixmap(fitfriendlist);

    QImage *state1 = new QImage;
    state1->load("/Users/maoyiru/Year_two/hackthon/hack2/src/good.png");
    ui->tag1->setPixmap(QPixmap::fromImage(*state1));
    QPixmap state1pixmap = QPixmap::fromImage(*state1);
    int width_state = ui->tag1->width();
    int height_state = ui->tag1->height();
    QPixmap fitstate1 = state1pixmap.scaled(width_state,height_state, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->tag1->setPixmap(fitstate1);
    ui->tag2->setPixmap(fitstate1);

    QImage *state2= new QImage;
    state2->load("/Users/maoyiru/Year_two/hackthon/hack2/src/bad.png");
    ui->tag3->setPixmap(QPixmap::fromImage(*state2));
    QPixmap state2pixmap = QPixmap::fromImage(*state2);
    QPixmap fitstate2 = state2pixmap.scaled(width_state,height_state, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->tag3->setPixmap(fitstate2);
    ui->tag4->setPixmap(fitstate2);
    ui->tag5->setPixmap(fitstate2);

    QString backButtonName;
    QPixmap backButton;
    backButtonName = "/Users/maoyiru/Year_two/hackthon/hack2/src/back2.jpg";
    backButton.load(backButtonName);
    int width2 = ui->refreshBtn->width();
    int height2 = ui->refreshBtn->height();
    QPixmap fixbackButton = backButton.scaled(width2, height2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->refreshBtn->setIcon(fixbackButton);
    ui->refreshBtn->show();

    QString picNameA;
    QPixmap pixmapA;
    picNameA = "/Users/maoyiru/Year_two/hackthon/hack2/src/111.jpg";
    pixmapA.load(picNameA);
    int width_ad = ui->ad->width()*2;
    int height_ad = ui->ad->height()*2;
    QPixmap fixad = pixmapA.scaled(width_ad, height_ad, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->ad->setIconSize(fixad.size());
    ui->ad->setIcon(fixad);
    ui->ad->show();
    ui->adinf->hide();
    ui->user->hide();
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
}



LoginDlg::~LoginDlg()
{
    delete ui;
}


void LoginDlg::on_refreshBtn_clicked(){
    this->parentWidget()->show();
//    delete this->parentWidget();
    delete this;
}


void LoginDlg::updateAd(){
    QString picNameA;
    QPixmap pixmapA;
    picNameA = "/Users/maoyiru/Year_two/hackthon/hack2/src/444.png";
    pixmapA.load(picNameA);
    int width_ad = ui->ad->width()*2;
    int height_ad = ui->ad->height()*2;
    QPixmap fixad = pixmapA.scaled(width_ad, height_ad, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->ad->setIconSize(fixad.size());
    ui->ad->setIcon(fixad);
    ui->ad->show();
}


void LoginDlg::on_ad_clicked(){
    ui->adinf->setStyleSheet("background-color:rgba(72,61,139,0.85)");
    ui->label_2->setWordWrap(true);
    ui->label_2->setAlignment(Qt::AlignTop);
    ui->adinf->show();
    ui->go->hide();
    ui->go_2->hide();
    ui->go_3->hide();
    ui->go_4->hide();
    ui->go_5->hide();
    ui->know->hide();
    ui->know_2->hide();
    ui->know_3->hide();
    ui->know_4->hide();
    ui->know_5->hide();
    ui->returnf->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
}


void LoginDlg::on_returnf_clicked(){
    ui->go->show();
    ui->go_2->show();
    ui->go_3->show();
    ui->go_4->show();
    ui->go_5->show();
    ui->know->show();
    ui->know_2->show();
    ui->know_3->show();
    ui->know_4->show();
    ui->know_5->show();
    ui->adinf->hide();
}


void LoginDlg::on_go_clicked()
{
    QDialog *dlg = new FileSys(this);
    dlg->show();
}


void LoginDlg::on_know_clicked()
{
    ui->user->setStyleSheet("background-color:rgba(72,61,139,0.85)");
    ui->user->show();
    ui->know->hide();
    ui->know_2->hide();
    ui->know_3->hide();
    ui->know_4->hide();
    ui->know_5->hide();

    ui->userreturn->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
}


void LoginDlg::on_userreturn_clicked()
{
    ui->user->hide();
    ui->know->show();
    ui->know_2->show();
    ui->know_3->show();
    ui->know_4->show();
    ui->know_5->show();

}


