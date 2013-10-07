#ifndef _SD_VIEW_EDIT_WIDGET_H_
#define _SD_VIEW_EDIT_WIDGET_H_

#include "GL/glew.h"
#include <QGLWidget>
#include <QCursor>

#include "math/FsVector2.h"
#include "graphics/FsColor.h"
NS_FS_USE


class SdViewEditWidget:public QGLWidget 
{
	Q_OBJECT
	public:
		static SdViewEditWidget* create();

	public:
		virtual void initializeGL();
		virtual void resizeGL(int width,int height);
		virtual void paintGL();

	public:

        void setTranslate(Vector2  t);
		Vector2 getTranslate();
		void setZoom(float s);
		float getZoom();
		void resetZoomTranslate();

		Vector2 toWidgetCoord(Vector2 v);
		Vector2 toEditCoord(Vector2 v);
		void getEditArea(Vector2* a,Vector2* b);

	public:
		void drawAxis();
		void drawGrid();
	
	public:
		SdViewEditWidget();
		~SdViewEditWidget();




	public:
		/* axis */
		void setShowAxis(bool enable);
		bool isShowAxis();


		/* grid */
		void setShowGrid(bool enable);
		bool isShowGrid();
		void setGridSize(Vector2 size);
		Vector2 getGridSize();
		void setGridColor(Color a,Color b);

		/* bone */
		void setShowBone(bool enable);
		bool isShowBone();


		void setShowBoneName(bool enable);
		bool isShowBoneName();

		void setShowImage(bool enable);
		bool isShowImage();


		/* background */
		void setBackgroundColor(Color c);
		Color getBackgroundColor();


	private:
		Vector2 m_translate;
		float m_zoom;

		bool m_showAxis;

		bool m_showGrid;
		Vector2 m_gridSize;
		Color m_gridColorA,m_gridColorB;

		Color m_backgroundColor;

		bool m_showBone;
		bool m_showImage;
		bool m_showBoneName;


		bool m_spaceDown;
		QPoint m_lastpos;
		QCursor m_prevCursor;


    public: /* mouse move event */

		virtual void wheelEvent(QWheelEvent* event);

		virtual void mouseMoveEvent(QMouseEvent* event);
		virtual void mousePressEvent(QMouseEvent* event);
		virtual void mouseReleaseEvent(QMouseEvent* event);
		virtual void keyPressEvent(QKeyEvent* event);
		virtual void keyReleaseEvent(QKeyEvent* event);

		/*
		virtual void focusInEvent(QFocusEvent* event);
		virtual void focusOutEvent(QFocusEvent* event);
		virtual void enterEvent(QEvent* event);
        virtual void leaveEvent(QEvent* event);
		*/

		/* draw func */

};



#endif /*_SD_VIEW_EDIT_WIDGET_H_*/

























