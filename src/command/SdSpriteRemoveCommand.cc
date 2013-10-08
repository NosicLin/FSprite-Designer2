#include "command/SdSpriteRemoveCommand.h"
#include "SdGlobal.h"
#include "SdMsgCenter.h"
#include "core/SdProject.h"
#include "core/SdSprite.h"


SdSpriteRemoveCommand::SdSpriteRemoveCommand(SdProject* proj,SdSprite* sprite)
{
	m_proj=proj;
	m_sprite=sprite;
    m_pos=m_proj->spritePos(m_sprite);
}

void SdSpriteRemoveCommand::redo()
{
    m_proj->removeSprite(m_sprite);
	if(m_proj->getCurSprite()==m_sprite)
	{
		m_proj->setCurSprite(NULL);
	}
}

void SdSpriteRemoveCommand::undo()
{
	m_proj->addSprite(m_pos,m_sprite);
	m_proj->setCurSprite(m_sprite);
}

void SdSpriteRemoveCommand::emitRedoSignal()
{
	SdGlobal::getMsgCenter()->emitSpriteRemove(m_proj,m_sprite);
	SdGlobal::getMsgCenter()->emitCurSpriteChange();
}

void SdSpriteRemoveCommand::emitUndoSignal()
{
	SdGlobal::getMsgCenter()->emitSpriteAdd(m_proj,m_sprite);
	SdGlobal::getMsgCenter()->emitCurSpriteChange();
}


void SdSpriteRemoveCommand::backDiscard()
{
	delete m_sprite;
}
