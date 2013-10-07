#ifndef _SD_TEXTURE_MGR_H_
#define _SD_TEXTURE_MGR_H_ 

#include <map>
class SdTexture;

class SdTextureMgr 
{
	public:
		SdTextureMgr();
		~SdTextureMgr();
	public:
		void setTextureLoadPath(const char* path);
		std::string getTextureLoadPath();

		SdTexture* loadTexture(const char* name);
		void refresh();

	public:
		std::map<std::string,SdTexture*> m_textures;

		std::string m_loadPath;
};

#endif /*_SD_TEXTURE_MGR_H_*/

