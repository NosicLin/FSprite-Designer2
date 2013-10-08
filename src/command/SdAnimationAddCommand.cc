#include "command/SdAnimationAddCommand.h"

#include "core/SdSprite.h"
#include "core/SdAnimation.h"
#include "SdMsgCenter.h"
#include "SdGlobal.h"

SdAnimationAddCommand::SdAnimationAddCommand(SdSprite* sprite,SdAnimation* anim,int pos)
{
	m_sprite=sprite;
	m_anim=anim;
	m_pos=pos;
}


void SdAnimationAddCommand::redo()
{
    m_sprite->addAnimation(m_pos,m_anim);
    m_sprite->setCurAnimation(m_anim);
}

void SdAnimationAddCommand::undo()
{
	m_sprite->removeAnimation(m_anim);
	if(m_sprite->getCurAnimation()==m_anim)
	{
		m_sprite->setCurAnimation(NULL);
	}
}

void SdAnimationAddCommand::emitRedoSignal()
{
	SdGlobal::getMsgCenter()->emitAnimationAdd(m_sprite,m_anim);
	SdGlobal::getMsgCenter()->emitCurAnimationChange();

}
void SdAnimationAddCommand::emitUndoSignal()
{
	SdGlobal::getMsgCenter()->emitAnimationRemove(m_sprite,m_anim);
	SdGlobal::getMsgCenter()->emitCurAnimationChange();
}

void SdAnimationAddCommand::forwardDiscard()
{
	delete m_anim;
}

