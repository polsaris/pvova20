#include "rdigital.h"
#include "ui_rdigital.h"
#include <QTime>
#include <QTimer>
#include <QDate>
#include "calaix.h"
#include <QPainter>
#include <QPixmap>


RDigital::RDigital(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RDigital)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    calaixx = new calaix(this);
    calaixx->close();

    data_avui();
    fontNormal();

    ui->pushButton->hide();
    ui->pushButton_4->hide();
    ui->c_blanc->hide();

    botons();


}

RDigital::~RDigital()
{
    delete ui;
}



void RDigital::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    QString text2 = time.toString("ss");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->label->setText(text);
    ui->label_3->setText(text2);
}

void RDigital::data_avui() {
    QDate date = QDate::currentDate();
    QString s = date.toString("dddd/MMMM/yyyy");

    ui->label_2->setText(s);
    QFont f("Ubuntu",40,50,QFont::Bold);      //font de la data
    ui->label_2->setFont(f);
    RDigital::setStyleSheet("background-color:white;");      //color fons

}

void RDigital::fontDigital() {
    QFont digital("Segment7",66,QFont::Bold);
    QFont digitalss("Segment7",46,QFont::Bold);
    ui->label->setFont(digital);
    ui->label_3->setFont(digitalss);
}

void RDigital::fontNormal() {
    QFont normal("Ubuntu",70,10,QFont::Bold);
    QFont normalss("Ubuntu",50,10,QFont::Bold);
    ui->label->setFont(normal);
    ui->label_3->setFont(normalss);
}


void RDigital::on_pushButton_clicked()
{
    fontNormal();
    ui->pushButton_2->show();
    ui->pushButton->hide();
}

void RDigital::on_pushButton_2_clicked()
{
    fontDigital();
    ui->pushButton->show();
    ui->pushButton_2->hide();

}

void RDigital::on_pushButton_3_clicked()
{
    QDate date = QDate::currentDate();
        QString s = date.toString("dd/MM/yy");
        ui->label_2->setText(s);
        QFont f("Ubuntu",40,50,QFont::Bold);      //font de la data
        ui->label_2->setFont(f);

        ui->pushButton_4->show();
        ui->pushButton_3->hide();

}

void RDigital::on_pushButton_4_clicked()
{

        data_avui();
        ui->pushButton_3->show();
        ui->pushButton_4->hide();

}


void RDigital::on_pb_calaix_clicked()
{
    calaixx->show();
}

void RDigital::on_pb_analogclock_clicked()
{
    close();
}

void RDigital::color_negre() {
    ui->label->setStyleSheet("QLabel { color : white; }");
    ui->centralWidget->setStyleSheet("QWidget {background-color : black;}");
    ui->label_2->setStyleSheet("QLabel { color : white; }");
    ui->label_3->setStyleSheet("QLabel { color : white; }");
}

void RDigital::color_blanc() {
    ui->label->setStyleSheet("QLabel { color : black; }");
    ui->centralWidget->setStyleSheet("QWidget {background-color : white;}");
    ui->label_2->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setStyleSheet("QLabel { color : black; }");
}

void RDigital::on_c_negre_clicked()
{
    color_negre();
    ui->c_blanc->show();
    ui->c_negre->hide();
    ui->pushButton->setStyleSheet("border: 1px solid white;");
    ui->pushButton_2->setStyleSheet("border: 1px solid white;");
    ui->pushButton_3->setStyleSheet("border: 1px solid white;");
    ui->pushButton_4->setStyleSheet("border: 1px solid white;");
    ui->c_blanc->setStyleSheet("border: 1px solid white;");
    ui->c_negre->setStyleSheet("border: 1px solid white;");
}

void RDigital::on_c_blanc_clicked()
{
    color_blanc();
    ui->c_negre->show();
    ui->c_blanc->hide();
    ui->pushButton->setStyleSheet("");
    ui->pushButton_2->setStyleSheet("");
    ui->pushButton_3->setStyleSheet("");
    ui->pushButton_4->setStyleSheet("");
    ui->c_blanc->setStyleSheet("");
    ui->c_negre->setStyleSheet("");
}

void RDigital::botons() {
    QPixmap blanc("/home/pi/prova20/imatges/blanc4.jpeg");
    QIcon b_blanc(blanc);
    ui->c_blanc->setIcon(b_blanc);
    ui->c_blanc->setIconSize(QSize(97,97));

    QPixmap negre("/home/pi/prova20/imatges/negre2.png");
    QIcon b_negre(negre);
    ui->c_negre->setIcon(b_negre);
    ui->c_negre->setIconSize(QSize(97,97));

    QPixmap fubuntu("/home/pi/prova20/imatges/fontubuntu2.png");
    QIcon b_fubuntu(fubuntu);
    ui->pushButton->setIcon(b_fubuntu);
    ui->pushButton->setIconSize(QSize(97,97));

    QPixmap f7s("/home/pi/prova20/imatges/7segment.jpg");
    QIcon b_f7s(f7s);
    ui->pushButton_2->setIcon(b_f7s);
    ui->pushButton_2->setIconSize(QSize(97,97));

    QPixmap datall("/home/pi/prova20/imatges/datalletres2.jpg");
    QIcon b_datall(datall);
    ui->pushButton_4->setIcon(b_datall);
    ui->pushButton_4->setIconSize(QSize(97,97));

    QPixmap datanu("/home/pi/prova20/imatges/datanum.jpg");
    QIcon b_datanu(datanu);
    ui->pushButton_3->setIcon(b_datanu);
    ui->pushButton_3->setIconSize(QSize(97,97));

    QPixmap dreta("/home/pi/prova20/imatges/dretabo.png");
    QIcon b_dreta(dreta);
    ui->pb_analogclock->setIcon(b_dreta);
    ui->pb_analogclock->setIconSize(QSize(75,480));

    QPixmap esquerra("/home/pi/prova20/imatges/esquerra.png");
    QIcon b_esquerra(esquerra);
    ui->pb_calaix->setIcon(b_esquerra);
    ui->pb_calaix->setIconSize(QSize(75,480));


}
