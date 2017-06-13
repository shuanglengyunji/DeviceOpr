#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


namespace Ui {
class Widget;
}


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_bt_Search_clicked();

    void on_bt_SendCMD_clicked();

    void on_get_fre_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
