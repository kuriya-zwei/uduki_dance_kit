#-------------------------------------------------
#
# Project created by QtCreator 2017-07-03T17:33:45
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Uduki_Dance_Kit
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
    udkbone.cpp \
    udkjoint.cpp \
    udkparts.cpp \
    udkmesh.cpp \
    udkglobaldata.cpp \
    udktimeline.cpp \
    partssettingdialog.cpp

HEADERS  += mainwindow.h \
    udkbone.h \
    udkjoint.h \
    udkparts.h \
    udkslerpcontainer.h \
    udkmesh.h \
    udkglobaldata.h \
    udktimeline.h \
    partssettingdialog.h

FORMS    += mainwindow.ui \
    partssettingdialog.ui

DEPENDPATH += /opt/local/include
INCLUDEPATH += /opt/local/include
LIBS += -L/opt/local/lib/ \
     -lopencv_core \
     -lopencv_imgproc \
     -lopencv_highgui
