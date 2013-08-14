#-------------------------------------------------
#
# Project created by QtCreator 2013-08-14T21:30:24
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FSpriteDesigner2
TEMPLATE = app

INCLUDEPATH +=  src \


SOURCES += \
    src/main.cpp \
    src/main.cpp \
    src/ui/DsResourceWidget.cc \
    src/ui/DsMainWindow.cc \
    src/ui/DsViewWidget.cc \
    src/core/DsData.cc \
    src/DsGlobal.cc \
    src/core/DsProject.cc \
    src/core/DsSprite.cc \
    src/util/DsFileUtil.cc

HEADERS  += \
    src/DsMacros.h \
    src/ui/DsMainWindow.h \
    src/ui/DsViewWidget.h \
    src/ui/DsResourceWidget.h \
    src/ui/DsMainWindow.h \
    src/core/DsData.h \
    src/DsGlobal.h \
    src/core/DsProject.h \
    src/util/DsFileUtil.h

RESOURCES += \
    resource/images/res.qrc

