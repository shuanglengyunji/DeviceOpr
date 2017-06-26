#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <math.h>

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

//剔除错误数据按钮按下
void Widget::on_tichu_button_clicked()
{
    QDateTime da_time;
    QString time_str = da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString tmp = time_str.left(10);

    ui->tichu_text3->clear();
    ui->tichu_text3->append("剔除每"+QString::number(dataType)+"秒的数据\n");
    tichu(tmp,"test1",dataType);
    tichu("test1","test2",dataType);
    tichu("test2","test3",dataType);
    ui->tichu_text3->moveCursor(QTextCursor::Start, QTextCursor::MoveAnchor);
}

//剔除类型选择
void Widget::on_comboBox_2_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        dataType = 1;
        break;
    case 1:
        dataType = 10;
        break;
    case 2:
        dataType = 100;
        break;
    case 3:
        dataType = 1000;
        break;
    case 4:
        dataType = 10000;
        break;
    case 5:
        dataType = 86400;
        break;
    default:
        break;
    }
}

//剔除错误数据操作函数
void Widget::tichu(QString srcFile,QString trgFile,int dataType )
{
    double  initialData=0;
    int dataNumber=0;//数据总数
    double standardError=0;//标准偏差
    double average=0;//平均
    static int tichuNum=0;//剔除操作执行次数


    ui->tichu_text3->append("__________________________________________\n");
    ui->tichu_text3->append("第"+QString::number(tichuNum+1)+"次剔除:\n");
    tichuNum += 1;
    tichuNum = tichuNum%3 ;

    QFile file(file_path+"/"+srcFile+"-"+QString::number(dataType)+".txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QFile file_1(file_path+"/"+trgFile+"-"+QString::number(dataType)+".txt");
    if(!file_1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }

    QTextStream in(&file);
    QTextStream in_1(&file_1);


    //求数据总数
    while(!in.atEnd()){
        QString line;
        line = in.readLine();
        dataNumber += 1;

    }
    ui->tichu_text3->append("数据总数:"+QString::number(dataNumber,'g',16));

    //求平均值
    in.seek(0);
    while(!in.atEnd()){
        QString line = in.readLine();
        double x;
        initialData = line.toDouble(); /*读入字符转转换成double型数值*/
//        in_1<<line<<"\n";
//        ui->tichu_text2->append(QString::number(initialData,'g',16));
        x = initialData/dataNumber;
        average +=x;
    }
    ui->tichu_text3->append("平均:\n"+QString::number(average,'g',16));

    //求实验标准偏差
    in.seek(0);//将当前读取文件指针移动到文件开始
    while(!in.atEnd()){
        QString line = in.readLine();
        double x;
        initialData = line.toDouble(); /*读入字符转转换成double型数值*/
        x=pow((initialData-average),2);
        x= x/dataNumber;
        standardError +=x;
    }
    standardError = sqrt(standardError);
    ui->tichu_text3->append("标准偏差:\n"+QString::number(standardError,'g',16));

    //判别
    in.seek(0);//将当前读取文件指针移动到文件开始
    while(!in.atEnd()){
        QString line = in.readLine();
        double x;
        initialData = line.toDouble(); /*读入字符转转换成double型数值*/
        x=qAbs((initialData-average));
        if(x<=(3*standardError)){
            in_1<<line<<"\n";
        }
    }

    //看剔除后总数
    dataNumber = 0;
    in_1.seek(0);
    while(!in_1.atEnd()){
        QString line;
        line = in_1.readLine();
        dataNumber += 1;
    }
    ui->tichu_text3->append("剔除后数据总数:\n"+QString::number(dataNumber,'g',16));

    //关闭文件
    file.close();
    file_1.close();


}

//性能评定数据按钮按下
void Widget::on_pushButton_clicked()
{
    ui->performanceEvaluateOutput->clear();
    ui->performanceEvaluateOutput->append("评定每"+QString::number(dataType)+"秒测量数据的性能\n");
    performanceEvaluation(dataType,"test3");
}

//性能评定类型选择
void Widget::on_comboBox_3_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        dataType = 1;
        break;
    case 1:
        dataType = 10;
        break;
    case 2:
        dataType = 100;
        break;
    case 3:
        dataType = 1000;
        break;
    case 4:
        dataType = 10000;
        break;
    case 5:
        dataType = 86400;
        break;
    default:
        break;
    }
}

