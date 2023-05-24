#-------------------------------------------------
#
# Project created by QtCreator 2023-05-22T09:06:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PushBox
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    GameMap.cpp \
    Role.cpp

HEADERS  += Widget.h \
    GameMap.h \
    Role.h

FORMS    += widget.ui

RESOURCES += \
    img.qrc
