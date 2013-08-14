#include "DsGlobal.h"
#include "core/DsData.h"

DsData* DsGlobal::ms_data=0;
DsData* DsGlobal::data()
{
	return ms_data;
}

