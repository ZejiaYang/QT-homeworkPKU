#-------------------------------------------------
#
# Project created by QtCreator 2023-05-30T22:50:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniMazeGameWidgetIII
TEMPLATE = app


SOURCES += main.cpp\
        minimazegamewidgetiii.cpp \
    mazegenerator.cpp

HEADERS  += minimazegamewidgetiii.h \
    minimaze_config.h \
    mazegenerator.h

FORMS    += minimazegamewidgetiii.ui

RESOURCES += \
    mazeresiii.qrc
