#include "SdMsgCenter.h"


SdMsgCenter::SdMsgCenter()
{
}

SdMsgCenter::~SdMsgCenter()
{
}



void SdMsgCenter::emitSpriteAttributeChange(SdSprite* sprite)
{
	emit signalSpriteAttributeChange(sprite);
}

void SdMsgCenter::emitCurSpriteChange()
{
	emit signalCurSpriteChange();
}

void SdMsgCenter::emitSpriteAdd(SdProject* proj,SdSprite* sprite)
{
	emit signalSpriteAdd(proj,sprite);
}

void SdMsgCenter::emitSpriteRemove(SdProject* proj,SdSprite* sprite)
{
	emit signalSpriteRemove(proj,sprite);
}



