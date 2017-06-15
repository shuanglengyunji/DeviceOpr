#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    state_1s = false;
    state_10s = false;
    state_100s = false;
    state_1000s = false;
    state_10000s = false;

    QString file_full = QCoreApplication::applicationFilePath();    //获取路径信息
    QFileInfo fi = QFileInfo(file_full);                            //建立文件信息对象
    file_path = fi.absolutePath();                                  //提取路径信息
    ui->lineEdit_filepath->setText(file_path);

    measure_counter = 0;    //测量次数记录

    QString str;
    str.setNum(measure_counter);
    ui->lineEdit_counter->setText(str);
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
        //手动发送指令部分使能
        ui->bt_SendCMD->setEnabled(true);
        ui->bt_SendCMD_Get->setEnabled(true);
        ui->lineEdit_Cmd->setEnabled(true);

        //进入时间间隔测量模式按钮使能
        ui->CMD_TINTerval->setEnabled(true);
    }

}

//防止文本框内容过多
void Widget::on_textEdit_Receive_textChanged()
{
    int length = ui->textEdit_Receive->toPlainText().length();
    if(length>2000)
        ui->textEdit_Receive->clear();
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

