#include "opcions.h"
#include "ui_opcions.h"
#include <opiwatch.h>

Opcions::Opcions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Opcions)
{
    ui->setupUi(this);


}

Opcions::~Opcions()
{
    delete ui;

}


void Opcions::on_p_6_clicked()
{
    close();
}
