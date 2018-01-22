#ifndef TB_CALAIX_H
#define TB_CALAIX_H
#include <QWidget>

class calaix;
namespace Ui {
class tb_calaix;
}

class tb_calaix : public QWidget
{
    Q_OBJECT

public:
    explicit tb_calaix(QWidget *parent = 0);
    ~tb_calaix();

private slots:

 void on_pushButton_clicked();

private:
    Ui::tb_calaix *ui;
    calaix *calaixx;
};

#endif // TB_CALAIX_H
