#include "widget.h"
#include "ui_widget.h"

//发送指令不回读
void Widget::on_bt_SendCMD_clicked()
{
    int iCmdLeng;
    iCmdLeng=ui->lineEdit_Cmd->text().length();
    if(iCmdLeng==0)
    {
        QMessageBox::warning(this,tr("Warning!"),tr("Please enter you Command!"),QMessageBox::Ok);
    }
    else
    {
        Send_No_Get(ui->lineEdit_Cmd->text());
    }
}

//发送指令且回读
void Widget::on_bt_SendCMD_Get_clicked()
{
    int iCmdLeng;

    iCmdLeng=ui->lineEdit_Cmd->text().length();

    if(iCmdLeng==0)
    {
        QMessageBox::warning(this,tr("Warning!"),tr("Please enter you Command!"),QMessageBox::Ok);
        return;
    }

    QString receive = Send_And_Get(ui->lineEdit_Cmd->text());

    ui->textEdit_Receive->append(receive);  //清空文本框
}

//发送门限电压设置指令
void Widget::on_Voltage_Set_clicked()
{
    double vol1 = ui->Voltage1->text().toDouble();
    QString volinput1 = "INPut1:LEVel:ABSolute " + QString::number(vol1,10,2);
    Send_No_Get(volinput1);
    volinput1.clear();

    double vol2 = ui->Voltage2->text().toDouble();
    QString volinput2 = "INPut2:LEVel:ABSolute " + QString::number(vol2,10,2);
    Send_No_Get(volinput2);
    volinput2.clear();

    //单次测量按钮使能
    ui->Time_Interval->setEnabled(true);

    //定时测量使能
    ui->Timer_button->setEnabled(true);
    ui->set_timer->setEnabled(true);
    ui->label_timer->setEnabled(true);

    //路径选择使能
    ui->lineEdit_filepath->setEnabled(true);
    ui->filepath->setEnabled(true);

    //定时保持按钮使能
    ui->checkBox_86400s->setEnabled(true);
    ui->checkBox_10000s->setEnabled(true);
    ui->checkBox_1000s->setEnabled(true);
    ui->checkBox_100s->setEnabled(true);
    ui->checkBox_10s->setEnabled(true);
    ui->checkBox_1s->setEnabled(true);

    //测量计数器使能
    ui->clear_counter->setEnabled(true);
    ui->lineEdit_counter->setEnabled(true);
    ui->label_counter->setEnabled(true);
}

//进入时间间隔测量模式
void Widget::on_CMD_TINTerval_clicked()
{
    //单次测量按钮失能
    ui->Time_Interval->setEnabled(false);

    //定时测量失能
    ui->Timer_button->setEnabled(false);
    ui->set_timer->setEnabled(false);
    ui->label_timer->setEnabled(false);

    //停止定时测量
    Timer_Stop();

    //路径选择失能
    ui->lineEdit_filepath->setEnabled(false);
    ui->filepath->setEnabled(false);

    //定时保持按钮失能
    ui->checkBox_86400s->setEnabled(false);
    ui->checkBox_10000s->setEnabled(false);
    ui->checkBox_1000s->setEnabled(false);
    ui->checkBox_100s->setEnabled(false);
    ui->checkBox_10s->setEnabled(false);
    ui->checkBox_1s->setEnabled(false);

    //测量计数器失能
    ui->clear_counter->setEnabled(false);
    ui->lineEdit_counter->setEnabled(false);
    ui->label_counter->setEnabled(false);

    //计数器清零
    measure_counter = 0;

    QString cmd2 = "SYSTem:TIMeout 2";  //设置测量时间间隔为2s（由于信号1s才出现一次，再加上测量时间，1s的超时时间很容易导致超时）
    Send_No_Get(cmd2);
    cmd2.clear();

    QString cmd = "CONFigure:SCALar:VOLTage:TINTerval (@1),(@2)";
    Send_No_Get(cmd);
    cmd.clear();

    //使能电压门限，失能时间间隔测量

    //电压门限设置窗口使能
    ui->Voltage1->setEnabled(true);
    ui->Voltage2->setEnabled(true);
    ui->Voltage_Set->setEnabled(true);
    ui->label_Gate1->setEnabled(true);
    ui->label_Gate2->setEnabled(true);
}

//单次测量
void Widget::on_Time_Interval_clicked()
{
    ui->Time_Interval->setEnabled(false);

    double time = Get_Number("READ?");
    QString str = QString("time interval: %1").arg(time, 0,'r',16); //最大能够达到16位精度（返回数据的精度是16位）
    ui->textEdit_Receive->append(str);  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
    str.clear();

    ui->Time_Interval->setEnabled(true);
}

//定时测量
void Widget::Timing1()
{
    double time = Continue_Get_Number("READ?");

    if(time>0.001 && time<1)    //只接受1ms~1s之间的值
    {
        QString str = QString("time interval: %1").arg(time, 0,'r',16); //最大能够达到16位精度（返回数据的精度是16位）
        ui->textEdit_Receive->append(str);  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
    }
    else
    {
        ui->textEdit_Receive->append("测量错误！");  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
        time = -1;
    }

    //测量计数器累加
    measure_counter++;

    //显示measure_counter变量值
    QString str1;
    str1.setNum(measure_counter);
    ui->lineEdit_counter->setText(str1);

    //存储数据
    if(state_1s)
    {
        Record_Data1(time);
    }

    if(state_10s)
    {
        if(measure_counter % 10 == 0)
            Record_Data10(time);
    }

    if(state_100s)
    {
        if(measure_counter % 100 == 0)
            Record_Data100(time);
    }

    if(state_1000s)
    {
        if(measure_counter % 1000 == 0)
            Record_Data1000(time);
    }

    if(state_10000s)
    {
        if(measure_counter % 10000 == 0)
            Record_Data10000(time);
    }

    if(state_86400s)
    {
        if(measure_counter % 86400 == 0)
            Record_Data86400(time);
    }
}

//清零测量次数统计
void Widget::on_clear_counter_clicked()
{
    measure_counter = 0;

    QString str1;
    str1.setNum(measure_counter);
    ui->lineEdit_counter->setText(str1);
}
