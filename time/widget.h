#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QTime time;
    QTimer timer;

private slots:
    void on_start_pushButton_clicked();

    void timeout_slot();

    void on_stop_pushButton_clicked();

    void on_reset_pushButton_clicked();

    void on_point_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
