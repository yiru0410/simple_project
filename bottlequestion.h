#ifndef BOTTLEQUESTION_H
#define BOTTLEQUESTION_H

#include <QWidget>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
namespace Ui {
class BottleQuestion;
}

class BottleQuestion : public QWidget
{
    Q_OBJECT

public:
    explicit BottleQuestion(QWidget *parent = nullptr);
    ~BottleQuestion();
    void scan_qb();
    std::vector<std::string>questionBank;
    unsigned int pick;
    char tag = 'U';

private slots:
    void on_pushButton_clicked();

private:
    Ui::BottleQuestion *ui;
};

#endif // BOTTLEQUESTION_H
