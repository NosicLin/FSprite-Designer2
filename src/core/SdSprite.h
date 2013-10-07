#ifndef _SD_SPRITE_H_
#define _SD_SPRITE_H_

#include <vector>
#include <string>
#include "core/SdIdentify.h"

class SdAnimation;
class SdProject;

class SdSprite:public SdIdentify
{
	public: 
		static SdSprite* create();

	public:
		SdSprite();
		virtual ~SdSprite();
	public:
		virtual int getClassType();
		virtual const char* className();

	public:
		void setName(const char* name);
		std::string getName();

		SdProject* getProject();
		void setProject(SdProject* proj);


        void addAnimation(SdAnimation* anim);

		SdAnimation* getAnimation(const char* name);
		SdAnimation* getAnimation(int index);
		int getAnimationNu();
		int animationPos(SdAnimation* anim);

		/* animation will not delete */
		void removeAnimation(SdAnimation* anim);

		/* animation will delete */
		void removeAnimation(int index);

		/* cur animation */
		SdAnimation* getCurAnimation();
		void setCurAnimation(SdAnimation* anim);

	private:
		std::vector<SdAnimation*> m_animations;
		std::string m_name;
		SdProject* m_project;

		SdAnimation* m_curAnimation;
};


#endif /*_SD_SPRITE_H_*/



