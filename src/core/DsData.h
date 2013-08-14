#ifndef _DS_DATA_H_
#define _DS_DATA_H_

class DsProject;
class DsData 
{
	public:
		DsData();
		~DsData();

	public:
		DsProject* getCurProject();
		void setCurProject(DsProject* proj);

	private:
		DsProject* m_curProject;

};

#endif /*_DS_DATA_H_*/
