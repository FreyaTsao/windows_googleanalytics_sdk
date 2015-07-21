#include "stdafx.h"
#include "GoogleAnalyticsAPI.h"

// Client ID
CString GA_Cid = _T("User-001");

GoogleAnalyticsAPI::GoogleAnalyticsAPI(void)
{
	ResetData();
}

GoogleAnalyticsAPI::~GoogleAnalyticsAPI(void)
{	
}

void GoogleAnalyticsAPI::ResetData()
{
	// 設定為已經呼叫過 ResetData()，BaseAPI::DoWork() 才能通過
	bResetDataDone = true;
	postData = _T("");
	vPostData.clear();
	m_otherParameters = _T("");
}

void GoogleAnalyticsAPI::SetCollectData(CGAEvent &gaEvent)
{
	postData += _T("v=") + GA_V;
	postData += _T("&tid=") + GA_Tid;
	postData += _T("&cid=") + GA_Cid;
	postData += _T("&t=") + gaEvent.t;
	postData += _T("&ec=") + gaEvent.ec;
	postData += _T("&ea=") + gaEvent.ea;
	postData += _T("&el=") + gaEvent.el;
	postData.Format(_T("%s&ev=%d"), postData, gaEvent.ev);
	if (!m_otherParameters.IsEmpty()) {
		postData += _T("&") + m_otherParameters;
	}

	vPostData.push_back(postData);
}

void GoogleAnalyticsAPI::SetCollectData(CGAScreenView &gaScreenView)
{
	postData += _T("v=") + GA_V;
	postData += _T("&tid=") + GA_Tid;
	postData += _T("&cid=") + GA_Cid;
	postData += _T("&t=") + gaScreenView.t;
	postData += _T("&an=") + gaScreenView.an;
	postData += _T("&av=") + gaScreenView.av;
	postData += _T("&aid=") + gaScreenView.aid;
	postData += _T("&aiid=") + gaScreenView.aiid;
	postData += _T("&cd=") + gaScreenView.cd;
	if (!m_otherParameters.IsEmpty()) {
		postData += _T("&") + m_otherParameters;
	}

	vPostData.push_back(postData);
}

void GoogleAnalyticsAPI::SetOtherData(CString data)
{
	m_otherParameters = data;
}

void GoogleAnalyticsAPI::PrepareData()
{	
	serverName.Format(_T("https://ssl.google-analytics.com/collect"));
}

void GoogleAnalyticsAPI::ExecuteResponseData()
{	
}

void GoogleAnalyticsAPI::Finish()
{
	//NotifyObservers(MessageCode::MESSAGE_GA_FINISH);
}
