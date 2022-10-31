#ifndef BOTTLESENDER_H
#define BOTTLESENDER_H

#include <QWidget>
#include <iostream>
#include <fstream>
#include <string>
namespace Ui {
class BottleSender;
}

class BottleSender : public QWidget
{
    Q_OBJECT

public:
    explicit BottleSender(QWidget *parent = nullptr);
    ~BottleSender();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BottleSender *ui;
};

#endif // BOTTLESENDER_H
