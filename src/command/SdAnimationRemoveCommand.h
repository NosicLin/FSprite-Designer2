#ifndef _SD_ANIMATION_REMOVE_COMMAND_H_
#define _SD_ANIMATION_REMOVE_COMMAND_H_ 

#include "command/SdCommand.h"

class SdSprite;
class SdAnimation;

class SdAnimationRemoveCommand:public SdCommand 
{
	public:
		SdAnimationRemoveCommand(SdSprite* sprite,SdAnimation* anim);

	public:
		virtual void redo();
		virtual void undo();
		virtual void emitRedoSignal();
		virtual void emitUndoSignal();
		virtual void backDiscard();

	private:
		int m_pos;
		SdSprite* m_sprite;
		SdAnimation* m_anim;
};



#endif /*_SD_ANIMATION_REMOVE_COMMAND_H_*/

