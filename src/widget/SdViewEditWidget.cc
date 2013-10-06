#include "widget/SdViewEditWidget.h"
#include "math/FsMatrix4.h"

#include "FsGlobal.h"
#include "FsFaerisModule.h"
#include "FsGlobal.h"
#include "graphics/FsRender.h"

#include "sys/FsWindow.h"
#include "extends/FsScriptEngine.h"
#include "mgr/FsTextureMgr.h"
#include "mgr/FsFontTTFDataMgr.h"
#include "mgr/FsSprite2DDataMgr.h"

#include "graphics/material/FsMat_V4F_T2F_A1F.h"
#include "graphics/material/FsMat_V4F_T2F.h"
#include "sys/io/FsVFS.h"
#include "sys/io/FsPackage.h"
#include "support/util/FsDict.h"
#include "support/util/FsArray.h"
#include "support/util/FsScriptUtil.h"




SdViewEditWidget* SdViewEditWidget::create()
{
	return new SdViewEditWidget;
}

void SdViewEditWidget::initializeGL()
{
	if(glewInit()!=GLEW_OK)
	{
		FS_TRACE_WARN("Create GlEW Failed");
    }

    VFS::moduleInit();

    Render* render=Render::create();
    Global::setRender(render);

    TextureMgr* tex_mgr=TextureMgr::create();
    Global::setTextureMgr(tex_mgr);


    FontTTFDataMgr* font_mgr=FontTTFDataMgr::create();
    Global::setFontTTFDataMgr(font_mgr);

    Sprite2DDataMgr* sprite_mgr=Sprite2DDataMgr::create();
    Global::setSprite2DDataMgr(sprite_mgr);

}

void SdViewEditWidget::resizeGL(int width,int height)
{
	Matrix4 mat;
	mat.makeOrthographic(-width/2,width/2,-height/2,height/2,0,100);
    Global::render()->setProjectionMatrix(&mat);
	Global::render()->setViewport(0,0,width,height);
}

void  SdViewEditWidget::paintGL()
{
}






