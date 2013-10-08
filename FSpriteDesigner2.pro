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
    src/core/SdTextureMgr.cc \
    src/widget/SdProjectExploreModel.cc \
    src/operator/SdOperator.cc \
    src/operator/SdDataOperator.cc \
    src/SdGlobal.cc \
    src/SdMsgCenter.cc \
    src/widget/SdProjectExploreWidget.cc \
    src/operator/SdOperator.cc \
    src/operator/SdUiOperator.cc \
    src/widget/SdInputDialog.cc \
    src/command/SdSpriteAttrChangeCommand.cc \
    src/command/SdCommand.cc \
    src/command/SdSpriteAddCommand.cc \
    src/command/SdSpriteRemoveCommand.cc \
    src/command/SdAnimationAttrChangeCommand.cc \
    src/command/SdAnimationAddCommand.cc \
    src/command/SdAnimationRemoveCommand.cc

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
    src/core/SdAnimation.h \
    src/widget/SdProjectExploreWidget.h \
    src/widget/SdProjectExploreModel.h \
    src/operator/SdOperator.h \
    src/operator/SdDataOperator.h \
    src/SdMsgCenter.h \
    src/test.h \
    src/operator/SdUiOperator.h \
    src/widget/SdInputDialog.h \
    src/command/SdSpriteAttrChangeCommand.h \
    src/command/SdCommand.h \
    src/util/SdCircleQueue.h \
    src/command/SdSpriteAddCommand.h \
    src/command/SdSpriteRemoveCommand.h \
    src/command/SdAnimationAttrChangeCommand.h \
    src/command/SdAnimationAddCommand.h \
    src/command/SdAnimationRemoveCommand.h


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

FORMS += \
    resource/ui/input_text.ui


