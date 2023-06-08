#-------------------------------------------------
#
# Project created by QtCreator 2023-06-08T17:09:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pushbox2
TEMPLATE = app


SOURCES += main.cpp\
        push.cpp \
    GameMap.cpp \
    Role.cpp

HEADERS  += push.h \
    GameMap.h \
    Role.h \
    push_config.h

FORMS    += push.ui

RESOURCES += \
    img.qrc
