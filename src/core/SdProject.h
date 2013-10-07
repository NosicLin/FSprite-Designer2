#ifndef _SD_PROJECT_H_
#define _SD_PROJECT_H_


#include <vector>
#include <string>
#include "core/SdIdentify.h"
#include "util/SdCircleQueue.h"

class SdSprite;
class SdTextureMgr;
class SdTexture; 
class SdCommand;

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
		void addSprite(int pos,SdSprite* sprite);

		SdSprite* getSprite(const char* name);
		SdSprite* getSprite(int index);
		int getSpriteNu();
		bool hasSpriteWithName(const char* name);
		bool hasSprite(SdSprite* sprite);

		void removeSprite(SdSprite* sprite); /* sprite not delete */
		void removeSprite(int index); /* sprite will delete */

		int spritePos(SdSprite* sprite);

		SdSprite* getCurSprite();
		void setCurSprite(SdSprite* sprite);



		/* undo/redo support */
	public:
		bool canRedo();
		bool canUndo();

		SdCommand* redo();
		SdCommand* undo();

		void pushCommand(SdCommand* cmd);


	private:
		std::vector<SdSprite*> m_sprites;
		SdSprite* m_curSprite;

		SdTextureMgr* m_textureMgr;
		std::string m_projectName;
		std::string m_projectDir;


		/* undo/redo  */
        SdCircleQueue<SdCommand> m_historyStates;
        int m_curStateIndex;
};


#endif /*_SD_PROJECT_H_*/


























