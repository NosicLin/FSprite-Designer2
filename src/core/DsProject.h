#ifndef _DS_PROJECT_H_
#define _DS_PROJECT_H_

#include <QString>

class DsIconProvider;
class DsTextureProvider;
class DsSprite;


class DsProject 
{
	public:
		static DsProject* create(const char* filename);
		static DsProject* create();

	public:
		DsProject();
		~DsProject();

	public:
		DsSprite* getSprite(const char* name);
		DsSprite* getSprite(int index);
		int spriteNu();

		void addSprite(Sprite* sp);
		void removeSprite(Sprite* sp);



	protected:
		void init(const char* filename);
		void destory();


	private:
		QString m_rootPath;
		DsIconProvider* m_iconProvider;
		DsTextureProvider* m_textureProvider;
		std::vector<DsSprite*> m_sprites;
};



#endif /*_DS_PROJECT_H_*/

