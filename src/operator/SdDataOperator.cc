#include <assert.h>
#include "operator/SdDataOperator.h"
#include "core/SdProject.h"
#include "core/SdSprite.h"
#include "core/SdAnimation.h"
#include "SdGlobal.h"
#include "SdMsgCenter.h"
#include "command/SdCommand.h"
#include "command/SdSpriteAttrChangeCommand.h"
#include "command/SdSpriteAddCommand.h"
#include "command/SdSpriteRemoveCommand.h"
#include "command/SdAnimationAttrChangeCommand.h"
#include "command/SdAnimationAddCommand.h"
#include "command/SdAnimationRemoveCommand.h"



SdDataOperator::SdDataOperator()
{
}


SdDataOperator::~SdDataOperator()
{

}

SdProject* SdDataOperator::getCurProject()
{
	return SdGlobal::getCurProject();
}

void SdDataOperator::setCurProject(SdProject* proj)
{
	SdGlobal::setCurProject(proj);
    SdGlobal::getMsgCenter()->emitCurProjectChange();
}

/* cur sprite */
SdSprite* SdDataOperator::getCurSprite()
{
	return SdGlobal::getCurSprite();
}

void SdDataOperator::setCurSprite(SdSprite* sprite)
{
	SdGlobal::setCurSprite(sprite);
	SdGlobal::getMsgCenter()->emitCurSpriteChange();
}


void SdDataOperator::addSprite(SdProject* proj,SdSprite* sprite)
{
	addSprite(proj,sprite,proj->getSpriteNu());
}


void SdDataOperator::addSprite(SdProject* proj,SdSprite* sprite,int pos)
{
	SdSpriteAddCommand* cmd=new SdSpriteAddCommand(proj,sprite,pos);
	proj->pushCommand(cmd);
	cmd->redo();
	cmd->emitRedoSignal();
}

void SdDataOperator::removeSprite(SdProject* proj,SdSprite* sprite)
{
    SdSpriteRemoveCommand* cmd=new SdSpriteRemoveCommand(proj,sprite);
    proj->pushCommand(cmd);
    cmd->redo();
    cmd->emitRedoSignal();
}



void SdDataOperator::setSpriteName(const char* name)
{
    SdSprite* sprite=getCurSprite();
	assert(sprite);
	setSpriteName(sprite,name);
}
void SdDataOperator::setSpriteName(SdSprite* sprite,const char* name)
{

	SdProject* proj=getCurProject();

    SdSpriteAttribute attr_old=sprite->getAttribute();
    SdSpriteAttribute attr_new=sprite->getAttribute();

    attr_new.name=std::string(name);

	SdSpriteAttrChangeCommand* cmd=new SdSpriteAttrChangeCommand(sprite,attr_old,attr_new);

	proj->pushCommand(cmd);
	cmd->redo();
	cmd->emitRedoSignal();
}



/* cur animation */
SdAnimation* SdDataOperator::getCurAnimation()
{
	return SdGlobal::getCurAnimation();
}


void SdDataOperator::setCurAnimation(SdAnimation* anim)
{
	SdSprite* sprite=anim->getSprite();

	if(sprite!=getCurSprite())
	{
		SdGlobal::setCurSprite(sprite);
		SdGlobal::setCurAnimation(anim);
		SdGlobal::getMsgCenter()->emitCurSpriteChange();
		SdGlobal::getMsgCenter()->emitCurAnimationChange();
	}
	else 
	{
		SdGlobal::setCurAnimation(anim);
		SdGlobal::getMsgCenter()->emitCurAnimationChange();
	}
}




void SdDataOperator::setAnimationName(SdAnimation* anim,const char* name)
{
	SdProject* proj=getCurProject();
	SdAnimationAttribute attr_old=anim->getAttribute();
	SdAnimationAttribute attr_new=anim->getAttribute();
	attr_new.name=std::string(name);

	SdAnimationAttrChangeCommand* cmd=new SdAnimationAttrChangeCommand(anim,attr_old,attr_new);
	proj->pushCommand(cmd);
	cmd->redo();
	cmd->emitRedoSignal();
}


void SdDataOperator::addAnimation(SdSprite* sprite,SdAnimation* anim)
{
	int anim_nu=sprite->getAnimationNu();
	addAnimation(sprite,anim,anim_nu);
}

void SdDataOperator::addAnimation(SdSprite* sprite,SdAnimation* anim,int pos)
{
    SdProject* proj=getCurProject();
    SdAnimationAddCommand* cmd=new SdAnimationAddCommand(sprite,anim,pos);
	proj->pushCommand(cmd);
	cmd->redo();
	cmd->emitRedoSignal();
}

void SdDataOperator::removeAnimation(SdSprite* sprite,SdAnimation* anim)
{
	SdProject* proj=getCurProject();
	SdAnimationRemoveCommand* cmd=new SdAnimationRemoveCommand(sprite,anim);
	proj->pushCommand(cmd);
	cmd->redo();
	cmd->emitRedoSignal();
}





/* redo/undo */


bool SdDataOperator::canRedo()
{
	return SdGlobal::canRedo();
}

bool SdDataOperator::canUndo()
{
	return SdGlobal::canUndo();
}

void SdDataOperator::redo()
{
	assert(canRedo());

	SdProject* proj=getCurProject();
	SdCommand* command=proj->redo();
	command->emitRedoSignal();
}

void SdDataOperator::undo()
{
	assert(canUndo());
	SdProject* proj=getCurProject();
	SdCommand* command=proj->undo();
	command->emitUndoSignal();
}




























