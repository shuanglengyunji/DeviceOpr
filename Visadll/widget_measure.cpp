#include "widget.h"
#include "ui_widget.h"

//发送指令读取回参
QString Widget::Send_And_Get(QString cmd)
{
    QString returndata = "ERROR";

    status=viOpenDefaultRM (&defaultRM);    //返回与默认资源管理器的通话
    if (status < VI_SUCCESS)
    {
        //失败处理
        QMessageBox::information(this,tr("Information"),tr("Could no open a session to the VISA Resource!"),QMessageBox::Ok);
        return returndata;
    }

    //获取设备名称
    QByteArray ba=ui->comboBox->currentText().toLatin1();
    ViRsrc DevName=ba.data();

    //打开设备端口
    status = viOpen (defaultRM, DevName, VI_NULL, VI_NULL, &instr);
    if (status < VI_SUCCESS)
    {
        QMessageBox::information(this,tr("Information"),tr("Cannot open a session to the device."),QMessageBox::Ok);
    }

    /* 设置连接超时时间为5s    Set timeout value to 5000 milliseconds (5 seconds).*/
    status = viSetAttribute (instr, VI_ATTR_TMO_VALUE, 5000);   //设置资源属性状态值。

    //定义指令
    QByteArray baCmd = cmd.toLatin1();

    int iCmdLeng = baCmd.length(); //获取指令长度
    if(iCmdLeng==0)
    {
        QMessageBox::warning(this,tr("Warning!"),tr("CMD Error!"),QMessageBox::Ok);
        return returndata;
    }

    //指令拷贝进入char型数组
    for(int i=0;i<=iCmdLeng;i++)
    {
        stringinput[i]=baCmd[i];
        if(i==iCmdLeng)
            stringinput[i]='\0';
    }

    //指令写入
    status = viWrite (instr, (ViBuf)stringinput, (ViUInt32)strlen(stringinput), &writeCount);
    if (status < VI_SUCCESS)
    {
        //写入失败处理
        QMessageBox::information(this,tr("Information"),tr("Error writing to the device."),QMessageBox::Ok);
    }

    //读取数据
    status = viRead (instr, buffer, 100, &retCount);
    if (status < VI_SUCCESS)
    {
        //读取失败处理
        QMessageBox::information(this,tr("Information"),tr("Error reading a response from the device."),QMessageBox::Ok);
    }
    else
    {
        returndata=(char*)buffer;
    }

    viClose(instr);         //关闭同设备的连接
    viClose(defaultRM);     //关闭与默认资源管理器的通话

    return returndata;

}

//发送指令不读取回参
void Widget::Send_No_Get(QString cmd)
{
    status=viOpenDefaultRM (&defaultRM);    //返回与默认资源管理器的通话
    if (status < VI_SUCCESS)
    {
        //失败处理
        QMessageBox::information(this,tr("Information"),tr("Could no open a session to the VISA Resource!"),QMessageBox::Ok);
        return ;
    }

    //获取设备名称
    QByteArray ba=ui->comboBox->currentText().toLatin1();
    ViRsrc DevName=ba.data();

    //打开设备端口
    status = viOpen (defaultRM, DevName, VI_NULL, VI_NULL, &instr);
    if (status < VI_SUCCESS)
    {
        QMessageBox::information(this,tr("Information"),tr("Cannot open a session to the device."),QMessageBox::Ok);
    }

    /* 设置连接超时时间为5s    Set timeout value to 5000 milliseconds (5 seconds).*/
    status = viSetAttribute (instr, VI_ATTR_TMO_VALUE, 5000);   //设置资源属性状态值。

    //定义指令
    QByteArray baCmd = cmd.toLatin1();

    int iCmdLeng = baCmd.length(); //获取指令长度
    if(iCmdLeng==0)
    {
        QMessageBox::warning(this,tr("Warning!"),tr("CMD Error!"),QMessageBox::Ok);
        return ;
    }

    //指令拷贝进入char型数组
    for(int i=0;i<=iCmdLeng;i++)
    {
        stringinput[i]=baCmd[i];
        if(i==iCmdLeng)
            stringinput[i]='\0';
    }

    //指令写入
    status = viWrite (instr, (ViBuf)stringinput, (ViUInt32)strlen(stringinput), &writeCount);
    if (status < VI_SUCCESS)
    {
        //写入失败处理
        QMessageBox::information(this,tr("Information"),tr("Error writing to the device."),QMessageBox::Ok);
    }

    ui->textEdit_Receive->append("指令发送成功！");

    viClose(instr);         //关闭同设备的连接
    viClose(defaultRM);     //关闭与默认资源管理器的通话
}


//获取一个数据
double Widget::Get_Number(QString cmd)
{
    double number = 0;

    status=viOpenDefaultRM (&defaultRM);    //返回与默认资源管理器的通话
    if (status < VI_SUCCESS)
    {
        //失败处理
        QMessageBox::information(this,tr("Information"),tr("Could no open a session to the VISA Resource!"),QMessageBox::Ok);
        return -1;
    }

    //获取设备名称
    QByteArray ba=ui->comboBox->currentText().toLatin1();
    ViRsrc DevName=ba.data();

    //打开设备端口
    status = viOpen (defaultRM, DevName, VI_NULL, VI_NULL, &instr);
    if (status < VI_SUCCESS)
    {
        QMessageBox::information(this,tr("Information"),tr("Cannot open a session to the device."),QMessageBox::Ok);
    }

    /* 设置连接超时时间为5s    Set timeout value to 5000 milliseconds (5 seconds).*/
    status = viSetAttribute (instr, VI_ATTR_TMO_VALUE, 5000);   //设置资源属性状态值

    //定义指令
    QByteArray baCmd = cmd.toLatin1();

    int iCmdLeng = baCmd.length(); //获取指令长度

    //指令拷贝进入char型数组
    for(int i=0;i<=iCmdLeng;i++)
    {
        stringinput[i]=baCmd[i];
        if(i==iCmdLeng)
            stringinput[i]='\0';
    }

    //指令写入
    status = viWrite (instr, (ViBuf)stringinput, (ViUInt32)strlen(stringinput), &writeCount);
    if (status < VI_SUCCESS)
    {
        //写入失败处理
        QMessageBox::information(this,tr("Information"),tr("Error writing to the device."),QMessageBox::Ok);
    }

    //读取数据
    status = viRead (instr, buffer, 100, &retCount);
    if (status < VI_SUCCESS)
    {
        //读取失败处理
        QMessageBox::information(this,tr("Information"),tr("Error reading a response from the device."),QMessageBox::Ok);
    }
    else
    {
        QString strbuffer=(char*)buffer;
        number = strbuffer.toDouble();

    }

    viClose(instr);         //关闭同设备的连接
    viClose(defaultRM);     //关闭与默认资源管理器的通话

    return number;
}



