#include "SdMsgCenter.h"


SdMsgCenter::SdMsgCenter()
{
}

SdMsgCenter::~SdMsgCenter()
{
}


/* project */
void SdMsgCenter::emitCurProjectChange()
{
	emit signalCurProjectChange();
}

/* sprite */

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



/* animation */

void SdMsgCenter::emitCurAnimationChange()
{
	emit signalCurAnimationChange();
}
void SdMsgCenter::emitAnimationAdd(SdSprite* sprite,SdAnimation* anim)
{
	emit signalAnimationAdd(sprite,anim);
}
void SdMsgCenter::emitAnimationRemove(SdSprite* sprite,SdAnimation* anim)
{
	emit signalAnimationRemove(sprite,anim);
}


void SdMsgCenter::emitAnimationAttributeChange(SdAnimation* anim)
{
	emit  signalAnimationAttributeChange(anim);
}













