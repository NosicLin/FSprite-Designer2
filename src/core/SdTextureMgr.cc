#include "core/SdTextureMgr.h"


SdTextureMgr::SdTextureMgr()
{
}
SdTextureMgr::~SdTextureMgr()
{
}



void SdTextureMgr::setTextureLoadPath(const char* path)
{
	m_loadPath=std::string(path);
}

std::string SdTextureMgr::getTextureLoadPath()
{
	return m_loadPath;
}




