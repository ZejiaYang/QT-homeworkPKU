#-------------------------------------------------
#
# Project created by QtCreator 2023-07-03T15:01:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = parkour_2
TEMPLATE = app


SOURCES += main.cpp\
        parkour_2.cpp \
    map.cpp \
    runner.cpp \
    barrier.cpp

HEADERS  += parkour_2.h \
    map.h \
    parkour_config.h \
    runner.h \
    barrier.h

FORMS    += parkour_2.ui

RESOURCES += \
    parkour_res.qrc
