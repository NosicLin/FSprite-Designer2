#include <assert.h>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include "core/SdProject.h"
#include "core/SdSprite.h"
#include "core/SdSprite.h"
#include "widget/SdProjectExploreWidget.h"
#include "widget/SdProjectExploreModel.h"
#include "operator/SdOperator.h"
#include "operator/SdUiOperator.h"
#include "operator/SdDataOperator.h"
#include "SdGlobal.h"
#include "SdMsgCenter.h"

SdProjectExploreWidget::SdProjectExploreWidget()
{
	m_projectExploreView=NULL;
	m_projectExploreModel=NULL;

	initWidget();
	initMenu();
	connectSignal();
}



SdProjectExploreWidget::~SdProjectExploreWidget()
{
	destory();
}



void SdProjectExploreWidget::initWidget()
{
	m_projectExploreView=new QTreeView(this);
	m_projectExploreView->setHeaderHidden(true);
    m_projectExploreView->setIndentation(12);
	m_projectExploreModel=new SdProjectExploreModel;
	m_projectExploreView->setModel(m_projectExploreModel);

	QVBoxLayout* vlayout=new QVBoxLayout();
	vlayout->addWidget(m_projectExploreView);
	setLayout(vlayout);
}



void SdProjectExploreWidget::initMenu()
{
	/* ---  project  ---- */
	m_menuProject=new QMenu(this);
	ma_newSprite=m_menuProject->addAction("Add Sprite");
	ma_renameProject=m_menuProject->addAction("Rename Project");
    ma_save=m_menuProject->addAction("Save");
	ma_exportAllFst=m_menuProject->addAction("Export All *.fst");
	ma_exportAllFsk=m_menuProject->addAction("Export All *.fsk");
    ma_close=m_menuProject->addAction("close");

	/* --- sprite --- */
	m_menuSprite=new QMenu(this);
	ma_newAnimation=m_menuSprite->addAction("Add Animation");
	ma_renameSprite=m_menuSprite->addAction("Rename Sprite");
	ma_cloneSprite=m_menuSprite->addAction("Clone Sprite");
	ma_exportSpriteFst=m_menuSprite->addAction("Export *.fst");
	ma_exportSpriteFsk=m_menuSprite->addAction("Export *.fsk");
	ma_deleteSprite=m_menuSprite->addAction("Delete Sprite");

	/* -- animaition -- */
	m_menuAnimation=new QMenu(this);
	ma_renameAnimation=m_menuAnimation->addAction("Rename Animation");
	ma_cloneAnimation=m_menuAnimation->addAction("Clone Animation");
	ma_deleteAnimation=m_menuAnimation->addAction("Delete Animation");

}

void SdProjectExploreWidget::connectSignal()
{
	connect(m_projectExploreView,SIGNAL(pressed(const QModelIndex&)),this,SLOT(mousePress(const QModelIndex&)));

	/* project */
	connect(ma_newSprite,SIGNAL(triggered()),SdOperator::ui(),SLOT(addSprite()));

	/* sprite */
	connect(ma_renameSprite,SIGNAL(triggered()),SdOperator::ui(),SLOT(renameSprite()));
	connect(ma_deleteSprite,SIGNAL(triggered()),SdOperator::ui(),SLOT(deleteSprite()));
	connect(ma_newAnimation,SIGNAL(triggered()),SdOperator::ui(),SLOT(addAnimation()));

	/* animaition */
	connect(ma_renameAnimation,SIGNAL(triggered()),SdOperator::ui(),SLOT(renameAnimation()));
	connect(ma_deleteAnimation,SIGNAL(triggered()),SdOperator::ui(),SLOT(deleteAnimation()));







	/* msg sprite */
    connect(SdGlobal::getMsgCenter(),SIGNAL(signalSpriteAttributeChange(SdSprite*)),this,SLOT(slotSpriteAttributeChange(SdSprite* )));

	connect(SdGlobal::getMsgCenter(),SIGNAL(signalSpriteAdd(SdProject*,SdSprite*)),this,SLOT(slotSpriteAdd(SdProject*,SdSprite*)));
	connect(SdGlobal::getMsgCenter(),SIGNAL(signalSpriteRemove(SdProject*,SdSprite*)),this,SLOT(slotSpriteRemove(SdProject*,SdSprite*)));



	/* msg animtion */
	connect(SdGlobal::getMsgCenter(),SIGNAL(signalAnimationAttributeChange(SdAnimation*)),this,SLOT(slotAnimationAttributeChange(SdAnimation*)));

	connect(SdGlobal::getMsgCenter(),SIGNAL(signalAnimationAdd(SdSprite* ,SdAnimation*)),this,SLOT(slotAnimationAdd(SdSprite*,SdAnimation*)));
    connect(SdGlobal::getMsgCenter(),SIGNAL(signalAnimationRemove(SdSprite*,SdAnimation*)),this,SLOT(slotAnimationRemove(SdSprite*,SdAnimation*)));


}



void SdProjectExploreWidget::mousePress(const QModelIndex& index)
{
	if(!index.isValid())
	{
		return ;
	}

	SdIdentify* idfier=(SdIdentify*)index.internalPointer();

	switch(idfier->getClassType())
	{
		case SD_CLASS_SPRITE:
			{
				SdSprite*  sprite= (SdSprite*)idfier;
				SdOperator::data()->setCurSprite(sprite);
				break;
			}

		case SD_CLASS_ANIMATION:
			{
				SdAnimation* anim=(SdAnimation*)idfier;
				SdOperator::data()->setCurAnimation(anim);
				break;
            }
        case SD_CLASS_PROJECT:
            break;

        default:
            assert(0);
	}


	if((QApplication::mouseButtons()&Qt::RightButton))
	{

		switch(idfier->getClassType())
		{
			case SD_CLASS_PROJECT:
				{
					m_menuProject->popup(QCursor::pos());
					break;
				}
			case SD_CLASS_SPRITE:
				{
					m_menuSprite->popup(QCursor::pos());
					break;
				}
			case SD_CLASS_ANIMATION:
				{
					m_menuAnimation->popup(QCursor::pos());
					break;
				}
			default:
				assert(0);
		}
	}

}
void SdProjectExploreWidget::destory()
{
	delete m_projectExploreView;
	m_projectExploreView=NULL;

	delete m_projectExploreModel;
	m_projectExploreModel=NULL;
}



void SdProjectExploreWidget::slotSpriteAttributeChange(SdSprite* /* sprite */)
{
	m_projectExploreModel->refresh();
}

void SdProjectExploreWidget::slotSpriteAdd(SdProject* /*proj*/,SdSprite* /*sprite*/)
{
	m_projectExploreModel->refresh();
}

void SdProjectExploreWidget::slotSpriteRemove(SdProject* /*proj*/,SdSprite* /*sprite*/)
{
	m_projectExploreModel->refresh();
}

void SdProjectExploreWidget::slotAnimationAttributeChange(SdAnimation* /* anim */) 
{
	m_projectExploreModel->refresh();
}


void SdProjectExploreWidget::slotAnimationAdd(SdSprite* /* sprite */,SdAnimation* /* anim */)
{
	m_projectExploreModel->refresh();
}


void SdProjectExploreWidget::slotAnimationRemove(SdSprite* /* sprite */,SdAnimation* /* anim */)
{
	m_projectExploreModel->refresh();
}






















