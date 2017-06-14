#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //定时器槽函数连接
    connect(&testTimer,SIGNAL(timeout()), this, SLOT(Timing()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_bt_Search_clicked()
{
    static ViString DevCmd; //指令字符串

    int DevIte=1;

    //获取新数据前清空列表框和下拉框
    ui->listWidget->clear();
    ui->comboBox->clear();

    //打开与默认资源管理器的通话
    status=viOpenDefaultRM (&defaultRM);
    if (status < VI_SUCCESS)
    {
        QMessageBox::information(this,tr("Information"),tr("Could no open a session to the VISA Resource!"),QMessageBox::Ok);
        return;
    }

    char myCmd[]={'?','*','I','N','S','T','R','\0'};
//    char myCmd[]={'T','C','P','I','P','?','*','I','N','S','T','R','\0'};    //TCPIP?*INSTR
    DevCmd=myCmd;
    status = viFindRsrc (defaultRM, DevCmd, &findList, &numInstrs, instrDescriptor);    //查询VISA系统进行资源定位

    if (status < VI_SUCCESS)
    {
        QMessageBox::information(this,tr("Information"),tr("An error occurred while finding resources."),QMessageBox::Ok);
        viClose (defaultRM);
        return;
    }

    ui->listWidget->addItem(tr("Instruments and serial ports found: %1\n").arg(numInstrs));
    ui->listWidget->addItem(tr("Other resources found: %1\n").arg(instrDescriptor));            //显示找到设备的数量
    ui->listWidget->addItem(tr("--------------------Device list----------------\n"));

    status = viOpen(defaultRM, instrDescriptor, VI_NULL, VI_NULL, &instr);
    if (status < VI_SUCCESS)
    {
        QMessageBox::information(this,tr("Information"),tr("An error occurred opening a session to %1").arg(instrDescriptor),QMessageBox::Ok);
    }
    else
    {
        /* Now close the session we just opened.                            */
        /* In actuality, we would probably use an attribute to determine    */
        /* if this is the instrument we are looking for.                    */
        ui->listWidget->addItem(QString::number(DevIte++,10) + tr(": %1\n").arg(instrDescriptor));
        ui->comboBox->addItem(tr("%1").arg(instrDescriptor));
        viClose (instr);
    }


    while (--numInstrs)
    {
       /* stay in this loop until we find all instruments */
       status = viFindNext (findList, instrDescriptor);  /* find next desriptor */
       if (status < VI_SUCCESS)
       {
          /* did we find the next resource? */
          QMessageBox::information(this,tr("Information"),tr("An error occurred finding the next resource.\nHit enter to continue."),QMessageBox::Ok);
          viClose (defaultRM);
       }

       ui->listWidget->addItem(QString::number(DevIte++,10) + tr(": %1\n").arg(instrDescriptor));
       ui->comboBox->addItem(tr("%1").arg(instrDescriptor));


       /* Now we will open a session to the instrument we just found */
       status = viOpen (defaultRM, instrDescriptor, VI_NULL, VI_NULL, &instr);
       if (status < VI_SUCCESS)
       {
           //printf ("An error occurred opening a session to %s\n",instrDescriptor);
           QMessageBox::information(this,tr("Information"),tr("An error occurred opening a session to %1 \n").arg(instrDescriptor),QMessageBox::Ok);
       }
       else
       {
          /* Now close the session we just opened.                            */
          /* In actuality, we would probably use an attribute to determine    */
          /* if this is the instrument we are looking for.                    */
          viClose (instr);
       }
    }    /* end while */

    status = viClose(findList);
    status = viClose (defaultRM);

    if(ui->comboBox->count()>0)
    {
        ui->bt_SendCMD->setEnabled(true);
        ui->bt_SendCMD_Get->setEnabled(true);
        ui->lineEdit_Cmd->setEnabled(true);
        ui->Voltage1->setEnabled(true);
        ui->Voltage2->setEnabled(true);
        ui->Voltage_Set->setEnabled(true);
        ui->CMD_TINTerval->setEnabled(true);
    }

}

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
    ui->textEdit_Receive->clear();  //清空文本框

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

    double vol2 = ui->Voltage2->text().toDouble();
    QString volinput2 = "INPut2:LEVel:ABSolute " + QString::number(vol2,10,2);
    Send_No_Get(volinput2);
}



void Widget::on_get_fre_clicked()
{
    ui->get_fre->setEnabled(false);

    double number = Get_Number("MEASure:SCALar:VOLTage:FREQuency?");
    QString str = QString("frequency: %1").arg(number, 0,'r',12);
    ui->textEdit_Receive->append(str);  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
    str.clear();

    ui->get_fre->setEnabled(true);
}

void Widget::on_Time_Interval_clicked()
{
    ui->get_fre->setEnabled(false);

    double time = Get_Number("MEASure:SCALar:VOLTage:TINTerval?");
    QString str = QString("time interval: %1").arg(time, 0,'r',12);
    ui->textEdit_Receive->append(str);  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
    str.clear();

    ui->get_fre->setEnabled(true);
}

void Widget::on_Timer_button_clicked()
{
    static int flag = 0;    //0:没开始   1：开始

    if(flag == 0)
    {
        testTimer.start(1000); //1s
        flag = 1;
        ui->Timer_button->setText("停止定时");
    }
    else
    {
        if (testTimer.isActive() )
        {
            testTimer.stop();
            flag = 0;
            ui->Timer_button->setText("开始定时");
        }
    }

}

void Widget::Timing()
{
    double time = Get_Number("MEASure:SCALar:VOLTage:TINTerval?");
    QString str = QString("time interval: %1").arg(time, 0,'r',12);
    ui->textEdit_Receive->append(str);  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
    str.clear();
}


//    //创建文件路径和文件
//    QDir TEST;
//    bool exist = TEST.exists("TEST");
//    if(!exist)
//        TEST.mkdir("TEST");
//    QString fileName = "TEST/1.txt";
//    QFile file(fileName);

//    //打开文件
//    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))
//    {
//        QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
//    }

//    //写入数据
//    QTextStream out(&file);
//    out << str  << "\n" ;

//    //关闭文件
//    file.close();

//    QString sFilePath = "C:\\test.txt";

//    QFile file(sFilePath);
//    //方式：Append为追加，WriteOnly，ReadOnly
//    if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
//        QMessageBox::critical(NULL, "提示", "无法创建文件");
//        return;
//    }
//    QTextStream out(&file);
//    out<<"要写入内容"<<endl;
//    out.flush();
//    file.close();

/*
 *
 *
 * 网络版本代码
 *
 *
 */

//#define MAX_SCPI_LEN    255
//#define DEFAULT_TMO     5000

//       /* Visa Session*/
//       ViStatus nRetStatus;
//       ViSession rmSession = 0;
//       ViSession pInstrHandle;

//       /* Visa communicate buffer */
//       ViByte wrBuff[MAX_SCPI_LEN];
//       ViByte rdBuff[MAX_SCPI_LEN];

//       int retCount = 0;

//       /* open device and get visa Handle */

         //打开与默认资源管理器的通话
//       nRetStatus = viOpenDefaultRM( &rmSession);

         //打开设备
//       nRetStatus = viOpen( rmSession, "TCPIP0::127.0.0.1::5000::SOCKET", VI_NULL, VI_NULL, &pInstrHandle);

//       /* set visa Format */
//       nRetStatus = viSetAttribute( pInstrHandle, VI_ATTR_TMO_VALUE, DEFAULT_TMO);
//       nRetStatus = viSetAttribute( pInstrHandle, VI_ATTR_SUPPRESS_END_EN, VI_FALSE);
//       nRetStatus = viSetAttribute( pInstrHandle, VI_ATTR_SEND_END_EN, VI_FALSE);

//       /* Query device IDN */
//       nRetStatus = viQueryf( pInstrHandle, "*IDN?\n", "%s", rdBuff);

//        ui->textEdit_Receive->setText(rdBuff);
//       cout << rdBuff << endl;

//       /* Close */
//       viClose( pInstrHandle);
//       viClose( rmSession);














