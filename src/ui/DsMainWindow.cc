#include "ui/DsMainWindow.h"
#include "ui/DsResourceWidget.h"
#include "ui/DsViewWidget.h"
#include "DsMacros.h"

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextStream>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSplitter>
#include <QDesktopServices>
#include <QUrl>

DsMainWindow* DsMainWindow::create()
{
	return new DsMainWindow;
}

DsMainWindow::DsMainWindow(QWidget* parent)
    :QMainWindow(parent)
{
	init();
	layout();
	createMenuBar();
}

DsMainWindow::~DsMainWindow()
{
	destory();
}




void DsMainWindow::init()
{
	m_resourceDockWidget=new QDockWidget("Resource",NULL);
    m_resourceWidget=new DsResourceWidget;
    QStringList filters;
    filters << "*.png" << "*.ttr" ;
    m_resourceWidget->setNameFilters(filters);
	m_resourceDockWidget->setWidget(m_resourceWidget);
	m_resourceDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    m_viewWidget=DsViewWidget::create();
    this->setCentralWidget(m_viewWidget);

}
void DsMainWindow::layout()
{
    /* position */
    setTabPosition(Qt::LeftDockWidgetArea,QTabWidget::North);
    setTabPosition(Qt::RightDockWidgetArea,QTabWidget::North);
    setTabPosition(Qt::BottomDockWidgetArea,QTabWidget::North);

    /* add dock widget */
    addDockWidget(Qt::LeftDockWidgetArea,m_resourceDockWidget);
}


void DsMainWindow::destory()
{
}


