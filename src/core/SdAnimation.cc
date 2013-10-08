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
	m_attr.name=std::string(name);
}

std::string SdAnimation::getName()
{
	return m_attr.name;
}

SdSprite* SdAnimation::getSprite()
{
	return m_sprite;
}

void SdAnimation::setSprite(SdSprite* sprite)
{
	m_sprite=sprite;
}

void SdAnimation::setAttribute(const SdAnimationAttribute& attr)
{
	m_attr=attr;
}

SdAnimationAttribute SdAnimation::getAttribute()
{
	return m_attr;
}



void SdAnimation::addBone(SdBone* /*bone*/)
{
	/*TODO*/
}

void SdAnimation::removeBone(SdBone* /*bone*/)
{
	/*TODO*/
}





