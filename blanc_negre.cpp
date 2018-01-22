#include "blanc_negre.h"
#include "ui_blanc_negre.h"

Blanc_negre::Blanc_negre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Blanc_negre)
{
    ui->setupUi(this);
}

Blanc_negre::~Blanc_negre()
{
    delete ui;
}
