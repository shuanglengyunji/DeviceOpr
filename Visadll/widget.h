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

    //操作函数
    QString Send_And_Get(QString cmd);  //发送指令读取回参

    void Send_No_Get(QString cmd);      //发送指令不读取回参

    double Get_Number(QString cmd); //获取1个数据


private slots:
    void on_bt_Search_clicked();

    void on_bt_SendCMD_clicked();

    void on_Time_Interval_clicked();

    void on_Timer_button_clicked();

    void Timing();

    void on_bt_SendCMD_Get_clicked();

    void on_Voltage_Set_clicked();

    void on_CMD_TINTerval_clicked();

    void on_textEdit_Receive_textChanged();

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
