#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDateTime>
#include <QDate>

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

    //设置生成剔除文件的起始与终止日期
    QDate BeginDate;
    QDate EndDate;
    //剔除算法部分
    int dataType = 1;//用来存放所要剔除的数据的类型
    void tichu(QString srcFile,QString trgFile,int dataType);//一共进行3次剔除，dataType用来标识数据是以多大间隔测量的

    //性能评定算法部分
    void performanceEvaluation(int dataType,QString srcFile);


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

    void Record_Data86400(double s); //86400保存数据函数
    void Record_Data300(double s); //86400保存数据函数

    void on_checkBox_1s_stateChanged(int arg1);

    void on_checkBox_10s_stateChanged(int arg1);

    void on_checkBox_100s_stateChanged(int arg1);

    void on_checkBox_1000s_stateChanged(int arg1);

    void on_checkBox_10000s_stateChanged(int arg1);

    void on_checkBox_86400s_stateChanged(int arg1);

    void on_filepath_clicked();

    void on_clear_counter_clicked();



    void on_pushButton_clicked();

    void on_tichu_button_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_4_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_BeginDate_dateChanged(const QDate &date);

    void on_EndDate_dateChanged(const QDate &date);

    void on_pushButton_3_clicked();

    void on_checkBox_300s_stateChanged(int arg1);

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
    bool state_86400s;
    bool state_300s;

    QString file_path;

    qulonglong measure_counter;
};

#endif // WIDGET_H
