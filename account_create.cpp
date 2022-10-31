#include "account_create.h"
#include "ui_account_create.h"
#include <QComboBox>
#include <QButtonGroup>
#include <QDebug>
#include <fstream>
#include <QWidget>
#include <QString>
#include <iostream>
#include "QPalette"
Account_create::Account_create(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account_create)
{
    ui->setupUi(this);
    QButtonGroup *gradegroup = new QButtonGroup;
    gradegroup->addButton(ui->radioButton_primary);
    gradegroup->addButton(ui->radioButton_mid);
    gradegroup->addButton(ui->radioButton_3);
    gradegroup->addButton(ui->radioButton_university);
    ui->radioButton_primary->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->radioButton_mid->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->radioButton_3->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->radioButton_university->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton_2->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
    ui->pushButton_back->setStyleSheet("background-color: rgba(255, 255, 255, 60)");
//    ui->radioButton_primary->setChecked(true);
    connect(ui->radioButton_primary,SIGNAL(clicked(bool)),this,SLOT(slots_grade_selection()));
    connect(ui->radioButton_mid,SIGNAL(clicked(bool)),this,SLOT(slots_grade_selection()));
    connect(ui->radioButton_3,SIGNAL(clicked(bool)),this,SLOT(slots_grade_selection()));
    connect(ui->radioButton_university,SIGNAL(clicked(bool)),this,SLOT(slots_grade_selection()));

    ui->label->setStyleSheet("color:white;");
    ui->label_ps->setStyleSheet("color:white;");
    ui->label_plan->setStyleSheet("color:white;");
    ui->label_major->setStyleSheet("color:white;");
    ui->label_hobbies->setStyleSheet("color:white;");
    ui->label_username->setStyleSheet("color:white;");
    ui->label_username_2->setStyleSheet("color:white;");
    ui->label_education->setStyleSheet("color:white;");
    ui->label_enter_password->setStyleSheet("color:white;");
    ui->checkBox->setStyleSheet("color:white;");
    ui->checkBox_2->setStyleSheet("color:white;");
    ui->checkBox_3->setStyleSheet("color:white;");
    ui->checkBox_4->setStyleSheet("color:white;");
    ui->checkBox_5->setStyleSheet("color:white;");
    ui->checkBox_6->setStyleSheet("color:white;");
    ui->checkBox_7->setStyleSheet("color:white;");
    ui->checkBox_8->setStyleSheet("color:white;");


    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,255,255,30)));
    ui->textEdit->setPalette(pl);

    pl = ui->textEdit_2->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,255,255,30)));
    ui->textEdit_2->setPalette(pl);

    pl = ui->textEdit_3->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,255,255,30)));
    ui->textEdit_3->setPalette(pl);

    pl = ui->textEdit_4->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,255,255,30)));
    ui->textEdit_4->setPalette(pl);

    pl = ui->textEdit_5->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,255,255,30)));
    ui->textEdit_5->setPalette(pl);
}

Account_create::~Account_create()
{
    delete ui;
}

void Account_create::on_pushButton_back_clicked()
{
    this->parentWidget()->show();
    delete this;
}

void Account_create::slots_grade_selection(){
    if (ui->radioButton_primary->isChecked()){
        ui->comboBox_major->clear();
        strList<<"无";

        ui->comboBox_major->addItems(strList);

    } else if(ui->radioButton_mid->isChecked()){
        ui->comboBox_major->clear();
        strList<<"无";
        ui->comboBox_major->addItems(strList);
    } else if(ui->radioButton_3->isChecked()){
        ui->comboBox_major->clear();
        strList<<"文科"<<"理科";
        ui->comboBox_major->addItems(strList);
    } else if(ui->radioButton_university->isChecked()){
        ui->comboBox_major->clear();
        ui->comboBox_major->update();
        strList<<"国际商务"<<"经济学"<<"市场营销"<<"金融学"<<"会计学"<<"金融工程"<<"电子信息工程"<<"数学与应用数学"<<"新能源科学与工程"<<"英语"<<"翻译"<<"应用心理学"<<"生物医学工程"<<"生物信息学"<<"药学"<<"数据科学"<<"统计学"<<"计算机科学与技术";
        ui->comboBox_major->addItems(strList);
    }
//    switch(gradegroup->checkedId()){
//    case 0 :
//        qDebug() <<"primary"<<endl;
////        ui->comboBox_major->clear();
////        strList<<""<<"上海"<<"天津"<<"河北省"<<"山东省"<<"山西省";
////        ui->comboBox_major->addItems(strList);
//        break;
//    case 1:
//        qDebug() <<"middle"<<endl;
//        break;
//    case 2:
//        qDebug() <<"high"<<endl;
//        break;
//    case 3:
//        qDebug() <<"university"<<endl;
//        break;
//    }
}


void Account_create::checkedIndex(){

    if(ui->checkBox->isChecked()){
        hobby_list[0] = 1;
    }
    if(ui->checkBox_2->isChecked()){
        hobby_list[1] = 1;
    }
    if(ui->checkBox_3->isChecked()){
        hobby_list[2] = 1;
    }
    if(ui->checkBox_4->isChecked()){
        hobby_list[3] = 1;
    }
    if(ui->checkBox_5->isChecked()){
        hobby_list[4] = 1;
    }
    if(ui->checkBox_6->isChecked()){
        hobby_list[5] = 1;
    }
    if(ui->checkBox_7->isChecked()){
        hobby_list[6] = 1;
    }
    if(ui->checkBox_8->isChecked()){
        hobby_list[7] = 1;
    }

    if(ui->radioButton_primary->isChecked()){
        grade_list[0] = 1;
    }
    if(ui->radioButton_mid->isChecked()){
        grade_list[1] = 1;
    }
    if(ui->radioButton_3->isChecked()){
        grade_list[2] = 1;
    }
    if(ui->radioButton_university->isChecked()){
        grade_list[3] = 1;
    }
}

std::string Account_create::supportuser(){
    std::string username = "Misa";
    std::fstream file;
    std::string line;
    file.open("/Users/maoyiru/Year_two/hackthon/hack/src/user_info.txt");
    std::string sub_username;
    int similarity=0;
    while(getline(file,line)){
        if (line[0] == '#'){
             sub_username = line.substr(2,line.length()-2);
        }
        else{
            for (int i =0; i<4;i++){
                int line_i = int(line[i])-48;
                if(line_i == grade_list[i] && line_i==1){
                    int sub_similarity = 0;
                    for (int i = -8;i<0;i++){
                        int s_i = int(line[i])-48;
                        if (s_i==hobby_list[i+8]){
                            sub_similarity +=1 ;
                        }
                    }
                    if(sub_similarity>=similarity){
                        similarity = sub_similarity;
                        username = sub_username;
                    }
                    username = sub_username;
                }
            }
        }
    }
    std::cout<<username<<std::endl;
    return username;
}

void Account_create::on_pushButton_clicked()
{
    hobby_list = {0,0,0,0,0,0,0,0};
    grade_list = {0,0,0,0};
//    qDebug()<<hobby_list[1]<<endl;
    checkedIndex();
//    qDebug()<<hobby_list[0]<<hobby_list[1]<<endl;
    this->parentWidget()->show();
    delete this;
}


void Account_create::on_pushButton_2_clicked()
{
    hobby_list = {0,0,0,0,0,0,0,0};
    grade_list = {0,0,0,0};
    checkedIndex();
    std::string username = supportuser();
//    std::string username = "Misa";
    QString qusername = QString::fromStdString(username);
    ui->textEdit_4->setText(qusername);
    ui->textEdit_4->update();
}
