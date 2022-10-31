#ifndef BOTTLE_H
#define BOTTLE_H

#include <QWidget>
#include "bottlequestion.h"
#include "bottlesender.h"
#include "myquestion.h"
namespace Ui {
class Bottle;
}

class Bottle : public QWidget
{
    Q_OBJECT

public:
    explicit Bottle(QWidget *parent = nullptr);
    ~Bottle();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Bottle *ui;
};

#endif // BOTTLE_H
