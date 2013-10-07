#include <assert.h>
#include <QMessageBox>
#include "widget/SdInputDialog.h"
#include "operator/SdUiOperator.h"
#include "operator/SdOperator.h"
#include "operator/SdDataOperator.h"
#include "core/SdProject.h"
#include "core/SdSprite.h"
#include "core/SdSprite.h"
#include "SdGlobal.h"


SdUiOperator::SdUiOperator()
{

}
SdUiOperator::~SdUiOperator()
{

}

void SdUiOperator::renameProject(SdProject* /*proj*/)
{
}

void SdUiOperator::renameAnimation(SdAnimation* /*anim*/)
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
			QMessageBox msg(QMessageBox::Warning, "Rename Sprite","Name Can't Empty String");
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
    QMessageBox msg( QMessageBox::Question,"Delete Sprite",QString("Are You Sure To Delete Sprite ")+QString(name.c_str()),QMessageBox::Ok|QMessageBox::Cancel);

	if(msg.exec()==QMessageBox::Ok)
	{
		SdOperator::data()->removeSprite(proj,sprite);
	}
}
















