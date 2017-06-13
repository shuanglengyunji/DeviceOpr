#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

#include "../Ni/include/visa.h"

static char instrDescriptor[VI_FIND_BUFLEN];
static ViUInt32 numInstrs;
static ViFindList findList;
static ViSession defaultRM, instr;
static ViStatus status;
static ViUInt32 retCount;
static ViUInt32 writeCount;
static unsigned char buffer[100];
static char stringinput[512];

//Next is add by me

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
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

    status=viOpenDefaultRM (&defaultRM);
    if (status < VI_SUCCESS)
    {
        QMessageBox::information(this,tr("Information"),tr("Could no open a session to the VISA Resource!"),QMessageBox::Ok);
    }
    else
    {
        char myCmd[]={'?','*','I','N','S','T','R','\0'};
        DevCmd=myCmd;
        status = viFindRsrc (defaultRM, DevCmd, &findList, &numInstrs, instrDescriptor);
        if (status < VI_SUCCESS)
        {
            QMessageBox::information(this,tr("Information"),tr("An error occurred while finding resources."),QMessageBox::Ok);
         //  fflush(stdin);
         //  getchar();
           viClose (defaultRM);
         //  return status;
        }

       // printf("%d instruments, serial ports, and other resources found:\n\n",numInstrs);
       // printf("%s \n",instrDescriptor);
        ui->listWidget->addItem(tr("Instruments and serial ports found: %1\n").arg(numInstrs));
        ui->listWidget->addItem(tr("Other resources found: %1\n").arg(instrDescriptor));
        ui->listWidget->addItem(tr("--------------------Device list----------------\n"));
        status = viOpen(defaultRM, instrDescriptor, VI_NULL, VI_NULL, &instr);
        if (status < VI_SUCCESS)
        {
          // printf ("An error occurred opening a session to %s\n",instrDescriptor);
            QMessageBox::information(this,tr("Information"),tr("An error occurred opening a session to %1").arg(instrDescriptor),QMessageBox::Ok);
        }
        else
        {
          /* Now close the session we just opened.                            */
          /* In actuality, we would probably use an attribute to determine    */
          /* if this is the instrument we are looking for.                    */
          viClose (instr);
        }

        while (numInstrs--)
        {
           /* stay in this loop until we find all instruments */
           status = viFindNext (findList, instrDescriptor);  /* find next desriptor */
           if (status < VI_SUCCESS)
           {   /* did we find the next resource? */
            //  printf ("An error occurred finding the next resource.\nHit enter to continue.");
              QMessageBox::information(this,tr("Information"),tr("An error occurred finding the next resource.\nHit enter to continue."),QMessageBox::Ok);
           //   fflush(stdin);
           //   getchar();
              viClose (defaultRM);
         //     return status;
           }
         //  printf("%s \n",instrDescriptor);
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
            ui->lineEdit_Cmd->setEnabled(true);
        }
    }
}


void Widget::on_bt_SendCMD_clicked()
{
    static ViRsrc DevName;  //设备名称

    ui->textEdit_Receive->clear();  //清空文本框

    status=viOpenDefaultRM (&defaultRM);    //返回与默认资源管理器的通话
    if (status < VI_SUCCESS)
    {
        //失败处理
        QMessageBox::information(this,tr("Information"),tr("Could no open a session to the VISA Resource!"),QMessageBox::Ok);
        return;
    }

    //获取设备名称
    QByteArray ba=ui->comboBox->currentText().toLatin1();
    DevName=ba.data();

    //打开设备端口
    status = viOpen (defaultRM, DevName, VI_NULL, VI_NULL, &instr);
    if (status < VI_SUCCESS)
    {
        QMessageBox::information(this,tr("Information"),tr("Cannot open a session to the device."),QMessageBox::Ok);
    }

    /* 设置连接超时时间为5s    Set timeout value to 5000 milliseconds (5 seconds).*/
    status = viSetAttribute (instr, VI_ATTR_TMO_VALUE, 5000);   //设置资源属性状态值。

    int iCmdLeng=ui->lineEdit_Cmd->text().length(); //获取指令长度
    if(iCmdLeng==0)
    {
        QMessageBox::warning(this,tr("Warning!"),tr("Please enter you Command!"),QMessageBox::Ok);
    }
    else
    {
        QByteArray baCmd=ui->lineEdit_Cmd->text().toLatin1();   //获取指令

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
            QString strbuffer;
            strbuffer=(char*)buffer;

            ui->textEdit_Receive->setEnabled(true);
            ui->textEdit_Receive->append(tr("Data Length: %1").arg(retCount));  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
            ui->textEdit_Receive->append(tr("Data read: ")+strbuffer);  //.arg(retCount)的作用是格式化输出，意思在%1的地方输出retCount
        }

        viClose(instr);         //关闭同设备的连接
        viClose(defaultRM);     //关闭与默认资源管理器的通话
    }

}

#define MAX_SCPI_LEN    255
#define DEFAULT_TMO     5000

void Widget::on_pushButton_clicked()
{
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
////       cout << rdBuff << endl;

//       /* Close */
//       viClose( pInstrHandle);
//       viClose( rmSession);
}
