#ifndef _SD_TEXTURE_H_
#define _SD_TEXTURE_H_ 

#include "graphics/FsTexture2D.h"

class SdTexture 
{
	public:
		SdTexture();
		~SdTexture();

	public:
		void load(const char* dir,const char* path);
		std::string getPath();

		Texture2D* getFsTexture() 
		{
			return m_texture;
		}
	private:
		std::string m_dir;
		std::string m_path;
		Texture2D* m_texture;
};



#endif /*_SD_TEXTURE_H_*/

