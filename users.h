#ifndef USERS_H
#define USERS_H

#include <QDialog>

namespace Ui {
class Users;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

private slots:

    void on_pushButton_login_clicked();

    void on_pushButton_back_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::Users *ui;
};

#endif // USERS_H
