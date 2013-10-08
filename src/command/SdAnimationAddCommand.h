#ifndef _SD_ANIMATION_ADD_COMMAND_H_
#define _SD_ANIMATION_ADD_COMMAND_H_

#include "command/SdCommand.h"

class SdSprite;
class SdAnimation;
class  SdAnimationAddCommand:public SdCommand 
{
	public:
		SdAnimationAddCommand(SdSprite* sprite,SdAnimation* anim,int pos);

	public:
		virtual void redo();
		virtual void undo();
		virtual void emitRedoSignal();
		virtual void emitUndoSignal();
		virtual void forwardDiscard();
	private:
		int m_pos;
		SdSprite* m_sprite;
		SdAnimation* m_anim;

};



#endif /*_SD_ANIMATION_ADD_COMMAND_H_*/

