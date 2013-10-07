#ifndef _SD_PROJECT_H_
#define _SD_PROJECT_H_


#include <vector>
#include <string>
#include "core/SdIdentify.h"

class SdSprite;
class SdTextureMgr;
class SdTexture; 

class SdProject:public SdIdentify
{
	public:
		static SdProject* create(const std::string& dir,const std::string& name);
	public:
		SdProject(const std::string& dir,const std::string& name);
		virtual ~SdProject();
	public:
		virtual int getClassType();
		virtual const char* className();


	public:
        std::string getName();

		/* sprite */

        void addSprite(SdSprite* sprite);

		SdSprite* getSprite(const char* name);
		SdSprite* getSprite(int index);
		int getSpriteNu();

		void removeSprite(SdSprite* sprite); /* sprite not delete */
		void removeSprite(int index); /* sprite will delete */

		int spritePos(SdSprite* sprite);

		SdSprite* getCurSprite();
		void setCurSprite(SdSprite* sprite);

	private:
		std::vector<SdSprite*> m_sprites;
		SdSprite* m_curSprite;

		SdTextureMgr* m_textureMgr;
		std::string m_projectName;
		std::string m_projectDir;
};


#endif /*_SD_PROJECT_H_*/


























