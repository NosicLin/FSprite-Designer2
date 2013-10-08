#ifndef _SD_SPRITE_REMOVE_COMMAND_H_
#define _SD_SPRITE_REMOVE_COMMAND_H_ 

#include "command/SdCommand.h"

class SdProject;
class SdSprite;

class SdSpriteRemoveCommand:public SdCommand
{
	public:
		SdSpriteRemoveCommand(SdProject* proj,SdSprite* sprite);

	public:
		 virtual void redo();
		 virtual void undo();
		 virtual void emitRedoSignal();
		 virtual void emitUndoSignal();
		 virtual void backDiscard();


	private:
		 SdProject* m_proj;
		 SdSprite* m_sprite;
		 int m_pos;
};


#endif /*_SD_SPRITE_REMOVE_COMMAND_H_*/

