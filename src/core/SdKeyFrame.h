#ifndef _SD_KEY_FRAME_H_
#define _SD_KEY_FRAME_H_ 

class SdKeyFrame 
{
	public:
		static SdKeyFrame* tween(SdKeyFrame* l,SdKeyFrame* r,float percent);

	public:
		SdKeyFrame();
		~SdKeyFrame();
		SdKeyFrame* clone();

	public:
		void setPos(int pos){m_pos=pos;}
		int getPos(){return m_pos;}

		void setAlpha(float alpha){m_alpha=alpha;}
		float getAlpha(){return m_alpha;}

		void  setAngle(float angle){m_angle=angle;}
		void getAngle(){return m_angle;}

		void setTranslate(float tx,float ty) { m_tx=x; m_ty=y; }
		void getTranslate(float* tx,float* ty) { *tx=m_tx; *ty=m_ty; }

		void setSize(float width,float height){m_width=width;m_height=height;}
		void getSize(float* width,float* height){*width=m_width;*height=m_height;}

		void setTextureCoord(float cx0,float cy0,float cx1,float cy1)
		{
			m_cx0=cx0;
			m_cy0=cy0;
			m_cx1=cx1;
			m_cy1=cy1;
		}

		void getTextureCoord(float* cx0,float* cy0,float* cx1,float* cy1)
		{
			*cx0=m_cx0; 
			*cy0=m_cy0; 
			*cx1=m_cx1; 
			*cy1=m_cy1;
		}


		void setTexture(SdTexture* texture) { m_texture=texture; }
		SdTexture* getTexture() { return m_texture;}

	private:
		int m_pos;

		/* attribute */
		float m_alpha;
		float m_angle;
		float m_tx,m_ty;
		float m_cx0,m_cy0,m_cx1,m_cy1;
		float m_width,m_height;
		SdTexture* m_texture;
};

#endif /*_SD_KEY_FRAME_H_*/


















