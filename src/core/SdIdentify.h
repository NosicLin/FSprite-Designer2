#ifndef _SD_IDENTIFY_H_
#define _SD_IDENTIFY_H_


enum 
{
	SD_CLASS_IDENTIFY=0,
	SD_CLASS_PROJECT,
	SD_CLASS_SPRITE,
	SD_CLASS_ANIMATION,
	SD_CLASS_BONE,

};

class SdIdentify
{
	public:
		virtual int getClassType()=0;
		virtual const char* className()=0;
		virtual ~SdIdentify();
};




#endif /*_SD_IDENTIFY_H_*/

