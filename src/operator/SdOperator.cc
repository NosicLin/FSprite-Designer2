#include <string>
#include "operator/SdOperator.h"
#include "operator/SdDataOperator.h"
#include "operator/SdUiOperator.h"


SdDataOperator* SdOperator::m_data=NULL;
SdUiOperator* SdOperator::m_ui=NULL;


SdDataOperator* SdOperator::data()
{
	if(SdOperator::m_data==NULL)
	{
		SdOperator::m_data=new SdDataOperator();
	}
	return SdOperator::m_data;
}

SdUiOperator* SdOperator::ui()
{
	if(SdOperator::m_ui==NULL)
	{
		SdOperator::m_ui=new SdUiOperator();
	}
	return SdOperator::m_ui;
}




