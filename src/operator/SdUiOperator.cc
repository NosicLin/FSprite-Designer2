#include <assert.h>
#include <QMessageBox>
#include "widget/SdInputDialog.h"
#include "operator/SdUiOperator.h"
#include "operator/SdOperator.h"
#include "operator/SdDataOperator.h"
#include "core/SdProject.h"
#include "core/SdSprite.h"
#include "core/SdAnimation.h"
#include "SdGlobal.h"


SdUiOperator::SdUiOperator()
{

}
SdUiOperator::~SdUiOperator()
{

}


void SdUiOperator::renameSprite()
{
    SdSprite* sprite=SdOperator::data()->getCurSprite();

	assert(sprite);
	renameSprite(sprite);
}

void SdUiOperator::renameSprite(SdSprite* sprite)
{
	SdInputDialog dialog("Rename Sprite",sprite->getName().c_str());
    if(dialog.exec()==QDialog::Accepted)
	{
		std::string name=dialog.getTextField();
		if(name=="")
		{
			QMessageBox msg(QMessageBox::Warning, "Rename Sprite","Name Can't Be Empty String");
			msg.exec();

		}
		else 
		{
			if(sprite->getName()==name)
			{
				return;
			}

			SdProject* proj=sprite->getProject();

			if(proj->hasSpriteWithName(name.c_str()))
			{
				QMessageBox msg(QMessageBox::Warning,"Rename Sprite","Name Already Used");
				msg.exec();
			}
			else 
			{
				SdOperator::data()->setSpriteName(sprite,name.c_str());
			}
		}
	} 
}

void SdUiOperator::addSprite()
{
    SdProject* proj=SdOperator::data()->getCurProject();
	assert(proj);

    char buf[1024];
	int i=0;

	while(true)
	{
		sprintf(buf,"untitled-sprite-%d",i);
		if(proj->hasSpriteWithName(buf))
		{
			i++;
			continue;
		}
		break;
	}
	SdInputDialog dialog("New Sprite",buf);

	if(dialog.exec()==QDialog::Accepted)
	{
		std::string name=dialog.getTextField();
		if(name=="")
		{
			QMessageBox msg(QMessageBox::Warning, "New Sprite","Name Can't Empty String");
			msg.exec();
		}
		else 
		{
			if(proj->hasSpriteWithName(name.c_str()))
			{
				QMessageBox msg(QMessageBox::Warning,"New Sprite",QString("Sprite With Name(")+QString(name.c_str())+QString(") Already Exist"));
				msg.exec();
			}
			else 
			{
				SdSprite* sprite=new SdSprite;
				sprite->setName(name.c_str());
				SdOperator::data()->addSprite(proj,sprite);
			}
		}
	}
}

void SdUiOperator::deleteSprite()
{
    SdSprite* sprite=SdOperator::data()->getCurSprite();
    SdProject* proj=sprite->getProject();
	assert(sprite);
    deleteSprite(proj,sprite);
}

void SdUiOperator::deleteSprite(SdProject* proj,SdSprite* sprite)
{
    std::string name=sprite->getName();
    QMessageBox msg( QMessageBox::Question,"Delete Sprite",QString("Are You Sure To Delete Sprite (")+QString(name.c_str())+QString(")"),QMessageBox::Ok|QMessageBox::Cancel); 

	if(msg.exec()==QMessageBox::Ok)
	{
		SdOperator::data()->removeSprite(proj,sprite);
	}
}


void SdUiOperator::renameAnimation()
{
	SdAnimation* anim=SdOperator::data()->getCurAnimation();
	assert(anim);
	renameAnimation(anim);
}

void SdUiOperator::renameAnimation(SdAnimation* anim)
{
	SdProject* proj=SdOperator::data()->getCurProject();
	assert(proj);


	SdInputDialog dialog("Rename Animation",anim->getName().c_str());
	if(dialog.exec()==QDialog::Accepted)
	{
		std::string name = dialog.getTextField();
		if(name=="")
		{
			QMessageBox msg(QMessageBox::Warning,"Rename Animation","Name Can't Be Empty String");
			msg.exec();
		}
		else 
		{
			if(anim->getName()==name)
			{
				return;
			}
			SdSprite* sprite=anim->getSprite();
			if(sprite->hasAnimationWithName(name.c_str()))
			{
				QMessageBox msg(QMessageBox::Warning,"Rename Animation","Name Already Used");
				msg.exec();

			}
			else 
			{
				SdOperator::data()->setAnimationName(anim,name.c_str());
			}

		}

	}
}



void SdUiOperator::addAnimation()
{
	SdSprite* sprite=SdOperator::data()->getCurSprite();
	assert(sprite);
	char buf[1024];
	int i=0;
	while(true)
	{
		sprintf(buf,"untitled-anim-%d",i);
		if(sprite->hasAnimationWithName(buf))
		{
			i++;
			continue;
		}
		break;
	}
    SdInputDialog dialog("New Animation",buf);

    if(dialog.exec()==QDialog::Accepted)
	{
		std::string name=dialog.getTextField();
		if(name=="")
		{
			QMessageBox msg(QMessageBox::Warning,"New Animation","Name Can't Empty String");
			msg.exec();
		}
		else 
		{
            if(sprite->hasAnimationWithName(name.c_str()))
			{
				QMessageBox msg(QMessageBox::Warning,"New Animation",QString("Animation With Name(")+QString(name.c_str())+QString(") Already Exist"));
				msg.exec();
			}
			else 
			{
				SdAnimation* anim=new SdAnimation;
				anim->setName(name.c_str());
				SdOperator::data()->addAnimation(sprite,anim);
			}
		}
	}
}


void SdUiOperator::deleteAnimation()
{
    SdSprite* sprite=SdOperator::data()->getCurSprite();
    SdAnimation* anim=SdOperator::data()->getCurAnimation();
	deleteAnimation(sprite,anim);

}

void SdUiOperator::deleteAnimation(SdSprite* sprite,SdAnimation* anim)
{
	std::string name=anim->getName();

    QMessageBox msg(QMessageBox::Question,"Delete Animation",QString("Are You Sure To Delete Animation (")+QString(name.c_str())+QString(")"),QMessageBox::Ok|QMessageBox::Cancel);

	if(msg.exec()==QMessageBox::Ok)
	{
		SdOperator::data()->removeAnimation(sprite,anim);
	}

}




























