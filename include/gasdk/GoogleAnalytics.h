#pragma once
#include "GAEvent.h"
#include "GAScreenView.h"
#include <memory>
#include "GoogleAnalyticsAPI.h"

using namespace std;

class GoogleAnalytics
{
public:
	GoogleAnalytics(void);
	~GoogleAnalytics(void);
	void Send(CGAEvent &gaEvent);
	void Send(CGAScreenView &gaScreenView);
	void SetGAClientId(CString id);
	void SetOtherParameters(CString str);

private:
	shared_ptr<GoogleAnalyticsAPI> pGoogleAnalyticsAPI;
	CString m_otherParameters;
};

