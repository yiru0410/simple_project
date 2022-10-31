#ifndef ACCOUNT_INFO_H
#define ACCOUNT_INFO_H

#include <QDialog>

namespace Ui {
class Account_info;
}

class Account_info : public QDialog
{
    Q_OBJECT

public:
    explicit Account_info(QWidget *parent = nullptr);
    ~Account_info();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::Account_info *ui;
};

#endif // ACCOUNT_INFO_H
