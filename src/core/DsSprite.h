#ifndef _DS_SPRITE_H_
#define _DS_SPRITE_H_


#include <QString>

class DsAnimtion;


class DsSprite 
{
	public:
		static DsProject* create();

	public:
		DsSprite();
		~DsSprite();

	public:
		DsAnimtion* getAnimtion(const char* name);
		DsAnimtion* getAnimtion(int index);
		int animationNu();

		void addAnimtion(DsAnimtion* anim);
		void removeAnimtion(DsAnimtion* anim);

		QString getName();
		void setName(const QString& name);

	protected:
		void init();
		void destory();

	private:
		QString m_name;



};


#endif /*_DS_SPRITE_H_*/
