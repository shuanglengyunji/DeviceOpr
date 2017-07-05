#include "widget.h"
#include "ui_widget.h"

//启动定时定时器
void Widget::Timer_Start(int ms)
{
    connect(&timer1,SIGNAL(timeout()), this, SLOT(Timing1()));    //定时器槽函数连接
    timer1.start(ms); //1s
}

//停止定时器
void Widget::Timer_Stop()
{
    if(timer1.isActive())
    {
        timer1.stop();
        disconnect(&timer1,SIGNAL(timeout()), this, SLOT(Timing1()));
    }
}

//开始定时测量按钮
MeasureThread Mythread;
void Widget::on_Timer_button_clicked()
{
    if(ui->Timer_button->text() == "定时测量")
    {
        Continue_Start();
        Mythread.start();

        ui->Timer_button->setText("停止");
    }
    else
    {
        Mythread.mystop();
        Continue_Stop();
        ui->Timer_button->setText("定时测量");
    }
}

void Widget::on_filepath_clicked()
{
    QString file_path_tmp = QFileDialog::getExistingDirectory(this,"请选择数据保存文件夹","./");
    if(file_path_tmp.isEmpty())
    {
        return;
    }
    else
    {
        file_path = file_path_tmp;
        ui->lineEdit_filepath->setText(file_path);
    }
}

void Widget::Record_Data1(double s)
{
    //获取当前时间
    QDateTime da_time;
    QString time_str = da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString tmp = time_str.left(10);

    //建立、打开文件
    QString fileName = file_path + "/" + tmp + "-1.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))   //打开文件
    {
      QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }

    QTextStream in(&file);
    QString str = QString("%1").arg(s, 0,'r',16); //最大能够达到16位精度（返回数据的精度是16位）
    in << str + "\n";

    file.close();
}

void Widget::Record_Data10(double s)
{
    //获取当前时间
    QDateTime da_time;
    QString time_str = da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString tmp = time_str.left(10);

    //建立、打开文件
    QString fileName = file_path + "/" + tmp + "-10.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))   //打开文件
    {
      QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }

    QTextStream in(&file);
    QString str = QString("%1").arg(s, 0,'r',16); //最大能够达到16位精度（返回数据的精度是16位）
    in << str + "\n";

    file.close();
}

void Widget::Record_Data100(double s)
{
    //获取当前时间
    QDateTime da_time;
    QString time_str = da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString tmp = time_str.left(10);

    //建立、打开文件
    QString fileName = file_path + "/" + tmp + "-100.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))   //打开文件
    {
      QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }

    QTextStream in(&file);
    QString str = QString("%1").arg(s, 0,'r',16); //最大能够达到16位精度（返回数据的精度是16位）
    in << str + "\n";

    file.close();
}

void Widget::Record_Data1000(double s)
{
    //获取当前时间
    QDateTime da_time;
    QString time_str = da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString tmp = time_str.left(10);

    //建立、打开文件
    QString fileName = file_path + "/" + tmp + "-1000.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))   //打开文件
    {
      QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }

    QTextStream in(&file);
    QString str = QString("%1").arg(s, 0,'r',16); //最大能够达到16位精度（返回数据的精度是16位）
    in << str + "\n";

    file.close();
}

void Widget::Record_Data10000(double s)
{
    //获取当前时间
    QDateTime da_time;
    QString time_str = da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString tmp = time_str.left(10);

    //建立、打开文件
    QString fileName = file_path + "/" + tmp + "-10000.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))   //打开文件
    {
      QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }

    QTextStream in(&file);
    QString str = QString("%1").arg(s, 0,'r',16); //最大能够达到16位精度（返回数据的精度是16位）
    in << str + "\n";

    file.close();
}

void Widget::Record_Data86400(double s)
{
    QDateTime da_time;
    QString time_str = da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString tmp = time_str.left(10);

    //建立、打开文件
    QString fileName = file_path + "/" + tmp + "-86400.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))   //打开文件
    {
      QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }

    QTextStream in(&file);
    QString str = QString("%1").arg(s, 0,'r',16); //最大能够达到16位精度（返回数据的精度是16位）
    in << str + "\n";

    file.close();
}

void Widget::on_checkBox_1s_stateChanged(int arg1)
{
    state_1s = arg1;
}

void Widget::on_checkBox_10s_stateChanged(int arg1)
{
    state_10s = arg1;
}

void Widget::on_checkBox_100s_stateChanged(int arg1)
{
    state_100s = arg1;
}

void Widget::on_checkBox_1000s_stateChanged(int arg1)
{
    state_1000s = arg1;
}

void Widget::on_checkBox_10000s_stateChanged(int arg1)
{
    state_10000s = arg1;
}

void Widget::on_checkBox_86400s_stateChanged(int arg1)
{
    state_86400s = arg1;
}

void Widget::on_checkBox_300s_stateChanged(int arg1)
{
    state_300s = arg1;
}
//void MainWindow::on_pushButton_clicked()
//{
//    QDateTime da_time;
//    QString time_str=da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
//    QString runPath = QCoreApplication::applicationFilePath();
//    ui->label->setText(runPath);
//    QDir *TEST = new QDir;
//    bool exist = TEST->exists("TEST");
//    if(!exist)
//          bool ok = TEST->mkdir("TEST");
//   QString fileName = "TEST/1.txt";
//   QString str="0000000nnnnnnnnnnnnnnnn";
//   QFile file(fileName);
//   if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))
//   {
//      QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
//   }
//   QTextStream in(&file);
//   in<<time_str+":"+str<<"\n";
//   file.close();
//}

