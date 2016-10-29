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
    may/date.cpp \
    may/db.cpp \
    third/jsoncpp/lib_json/json_reader.cpp \
    third/jsoncpp/lib_json/json_value.cpp \
    third/jsoncpp/lib_json/json_valueiterator.inl \
    third/jsoncpp/lib_json/json_writer.cpp \
    addworddialog.cpp

HEADERS  += mainwindow.h \
    may/config.h \
    may/word.h \
    may/date.h \
    may/db.h \
    may/JsonObject.h \
    third/jsoncpp/include/json/allocator.h \
    third/jsoncpp/include/json/assertions.h \
    third/jsoncpp/include/json/autolink.h \
    third/jsoncpp/include/json/config.h \
    third/jsoncpp/include/json/features.h \
    third/jsoncpp/include/json/forwards.h \
    third/jsoncpp/include/json/json.h \
    third/jsoncpp/include/json/reader.h \
    third/jsoncpp/include/json/value.h \
    third/jsoncpp/include/json/version.h \
    third/jsoncpp/include/json/writer.h \
    third/jsoncpp/lib_json/json_tool.h \
    third/jsoncpp/lib_json/version.h.in \
    addworddialog.h

INCLUDEPATH += . third/jsoncpp/include third/jsoncpp/include/json

FORMS    += mainwindow.ui \
    addworddialog.ui

DISTFILES += \
    third/jsoncpp/lib_json/sconscript \
    third/jsoncpp/include/CMakeLists.txt \
    third/jsoncpp/lib_json/CMakeLists.txt
