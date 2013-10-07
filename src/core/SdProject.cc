#include <assert.h>
#include "core/SdProject.h"
#include "core/SdTextureMgr.h"
#include "core/SdSprite.h"



SdProject* SdProject::create(const std::string& dir,const std::string& name )
{
	return new SdProject(dir,name);
}

SdProject::SdProject(const std::string& dir,const std::string& name)
{
	m_curSprite=NULL;
	m_textureMgr=new SdTextureMgr();
	m_textureMgr->setTextureLoadPath(dir.c_str());
	m_projectName=name;
	m_projectDir=dir;
}


SdProject::~SdProject()
{
	if(m_textureMgr)
	{
		delete m_textureMgr;
	}
}

int SdProject::getClassType()
{
	return SD_CLASS_PROJECT;
}

const char* SdProject::className()
{
	return "SdProject";
}


SdSprite* SdProject::getSprite(const char* name)
{
	std::string s_name(name);
	int size=m_sprites.size();
	for(int i=0;i<size;i++)
	{
        if(m_sprites[i]->getName()==s_name)
		{
			return m_sprites[i];
		}
	}
	return NULL;
}

SdSprite* SdProject::getSprite(int index)
{
	return m_sprites[index];
}

void SdProject::removeSprite(SdSprite* sprite)
{
	std::vector<SdSprite*>::iterator iter;
	for(iter=m_sprites.begin();iter!=m_sprites.end();++iter)
	{
		if(*iter==sprite)
		{
			m_sprites.erase(iter);
			return;
		}
	}
	assert(0); /* sprite not find */
}


void SdProject::removeSprite(int index)
{
	std::vector<SdSprite*>::iterator iter=m_sprites.begin()+index;
	delete *iter;
	m_sprites.erase(iter);
}

int SdProject::spritePos(SdSprite* sprite)
{
	int size=m_sprites.size();
	for(int i=0;i<size;i++)
	{
		if(m_sprites[i]==sprite)
		{
			return i;
		}

	}
	assert(0);
	return -1;
}



SdSprite* SdProject::getCurSprite()
{
	return m_curSprite;
}


void SdProject::setCurSprite(SdSprite* sprite)
{
	m_curSprite=sprite;
}





























