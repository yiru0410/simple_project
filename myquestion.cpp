#include "myquestion.h"
#include "ui_myquestion.h"
using namespace std;

MyQuestion::MyQuestion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyQuestion)
{
    ui->setupUi(this);


    //###########################
    //######### 绝对地址 #########
    //###########################
    QPixmap pixmap("/Users/maoyiru/Year_two/hackthon/hack2/src/coffee.jpg");
    QPalette palette;
    ui->setupUi(this);
    int width = this->width();
    int height = this->height();
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    palette.setBrush(backgroundRole(), QBrush(fitpixmap));
    setPalette(palette);



    show_question();
}

MyQuestion::~MyQuestion()
{
    delete ui;
}
void MyQuestion::show_question(){
    fstream open_mq;
    open_mq.open("/Users/maoyiru/Year_two/hackthon/hack2/src/myquestion.txt",ios::in);
    string out_mq;
    string buf;
    string question = "";
    string answer = "";
    while(getline(open_mq,buf)){
        out_mq += "\n";
        if(buf[0] == 'Q'){
            question = buf;
            out_mq += question;
        } else if (buf[0] == 'A'){
            answer = buf;
            if (answer.size() < 3){
                out_mq += "暂时没有人回复哦。";
                continue;
            }
            out_mq += answer;
        }

    }
    ui->label->setWordWrap(true);
    ui->label->setAlignment(Qt::AlignTop);
    ui->label->setText(QString::fromStdString(out_mq));

}
void MyQuestion::on_pushButton_clicked()
{
    close();
}
