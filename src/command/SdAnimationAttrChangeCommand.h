#ifndef _SD_ANIMATION_ATTR_CHANGE_COMMAND_H_
#define _SD_ANIMATION_ATTR_CHANGE_COMMAND_H_

#include "command/SdCommand.h"

#include "core/SdAnimation.h"

class SdAnimationAttrChangeCommand:public SdCommand 
{
	public:
		SdAnimationAttrChangeCommand(SdAnimation* anim,const SdAnimationAttribute& attr_old,const SdAnimationAttribute& attr_new);


	public:
		virtual void redo();
		virtual void undo();
		virtual void emitRedoSignal();
		virtual void emitUndoSignal();
	private:

		SdAnimation* m_anim;
		SdAnimationAttribute m_old;
		SdAnimationAttribute m_new;


};




#endif /*_SD_ANIMATION_ATTR_CHANGE_COMMAND_H_*/

