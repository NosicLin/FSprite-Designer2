#ifndef _SD_BONE_H_
#define _SD_BONE_H_

#include <string>
#include <vector>

#include "math/FsMatrix4.h"

class SdBone 
{
	public:
		SdBone(SdBone* parent=NULL);
		~SdBone();

	public:
		void setName(const char* name);
		std::string getName();

		void setParent(SdBone* bone);
		SdBone* getParent();

		void addChild(SdBone* bone);
		void removeChild(SdBone* bone);

		int getChildNu();
		SdBone* getChild(int index);

	public:
		void updateLocalMatrix();
		void updateWorldMatrix(bool child=true);

	public:
		SdKeyFrame* getKeyFrame(int pos);
		void getKeyFrameNu();

	public:
		void insertFrame(int pos);
		void removeFrame(int pos);


	private:
		std::string m_name;

		SdBone* m_parent;
		std::vector<SdBone*> m_children;

		float m_tx,m_ty;
		float m_angle;
		float m_sx,sy;
		bool m_flipX,m_flipY;

		Matrix4 m_localMatrix;
		Matrix4 m_worldMatrix;

		std::vector<SdKeyFrame*> m_keyFrames;

};


#endif /*_SD_BONE_H_*/

















