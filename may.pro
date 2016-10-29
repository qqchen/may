#-------------------------------------------------
#
# Project created by QtCreator 2016-10-29T13:34:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = may
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    may/word.cpp \
    may/date.cpp

HEADERS  += mainwindow.h \
    may/config.h \
    may/word.h \
    may/date.h

FORMS    += mainwindow.ui
