#ifndef MEASURETHREAD_H
#define MEASURETHREAD_H

#include <QThread>
#include "widget.h"

class MeasureThread : public QThread
{
    Q_OBJECT
public:
    MeasureThread();
    void run();
    void mystop();

private:
    int flag;
};

#endif // MEASURETHREAD_H
