
#include <QApplication>

#include <stdio.h>
#include "ui/DsMainWindow.h"

#include "DsGlobal.h"
#include "core/DsProject.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    DsGlobal::ms_data=new DsData;
    DsProject* project=DsProject::create("E:/DesignSpace/FS_Test/aaa.proj");
    DsGlobal::data()->setCurProject(project);

    DsMainWindow* win=DsMainWindow::create();



	win->show();
	win->setWindowTitle("FSprite Designer 2");
	win->resize(1024,800);
	win->showMaximized();

	return app.exec();
}
