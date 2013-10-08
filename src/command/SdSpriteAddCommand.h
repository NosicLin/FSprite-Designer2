#ifndef _SD_SPRITE_ADD_COMMAND_H_
#define _SD_SPRITE_ADD_COMMAND_H_

#include "command/SdCommand.h"

class SdProject;
class SdSprite;
class SdSpriteAddCommand :public SdCommand
{
	public:
		SdSpriteAddCommand(SdProject* proj,SdSprite* sprite,int pos);

	public:
		 virtual void redo();
		 virtual void undo();
         virtual void emitRedoSignal();
         virtual void emitUndoSignal();
         virtual void forwardDiscard();

	private:
		 SdProject* m_proj;
		 SdSprite* m_sprite;
		 int m_pos;
};



#endif /*_SD_SPRITE_ADD_COMMAND_H_*/

