#include "core/DsProject.h"
#include "core/DsData.h"


DsProject* DsData::getCurProject()
{
	return m_curProject;
}
void DsData::setCurProject(DsProject* proj)
{
	if(m_curProject)
	{
		delete m_curProject;
		m_curProject=NULL;
	}
	m_curProject=proj;
}


DsData::DsData()
{
	m_curProject=NULL;
}
DsData::~DsData()
{
	if(m_curProject)
	{
		delete m_curProject;
	}
	m_curProject=NULL;
}




