#ifndef _SD_GLOBAL_H_
#define _SD_GLOBAL_H_

class SdMsgCenter;

class SdProject;
class SdSprite;
class SdAnimation;

class SdGlobal 
{
	public:
		static void moduleInit();
		static void moduleExit();
	public:
		static SdMsgCenter* getMsgCenter();

		static SdProject* getCurProject();
		static void setCurProject(SdProject* p);

		static SdSprite* getCurSprite();
		static void setCurSprite(SdSprite* sprite);

		static SdAnimation* getCurAnimation();
		static void setCurAnimation(SdAnimation* anim);


		/* undo/redo */

		static bool canUndo();
		static bool canRedo(); 

	private:
		static SdMsgCenter* m_msgCenter;
		static SdProject* m_curProject;

};



#endif /*_SD_GLOBAL_H_*/

