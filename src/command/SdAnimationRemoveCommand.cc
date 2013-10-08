#include "command/SdAnimationRemoveCommand.h"

#include "SdGlobal.h"
#include "SdMsgCenter.h"
#include "core/SdProject.h"
#include "core/SdSprite.h"


SdAnimationRemoveCommand::SdAnimationRemoveCommand(SdSprite* sprite,SdAnimation* anim)
{
	m_pos=sprite->animationPos(anim);
	m_sprite=sprite;
	m_anim=anim;
}


void SdAnimationRemoveCommand::redo()
{
	m_sprite->removeAnimation(m_anim);
	if(m_sprite->getCurAnimation()==m_anim)
	{
		m_sprite->setCurAnimation(NULL);
	}

}

void SdAnimationRemoveCommand::undo()
{
	m_sprite->addAnimation(m_pos,m_anim);
	m_sprite->setCurAnimation(m_anim);
}

void SdAnimationRemoveCommand::emitRedoSignal()
{
	SdGlobal::getMsgCenter()->emitAnimationRemove(m_sprite,m_anim);
	SdGlobal::getMsgCenter()->emitCurAnimationChange();
}
void SdAnimationRemoveCommand::emitUndoSignal()
{
	SdGlobal::getMsgCenter()->emitAnimationAdd(m_sprite,m_anim);
	SdGlobal::getMsgCenter()->emitCurAnimationChange();
}

void SdAnimationRemoveCommand::backDiscard()
{
	delete m_anim;
}


