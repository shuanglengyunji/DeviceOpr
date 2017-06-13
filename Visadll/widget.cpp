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
static ViString DevCmd;
static ViRsrc DevName;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/MainW/search"));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_bt_Search_clicked()
{
    int DevIte=1;

    //获取新数据前清空列表框和下拉框
    ui->listWidget->clear();
    ui->comboBox->clear();

    status=viOpenDefaultRM (&defaultRM);
    if (status < VI_SUCCESS)
    {
     //  printf("Could not open a session to the VISA Resource Manager!\n");
     //  exit (EXIT_FAILURE);
        QMessageBox::information(this,tr("Information"),tr("Could no open a session to the VISA Resource!"),QMessageBox::Ok);
    }
    else
    {
        char myCmd[]={'?','*','I','N','S','T','R','\0'};

      //  char myCmd[]="?*INSTR";
        DevCmd=myCmd;
        status = viFindRsrc (defaultRM, DevCmd, &findList, &numInstrs, instrDescriptor);
        if (status < VI_SUCCESS)
        {

           // printf ("An error occurred while finding resources.\nHit enter to continue.");
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
    ui->textEdit_Receive->clear();

    status=viOpenDefaultRM (&defaultRM);
    if (status < VI_SUCCESS)
    {
     //  printf("Could not open a session to the VISA Resource Manager!\n");
     //  exit (EXIT_FAILURE);
        QMessageBox::information(this,tr("Information"),tr("Could no open a session to the VISA Resource!"),QMessageBox::Ok);
    }
    else
    {
        QByteArray ba=ui->comboBox->currentText().toLatin1();
        DevName=ba.data();

        status = viOpen (defaultRM, DevName, VI_NULL, VI_NULL, &instr);
        if (status < VI_SUCCESS)
        {
          // printf ("Cannot open a session to the device.\n");
            QMessageBox::information(this,tr("Information"),tr("Cannot open a session to the device."),QMessageBox::Ok);
           //goto Close;
        }
        /*
        * Set timeout value to 5000 milliseconds (5 seconds).
        */
        status = viSetAttribute (instr, VI_ATTR_TMO_VALUE, 5000);

        int iCmdLeng;
        iCmdLeng=ui->lineEdit_Cmd->text().length();
        if(iCmdLeng==0)
        {
            QMessageBox::warning(this,tr("Warning!"),tr("Please enter you Command!"),QMessageBox::Ok);
        }
        else
        {
            QByteArray baCmd=ui->lineEdit_Cmd->text().toLatin1();

            for(int i=0;i<=iCmdLeng;i++)
            {
                stringinput[i]=baCmd[i];
                if(i==iCmdLeng)
                    stringinput[i]='\0';
            }
            status = viWrite (instr, (ViBuf)stringinput, (ViUInt32)strlen(stringinput), &writeCount);
            if (status < VI_SUCCESS)
            {
            //  printf("Error writing to the device\n");
              QMessageBox::information(this,tr("Information"),tr("Error writing to the device."),QMessageBox::Ok);
            }

            status = viRead (instr, buffer, 100, &retCount);
            if (status < VI_SUCCESS)
            {
              // printf("Error reading a response from the device\n");
               QMessageBox::information(this,tr("Information"),tr("Error reading a response from the device."),QMessageBox::Ok);
            }
            else
            {
              // printf("Data read: %*s\n",retCount,buffer);
                QString strbuffer;

                /*
                int bufLen;
                QString strtmp;

                bufLen=strlen(reinterpret_cast<const char*>(buffer));

                for(int i=0;i<bufLen;i++)
                {
                    strtmp=QString("%1").arg(buffer[i],0,16);
                    if(strtmp.length()==bufLen)
                        strbuffer.append("0");
                    strbuffer.append(strtmp);
                }
                */

                strbuffer=(char*)buffer;

                ui->textEdit_Receive->setEnabled(true);
                ui->textEdit_Receive->setText(tr("Data Length: %1\nData read: ").arg(retCount)+strbuffer);
            }
            viClose(instr);
            viClose(defaultRM);
        }
    }
}
