#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T19:44:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SchoolStore_new
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


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    messagebox_1.cpp \
    user_information.cpp \
    recharge.cpp \
    adminchange.cpp \
    shoppingcar.cpp \
    message.cpp \
    messagewelcome.cpp \
    upload.cpp

HEADERS  += mainwindow.h \
    login.h \
    connection.h \
    messagebox_1.h \
    user_information.h \
    recharge.h \
    adminchange.h \
    shoppingcar.h \
    message.h \
    messagewelcome.h \
    upload.h

FORMS    += mainwindow.ui \
    login.ui \
    messagebox_1.ui \
    user_information.ui \
    recharge.ui \
    adminchange.ui \
    shoppingcar.ui \
    message.ui \
    messagewelcome.ui \
    upload.ui

RESOURCES += \
    pic1.qrc
QT += sql
QT+=widgets

DISTFILES +=
QT +=network
