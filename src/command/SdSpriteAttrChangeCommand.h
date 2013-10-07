#ifndef _SD_SPRITE_ATTR_CHANGE_COMMAND_H_
#define _SD_SPRITE_ATTR_CHANGE_COMMAND_H_ 

#include "command/SdCommand.h"
#include "core/SdSprite.h"

class SdSpriteAttrChangeCommand:public SdCommand
{
	public:
		SdSpriteAttrChangeCommand(SdSprite* sprite,const SdSpriteAttribute& o,const SdSpriteAttribute& n);
		virtual ~SdSpriteAttrChangeCommand();

	public:
		void redo();
		void undo();
		void emitRedoSignal();
		void emitUndoSignal();

	private:
		SdSpriteAttribute m_old;
		SdSpriteAttribute m_new;
		SdSprite* m_sprite;
};


#endif /*_SD_SPRITE_ATTR_CHANGE_COMMAND_H_*/

