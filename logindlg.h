#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = nullptr);
    ~LoginDlg();

private slots:
    void updateAd();
    void on_refreshBtn_clicked();
    void on_ad_clicked();
    void on_returnf_clicked();
    void on_go_clicked();
    void on_know_clicked();
    void on_userreturn_clicked();

private:
    Ui::LoginDlg *ui;
     QTimer *ad_time;



};


#endif // LOGINDLG_H
