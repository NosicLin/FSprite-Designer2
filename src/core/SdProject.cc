#include <QtGlobal>
#include <assert.h>
#include "core/SdProject.h"
#include "core/SdTextureMgr.h"
#include "core/SdSprite.h"
#include "command/SdCommand.h"



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
	m_curStateIndex=-1;
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

std::string SdProject::getName()
{
	return m_projectName;
}



void SdProject::addSprite(SdSprite* sprite)
{
	m_sprites.push_back(sprite);
	sprite->setProject(this);
}

void SdProject::addSprite(int pos,SdSprite* sprite)
{
	qDebug("addSprite,pos=%d",pos);
	m_sprites.insert(m_sprites.begin()+pos,sprite);
	sprite->setProject(this);
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

bool SdProject::hasSpriteWithName(const char* name)
{
	return getSprite(name)!=NULL;
}

bool SdProject::hasSprite(SdSprite* sprite)
{
	int size=m_sprites.size();
	for(int i=0;i<size;i++)
	{
		if(m_sprites[i]==sprite)
		{
			return true;
		}
	}
	return false;
}



SdSprite* SdProject::getSprite(int index)
{
	return m_sprites[index];
}

int SdProject::getSpriteNu()
{
	return m_sprites.size();
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


void SdProject::pushCommand(SdCommand* cmd)
{
	if(m_curStateIndex<m_historyStates.size()-1)
	{
		m_historyStates.dropTail(m_historyStates.size()-1-m_curStateIndex);
	}

	if(m_historyStates.full())
	{
		m_historyStates.push(cmd);
	}
	else 
	{
		m_historyStates.push(cmd);
		m_curStateIndex++;
	}
}

SdCommand* SdProject::undo()
{
	assert(canUndo());
	SdCommand* command=m_historyStates.getItem(m_curStateIndex);
	m_curStateIndex--;
	command->undo();
	return command;

}

SdCommand* SdProject::redo()
{
	assert(canRedo());
	SdCommand* command=m_historyStates.getItem(m_curStateIndex+1);
	m_curStateIndex++;
	command->redo();
	return command;
}

bool SdProject::canRedo()
{
	if(m_curStateIndex<m_historyStates.size()-1)
	{
		return true;
	}
	return false;
}

bool SdProject::canUndo()
{
	if(m_curStateIndex>=0)
	{
		return true;
	}
    return false;

}

