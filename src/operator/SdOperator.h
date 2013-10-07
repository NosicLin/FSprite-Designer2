#ifndef _SD_OPERATOR_H_
#define _SD_OPERATOR_H_

class SdDataOperator;
class SdUiOperator;
class SdOperator
{
	public:
		static SdDataOperator* data();
		static SdUiOperator* ui();

	public:
		static SdDataOperator* m_data;
		static SdUiOperator* m_ui;
};


#endif /*_SD_OPERATOR_H_*/

