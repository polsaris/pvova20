#include "tb_calaix.h"
#include "ui_tb_calaix.h"
#include "opiwatch.h"
#include "calaix.h"

tb_calaix::tb_calaix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tb_calaix)
{
    ui->setupUi(this);
    //ui->toolButton->setGeometry(150,200,24,24);

    calaixx = new calaix(this);
    calaixx->hide();


}





tb_calaix::~tb_calaix()
{
    delete ui;
}



void tb_calaix::on_pushButton_clicked()
{
    calaixx->show();
}
