#ifndef MYQUESTION_H
#define MYQUESTION_H

#include <QWidget>
#include <fstream>
#include <iostream>
#include <string>
#include <QString>
namespace Ui {
class MyQuestion;
}

class MyQuestion : public QWidget
{
    Q_OBJECT

public:
    explicit MyQuestion(QWidget *parent = nullptr);
    ~MyQuestion();
    void show_question();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyQuestion *ui;
};

#endif // MYQUESTION_H