//性能评定操作函数
void Widget::performanceEvaluation(int dataType, QString srcFile)
{
    double initialData[2];//用来求取频率偏差的数组
    double initialData2[4];
    int index=0;//initialData索引
    int index2=0;//initialData2索引
    double frequencyStability =0;//频率稳定度
    double frequencyDeparture =0;//频率偏差
    int dataNumber=0;
    int i;//各种for中的索引
    QString line1;//文本流，定义在这里有特别用处
    //打开源文件定义文本流
    QFile file(file_path+"/"+srcFile+"-"+QString::number(dataType)+".txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QTextStream in(&file);

    //头文本
    ui->performanceEvaluateOutput->append("__________________________________________\n");

    //求数据总数
    in.seek(0);
    while(!in.atEnd()){
        QString line;
        line = in.readLine();
        dataNumber += 1;
    }
    ui->performanceEvaluateOutput->append("数据总数:"+QString::number(dataNumber,'g',16));
    //计算相对频率偏差y=(x1-x2)/d_t
    in.seek(0);
    line1 = in.readLine();
    initialData[index] = line1.toDouble(); /*读入字符转转换成double型数值*/
    index = !index;
    frequencyDeparture = 0;
    while(!in.atEnd()){
        double x;
        line1 = in.readLine();
        initialData[index] = line1.toDouble();
        index = !index;
        x = qAbs(initialData[!index]-initialData[index]);
        x = x/dataType;
        frequencyDeparture += x/dataNumber;
//        ui->performanceEvaluateOutput->append(QString::number(x,'g',16));
    }
    ui->performanceEvaluateOutput->append("相对平均频率偏差:\n"+QString::number(frequencyDeparture,'g',16));

    //计算频率稳定度
    in.seek(0);
    for(i=0;i<3;i++){
        line1 = in.readLine();
        initialData2[i] = line1.toDouble();
    }
    frequencyStability = 0;
    while(!in.atEnd()){
        double x;
        line1 = in.readLine();
        initialData2[3] = line1.toDouble();
        x=initialData2[3]-(3*initialData2[2])+(3*initialData2[1])-initialData2[0];
        x = pow(x,2);
        x = x*(1/(6*pow(dataType,2)*(dataNumber-3)));
        frequencyStability +=x;
        for(index2=0;index2<3;index2++){
            initialData2[index2] = initialData2[index2+1];
        }
//        ui->performanceEvaluateOutput->append(" "+QString::number(x,'g',16));
    }
    frequencyStability = sqrt(frequencyStability);
    ui->performanceEvaluateOutput->append("频率稳定度:\n"+QString::number(frequencyStability,'g',16));

    file.close();

}


//选择生成性能评定文件的类型
void Widget::on_comboBox_4_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        dataType = 1;
        break;
    case 1:
        dataType = 10;
        break;
    case 2:
        dataType = 100;
        break;
    case 3:
        dataType = 1000;
        break;
    case 4:
        dataType = 10000;
        break;
    case 5:
        dataType = 86400;
        break;
    default:
        break;
    }

}

//改变qspinbox时候改变起始和结束日期
void Widget::on_BeginMonth_valueChanged(int arg1)
{
    BeginMonth = arg1;
}
void Widget::on_BeginDay_valueChanged(int arg1)
{
    BeginDay = arg1;
}
void Widget::on_EndMonth_valueChanged(int arg1)
{
    EndMonth = arg1;
}
void Widget::on_EndDay_valueChanged(int arg1)
{
    EndDay = arg1;
}

