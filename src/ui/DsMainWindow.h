#ifndef _DS_MAIN_WINDOW_H_
#define _DS_MAIN_WINDOW_H_

#include <QString>
#include <QMainWindow>
#include <QDockWidget>
#include <QToolBar>
#include <vector>

class DsResourceWidget;
class DsViewWidget;


class DsMainWindow:public QMainWindow
{
	Q_OBJECT
	public:
		static DsMainWindow* create();

	public slots:
		/* menu bar */
		/* file */
		void onNewProject(){};
		void onOpenProject(){};
		void onSaveProject(){};
		void onExportSprite(){};
		void onCloseProject(){};
		void onExit(){};

		/* --edit-- */
        void onRenameSprite(){};
        void onRenameAnimation(){};
		void onUndo(){};
		void onRedo(){};

		void onMoveUp(){};
		void onMoveDown(){};
		void onMoveFront(){};
		void onMoveEnd(){};

		void onZoomIn(){};
		void onZoomOut(){};
		void onActualSize(){};

		/* --sprite--*/
		void onNewSprite(){};
		void onNewAnimation(){};
		void onInsertKeyFrame(){};
		void onInsertEmptyFrame(){};
		void onRemoveKeyFrame(){};
		void onCreateTween(){};
		void onRemoveTween(){};
		void onSetAnimationFps(){};

		/* -- view --*/
		void onShowGrid(){};
		void onShowCoordnate(){};


		/* -- help --*/
		void onAboutUs(){};
		void onHelp(){};

	protected:
		DsMainWindow(QWidget* parent=0);
		~DsMainWindow();

	protected:
        void init();
        void layout();
		void destory();

		void createMenuBar();
		void createToolBar();

		void configureMenu();

	private:
		QToolBar* m_toolBar;
		QMenuBar* m_menuBar;
		QStatusBar* m_statusBar;

        QDockWidget* m_resourceDockWidget;
        DsResourceWidget* m_resourceWidget;
		DsViewWidget* m_viewWidget;





	private: /* menu bar */

		/* menu file */
		QMenu* mn_file;
		QAction* ms_newProject;
		QAction* ms_openProject;
		QAction* ms_saveProject;
		QAction* ms_exportSprite;
		QAction* ms_closeProject;
		QAction* ms_exit;

		/* menu edit */
		QMenu* mn_edit;

		QAction* ms_renameSprite;
		QAction* ms_renameAnimation;
		QAction* ms_undo;
		QAction* ms_redo;

		QAction* ms_moveUp;
		QAction* ms_moveDown;
		QAction* ms_moveFront;
		QAction* ms_moveTail;



		/* menu sprite */
		QMenu* mn_sprite;
		QAction* ms_newSprite;
		QAction* ms_newAnimation;
		QAction* ms_insertKeyFrame;
		QAction* ms_insertEmptyFrame;
		QAction* ms_createTween;
		QAction* ms_removeTween;
		QAction* ms_setAnimationFps;

		/* menu view */
		QMenu* mn_view;
		QAction* ms_showGrid;
		QAction* ms_showCoordnate;

		QAction* ms_zoomIn;
		QAction* ms_zoomOut;
        QAction* ms_actualSize;


		/* menu help */
        QMenu* mn_help;
		QAction* ms_aboutus;
        QAction* ms_help;

};

#endif /*_DS_MAIN_WINDOW_H_*/
