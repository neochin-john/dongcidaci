QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 sdk_no_version_check
QMAKE_CXXFLAGS += -Wno-deprecated-copy

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controlpanel.cpp \
    leftpanel.cpp \
    main.cpp \
    movewinwidget.cpp \
    player.cpp \
    topbar.cpp

HEADERS += \
    controlpanel.h \
    leftpanel.h \
    movewinwidget.h \
    player.h \
    topbar.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
