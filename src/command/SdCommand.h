#ifndef _SD_COMMAND_H_
#define _SD_COMMAND_H_

class SdCommand 
{
	public:
		virtual ~SdCommand();
		virtual void redo()=0;
		virtual void undo()=0;
		virtual void emitRedoSignal()=0;
		virtual void emitUndoSignal()=0;
		virtual void forwardDiscard();
		virtual void backDiscard();
};

#endif /*_SD_COMMAND_H_*/

