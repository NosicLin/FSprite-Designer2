#include "command/SdSpriteAddCommand.h"
#include "SdGlobal.h"
#include "SdMsgCenter.h"
#include "core/SdProject.h"
#include "core/SdSprite.h"


SdSpriteAddCommand::SdSpriteAddCommand(SdProject* proj,SdSprite* sprite,int pos)
{
	m_proj=proj;
	m_sprite=sprite;
	m_pos=pos;
}

void SdSpriteAddCommand::redo()
{
	m_proj->addSprite(m_pos,m_sprite);
	m_proj->setCurSprite(m_sprite);
}

void SdSpriteAddCommand::undo()
{
	m_proj->removeSprite(m_sprite);

	if(m_proj->getCurSprite()==m_sprite)
	{
		m_proj->setCurSprite(NULL);
	}
}


void SdSpriteAddCommand::emitRedoSignal()
{
	SdGlobal::getMsgCenter()->emitSpriteAdd(m_proj,m_sprite);
	SdGlobal::getMsgCenter()->emitCurSpriteChange();

}


void SdSpriteAddCommand::emitUndoSignal()
{
	SdGlobal::getMsgCenter()->emitSpriteRemove(m_proj,m_sprite);
	SdGlobal::getMsgCenter()->emitCurSpriteChange();
}


void SdSpriteAddCommand::forwardDiscard()
{
	delete m_sprite;
}








