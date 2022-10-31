#ifndef ACCOUNT_CREATE_H
#define ACCOUNT_CREATE_H

#include <QDialog>
#include <QButtonGroup>
#include <vector>
namespace Ui {
class Account_create;
}

class Account_create : public QDialog
{
    Q_OBJECT

public:
    explicit Account_create(QWidget *parent = nullptr);
    ~Account_create();
    std::vector<int> hobby_list;
    std::vector<int> grade_list;
    void checkedIndex();
    std::string supportuser();

private slots:
    void on_pushButton_back_clicked();
    void slots_grade_selection();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QButtonGroup *gradegroup;
    Ui::Account_create *ui;
    QButtonGroup *hobbygroup;
    QStringList strList;


};

#endif // ACCOUNT_CREATE_H
