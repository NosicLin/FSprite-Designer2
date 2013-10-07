#ifndef _SD_MAIN_WINDOW_H_
#define _SD_MAIN_WINDOW_H_

#include <QString>
#include <QMainWindow>
#include <QDockWidget>
#include <QToolBar>

class SdViewEditWidget;
class SdProjectExploreWidget;

class SdMainWindow :public QMainWindow
{
	Q_OBJECT 
	public:
		static SdMainWindow* create();

    public:
        SdMainWindow();
        ~SdMainWindow();

    public:
        void initWidget();
        void initMenuBar();

    public slots:
		/* ----- file ---- */
        void onOpenProject(){};
        void onCreatePoject(){};
        void onSaveProject(){};
        void onSaveProjectAs(){};
        void onCloseProject(){};

        void onExportFst(){};
        void onExportFsk(){};
        void onExportAll(){};
        void onQuit(){};

		/* ---- Edit ----- */
		void onUndo();
		void onRedo();
        void onCopy(){};
        void onPaste(){};
        void onCut(){};
        void onDelete(){};


		/* ---- view ---- */
        void onZoomIn(){};
        void onZoomOut(){};
        void onResetView(){};

        void onSetBackgroundColor(){};
        void onShowGrid(){};
        void onShowCoordnate(){};
        void onShowBone(){};
        void onShowBoneText(){};
        void onShowImage(){};


		/* ---- sprite ---- */
        void onNewSprite(){};
        void onRenameSprite(){};
        void onDeleteSprite(){};

        void onNewAnimation(){};
        void onRenameAnimation(){};
        void onDeleteAnimation(){};

        void onInsertKeyFrame(){};
        void onDeleteKeyFrame(){};
        void onSetFps(){};

        void onNewBone(){};
        void onRenameBone(){};
        void onDeleteBone(){};


		/* --- widget --- */
        void onShowWidget(){};
        void onShowToolBar(){};
        void onShowResourceWidget(){};
        void onShowAnimationEditWidget(){};
        void onShowPropertyEditWidget(){};

		/* --- setting --- */
        void onProjectSetting(){};


		/* ---- about ----*/
        void onAboutAuthor(){};
        void onOnlineTutorial(){};



    private:
        SdViewEditWidget* m_viewEditWidget;

		QDockWidget* m_projectExploreDockWidget;
		SdProjectExploreWidget* m_projectExploreWidget;

        /* menu filed */
	private:
		QMenuBar* m_menuBar;

		/* file */ 
		QMenu* mn_file;
		QAction* ms_openProject;
		QAction* ms_createProject;
		QAction* ms_saveProject;
		QAction* ms_closeProject;
		QAction* ms_exportFst;
		QAction* ms_exportFsk;
		QAction* ms_exportAll;
		QAction* ms_quit;

		/* edit */
		QMenu* mn_edit;
		QAction* ms_undo;
		QAction* ms_redo;
		QAction* ms_copy;
		QAction* ms_paste;
		QAction* ms_cut;
		QAction* ms_delete;

		/* view */
		QMenu* mn_view;
		QAction* ms_zoomIn;
		QAction* ms_zoomOut;
		QAction* ms_resetView;
		QAction* ms_setBackgroundColor;
		QAction* ms_showGrid;
		QAction* ms_showCoordnate;
		QAction* ms_showBone;
		QAction* ms_showBoneText;
		QAction* ms_showImage;


		/* Sprite */
		QMenu* mn_sprite;
		QAction* ms_newSprite;
		QAction* ms_renameSprite;
		QAction* ms_deleteSprite;
		QAction* ms_newAnimation;
		QAction* ms_renameAnimation;
		QAction* ms_deleteAnimation;
		QAction* ms_insertKeyFrame;
		QAction* ms_deleteKeyFrame;
		QAction* ms_setFps;
		QAction* ms_newBone;
		QAction* ms_renameBone;
		QAction* ms_deleteBone;

		/* widget */
		QMenu* mn_widget;
		QAction* ms_toolBar;
		QAction* ms_resourceWidget;
		QAction* ms_animationEditWidget;
		QAction* ms_propertyEditWidget;


		/* setting */
		QMenu* mn_setting;
		QAction* ms_projectSetting;


		/* about */
		QMenu* mn_about;
		QAction* ms_aboutAuthor;
		QAction* ms_onlineTutorial;
};
#endif /*_SD_MAIN_WINDOW_H_*/



























