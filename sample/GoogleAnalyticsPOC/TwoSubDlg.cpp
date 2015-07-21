// TwoSubDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GoogleAnalyticsPOC.h"
#include "TwoSubDlg.h"
#include "afxdialogex.h"


// GA Client ID
extern CString GA_Cid;
// OS version
extern CString strOsVer;

IMPLEMENT_DYNAMIC(TwoSubDlg, CDialogEx)

TwoSubDlg::TwoSubDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TwoSubDlg::IDD, pParent)
{
	pGoogleAnalytics = shared_ptr<GoogleAnalytics>(new GoogleAnalytics());
}

TwoSubDlg::~TwoSubDlg()
{
}

void TwoSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btn1);
	DDX_Control(pDX, IDC_BUTTON2, m_btn2);
	DDX_Control(pDX, IDC_BUTTON3, m_btn3);
}


BEGIN_MESSAGE_MAP(TwoSubDlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON1, &TwoSubDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TwoSubDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &TwoSubDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// TwoSubDlg message handlers


BOOL TwoSubDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(207, 232, 254));    // dialog background color
	CBrush *pOld = pDC->SelectObject(&myBrush);
	BOOL bRes  = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}


void TwoSubDlg::OnBnClickedButton1()
{
	// 回報 Google analytics
	if (pGoogleAnalytics) {
		CGAEvent gaEvent;
		gaEvent.ec = _T("Api");
		gaEvent.ea = _T("Follow_ING");
		gaEvent.el = _T("Follow_1ST_SIR");
		gaEvent.ev = 10;
		CString str = _T("cd1=") + GA_Cid + _T("&ua=(Windows NT ") + strOsVer + _T(")");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaEvent);

		CGAScreenView gaScreenView;
		gaScreenView.an = _T("GA_Demo");
		gaScreenView.av = _T("1.0");
		gaScreenView.aid = _T("identifier");
		gaScreenView.aiid = _T("installer identifier");
		gaScreenView.cd = GetScreenNameById(1);
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaScreenView);
	}
}


void TwoSubDlg::OnBnClickedButton2()
{
	// 回報 Google analytics
	if (pGoogleAnalytics) {
		CGAEvent gaEvent;
		gaEvent.ec = _T("Api");
		gaEvent.ea = _T("Follow_ING");
		gaEvent.el = _T("Follow_2ND_SIR");
		gaEvent.ev = 20;
		CString str = _T("cd1=") + GA_Cid + _T("&ua=(Windows NT ") + strOsVer + _T(")");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaEvent);

		CGAScreenView gaScreenView;
		gaScreenView.an = _T("GA_Demo");
		gaScreenView.av = _T("1.0");
		gaScreenView.aid = _T("identifier");
		gaScreenView.aiid = _T("installer identifier");
		gaScreenView.cd = GetScreenNameById(2);
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaScreenView);
	}
}


void TwoSubDlg::OnBnClickedButton3()
{
	// 回報 Google analytics
	if (pGoogleAnalytics) {
		CGAEvent gaEvent;
		gaEvent.ec = _T("Api");
		gaEvent.ea = _T("Follow_ING");
		gaEvent.el = _T("Follow_3RD_SIR");
		gaEvent.ev = 30;
		CString str = _T("cd1=") + GA_Cid + _T("&ua=(Windows NT ") + strOsVer + _T(")");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaEvent);

		CGAScreenView gaScreenView;
		gaScreenView.an = _T("GA_Demo");
		gaScreenView.av = _T("1.0");
		gaScreenView.aid = _T("identifier");
		gaScreenView.aiid = _T("installer identifier");
		gaScreenView.cd = GetScreenNameById(3);
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaScreenView);
	}
}

CString TwoSubDlg::GetScreenNameById(int nCurItemID)
{
	CString screenName;
	switch (nCurItemID)
	{
	case 1:
		screenName = _T("FOLLOW_1ST");
		break;
	case 2:
		screenName = _T("FOLLOW_2ND");
		break;
	case 3:
		screenName = _T("FOLLOW_3RD");
		break;
	default:
		screenName.Format(_T("%d"), nCurItemID);
		break;
	}
	return screenName;
}
