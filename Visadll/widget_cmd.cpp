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
}

//进入时间间隔测量模式按钮
void Widget::on_CMD_TINTerval_clicked()
{
    QString cmd = "CONFigure:SCALar:VOLTage:TINTerval (@1),(@2)";
    Send_No_Get(cmd);
    cmd.clear();
}

//单次测量按钮
void Widget::on_Time_Interval_clicked()
{
    ui->Time_Interval->setEnabled(false);

    double time = Get_Number("READ?");
    QString str = QString("time interval: %1").arg(time, 0,'r',12);
    ui->textEdit_Receive->append(str);  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
    str.clear();

    ui->Time_Interval->setEnabled(true);
}

//定时控制按钮
void Widget::on_Timer_button_clicked()
{
    static int flag = 0;    //0:没开始   1：开始

    if(flag == 0)
    {
        int timer = ui->set_timer->text().toInt();
        testTimer.start(timer); //1s
        flag = 1;
        ui->Timer_button->setText("停止定时测量");

        //定时器槽函数连接
        connect(&testTimer,SIGNAL(timeout()), this, SLOT(Timing()));
    }
    else
    {
        testTimer.stop();
        flag = 0;
        ui->Timer_button->setText("开始定时测量");

        //定时器槽函数连接
        disconnect(&testTimer,SIGNAL(timeout()), this, SLOT(Timing()));
    }
}

//定时器函数
void Widget::Timing()
{
    double time = Get_Number("READ?");
    QString str = QString("time interval: %1").arg(time, 0,'r',12);
    ui->textEdit_Receive->append(str);  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
    str.clear();
}
