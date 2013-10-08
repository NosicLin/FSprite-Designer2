#ifndef _SD_SPRITE_H_
#define _SD_SPRITE_H_

#include <vector>
#include <string>
#include "core/SdIdentify.h"

class SdAnimation;
class SdProject;

class SdSpriteAttribute 
{
	public:
		std::string name;
};

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
		void setAttribute(const SdSpriteAttribute& attr);
		SdSpriteAttribute getAttribute();
	public:
		void setName(const char* name);
		std::string getName();

		SdProject* getProject();
		void setProject(SdProject* proj);


        void addAnimation(int pos,SdAnimation* anim);
		void addAnimation(SdAnimation* anim);

		SdAnimation* getAnimation(const char* name);
		SdAnimation* getAnimation(int index);
		int getAnimationNu();
		int animationPos(SdAnimation* anim);

		bool hasAnimationWithName(const char* name);


		/* animation will not delete */
		void removeAnimation(SdAnimation* anim);

		/* animation will delete */
		void removeAnimation(int index);

		/* cur animation */
		SdAnimation* getCurAnimation();
		void setCurAnimation(SdAnimation* anim);

	private:
		std::vector<SdAnimation*> m_animations;
		SdAnimation* m_curAnimation;
		SdProject* m_project;

		/* attribute */
		SdSpriteAttribute m_attr;
};


#endif /*_SD_SPRITE_H_*/












