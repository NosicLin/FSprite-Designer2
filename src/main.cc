#include <QApplication>
#include "widget/SdMainWindow.h"
#include "SdGlobal.h"


#include "test.h"

int main(int argc,char** argv)
{



	QApplication app(argc,argv);
    SdProject* proj=createProject();
    SdGlobal::moduleInit();
    SdGlobal::setCurProject(proj);


    SdMainWindow* win=SdMainWindow::create();
	win->show();
    win->setWindowTitle("FSprite Designer");
	win->resize(1024,800);
	win->showMaximized();
	return app.exec();

}

