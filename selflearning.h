#ifndef SELFLEARNING_H
#define SELFLEARNING_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QString>
#include <QMovie>

namespace Ui {
class selfLearning;
}

class selfLearning : public QMainWindow
{
    Q_OBJECT

public:
    explicit selfLearning(QWidget *parent = nullptr);
    ~selfLearning();

public:
    void init();

private slots:

    void updateDisplay();

    void on_btn_start_clicked();

    //void on_btn_stop_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_btnBack_clicked();

private:
    Ui::selfLearning *ui;

    QTimer *pTimer;
    QTime baseTime;
    //显示的时间
    QString timeStr;
};

#endif // SELFLEARNING_H
