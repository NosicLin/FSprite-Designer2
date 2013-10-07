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
    src/widget/SdMainWindow.cc \
    src/main.cc \
    src/widget/SdViewEditWidget.cc \
    src/util/SdUtil.cc \
    src/util/SdRenderUtil.cc \
    src/core/SdSprite.cc \
    src/core/SdProject.cc \
    src/core/SdProject.cc \
    src/core/SdIdentify.cc \
    src/core/SdAnimation.cc \
    src/core/SdTextureMgr.cc

HEADERS  += \
    src/widget/SdMainWindow.h \
    src/SdMacros.h \
    src/widget/SdViewEditWidget.h \
    src/util/SdUtil.h \
    src/util/SdRenderUtil.h \
    src/core/SdTextureMgr.h \
    src/core/SdTexture.h \
    src/core/SdSprite.h \
    src/core/SdProjectConfig.h \
    src/core/SdProject.h \
    src/core/SdKeyFrame.h \
    src/core/SdIdentify.h \
    src/core/SdBone.h \
    src/core/SdAnimation.h


INCLUDEPATH +=faeris/lib/libfaeris/src \
                         faeris/lib/lib3rdparty/c99/include \
                         faeris/lib/lib3rdparty/freetype/include \
                         faeris/lib/lib3rdparty/curl/include \
                         faeris/lib/lib3rdparty/GL/include \
                         faeris/lib/lib3rdparty/libpng/include \
						 faeris/lib/lib3rdparty/pthread/include \


win32 {

        LIBS += -L$$PWD/faeris/lib/library/win32  -llibfaerisd   \
                -L$$PWD/faeris/lib/library/win32/3rdparty -lcurld -lglew32 -llibpngd -lfreetype

		CONFIG +=console
}


