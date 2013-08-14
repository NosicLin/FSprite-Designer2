#ifndef _MD_VIEW_WIDGET_H_
#define _MD_VIEW_WIDGET_H_
#include <QGLWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QCursor>



class DsViewWidget:public QGLWidget
{
	Q_OBJECT
	public:
        static DsViewWidget* create();
	public:
		DsViewWidget();
		~DsViewWidget();
	public:
		virtual void initializeGL();
		virtual void resizeGL(int width,int height);
		virtual void paintGL();

	public:
		virtual void mousePressEvent(QMouseEvent* event);
		virtual void mouseReleaseEvent(QMouseEvent* event);
        virtual void mouseMoveEvent(QMouseEvent* event);
        virtual void wheelEvent(QWheelEvent* event);
		virtual void enterEvent(QEvent* event);
		virtual void leaveEvent(QEvent* event);
        virtual void keyPressEvent(QKeyEvent* event);
        virtual void keyReleaseEvent(QKeyEvent* event);

    protected:
        void init();
        void destory();


};

#endif /*_MD_VIEW_WIDGET_H_*/




