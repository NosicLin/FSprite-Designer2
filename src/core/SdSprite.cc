#include <assert.h>
#include "core/SdSprite.h"
#include "core/SdAnimation.h"


SdSprite* SdSprite::create()
{
	return new SdSprite();
}



SdSprite::SdSprite()
{
	m_project=NULL;
}

SdSprite::~SdSprite()
{

}

int SdSprite::getClassType()
{
	return SD_CLASS_SPRITE;
}

const char* SdSprite::className()
{
	return "SdSprite";
}



void SdSprite::setName(const char* name)
{
	m_name=std::string(name);
}

std::string SdSprite::getName()
{
	return m_name;
}


SdProject* SdSprite::getProject()
{
	return m_project;
}


void SdSprite::setProject(SdProject* proj)
{
	m_project=proj;
}

void SdSprite::addAnimation(SdAnimation* anim)
{
	m_animations.push_back(anim);
	anim->setSprite(this);
}


SdAnimation* SdSprite::getAnimation(const char* name)
{
	int size=m_animations.size();
	std::string s_name(name);

	for(int i=0;i<size;i++)
	{
		if(m_animations[i]->getName()==s_name)
		{
			return m_animations[i];
		}
	}
	return NULL;
}


SdAnimation* SdSprite::getAnimation(int index)
{
    return m_animations[index];
}

int SdSprite::getAnimationNu()
{
	return m_animations.size();
}


int SdSprite::animationPos(SdAnimation* anim)
{
	int size=m_animations.size();

	for(int i=0;i<size;i++)
	{
		if(m_animations[i] == anim)
		{
			return i;
		}
	}
	assert(0);
	return -1;
}


void SdSprite::removeAnimation(SdAnimation* anim)
{
	std::vector<SdAnimation*>::iterator iter;
	for(iter=m_animations.begin();iter!=m_animations.end();++iter)
	{
		if(*iter==anim)
		{
            m_animations.erase(iter);
			return ;
		}

	}
	assert(0);
}


void SdSprite::removeAnimation(int index)
{
	delete m_animations[index];
	m_animations.erase(m_animations.begin()+index);
}


















































