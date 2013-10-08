#include "command/SdAnimationAttrChangeCommand.h"

#include "SdGlobal.h"
#include "SdMsgCenter.h"

SdAnimationAttrChangeCommand::SdAnimationAttrChangeCommand(SdAnimation* anim,const SdAnimationAttribute& attr_old,const SdAnimationAttribute& attr_new)
{
	m_anim=anim;
	m_old=attr_old;
	m_new=attr_new;
}

void SdAnimationAttrChangeCommand::redo()
{
	m_anim->setAttribute(m_new);
}
void SdAnimationAttrChangeCommand::undo()
{
	m_anim->setAttribute(m_old);
}

void SdAnimationAttrChangeCommand::emitRedoSignal()
{
	SdGlobal::getMsgCenter()->emitAnimationAttributeChange(m_anim);
}
void SdAnimationAttrChangeCommand::emitUndoSignal()
{
	SdGlobal::getMsgCenter()->emitAnimationAttributeChange(m_anim);
}




