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
			QMessageBox msg(QMessageBox::Warning, "Rename Project","Name Can't Empty String");
			msg.exec();

		}
		else 
		{
			/*TODO*/
			sprite->setName(name.c_str());
		}
	} 

}







