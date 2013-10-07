#include "operator/SdDataOperator.h"
#include "core/SdProject.h"
#include "SdGlobal.h"


SdDataOperator::SdDataOperator()
{
}


SdDataOperator::~SdDataOperator()
{

}

SdProject* SdDataOperator::getCurProject()
{
	return SdGlobal::getCurProject();
}

