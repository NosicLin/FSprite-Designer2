#include "core/DsProject.h"
#include <assert.h>
/*
#include "core/DsIconProvider.h"
#include "core/DsTextureProvider.h"

*/

#include "core/DsSprite.h"
#include "util/DsFileUtil.h"


DsProject* DsProject::create(const char* filename)
{
	DsProject* ret=new DsProject();
	ret->init(filename);
	return ret;
}

DsProject::DsProject()
{
	m_iconProvider=NULL;
	m_textureProvider=NULL;
	m_rootDir="";
}
DsProject::~DsProject()
{
    destory();
}


void DsProject::init(const char* filename)
{
	QString dirName=DsFileUtil::dirName(filename);
	m_rootDir=dirName;
}

void DsProject::destory()
{
	clear();
}

void DsProject::clear()
{
	for(unsigned int i=0;i<m_sprites.size();i++)
	{
		delete m_sprites[i];
	}
	m_sprites.clear();
}



DsSprite* DsProject::getSprite(const char* name)
{
	for(unsigned int i=0;i<m_sprites.size();i++)
	{
		if(m_sprites[i]->getName()==name)
		{
			return m_sprites[i];
		}

	}
	return NULL;
}

DsSprite* DsProject::getSprite(int index)
{
    return m_sprites[index];
}

int DsProject::getSpriteNu()
{
	return m_sprites.size();
}

void DsProject::addSprite(DsSprite* sp)
{
	m_sprites.push_back(sp);
}


void DsProject::removeSprite(DsSprite* sp)
{
	for(std::vector<DsSprite*>::iterator iter=m_sprites.begin();  
			iter!=m_sprites.end(); ++iter)
	{
		if(*iter==sp)
		{
			m_sprites.erase(iter);
			return;
		}

	}
	assert(0);
}


void DsProject::setProjectDir(const char* dir)
{
	m_rootDir=dir;
}

QString DsProject::getProjectDir()
{
	return m_rootDir;
}





















