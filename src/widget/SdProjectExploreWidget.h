#ifndef _SD_PROJECT_EXPLORE_H_
#define _SD_PROJECT_EXPLORE_H_

#include <QWidget>
#include <QTreeView>

class SdProjectExploreModel;
class SdSprite;
class SdProject;
class SdAnimation;

class SdProjectExploreWidget:public QWidget
{
	Q_OBJECT 
	public:
		SdProjectExploreWidget();
		~SdProjectExploreWidget();


	public slots:
		void mousePress(const QModelIndex& index);

		/* sprite */
		void slotSpriteAttributeChange(SdSprite* sprite);
		void slotSpriteAdd(SdProject* proj,SdSprite* sprite);
		void slotSpriteRemove(SdProject* proj,SdSprite* sprite);

		/* animation */
		void slotAnimationAttributeChange(SdAnimation* anim);
		void slotAnimationAdd(SdSprite* sprite,SdAnimation* anim);
		void slotAnimationRemove(SdSprite* sprite,SdAnimation* anim);


	protected:
		void initWidget();
		void initMenu();
		void destory();
		void connectSignal();

    public:
        QTreeView* m_projectExploreView;
		SdProjectExploreModel* m_projectExploreModel;

		/* pop up menu */

		/*  ---  project ---*/
		QMenu* m_menuProject;
		QAction* ma_newSprite;
		QAction* ma_renameProject;
		QAction* ma_save;
		QAction* ma_exportAllFst;
		QAction* ma_exportAllFsk;
		QAction* ma_close;

		/*  ---- sprite ---- */
		QMenu* m_menuSprite;
		QAction* ma_newAnimation;
		QAction* ma_renameSprite;
		QAction* ma_cloneSprite;

		QAction* ma_exportSpriteFst;
		QAction* ma_exportSpriteFsk;
		QAction* ma_deleteSprite;

		/* --- animation --- */
		QMenu* m_menuAnimation;
        QAction* ma_renameAnimation;
        QAction* ma_cloneAnimation;
		QAction* ma_deleteAnimation;
};

#endif /*_SD_PROJECT_EXPLORE_H_*/


