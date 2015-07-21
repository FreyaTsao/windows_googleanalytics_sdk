#pragma once

#include "../BaseAPI.h"
#include "GAEvent.h"
#include "GAScreenView.h"

class GoogleAnalyticsAPI : public BaseAPI
{
public:
	GoogleAnalyticsAPI(void);
	~GoogleAnalyticsAPI(void);	
	void ResetData();
	void SetCollectData(CGAEvent &gaEvent);
	void SetCollectData(CGAScreenView &gaScreenView);
	void SetOtherData(CString data);

protected:
	void PrepareData();
	void ExecuteResponseData();
	void Finish();

private:
	std::vector<CString> vPostData;
	CString m_otherParameters;
};

