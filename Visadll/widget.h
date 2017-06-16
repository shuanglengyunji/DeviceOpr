#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDateTime>

#include "measurethread.h"

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

    //定时采样控制函数

    void Timer_Start(int ms);

    void Timer_Stop();

    //单独的采样函数
    void Timing1();  //定时器服务函数

    void Continue_Start();
    void Continue_Stop();
    double Continue_Get_Number(QString cmd);

private slots:
    void on_bt_Search_clicked();

    void on_bt_SendCMD_clicked();

    void on_Time_Interval_clicked();

    void on_Timer_button_clicked();

    void on_bt_SendCMD_Get_clicked();

    void on_Voltage_Set_clicked();

    void on_CMD_TINTerval_clicked();

    void on_textEdit_Receive_textChanged();

    void Record_Data1(double s); //1s保存数据函数

    void Record_Data10(double s); //10s保存数据函数

    void Record_Data100(double s); //100s保存数据函数

    void Record_Data1000(double s); //1000s保存数据函数

    void Record_Data10000(double s); //10000s保存数据函数

    void on_checkBox_1s_stateChanged(int arg1);

    void on_checkBox_10s_stateChanged(int arg1);

    void on_checkBox_100s_stateChanged(int arg1);

    void on_checkBox_1000s_stateChanged(int arg1);

    void on_checkBox_10000s_stateChanged(int arg1);

    void on_filepath_clicked();

    void on_clear_counter_clicked();

private:
    Ui::Widget *ui;

    QTimer timer1;

    //连接设备所需
    char instrDescriptor[VI_FIND_BUFLEN];
    ViUInt32 numInstrs;
    ViFindList findList;
    ViSession defaultRM, instr;
    ViStatus status;
    ViUInt32 retCount;
    ViUInt32 writeCount;
    unsigned char buffer[100];
    char stringinput[512];          //将指令转换为字符串后的默认存储位置

    //选择是否保存数据
    bool state_1s;
    bool state_10s;
    bool state_100s;
    bool state_1000s;
    bool state_10000s;

    QString file_path;

    qulonglong measure_counter;
};

#endif // WIDGET_H
