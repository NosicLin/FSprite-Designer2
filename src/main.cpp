
#include <QApplication>

#include <stdio.h>
#include "ui/DsMainWindow.h"

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
    DsMainWindow* win=DsMainWindow::create();

	win->show();
	win->setWindowTitle("FSprite Designer 2");
	win->resize(1024,800);
	win->showMaximized();

	return app.exec();
}
