#include "measurethread.h"

Widget * m_pwidget;

MeasureThread::MeasureThread()
{

}

void MeasureThread::run()
{
    flag = 1;
    while(true)
    {
        m_pwidget->Timing1();
        if(!flag)
            return;
    }
}

void MeasureThread::mystop()
{
    flag = 0;
}
