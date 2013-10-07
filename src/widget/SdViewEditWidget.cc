#include <QWheelEvent>
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


#include "util/SdRenderUtil.h"


SdViewEditWidget* SdViewEditWidget::create()
{
	return new SdViewEditWidget;
}


SdViewEditWidget::SdViewEditWidget()
{
	m_translate=Vector2(0,0);
	m_zoom=1.0f;
	m_showAxis=true;
	m_showGrid=true;
	m_gridSize=Vector2(32,32);
	m_gridColorA=Color(100,100,100);
    m_gridColorB=Color(70,70,70);
	m_backgroundColor=Color::WHITE;
	m_showBone=true;
	m_showImage=true;
	m_showBoneName=true;

	m_spaceDown=false;

	setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

SdViewEditWidget::~SdViewEditWidget()
{
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
	mat.makeOrthographic(-width/2,width/2,-height/2,height/2,-100,100);
	SdRenderUtil::setProjectionMatrix(&mat);
	glViewport(0,0,width,height);
}

void  SdViewEditWidget::paintGL()
{
    Global::render()->setClearColor(m_backgroundColor);
    Global::render()->clear();

	Matrix4 mat;
	mat.makeCompose(Vector3(m_translate.x,m_translate.y,0),
					Vector3(0,0,0),FS_EULER_XYZ,
					Vector3(m_zoom,m_zoom,1));
	glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf((float*)&mat);

	if(m_showGrid)
	{
		drawGrid();
	}
	if(m_showAxis)
	{
		drawAxis();
	}
}

void SdViewEditWidget::drawAxis()
{
	Vector2 a,b;
	getEditArea(&a,&b);
    SdRenderUtil::drawLine(Vector2(a.x,0),Vector2(b.x,0),1,Color::RED);
    SdRenderUtil::drawLine(Vector2(0,a.y),Vector2(0,b.y),1,Color::BLUE);
}
void SdViewEditWidget::drawGrid()
{
	Vector2 a,b;
	getEditArea(&a,&b);

	int min_x=floor(a.x/m_gridSize.x);
	int max_x=ceil(b.x/m_gridSize.x);

	int min_y=floor(a.y/m_gridSize.y);
	int max_y=float(b.y/m_gridSize.y);

	for(int i=min_x-1;i<=max_x;i++)
	{
		for(int j=min_y-1;j<=max_y;j++)
		{
			Vector2 start=Vector2(i*m_gridSize.x,j*m_gridSize.y);
            Vector2 end=Vector2((i+1)*m_gridSize.x,(j+1)*m_gridSize.y);

			if((i+j)%2)
			{
				SdRenderUtil::drawRectangle(start,end,m_gridColorA);
			}
			else 
			{
				SdRenderUtil::drawRectangle(start,end,m_gridColorB);
			}
		}
	}
}


Vector2 SdViewEditWidget::toWidgetCoord(Vector2 v)
{
    float rx=v.x;
    float ry=v.y;
    QSize  wsize=size();
    rx=rx*m_zoom+m_translate.x;
    ry=ry*m_zoom+m_translate.y;
    rx=rx+wsize.width()/2;
    ry=wsize.height()/2-ry;

	Vector2 ret;
    ret.x=rx;
    ret.y=ry;
	return ret;
}

Vector2 SdViewEditWidget::toEditCoord(Vector2 v)
{
	float rx=v.x;
	float ry=v.y;
	QSize wsize=size();

	rx=rx-wsize.width()/2;
	ry=wsize.height()/2-ry;

	Vector2 ret;
	ret.x=(rx-m_translate.x)/m_zoom;
	ret.y=(ry-m_translate.y)/m_zoom;
	return ret;
}


void SdViewEditWidget::getEditArea(Vector2* a,Vector2* b)
{
	QSize wsize=size();
    Vector2 start=toEditCoord(Vector2(0,wsize.height()));
    Vector2 end=toEditCoord(Vector2(wsize.width(),0));

	a->x=start.x;
	a->y=start.y;

	b->x=end.x;
	b->y=end.y;
}

void SdViewEditWidget::setTranslate(Vector2 t)
{
	m_translate=t;
}
Vector2 SdViewEditWidget::getTranslate()
{
	return m_translate;
}
void SdViewEditWidget::setZoom(float s)
{
	m_zoom=s;
}

float SdViewEditWidget::getZoom()
{
	return m_zoom;
}
void SdViewEditWidget::resetZoomTranslate()
{
	m_zoom=1.0f;
	m_translate=Vector2(0.0f,0.0f);
}





void SdViewEditWidget::wheelEvent(QWheelEvent* event)
{
    float detal;

    float zoom=m_zoom;
    float x=event->x();
    float y=event->y();

    QSize wsize=size();
    x=x-wsize.width()/2;
    y=wsize.height()/2-y;

    float rx=(x-m_translate.x)/zoom;
    float ry=(y-m_translate.y)/zoom;

    detal=event->delta()>0?1.1f:0.9f;
    m_zoom*=detal;

    float tx=x-rx*m_zoom;
    float ty=y-ry*m_zoom;
    m_translate=Vector2(tx,ty);

    update();
}

void SdViewEditWidget::mouseMoveEvent(QMouseEvent* event)
{
	float dx=event->x()-m_lastpos.x();
	float dy=event->y()-m_lastpos.y();

	if(event->buttons()&Qt::LeftButton)
	{
		if(m_spaceDown)
		{
			setTranslate(Vector2(m_translate.x+dx,m_translate.y-dy));
			m_lastpos=event->pos();
			update();
			return;
		}
	}

	m_lastpos=event->pos();
}

void SdViewEditWidget::mousePressEvent(QMouseEvent* event)
{
	if(m_spaceDown)
	{
		m_lastpos=event->pos();
		return;
	}
	m_lastpos=event->pos();
	
}

void SdViewEditWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if(m_spaceDown)
	{
		m_lastpos=event->pos();
		return;
	}
	m_lastpos=event->pos();
}

void SdViewEditWidget::keyPressEvent(QKeyEvent* event)
{
	if(event->key()==Qt::Key_Space)
	{
		m_spaceDown=true;
		m_prevCursor=cursor();
        setCursor(Qt::ClosedHandCursor);
        update();
		return ;
	}

}
void SdViewEditWidget::keyReleaseEvent(QKeyEvent* event)
{
	if(event->key()==Qt::Key_Space)
	{
		m_spaceDown=false;
		setCursor(m_prevCursor);
        m_prevCursor=Qt::ArrowCursor;
        update();
		return ;
	}
}































