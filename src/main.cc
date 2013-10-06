#include <QApplication>
#include "widget/SdMainWindow.h"

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
    SdMainWindow* win=SdMainWindow::create();
	win->show();
    win->setWindowTitle("FSprite Designer");
	win->resize(1024,800);
	win->showMaximized();
	return app.exec();

}

