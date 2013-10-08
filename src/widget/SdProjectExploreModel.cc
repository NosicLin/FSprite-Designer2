#include <assert.h>

#include "widget/SdProjectExploreModel.h"
#include "core/SdProject.h"
#include "core/SdSprite.h"
#include "core/SdAnimation.h"
#include "operator/SdOperator.h"
#include "operator/SdDataOperator.h"

SdProjectExploreModel::SdProjectExploreModel()
{
}

SdProjectExploreModel::~SdProjectExploreModel()
{
}


QModelIndex SdProjectExploreModel::index(int row,
		int column,const QModelIndex& parent) const 
{
    SdProject* proj=SdOperator::data()->getCurProject();
	if(!proj)
	{
		return QModelIndex(); 
	}

	if(!parent.isValid())
	{
		return createIndex(row,column,proj);
	}

	SdIdentify* idfier=(SdIdentify*) parent.internalPointer();
    switch(idfier->getClassType())
	{
		case SD_CLASS_PROJECT:
			{
				int sprite_nu=((SdProject*)idfier)->getSpriteNu();
				if(row>=sprite_nu)
				{
					qDebug("sprite nu is %d,row=%d",sprite_nu,row);
					return QModelIndex();
				}

				SdSprite* sprite=((SdProject*)idfier)->getSprite(row);
				return createIndex(row,column,sprite);
			}
		case SD_CLASS_SPRITE:
			{
				int anim_nu=((SdSprite*)idfier)->getAnimationNu();
				if(row>=anim_nu)
				{
					qDebug("animation nu is %d,row=%d",anim_nu,row);
					return QModelIndex();
				}
				SdAnimation* anim=((SdSprite*)idfier)->getAnimation(row);
				return createIndex(row,column,anim);
			}
		default:
			assert(0);
	}
	return QModelIndex();

}

QModelIndex SdProjectExploreModel::parent(const QModelIndex& child) const 
{
	if(!child.isValid())
	{
		return QModelIndex();
	}
	SdIdentify* idfier=(SdIdentify*)child.internalPointer();

	switch(idfier->getClassType())
	{
		case SD_CLASS_PROJECT:
			{
				return QModelIndex();
			}
		case SD_CLASS_SPRITE:
			{
				SdProject* proj=((SdSprite*)idfier)->getProject();
				return createIndex(0,0,proj);
			}
		case SD_CLASS_ANIMATION:
			{
				SdAnimation* anim=(SdAnimation*)idfier;
				SdSprite* sprite=anim->getSprite();
				SdProject* proj=sprite->getProject();
				return createIndex(proj->spritePos(sprite),0,sprite);
			}
		default:
			assert(0);
	}
	return QModelIndex();
}

int SdProjectExploreModel::rowCount(const QModelIndex& parent)const 
{
	if(parent.column()>0)
	{
		return 0;
	}
	if(!parent.isValid())
	{
		return 1;
	}

	SdIdentify* idfier=(SdIdentify*)parent.internalPointer();
	switch(idfier->getClassType())
	{
		case SD_CLASS_PROJECT:
			{
				SdProject* proj=(SdProject*)idfier;
				return proj->getSpriteNu();
			}
		case SD_CLASS_SPRITE:
			{
				SdSprite* sprite=(SdSprite*) idfier;
				return sprite->getAnimationNu();
			}
	}
	return 0;
}

int SdProjectExploreModel::columnCount(const QModelIndex& /*parent*/)const
{
	return 1;
}


QVariant SdProjectExploreModel::data(const QModelIndex& index,int role)const 
{
	if(!index.isValid())
	{
		return QVariant();
	}

	SdIdentify* idfier=(SdIdentify*)index.internalPointer();
	switch(role)
	{
		case Qt::DisplayRole:
			{

				switch(idfier->getClassType())
				{
					case SD_CLASS_PROJECT:
						{
							return QString(((SdProject*)idfier)->getName().c_str());
						}
					case SD_CLASS_SPRITE:
						{
							return QString(((SdSprite*)idfier)->getName().c_str());
						}
					case SD_CLASS_ANIMATION:
						{
							return QString(((SdAnimation*)idfier)->getName().c_str());
						}
					default:
						assert(0);
				}
			}
	}
	return QVariant();
}




void SdProjectExploreModel::refresh()
{
	emit layoutChanged();
}












