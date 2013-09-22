#ifndef _SD_ANIMATION_H_
#define _SD_ANIMATION_H_ 

class SdAnimation 
{
	public:
		SdAnimation();
		~SdAnimation();


	public:
		void setName(const char* name);
		std::string getName();

	public:
		void addBone(SdBone* bone);
		void removeBone(SdBone* bone);

		int getBoneNu();
		SdBone* getBone(int index);

	public:
		void addKeyFrame(int pos);
		void removeKeyFrame(int pos);

	private:
		std::vector<SdBone*> m_bones;
		SdBone* m_root;
};


#endif /*_SD_ANIMATION_H_*/

