#ifndef BLANC_NEGRE_H
#define BLANC_NEGRE_H

#include <QWidget>

namespace Ui {
class Blanc_negre;
}

class Blanc_negre : public QWidget
{
    Q_OBJECT

public:
    explicit Blanc_negre(QWidget *parent = 0);
    ~Blanc_negre();

private:
    Ui::Blanc_negre *ui;
};

#endif // BLANC_NEGRE_H
