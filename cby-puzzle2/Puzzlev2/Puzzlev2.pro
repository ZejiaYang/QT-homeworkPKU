#-------------------------------------------------
#
# Project created by QtCreator 2023-06-05T04:03:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Puzzlev2
TEMPLATE = app


SOURCES += main.cpp\
        mazegame.cpp \
    puzzlepart.cpp

HEADERS  += mazegame.h \
    puzzlepart.h \
    minimaze_config.h

FORMS    += mazegame.ui

RESOURCES += \
    image/images.qrc \
    1.qrc

DISTFILES += \
    image/2.jpg \
    image/3.jpg \
    image/bygg.png \
    image/ground2.png
