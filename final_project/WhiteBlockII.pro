QT       += core gui
QT       += multimedia
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Ending.cpp \
    GameMap.cpp \
    Role.cpp \
    barrier.cpp \
    block.cpp \
    gameview.cpp \
    main.cpp \
    map.cpp \
    mazegame.cpp \
    mazegenerator.cpp \
    minimazegamewidgetiii.cpp \
    parkour_2.cpp \
    push.cpp \
    puzzlepart.cpp \
    runner.cpp \
    visitor.cpp \
    widget.cpp

HEADERS += \
    Ending.h \
    GameMap.h \
    Role.h \
    barrier.h \
    block.h \
    gameview.h \
    map.h \
    mazegame.h \
    mazegenerator.h \
    minimaze_config.h \
    minimaze_config.h \
    minimaze_config2.h \
    minimazegamewidgetiii.h \
    parkour_2.h \
    parkour_config.h \
    push.h \
    push_config.h \
    puzzlepart.h \
    runner.h \
    visitor.h \
    widget.h

FORMS += \
    Ending.ui \
    gameview.ui \
    mazegame.ui \
    minimazegamewidgetiii.ui \
    parkour_2.ui \
    push.ui \
    visitor.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    1.qrc \
    EndMap.qrc \
    Resource.qrc \
    Resource.qrc \
    img.qrc \
    mazeresiii.qrc \
    parkour_res.qrc \
    pic.qrc \
    qss.qrc

DISTFILES += \
    ../../R.jpg \
    style.qss \
    style_copy.qss
