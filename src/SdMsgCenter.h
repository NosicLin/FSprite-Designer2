#ifndef _SD_MSG_CENTER_H_
#define _SD_MSG_CENTER_H_

class SdMsgCenter:public QObject 
{
	Q_OBJECT
	public:
		SdMsgCenter();
		~SdMsgCenter();

	public:
		void emitCurProjectChange();
		void emitCurSpriteChange();
		void emitCurAnimationChange();
		void emitCurEditModeChange();
		void emitCurBoneChange();
		void emitCurBoneAttrChange();
		void emitCurImageChange();
		void emitCurImageAttrChange();
		void emitCurFrameChange();
};


#endif /*_SD_MSG_CENTER_H_*/

