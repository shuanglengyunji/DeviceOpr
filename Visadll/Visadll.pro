#-------------------------------------------------
#
# Project created by QtCreator 2013-10-18T14:25:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Device_Control
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    widget_measure.cpp \
    widget_cmd.cpp \
    widget_timer_recorder.cpp

HEADERS  += widget.h\
          ../Ni/include/visa.h

FORMS    += widget.ui

LIBS     += ../Ni/lib/msc/visa32.lib

win32:RC_FILE  += AppIco.rc

OTHER_FILES +=

