#include <QDebug>
#include "ui/DsViewWidget.h"

DsViewWidget* DsViewWidget::create()
{
     return new DsViewWidget;
}
void DsViewWidget::initializeGL()
{
}

void DsViewWidget::resizeGL(int width,int height)
{
}
void DsViewWidget::paintGL()
{
}



DsViewWidget::DsViewWidget()
{
    init();
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true) ;
}
DsViewWidget::~DsViewWidget()
{
	destroy();
}
void DsViewWidget::mousePressEvent(QMouseEvent* event)
{
}

void DsViewWidget::mouseReleaseEvent(QMouseEvent* event)
{
}


void DsViewWidget::mouseMoveEvent(QMouseEvent* event)
{
    qDebug()<<"DsViewWidget Move";
}
void DsViewWidget::wheelEvent(QWheelEvent* event)
{
}

void DsViewWidget::enterEvent(QEvent* event)
{
    qDebug()<<"DsViewWidget Enter";

}
void DsViewWidget::leaveEvent(QEvent* event)
{
    qDebug()<<"DsViewWidget Level";
}

void DsViewWidget::keyPressEvent(QKeyEvent* event)
{
}
void DsViewWidget::keyReleaseEvent(QKeyEvent* event)
{
}



void DsViewWidget::init()
{
}

void DsViewWidget::destory()
{
}



















