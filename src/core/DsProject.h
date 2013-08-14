#ifndef _DS_PROJECT_H_
#define _DS_PROJECT_H_

#include <QString>
#include <vector>

class DsIconProvider;
class DsTextureProvider;
class DsSprite;


class DsProject 
{
	public:
		static DsProject* create(const char* filename);

	public:
		DsProject();
		~DsProject();

	public:
		DsSprite* getSprite(const char* name);
		DsSprite* getSprite(int index);
		int getSpriteNu();

        void addSprite(DsSprite* sp);
        void removeSprite(DsSprite* sp);


		void setProjectDir(const char* dir);
		QString getProjectDir();

		void clear();
	protected:
		void init(const char* filename);
		void destory();


	private:
		QString m_rootDir;
		DsIconProvider* m_iconProvider;
		DsTextureProvider* m_textureProvider;
		std::vector<DsSprite*> m_sprites;
};



#endif /*_DS_PROJECT_H_*/

