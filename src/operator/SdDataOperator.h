#ifndef _SD_DATA_OPERATOR_H_
#define _SD_DATA_OPERATOR_H_ 

class SdProject;
class SdDataOperator 
{
	public:
		SdDataOperator();
		~SdDataOperator();

	public:
		SdProject* getCurProject();
};



#endif /*_SD_DATA_OPERATOR_H_*/

