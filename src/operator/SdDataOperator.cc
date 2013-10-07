#include "operator/SdDataOperator.h"
#include "core/SdProject.h"
#include "SdGlobal.h"


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
	/* emit signal */
}

/* cur sprite */
SdSprite* SdDataOperator::getCurSprite()
{
	return SdGlobal::getCurSprite();
}

void SdDataOperator::setCurSprite(SdSprite* sprite)
{
	SdGlobal::setCurSprite(sprite);
}


/* cur animation */
SdAnimation* SdDataOperator::getCurAnimation()
{
	return SdGlobal::getCurAnimation();
}


void SdDataOperator::setCurAnimation(SdAnimation* anim)
{
	SdGlobal::setCurAnimation(anim);
}



