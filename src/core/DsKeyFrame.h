#ifndef _DS_KEY_FRAME_H_
#define _DS_KEY_FRAME_H_

class DsKeyFrame
{
	public:
		static DsKeyFrame* create();

	public:
		DsKeyFrame();
		~DsKeyFrame();

	public:
		DsDrawAble* getDrawAble(int index);
		int drawAbleNu();

		void addDrawAble(DsDrawAble* da);
		void removeDrawAble(DsDrawAble* da);

		void upDrawAble(DsDrawAble* da);
		void downDrawAble(DsDrawAble* da);
		void frontDrawAble(DsDrawAble* da);
		void tailDrawAble(DsDrawAble* da);

		int getPos();
		void setPos(int pos);

		bool getTween();
		void setTween(bool tween);

		int drawAbleGroupNu();
		DsDrawAbleGroup* getDrawAbleGroup(int pos);




	public:
		void init();
		void destory();

	private:
		int m_pos;
		bool m_tween;
		std::vector<DsDrawAble*> m_drawables;

};




#endif /*_DS_KEY_FRAME_H_*/

