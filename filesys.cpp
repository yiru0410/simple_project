#include "filesys.h"
#include "ui_filesys.h"
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
#include <QDebug>
#include<fstream>
#include <sys/dir.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include "vector"
#include <iostream>

FileSys::FileSys(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileSys)
{
    ui->setupUi(this);
    ui->qlabel->setWordWrap(true);
    ui->qlabel->setAlignment(Qt::AlignTop);

}

FileSys::~FileSys()
{
    delete ui;
}


void FileSys::on_clear_clicked(){
    ui->myanswer->clear();
}



void FileSys::on_update_clicked(){
    QString newanser = ui->myanswer->toPlainText();
    std::string update_content = newanser.toStdString();
    ui->qlabel->setText(ui->qlabel->text()+"\n\n我的答案："+newanser);
}