//"生成文件"按钮按下
void Widget::on_pushButton_2_clicked()
{
    int i,j;//循环索引
    QDateTime da_time;
    QString time_str = da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString tmp = time_str.left(5);

    //生成样本文件夹
   QDir *temp = new QDir;
   bool exist = temp->exists(file_path+"/sample");
   if(exist)
       ui->samlpe_edit->append("文件夹已经存在！");
   else
   {
       bool ok = temp->mkdir(file_path+"/sample");
       if( ok )
           ui->samlpe_edit->append("文件夹创建成功！");
   }
   delete temp;
   ui->samlpe_edit->append("抽取"+QString::number(BeginMonth)+"月"+QString::number(BeginDay)+"日到"+QString::number(EndMonth)+"月"+QString::number(EndDay)+"日的"+QString::number(dataType)+"秒样本");

   //清空原有数据
   QFile file2(file_path+"/"+"sample/"+"sample-"+QString::number(dataType)+".txt");
   if(!file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
       qDebug()<<"Can't open the file1!"<<endl;
   }
    //生成sample文件
   for(i=BeginMonth;i<=EndMonth;i++)
   {
       for(j=BeginDay;j<=EndDay;j++)
       {


           QFile file(file_path+"/"+tmp+QString::number(i)+"-"+QString::number(j)+"-"+QString::number(dataType)+".txt");
           if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
               qDebug()<<"Can't open the file!!"<<endl;
           }
           QTextStream in(&file);


           QFile file1(file_path+"/"+"sample/"+"sample-"+QString::number(dataType)+".txt");
           if(!file1.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append)) {
               qDebug()<<"Can't open the file1!"<<endl;
           }
           QTextStream in1(&file1);

           in.seek(0);
           while(!in.atEnd()){
               QString line;
               line = in.readLine();
               in1<<line<<"\n";

           }

//           file.close();
//           file1.close();

       }
   }

}






//下面这个函数使用数组的思想做的，可扩展性不好，
//函数之前的内容是以前放置在on_tichu_button_clicked()函数里面的

//    double initailData[100]; /*存储最初的数据*/
//    qint8 index_initialData = 0; /*最初数据存储数组的索引*/
//    qint8 &index=index_initialData;
//    qint8 i;//索引

//   打开目标文件并转化成数字之后的格式
//    QFile file(file_path+"/2017-06-19-1.txt");
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        qDebug()<<"Can't open the file!"<<endl;
//    }
//    QTextStream in(&file);
//    while(!in.atEnd()){
//        QString line = in.readLine();
//        initailData[index_initialData] = line.toDouble(); /*读入字符转转换成double型数值*/
//        ui->tichu_text2->append(QString::number(initailData[index_initialData],'g',16));
//        index_initialData+= 1;

//    }

//    tichu(initailData,index);
//    tichu(initailData,index);
//    tichu(initailData,index);
//    ui->tichu_text3->append("剔除后:\n");
//    for(i=0;i<index;i++)
//    {
//        ui->tichu_text3->append(QString::number(initailData[i],'g',16));
//    }


//void Widget::tichu(double *initial, qint8 &index_initial)
//{

//    qint8 i,j;//循环索引
//    double Sum=0;//和
//    double Sum_1=0;//之后算法的中间变量
//    double standardError=0;//标准误差
//    double Average=0;  /*平均*/
//    double d_x=0;//变化量
//    //求平均值，把和,平均值输出,index_initial = 100
//    for(i=0;i<index_initial;i++){
//        Sum += initial[i];
//    }
//    Average = Sum/(index_initial);
//    ui->tichu_text3->append("SUM:\n"+QString::number(Sum,'g',16));
//    ui->tichu_text3->append("AVERAGE:\n"+QString::number(Average,'g',16));


//    //求实验标准偏差
//    Sum_1 = 0; //初始化Sum
//    for(i=0;i<index_initial;i++){
//        d_x = pow((initial[i] - Average),2);
//        Sum_1 += d_x;
//    }
//    ui->tichu_text3->append("第一步:\n"+QString::number(Sum_1,'g',16));

//    Sum_1 = Sum_1/(index_initial-1);
//    ui->tichu_text3->append("第二步:\n"+QString::number(Sum_1,'g',16));

//    Sum_1 = sqrt(Sum_1);
//    ui->tichu_text3->append("第三步:\n"+QString::number(Sum_1,'g',16));
//    standardError = Sum_1;
//    //以上完成后会得到标准偏差

//    //判别，剔除粗大误差

//    for(i=0;i<index_initial;i++){
//        Sum_1 =qAbs(initial[i]-Average);

//        if(Sum_1>(3*standardError))
//        {
//            initial[i] = 1;
//        }

//    }
//    for(i=0;i<index_initial;i++){
//        if(initial[i]==1){
//            for(j=i;j<index_initial-1;j++){
//                initial[j]=initial[j+1];
//            }
//            i = i-1;
//            index_initial =index_initial-1;
//        }
//    }



//}
