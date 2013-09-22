#ifndef _SD_SPRITE_H_
#define _SD_SPRITE_H_

#include <vector>
#include <string>

class SdAnimation;

class SdSprite
{
	public: 
		static SdSprite* create();

	public:
		SdSprite();
		~SdSprite();

	public:
		void setName(const char* name);
		std::string getName();

		SdAnimation* getAnimation(const char* name);
		SdAnimation* getAnimation(int index);
		int getSpriteNu();
		void removeAnimation(SdAnimation* anim);
		void removeAnimation(int index);

	private:
		std::vector<SdAnimation*> m_animations;
		std::string m_name;
};

#endif /*_SD_SPRITE_H_*/



