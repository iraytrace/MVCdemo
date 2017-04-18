#-------------------------------------------------
#
# Project created by QtCreator 2017-02-27T07:35:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = full
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    TemperatureSensor.cpp \
    Furnace.cpp \
    SetPoint.cpp

HEADERS  += MainWindow.h \
    TemperatureSensor.h \
    Furnace.h \
    SetPoint.h

FORMS    += MainWindow.ui
