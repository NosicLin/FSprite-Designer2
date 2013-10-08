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

		/* animation */
		void renameAnimation();
		void renameAnimation(SdAnimation* anim);
		void addAnimation();
		void deleteAnimation();
		void deleteAnimation(SdSprite* sprite,SdAnimation* anim);


		/* sprite */
		void renameSprite();
		void renameSprite(SdSprite* sprite);
		void addSprite();
		void deleteSprite();
        void deleteSprite(SdProject* proj,SdSprite* sprite);
};

#endif /*_SD_UI_OPERATOR_H_*/

