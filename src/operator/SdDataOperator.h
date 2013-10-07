#ifndef _SD_DATA_OPERATOR_H_
#define _SD_DATA_OPERATOR_H_ 

class SdProject;
class SdSprite;
class SdAnimation;
class SdDataOperator 
{
	public:
		SdDataOperator();
		~SdDataOperator();

	public:
		SdProject* getCurProject();
		void setCurProject(SdProject* proj);

		void setCurSprite(SdSprite* sprite);
		SdSprite* getCurSprite();

		void setCurAnimation(SdAnimation* anim);
		SdAnimation* getCurAnimation();
};




#endif /*_SD_DATA_OPERATOR_H_*/

