#-------------------------------------------------
#
# Project created by QtCreator 2016-02-03T01:17:47
#
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calendar
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    calendar.cpp \
    event.cpp \
    eventdialog.cpp

HEADERS  += mainwindow.h \
    calendar.h \
    event.h \
    eventdialog.h
