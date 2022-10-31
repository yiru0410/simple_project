#ifndef FRIENDS_H
#define FRIENDS_H

#include <QWidget>

namespace Ui {
class Friends;
}

class Friends : public QWidget
{
    Q_OBJECT

public:
    explicit Friends(QWidget *parent = nullptr);
    ~Friends();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Friends *ui;
};

#endif // FRIENDS_H
