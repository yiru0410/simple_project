#ifndef FILESYS_H
#define FILESYS_H

#include <QDialog>

namespace Ui {
class FileSys;
}

class FileSys : public QDialog
{
    Q_OBJECT

public:
    explicit FileSys(QWidget *parent = nullptr);
    ~FileSys();
private slots:
    void on_clear_clicked();
    void on_update_clicked();
private:
    Ui::FileSys *ui;

};

#endif // FILESYS_H
