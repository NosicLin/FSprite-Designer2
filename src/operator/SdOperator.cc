#include <string>
#include "operator/SdOperator.h"
#include "operator/SdDataOperator.h"


SdDataOperator* SdOperator::m_data=NULL;


SdDataOperator* SdOperator::data()
{
	if(SdOperator::m_data==NULL)
	{
		SdOperator::m_data=new SdDataOperator();
	}
	return SdOperator::m_data;
}








