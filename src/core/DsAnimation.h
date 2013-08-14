#ifndef _DS_ANIMATION_H_
#define _DS_ANIMATION_H_ 

#include <QString>

class DsKeyFrame 


class DsAnimation 
{
	public:
		static DsAnimation* create();

	public:
		DsAnimation();
		~DsAnimation();

	public:
		/* Frame */
		int getTotalFrame();
		void insertEmptyKeyFrame(int pos);
		void insertKeyFrame(int pos);
		void removeFrame(int pos);

		DsKeyFrame* getNearestFrame(int pos);
		DsKeyFrame* getFrame(int pos);
		void createTween(int pos);
		DsKeyFrame* generateTweenFrame(int pos);


		/* KeyFrame */
		int keyFrameNu();
		int getKeyFrame(int pos);

		/* fps */
		int getFps();
		void setFps(int fps);

		/* name */
		QString getName();
		void setName(const QString& name);




	protected:
		void init();
		void destory();

	private:
		QString m_name;
		int m_fps;

};



#endif /*_DS_ANIMATION_H_*/


















