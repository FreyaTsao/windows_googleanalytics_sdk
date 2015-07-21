#include "stdafx.h"
#include "GoogleAnalytics.h"

extern CString GA_Cid;

GoogleAnalytics::GoogleAnalytics(void)
{
	pGoogleAnalyticsAPI = shared_ptr<GoogleAnalyticsAPI>(new GoogleAnalyticsAPI());
}


GoogleAnalytics::~GoogleAnalytics(void)
{
}

void GoogleAnalytics::Send(CGAEvent &gaEvent)
{
	pGoogleAnalyticsAPI->ResetData();
	if (!m_otherParameters.IsEmpty()) {
		pGoogleAnalyticsAPI->SetOtherData(m_otherParameters);
	}
	pGoogleAnalyticsAPI->SetCollectData(gaEvent);
	pGoogleAnalyticsAPI->DoWork();
}

void GoogleAnalytics::Send(CGAScreenView &gaScreenView)
{
	pGoogleAnalyticsAPI->ResetData();
	if (!m_otherParameters.IsEmpty()) {
		pGoogleAnalyticsAPI->SetOtherData(m_otherParameters);
	}
	pGoogleAnalyticsAPI->SetCollectData(gaScreenView);
	pGoogleAnalyticsAPI->DoWork();
}

void GoogleAnalytics::SetGAClientId(CString id)
{
	GA_Cid = id;
}

void GoogleAnalytics::SetOtherParameters(CString str)
{
	m_otherParameters = str;
}
