#ifndef _SD_MSG_CENTER_H_
#define _SD_MSG_CENTER_H_

#include <QObject>
class SdSprite;
class SdProject;
class SdAnimation;

class SdMsgCenter:public QObject 
{
	Q_OBJECT

	public:

		SdMsgCenter();
		~SdMsgCenter();


    signals:
		/* project */
		void signalCurProjectChange();

		/* sprite */
		void signalSpriteAttributeChange(SdSprite* sprite);
		void signalSpriteAdd(SdProject* proj,SdSprite* sprite);
		void signalSpriteRemove(SdProject* proj,SdSprite* sprite);
		void signalCurSpriteChange();

		/* animation */
		void signalCurAnimationChange();
		void signalAnimationAttributeChange(SdAnimation* anim);
		void signalAnimationAdd(SdSprite* sprite,SdAnimation* anim);
		void signalAnimationRemove(SdSprite* sprite,SdAnimation* anim);




	public:

		void emitCurEditModeChange();
		void emitCurBoneChange();
		void emitCurBoneAttrChange();
		void emitCurImageChange();
		void emitCurImageAttrChange();
		void emitCurFrameChange();

		/* project */
		void emitCurProjectChange();

		/* sprite */
		void emitCurSpriteChange();
		void emitSpriteAttributeChange(SdSprite* sprite);
		void emitSpriteAdd(SdProject* proj,SdSprite* sprite);
		void emitSpriteRemove(SdProject* proj,SdSprite* sprite);


		/* anim */
		void emitCurAnimationChange();
		void emitAnimationAttributeChange(SdAnimation* anim);
		void emitAnimationAdd(SdSprite* sprite,SdAnimation* anim);
		void emitAnimationRemove(SdSprite* sprite,SdAnimation* anim);
};


#endif /*_SD_MSG_CENTER_H_*/












