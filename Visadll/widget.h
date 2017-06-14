#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>

#include "../Ni/include/visa.h"


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


    //连接设备所需
    char instrDescriptor[VI_FIND_BUFLEN];
    ViUInt32 numInstrs;
    ViFindList findList;
    ViSession defaultRM, instr;
    ViStatus status;
    ViUInt32 retCount;
    ViUInt32 writeCount;
    unsigned char buffer[100];
    char stringinput[512];

};

#endif // WIDGET_H
