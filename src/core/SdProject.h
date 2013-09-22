#ifndef _SD_PROJECT_H_
#define _SD_PROJECT_H_


#include <vector>
#include <string>

class SdSprite;
class SdTextureMgr;
class SdTexture; 

class SdProject
{
	public:
		static SdProject* create();
		static SdProject* create(const char* filename);

	public:
		SdProject();
		~SdProject();

	public:
		/* sprite */
		SdSprite* getSprite(const char* name);
		SdSprite* getSprite(int index);
		int getSpriteNu();
		void removeSprite(SdSprite* sprite);
		void removeSprite(int index);


	private:
		std::vector<SdSprite*> m_sprites;
		SdTextureMgr* m_textureMgr;
		std::string m_projectName;
		std::string m_projectDir;
};


#endif /*_SD_PROJECT_H_*/









