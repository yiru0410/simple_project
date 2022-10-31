#ifndef FLOATPAN_H
#define FLOATPAN_H

#include <QWidget>

namespace Ui {
class Floatpan;
}

class Floatpan : public QWidget
{
    Q_OBJECT

public:
    explicit Floatpan(QWidget *parent = nullptr, QString text = "default");
    ~Floatpan();

    void setCustomText(QString text);

private:
    Ui::Floatpan *ui;
};

#endif // FLOATPAN_H
