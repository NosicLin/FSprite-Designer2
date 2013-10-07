#ifndef _SD_UI_OPERATOR_H_
#define _SD_UI_OPERATOR_H_

#include <QObject>
class SdProject;
class SdSprite;
class SdAnimation;

class SdUiOperator:public QObject 
{
	Q_OBJECT
	public:
		SdUiOperator();
		~SdUiOperator();

	public slots:
		void renameProject(SdProject* proj);
		void renameAnimation(SdAnimation* anim);
		void renameSprite(SdSprite* sprite);
		void renameSprite();

		void addSprite();
		void deleteSprite();
        void deleteSprite(SdProject* proj,SdSprite* sprite);
};

#endif /*_SD_UI_OPERATOR_H_*/

