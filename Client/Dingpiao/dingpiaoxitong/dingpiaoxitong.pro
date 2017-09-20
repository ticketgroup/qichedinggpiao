#-------------------------------------------------
#
# Project created by QtCreator 2017-09-12T11:23:30
#
#-------------------------------------------------

QT       += core gui
QT       += network
LIBS     += -lpthread libwsock32 libws2_32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dingpiaoxitong
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    denglu.cpp \
    client.cpp \
    passwordchange.cpp \
    telephonechange.cpp \
    passwordback.cpp \
    passwordback1.cpp \
    registration.cpp \
    buyticket.cpp \
    endorse.cpp \
    registration1.cpp \
    variables.cpp

HEADERS += \
        mainwindow.h \
    denglu.h \
    passwordchange.h \
    telephonechange.h \
    passwordback.h \
    passwordback1.h \
    registration.h \
    buyticket.h \
    endorse.h \
    registration1.h \
    Client.h \
    variables.h

FORMS += \
        mainwindow.ui \
    denglu.ui \
    passwordchange.ui \
    telephonechange.ui \
    passwordback.ui \
    passwordback1.ui \
    registration.ui \
    buyticket.ui \
    endorse.ui \
    registration1.ui

RESOURCES += \
    tupian.qrc
