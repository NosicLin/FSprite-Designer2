#ifndef _SD_ANIMATION_H_
#define _SD_ANIMATION_H_ 

#include <string>
#include <vector>

#include "core/SdIdentify.h"

class SdBone;
class SdSprite;

class SdAnimationAttribute
{
	public:
		std::string name;
};

class SdAnimation :public SdIdentify
{
	public:
		SdAnimation();
        virtual ~SdAnimation();

	public:
        virtual int getClassType();
        virtual const char* className();

	public:
		void setName(const char* name);
		std::string getName();

		SdSprite* getSprite();
		void setSprite(SdSprite* sprite);

		void setAttribute(const SdAnimationAttribute& attr);
		SdAnimationAttribute getAttribute();



	public:
		void addBone(SdBone* bone);
		void removeBone(SdBone* bone);

		int getBoneNu();
		SdBone* getBone(int index);

	public:
		void addKeyFrame(int pos);
		void removeKeyFrame(int pos);

	private:
		std::vector<SdBone*> m_bones;
		SdBone* m_root;
		SdSprite* m_sprite;

		/* attribute */
		SdAnimationAttribute m_attr;
};



#endif /*_SD_ANIMATION_H_*/










