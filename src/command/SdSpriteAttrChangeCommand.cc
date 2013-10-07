#include "command/SdSpriteAttrChangeCommand.h"
#include "SdGlobal.h"
#include "SdMsgCenter.h"

SdSpriteAttrChangeCommand::SdSpriteAttrChangeCommand(SdSprite* sprite,
        const SdSpriteAttribute& o,
        const SdSpriteAttribute& n)
{
	m_old=o;
	m_new=n;
	m_sprite=sprite;
}

SdSpriteAttrChangeCommand::~SdSpriteAttrChangeCommand()
{

}

void SdSpriteAttrChangeCommand::redo()
{
	m_sprite->setAttribute(m_new);
}

void SdSpriteAttrChangeCommand::undo()
{
	m_sprite->setAttribute(m_old);
}


void SdSpriteAttrChangeCommand::emitRedoSignal()
{
    SdGlobal::getMsgCenter()->emitSpriteAttributeChange(m_sprite);
}

void SdSpriteAttrChangeCommand::emitUndoSignal()
{
    SdGlobal::getMsgCenter()->emitSpriteAttributeChange(m_sprite);
}


