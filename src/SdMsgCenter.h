#ifndef _SD_MSG_CENTER_H_
#define _SD_MSG_CENTER_H_

#include <QObject>
class SdSprite;
class SdProject;

class SdMsgCenter:public QObject 
{
	Q_OBJECT

	public:

		SdMsgCenter();
		~SdMsgCenter();


    signals:
		void signalSpriteAttributeChange(SdSprite* sprite);
		void signalSpriteAdd(SdProject* proj,SdSprite* sprite);
		void signalSpriteRemove(SdProject* proj,SdSprite* sprite);
		void signalCurSpriteChange();

	public:
		void emitCurProjectChange();
		void emitCurAnimationChange();
		void emitCurEditModeChange();
		void emitCurBoneChange();
		void emitCurBoneAttrChange();
		void emitCurImageChange();
		void emitCurImageAttrChange();
		void emitCurFrameChange();


		/* sprite */
		void emitCurSpriteChange();
		void emitSpriteAttributeChange(SdSprite* sprite);
		void emitSpriteAdd(SdProject* proj,SdSprite* sprite);
		void emitSpriteRemove(SdProject* proj,SdSprite* sprite);


};


#endif /*_SD_MSG_CENTER_H_*/

