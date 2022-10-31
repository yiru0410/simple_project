#include "bottlequestion.h"
#include "ui_bottlequestion.h"
#include <ctime>
#include <stdlib.h>
#include <cmath>
using namespace std;
BottleQuestion::BottleQuestion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottleQuestion)
{
    ui->setupUi(this);

    //###########################
    //######### 绝对地址 #########
    //###########################
    int width = this->width();
    int height = this->height();
    QPixmap pixmap("/Users/maoyiru/Year_two/hackthon/hack2/src/watermelon.png");
    QPalette palette;
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    //QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    //ui->friend1->setText(showText);
    palette.setBrush(backgroundRole(), QBrush(fitpixmap));
    setPalette(palette);
    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,255,255,30)));
    ui->textEdit->setPalette(pl);
    scan_qb();
}

BottleQuestion::~BottleQuestion()
{
    delete ui;
}
void BottleQuestion::scan_qb(){
    srand(time(nullptr));
    fstream open_qb;

    //###########################
    //######### 绝对地址 #########
    //###########################
    open_qb.open("/Users/maoyiru/Year_two/hackthon/hack2/src/question_bank.txt",ios::in);
    string buf;
    string question;
    while(getline(open_qb,buf)){
        if(buf.size() <= 1){
            continue;
        }
        if(buf.substr(buf.size()-1,1) == "#"){
            question+=buf.substr(0,buf.size()-1);

            switch (tag) {
            case 'P':
                if(question.substr(0,1)== "Q"&&question.substr(2,1)=="P"){
                    questionBank.push_back(question.substr(7,question.size()-7));
                }
                break;
            case 'M':
                if(question.substr(0,1)== "Q"&&question.substr(2,1)=="M"){
                    questionBank.push_back(question.substr(7,question.size()-7));
                }
                break;
            case 'H':
                if(question.substr(0,1)== "Q"&&question.substr(2,1)=="H"){
                    questionBank.push_back(question.substr(7,question.size()-7));
                }
                break;
            case 'U':
                if(question.substr(0,1)== "Q"&&question.substr(2,1)=="U"){
                    questionBank.push_back(question.substr(7,question.size()-7));
                }
                break;
           }
            question = "";
        } else {
            question += "\n";
            question += buf;
        }
    }
    pick = rand()%questionBank.size();
//    string out_o = questionBank[pick];
//    string out_qs = "";
//    for (int i = 0;i*30<questionBank[pick].size();i++) {
//        out_qs += out_o.substr(i*10,10);
//        out_qs += "\n";
//    }
    ui->label->setGeometry(QRect(20, 50, 800, 27*4));
    ui->label->setWordWrap(true);
    ui->label->setAlignment(Qt::AlignTop);
    QString out_q = QString::fromStdString(questionBank[pick]);
    ui->label->setText(out_q);
    open_qb.close();
}

void BottleQuestion::on_pushButton_clicked()
{
    ofstream edited_file;


    //###########################
    //######### 绝对地址 #########
    //###########################
    edited_file.open("/Users/maoyiru/Year_two/hackthon/hack2/src/question_bank.txt",ios::app);
    QString q = ui->textEdit->toPlainText();
    string num = to_string(pick);
    while(num.size()<4){
        num = "0"+num;
    }
    edited_file<<"\nA:"<<tag<<num<<q.toStdString()<<"#";
    close();
}
