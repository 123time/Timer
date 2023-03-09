#include "widget.h"
#include "ui_widget.h"

static int i = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置的时间超时了就会触发超时信号，执行槽函数timer_slot函数
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
    //设置时间的格式初始化
    time.setHMS(0,0,0,0);
    ui->show_label->setText("00:00:00:000");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timeout_slot(){
    time = time.addMSecs(40);
    ui->show_label->setText(time.toString("hh:mm:ss:zzz"));
}

void Widget::on_start_pushButton_clicked()
{
    timer.start(40);
}

void Widget::on_stop_pushButton_clicked()
{
    timer.stop();
}


void Widget::on_reset_pushButton_clicked()
{
    timer.stop();
    time.setHMS(0,0,0,0);
    ui->show_label->setText("00:00:00:000");

    ui->point_textBrowser->clear();
    i = 0;
}


void Widget::on_point_pushButton_clicked()
{
    QString temp;
    i = i + 1;
    temp = QString::number(i);
    ui->point_textBrowser->append(temp +":  "+ time.toString("hh:mm:ss:zzz"));
}

