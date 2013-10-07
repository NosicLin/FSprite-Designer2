#include "core/SdAnimation.h"



SdAnimation::SdAnimation()
{
}

SdAnimation::~SdAnimation()
{
}


int SdAnimation::getClassType()
{
	return SD_CLASS_ANIMATION;
}

const char* SdAnimation::className()
{
	return "SdAnimation";
}

void SdAnimation::setName(const char* name)
{
	m_name=std::string(name);
}

std::string SdAnimation::getName()
{
	return m_name;
}

SdSprite* SdAnimation::getSprite()
{
	return m_sprite;
}

void SdAnimation::setSprite(SdSprite* sprite)
{
	m_sprite=sprite;
}



void SdAnimation::addBone(SdBone* /*bone*/)
{
	/*TODO*/
}

void SdAnimation::removeBone(SdBone* /*bone*/)
{
	/*TODO*/
}





