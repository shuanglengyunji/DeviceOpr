#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDir>
#include <QTextStream>


namespace Ui {
class Widget;
}


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_bt_Search_clicked();

    void on_bt_SendCMD_clicked();

    void on_get_fre_clicked();

    void on_Time_Interval_clicked();

    void on_Timer_button_clicked();


    double Get_Number(QString cmd);

    void Timing();

private:
    Ui::Widget *ui;

    QTimer testTimer;
};

#endif // WIDGET_H