void DsMainWindow::createMenuBar()
{

	m_menuBar=menuBar();
	/*File*/
	QMenu* mn_file=menuBar()->addMenu("&File");
	{	
		/* new */
        ms_newProject=new QAction(QPixmap(DS_MS_NEW),"&New Project",this);
        mn_file->addAction(ms_newProject);
        connect(ms_newProject,SIGNAL(triggered()),this,SLOT(onNewProject()));


		/* open */
        ms_openProject=new QAction(QPixmap(DS_MS_OPEN),"&Open Project",this);
        mn_file->addAction(ms_openProject);
        connect(ms_openProject,SIGNAL(triggered()),this,SLOT(onOpenProject()));

		/* save */
		ms_saveProject=new QAction(QPixmap(DS_MS_SAVE),"&Save",this);
		mn_file->addAction(ms_saveProject);
		connect(ms_saveProject,SIGNAL(triggered()),this,SLOT(onSaveProject()));


		/* close */
		ms_closeProject=new QAction(QPixmap(DS_MS_CLOSE),"&Close",this);
		mn_file->addAction(ms_closeProject);
		connect(ms_closeProject,SIGNAL(triggered()),this,SLOT(onCloseProject()));

		/* export  */
		ms_exportSprite=new QAction(QPixmap(DS_MS_EXPORT),"&Export...",this);
		mn_file->addAction(ms_exportSprite);
		connect(ms_exportSprite,SIGNAL(triggered()),this,SLOT(onExportSprite()));

		/* quit */
		ms_exit=new QAction(QPixmap(DS_MS_QUIT),"&Exit",this);
        mn_file->addAction(ms_exit);
        connect(ms_exit,SIGNAL(triggered()),this,SLOT(onExit()));


	}


	/* Edit */
	QMenu* mn_edit=menuBar()->addMenu("&Edit");
	{
        /* undo */
        ms_undo=new QAction(QPixmap(DS_MS_UNDO),"&Undo",this);
        mn_edit->addAction(ms_undo);
        connect(ms_undo,SIGNAL(triggered()),this,SLOT(onUndo()));

        /* redo */
        ms_redo=new QAction(QPixmap(DS_MS_REDO),"&Redo",this);
        mn_edit->addAction(ms_redo);
        connect(ms_redo,SIGNAL(triggered()),this,SLOT(onRedo()));

        mn_edit->addSeparator();

		/* rename sprite */
		ms_renameSprite=new QAction(QPixmap(DS_MS_RENAME_SPRITE),"Rename Sprite",this);
		mn_edit->addAction(ms_renameSprite);
		connect(ms_renameSprite,SIGNAL(triggered()),this,SLOT(onRenameSprite()));

		/* rename animation */
		ms_renameAnimation=new QAction(QPixmap(DS_MS_RENAME_ANIMATION),"Rename Animation",this);
		mn_edit->addAction(ms_renameAnimation);
        connect(ms_renameAnimation,SIGNAL(triggered()),this,SLOT(onRenameAnimation()));

        mn_edit->addSeparator();



		/* moveUp */
		ms_moveUp=new QAction(QPixmap(DS_MS_MOVE_UP),"&MoveUp",this);
		mn_edit->addAction(ms_moveUp);
		connect(ms_moveUp,SIGNAL(triggered()),this,SLOT(onMoveUp()));

		/* down */
		ms_moveDown=new QAction(QPixmap(DS_MS_MOVE_DOWN),"&MoveDown",this);
		mn_edit->addAction(ms_moveDown);
		connect(ms_moveDown,SIGNAL(triggered()),this,SLOT(onMoveDown()));

		/* tofront */
		ms_moveFront=new QAction(QPixmap(DS_MS_MOVE_FRONT),"&MoveFront",this);
		mn_edit->addAction(ms_moveFront);
		connect(ms_moveFront,SIGNAL(triggered()),this,SLOT(onMoveFront()));

		/* toend */
		ms_moveTail=new QAction(QPixmap(DS_MS_MOVE_END),"&MoveEnd",this);
		mn_edit->addAction(ms_moveTail);
		connect(ms_moveTail,SIGNAL(triggered()),this,SLOT(onMoveEnd()));

	}

	/* sprite */




	/* view */
	QMenu* mn_view=menuBar()->addMenu("&View");
	{

		/*show Axis*/
        ms_showCoordnate=new QAction("&Show Axis",this);
        ms_showCoordnate->setCheckable(true);
        ms_showCoordnate->setChecked(true);
        mn_view->addAction(ms_showCoordnate);

        connect(ms_showCoordnate,SIGNAL(triggered()),this,SLOT(onShowCoordnate()));

		/* show grid */
        ms_showGrid=new QAction("&Show Grid",this);
        ms_showGrid->setCheckable(true);
        ms_showGrid->setChecked(false);
        mn_view->addAction(ms_showGrid);
        connect(ms_showGrid,SIGNAL(triggered()),this,SLOT(onShowGrid()));

        mn_view-> addSeparator();

		/* zoomin */
		ms_zoomIn=new QAction(QPixmap(DS_MS_ZOOM_IN),"&ZoomIn",this);
		mn_view ->addAction(ms_zoomIn);
		connect(ms_zoomIn,SIGNAL(triggered()),this,SLOT(onZoomIn()));

		/* zoomout */
		ms_zoomOut=new QAction(QPixmap(DS_MS_ZOOM_OUT),"&ZoomOut",this);
		mn_view->addAction(ms_zoomOut);
		connect(ms_zoomOut,SIGNAL(triggered()),this,SLOT(onZoomOut()));

		/* actual size*/
		ms_actualSize=new QAction(QPixmap(DS_MS_ACTUAL_SIZE),"&Actual Size",this);
		mn_view->addAction(ms_actualSize);
		connect(ms_actualSize,SIGNAL(triggered()),this,SLOT(onActualSize()));

    }
	QMenu* mn_sprite= menuBar()->addMenu("&Sprite");
	{
		ms_newSprite=new QAction("&New Sprite",this);
		mn_sprite->addAction(ms_newSprite);
        connect(ms_newSprite,SIGNAL(triggered()),this,SLOT(onNewSprite()));

		ms_newAnimation=new QAction("&New Animation",this);
		mn_sprite->addAction(ms_newAnimation);
        connect(ms_newAnimation,SIGNAL(triggered()),this,SLOT(onNewAnimation()));

        mn_sprite-> addSeparator();

		ms_insertKeyFrame=new QAction("&Insert KeyFrame",this);
		mn_sprite->addAction(ms_insertKeyFrame);
        connect(ms_insertKeyFrame,SIGNAL(triggered()),this,SLOT(onInsertKeyFrame()));

		ms_insertEmptyFrame=new QAction("&Insert EmprtyFrame",this);
		mn_sprite->addAction(ms_insertEmptyFrame);
        connect(ms_insertEmptyFrame,SIGNAL(triggered()),this,SLOT(onInsertEmptyFrame()));

		ms_createTween=new QAction("&Create Tween",this);
		mn_sprite->addAction(ms_createTween);
        connect(ms_createTween,SIGNAL(triggered()),this,SLOT(onCreateTween()));

        ms_removeTween=new QAction("&Remove Tween",this);
		mn_sprite->addAction(ms_removeTween);
        connect(ms_removeTween,SIGNAL(triggered()),this,SLOT(onRemoveTween()));

        mn_sprite-> addSeparator();

		ms_setAnimationFps=new QAction("&Set Animation Fps",this);
		mn_sprite->addAction(ms_setAnimationFps);
        connect(ms_setAnimationFps,SIGNAL(triggered()),this,SLOT(onSetAnimationFps()));
	}


	/* about */
    QMenu* mn_help=menuBar()->addMenu("About");
	{
		/* online toturial*/
		ms_help=new QAction(QPixmap(DS_MS_HELP),"&Online Tutorial",this);
        mn_help->addAction(ms_help);
		connect(ms_help,SIGNAL(triggered()),this,SLOT(onHelp()));

		/* about us */
        ms_aboutus=new QAction(QPixmap(DS_MS_ABOUT_US),"&About Us",this);
        mn_help->addAction(ms_aboutus);
        connect(ms_aboutus,SIGNAL(triggered()),this,SLOT(onAboutUs()));
	}

}

