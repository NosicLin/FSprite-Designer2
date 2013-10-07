#include <QMenuBar>
#include <QtGlobal>

#include "widget/SdMainWindow.h"
#include "widget/SdViewEditWidget.h"
#include "widget/SdProjectExploreWidget.h"
#include "SdMacros.h"
#include "operator/SdOperator.h"
#include "operator/SdDataOperator.h"


SdMainWindow*  SdMainWindow::create()
{
	return new SdMainWindow;
}


SdMainWindow::SdMainWindow()
{
	initMenuBar();
    initWidget();
}

SdMainWindow::~SdMainWindow()
{

}

void SdMainWindow::initWidget()
{
    m_viewEditWidget=SdViewEditWidget::create();
    setCentralWidget(m_viewEditWidget);

	/* project explore widget */
	m_projectExploreWidget=new SdProjectExploreWidget();
	m_projectExploreDockWidget=new QDockWidget("ProjectExplore");
	m_projectExploreDockWidget->setWidget(m_projectExploreWidget);
	m_projectExploreDockWidget->setAllowedAreas(Qt::RightDockWidgetArea|Qt::LeftDockWidgetArea);

	addDockWidget(Qt::RightDockWidgetArea,m_projectExploreDockWidget);

}





void SdMainWindow::initMenuBar()
{
	m_menuBar=menuBar();
	/* file */
	mn_file=m_menuBar->addMenu(SD_M_FILE);
	{
		ms_openProject=new QAction(QPixmap(SD_I_OPEN_PROJECT),SD_M_OPEN_PROJECT,this);
		mn_file->addAction(ms_openProject);
        connect(ms_openProject,SIGNAL(triggered()),this,SLOT(onOpenProject()));
		ms_createProject=new QAction(QPixmap(SD_I_CREATE_PROJECT),SD_M_CREATE_PROJECT,this);
		mn_file->addAction(ms_createProject);
        connect(ms_createProject,SIGNAL(triggered()),this,SLOT(onCreatePoject()));

		ms_saveProject=new QAction(QPixmap(SD_I_SAVE_PROJECT),SD_M_SAVE_PROJECT,this);
		mn_file->addAction(ms_saveProject);
        connect(ms_saveProject,SIGNAL(triggered()),this,SLOT(onSaveProject()));
		ms_closeProject= new QAction(QPixmap(SD_I_CLOSE_PROJECT),SD_M_CLOSE_PROJECT,this);
		mn_file->addAction(ms_closeProject);
        connect(ms_closeProject,SIGNAL(triggered()),this,SLOT(onCloseProject()));
        mn_file->addSeparator();



		ms_exportFst=new QAction(QPixmap(SD_I_EXPORT_FST),SD_M_EXPORT_FST,this);
		mn_file->addAction(ms_exportFst);
        connect(ms_exportFst,SIGNAL(triggered()),this,SLOT(onExportFst()));

		ms_exportFsk=new QAction(QPixmap(SD_I_EXPORT_FSK),SD_M_EXPORT_FSK,this);
        mn_file->addAction(ms_exportFsk);

		ms_exportAll=new QAction(QPixmap(SD_I_EXPORT_ALL),SD_M_EXPORT_ALL,this);
		mn_file->addAction(ms_exportAll);
		connect(ms_exportAll,SIGNAL(triggered()),this,SLOT(onExportAll()));

        mn_file->addSeparator();
		
		ms_quit=new QAction(QPixmap(SD_I_QUIT),SD_M_QUIT,this);
		mn_file->addAction(ms_quit);
		connect(ms_quit,SIGNAL(triggered()),this,SLOT(onQuit()));
	}

    mn_edit=m_menuBar->addMenu(SD_M_EDIT);
	{
		ms_undo=new QAction(QPixmap(SD_I_UNDO),SD_M_UNDO,this);
		mn_edit->addAction(ms_undo);
		connect(ms_undo,SIGNAL(triggered()),this,SLOT(onUndo()));

		ms_redo=new QAction(QPixmap(SD_I_REDO),SD_M_REDO,this);
		mn_edit->addAction(ms_redo);
		connect(ms_redo,SIGNAL(triggered()),this,SLOT(onRedo()));

        mn_edit->addSeparator();

		ms_copy=new QAction(QPixmap(SD_I_COPY),SD_M_COPY,this);
		mn_edit->addAction(ms_copy);
		connect(ms_copy,SIGNAL(triggered()),this,SLOT(onCopy()));

		ms_paste=new QAction(QPixmap(SD_I_PASTE),SD_M_PASTE,this);
		mn_edit->addAction(ms_paste);
		connect(ms_paste,SIGNAL(triggered()),this,SLOT(onPaste()));

		ms_cut=new QAction(QPixmap(SD_I_CUT),SD_M_CUT,this);
		mn_edit->addAction(ms_cut);
		connect(ms_cut,SIGNAL(triggered()),this,SLOT(onCut()));
			
		ms_delete=new QAction(QPixmap(SD_I_DELETE),SD_M_DELETE,this);
		mn_edit->addAction(ms_delete);
		connect(ms_delete,SIGNAL(triggered()),this,SLOT(onDelete()));
	}
	mn_view=m_menuBar->addMenu(SD_M_VIEW);
	{
		ms_zoomIn=new QAction(QPixmap(SD_I_ZOOM_IN),SD_M_ZOOM_IN,this);
		mn_view->addAction(ms_zoomIn);
		connect(ms_zoomIn,SIGNAL(triggered()),this,SLOT(onZoomIn()));

		ms_zoomOut=new QAction(QPixmap(SD_I_ZOOM_OUT),SD_M_ZOOM_OUT,this);
		mn_view->addAction(ms_zoomOut);
		connect(ms_zoomOut,SIGNAL(triggered()),this,SLOT(onZoomOut()));

		ms_resetView=new QAction(QPixmap(SD_I_RESET_VIEW),SD_M_RESET_VIEW,this);
		mn_view->addAction(ms_resetView);
		connect(ms_resetView,SIGNAL(triggered()),this,SLOT(onResetView()));

		mn_view->addSeparator();




		ms_setBackgroundColor=new QAction(QPixmap(SD_I_SET_BG_COLOR),SD_M_SET_BG_COLOR,this);
		mn_view->addAction(ms_setBackgroundColor);
		connect(ms_setBackgroundColor,SIGNAL(triggered()),this,SLOT(onSetBackgroundColor()));

		mn_view->addSeparator();

		ms_showGrid= new QAction(QPixmap(SD_I_SHOW_GRID),SD_M_SHOW_GRID,this);
		mn_view->addAction(ms_showGrid);
		connect(ms_showGrid,SIGNAL(triggered()),this,SLOT(onShowGrid()));
		ms_showGrid->setCheckable(true);

		ms_showCoordnate=new QAction(QPixmap(SD_I_SHOW_COORDNATE),SD_M_SHOW_COORDNATE,this);
		mn_view->addAction(ms_showCoordnate);
		connect(ms_showCoordnate,SIGNAL(triggered()),this,SLOT(onShowCoordnate()));
		ms_showCoordnate->setCheckable(true);

		ms_showBone=new QAction(QPixmap(SD_I_SHOW_BONE),SD_M_SHOW_BONE,this);
		mn_view->addAction(ms_showBone);
		connect(ms_showBone,SIGNAL(triggered()),this,SLOT(onShowBone()));
		ms_showBone->setCheckable(true);

		ms_showBoneText=new QAction(QPixmap(SD_I_SHOW_BONE_TEXT),SD_M_SHOW_BONE_TEXT,this);
		mn_view->addAction(ms_showBoneText);
		connect(ms_showBoneText,SIGNAL(triggered()),this,SLOT(onShowBoneText()));
		ms_showBoneText->setCheckable(true);

	}

    mn_sprite=m_menuBar->addMenu(SD_M_SPRITE);
	{
		ms_newSprite=new QAction(QPixmap(SD_I_NEW_SPRITE),SD_M_NEW_SPRITE,this);
		mn_sprite->addAction(ms_newSprite);
		connect(ms_newSprite,SIGNAL(triggered()),this,SLOT(onNewSprite()));


		ms_renameSprite=new QAction(QPixmap(SD_I_RENAME_SPRITE),SD_M_RENAME_SPRITE,this);
		mn_sprite->addAction(ms_renameSprite);
		connect(ms_renameSprite,SIGNAL(triggered()),this,SLOT(onRenameSprite()));


		ms_deleteSprite=new QAction(QPixmap(SD_I_DELETE_SPRITE),SD_M_DELETE_SPRITE,this);
		mn_sprite->addAction(ms_deleteSprite);
		connect(ms_deleteSprite,SIGNAL(triggered()),this,SLOT(onDeleteSprite()));

		mn_sprite->addSeparator();

		ms_newAnimation=new QAction(QPixmap(SD_I_NEW_ANIMATION),SD_M_NEW_ANIMATION,this);
		mn_sprite->addAction(ms_newAnimation);
		connect(ms_newAnimation,SIGNAL(triggered()),this,SLOT(onNewAnimation()));

		ms_renameAnimation=new QAction(QPixmap(SD_I_RENAME_ANIMATION),SD_M_RENAME_ANIMATION,this);
		mn_sprite->addAction(ms_renameAnimation);
		connect(ms_renameAnimation,SIGNAL(triggered()),this,SLOT(onRenameAnimation()));


        ms_deleteAnimation=new QAction(QPixmap(SD_I_DELETE_ANIMATION),SD_M_DELETE_ANIMATION,this);
		mn_sprite->addAction(ms_deleteAnimation);
		connect(ms_deleteAnimation,SIGNAL(triggered()),this,SLOT(onDeleteAnimation()));

		mn_sprite->addSeparator();

        ms_newBone=new QAction(QPixmap(SD_I_NEW_BONE),SD_M_NEW_BONE,this);
        mn_sprite->addAction(ms_newBone);
        connect(ms_newBone,SIGNAL(triggered()),this,SLOT(onNewBone()));

        ms_renameBone=new QAction(QPixmap(SD_I_RENAME_BONE),SD_M_RENAME_BONE,this);
        mn_sprite->addAction(ms_renameBone);
        connect(ms_renameBone,SIGNAL(triggered()),this,SLOT(onRenameBone()));

        ms_deleteBone=new QAction(QPixmap(SD_I_DELETE_BONE),SD_M_DELETE_BONE,this);
        mn_sprite->addAction(ms_deleteBone);
        connect(ms_deleteBone,SIGNAL(triggered()),this,SLOT(onDeleteBone()));

        mn_sprite->addSeparator();

		ms_insertKeyFrame=new QAction(QPixmap(SD_I_INSERT_KEYFRAME),SD_M_INSERT_KEYFRAME,this);
		mn_sprite->addAction(ms_insertKeyFrame);
		connect(ms_insertKeyFrame,SIGNAL(triggered()),this,SLOT(onInsertKeyFrame()));

		ms_deleteKeyFrame=new QAction(QPixmap(SD_I_DELETE_KEYFRAME),SD_M_DELETE_KEYFRAME,this);
		mn_sprite->addAction(ms_deleteKeyFrame);
		connect(ms_deleteKeyFrame,SIGNAL(triggered()),this,SLOT(onDeleteKeyFrame()));

		ms_setFps=new QAction(QPixmap(SD_I_SET_FPS),SD_M_SET_FPS,this);
		mn_sprite->addAction(ms_setFps);
		connect(ms_setFps,SIGNAL(triggered()),this,SLOT(onSetFps()));
	}


	mn_widget=m_menuBar->addMenu(SD_M_WIDGET);
	{
		ms_toolBar=new QAction(QPixmap(SD_I_TOOL_BAR),SD_M_TOOL_BAR,this);
		mn_widget->addAction(ms_toolBar);
		connect(ms_toolBar,SIGNAL(triggered()),this,SLOT(onShowToolBar()));
        ms_toolBar->setCheckable(true);

		ms_resourceWidget=new QAction(QPixmap(SD_I_RESOURCE_WIDGET),SD_M_RESOURCE_WIDGET,this);
		mn_widget->addAction(ms_resourceWidget);
		connect(ms_resourceWidget,SIGNAL(triggered()),this,SLOT(onShowResourceWidget()));
        ms_resourceWidget->setCheckable(true);


		ms_animationEditWidget=new QAction(QPixmap(SD_I_ANIMATION_EDIT_WIDGET),SD_M_ANIMATION_EDIT_WIDGET,this);
		mn_widget->addAction(ms_animationEditWidget);
        connect(ms_animationEditWidget,SIGNAL(triggered()),this,SLOT(onShowAnimationEditWidget()));
        ms_animationEditWidget->setCheckable(true);


        ms_propertyEditWidget=new QAction(QPixmap(SD_I_PROPERTY_EDIT_WIDGET),SD_M_PROPERTY_EDIT_WIDGET,this);
        mn_widget->addAction(ms_propertyEditWidget);
        connect(ms_propertyEditWidget,SIGNAL(triggered()),this,SLOT(onShowPropertyEditWidget()));
        ms_propertyEditWidget->setCheckable(true);

	}

    mn_setting=m_menuBar->addMenu(SD_M_SETTING);
	{
        ms_projectSetting=new QAction(QPixmap(SD_I_PROJECT_SETTING),SD_M_PROJECT_SETTING,this);
		mn_setting->addAction(ms_projectSetting);
		connect(ms_projectSetting,SIGNAL(triggered()),this,SLOT(onProjectSetting()));
	}


	mn_about=m_menuBar->addMenu(SD_M_ABOUT);
	{
        ms_aboutAuthor=new QAction(QPixmap(SD_I_ABOUT_AUTHOR),SD_M_ABOUT_AUTHOR,this);
		mn_about->addAction(ms_aboutAuthor);
        connect(ms_aboutAuthor,SIGNAL(triggered()),this,SLOT(onAboutAuthor()));


		ms_onlineTutorial=new QAction(QPixmap(SD_I_ONLINE_TUTORIAL),SD_M_ONLINE_TUTORIAL,this);
		mn_about->addAction(ms_onlineTutorial);
		connect(ms_onlineTutorial,SIGNAL(triggered()),this,SLOT(onOnlineTutorial()));
	}


}






/* slot */



void SdMainWindow::onUndo()
{
	if(SdOperator::data()->canUndo())
    {
        qDebug("undo");
		SdOperator::data()->undo();
	}

}

void SdMainWindow::onRedo()
{
	if(SdOperator::data()->canRedo())
    {
        qDebug("redo");
		SdOperator::data()->redo();
	}
}














