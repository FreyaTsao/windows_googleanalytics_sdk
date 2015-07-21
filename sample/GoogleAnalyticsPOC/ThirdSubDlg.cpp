// ThirdSubDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GoogleAnalyticsPOC.h"
#include "ThirdSubDlg.h"
#include "afxdialogex.h"
#include <afxmsg_.h>
#include "GAEvent.h"
#include "GAScreenView.h"


// GA Client ID
extern CString GA_Cid;
// OS version
extern CString strOsVer;

IMPLEMENT_DYNAMIC(ThirdSubDlg, CDialogEx)

ThirdSubDlg::ThirdSubDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ThirdSubDlg::IDD, pParent)
{
	pGoogleAnalytics = shared_ptr<GoogleAnalytics>(new GoogleAnalytics());
}

ThirdSubDlg::~ThirdSubDlg()
{
}

void ThirdSubDlg::InitialUI()
{
	CRect rc;
	GetClientRect(&rc);
	m_songList.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 150);
	m_songList.InsertColumn(1, _T("Artist"), LVCFMT_LEFT, 150);
	m_songList.InsertColumn(2, _T("Album"), LVCFMT_LEFT, 150);
	m_songList.InsertColumn(3, _T("Time"), LVCFMT_LEFT, 150);
	InsertSong();
	m_songList.SetWindowPos(NULL, rc.left+5, rc.top+5, rc.right-5, rc.bottom-5, SWP_SHOWWINDOW);
}

void ThirdSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_songList);
}


BEGIN_MESSAGE_MAP(ThirdSubDlg, CDialogEx)
	ON_WM_CREATE()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &ThirdSubDlg::OnNMDblclkList1)
END_MESSAGE_MAP()


// ThirdSubDlg message handlers


void ThirdSubDlg::InsertSong()
{
	m_songList.DeleteAllItems();
	DWORD dwStyle = m_songList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	m_songList.SetExtendedStyle(dwStyle);
	m_songList.ModifyStyle(0, LVS_REPORT);

	m_songList.SetBkColor(RGB(255,255,255)); 
	m_songList.SetTextColor(RGB(0,0,0)); 

	int nIndex = m_songList.InsertItem(0, _T("點水"));
	m_songList.SetItemText(nIndex, 1, _T("楊丞琳"));
	m_songList.SetItemText(nIndex, 2, _T("雙丞戲"));
	m_songList.SetItemText(nIndex, 3, _T("04:19"));

	nIndex = m_songList.InsertItem(1, _T("我想愛"));
	m_songList.SetItemText(nIndex, 1, _T("楊丞琳"));
	m_songList.SetItemText(nIndex, 2, _T("雙丞戲"));
	m_songList.SetItemText(nIndex, 3, _T("03:29"));

	nIndex = m_songList.InsertItem(2, _T("失憶的金魚"));
	m_songList.SetItemText(nIndex, 1, _T("楊丞琳"));
	m_songList.SetItemText(nIndex, 2, _T("雙丞戲"));
	m_songList.SetItemText(nIndex, 3, _T("04:33"));

	nIndex = m_songList.InsertItem(3, _T("掛失的青春"));
	m_songList.SetItemText(nIndex, 1, _T("楊丞琳"));
	m_songList.SetItemText(nIndex, 2, _T("雙丞戲"));
	m_songList.SetItemText(nIndex, 3, _T("05:16"));

	nIndex = m_songList.InsertItem(4, _T("下個轉彎是你嗎"));
	m_songList.SetItemText(nIndex, 1, _T("楊丞琳"));
	m_songList.SetItemText(nIndex, 2, _T("雙丞戲"));
	m_songList.SetItemText(nIndex, 3, _T("04:44"));

	nIndex = m_songList.InsertItem(5, _T("我還想念你"));
	m_songList.SetItemText(nIndex, 1, _T("Bii"));
	m_songList.SetItemText(nIndex, 2, _T("Action Bii"));
	m_songList.SetItemText(nIndex, 3, _T("03:56"));

	nIndex = m_songList.InsertItem(6, _T("我們在愛中漫步"));
	m_songList.SetItemText(nIndex, 1, _T("Bii"));
	m_songList.SetItemText(nIndex, 2, _T("Action Bii"));
	m_songList.SetItemText(nIndex, 3, _T("03:48"));

	nIndex = m_songList.InsertItem(7, _T("你不是我"));
	m_songList.SetItemText(nIndex, 1, _T("戴愛玲"));
	m_songList.SetItemText(nIndex, 2, _T("一無所懼"));
	m_songList.SetItemText(nIndex, 3, _T("04:06"));

	nIndex = m_songList.InsertItem(8, _T("一無所懼"));
	m_songList.SetItemText(nIndex, 1, _T("戴愛玲"));
	m_songList.SetItemText(nIndex, 2, _T("一無所懼"));
	m_songList.SetItemText(nIndex, 3, _T("03:18"));

	nIndex = m_songList.InsertItem(9, _T("迴"));
	m_songList.SetItemText(nIndex, 1, _T("JJ Lin"));
	m_songList.SetItemText(nIndex, 2, _T("新地球"));
	m_songList.SetItemText(nIndex, 3, _T("02:13"));

	nIndex = m_songList.InsertItem(10, _T("新地球"));
	m_songList.SetItemText(nIndex, 1, _T("JJ Lin"));
	m_songList.SetItemText(nIndex, 2, _T("新地球"));
	m_songList.SetItemText(nIndex, 3, _T("04:37"));

	nIndex = m_songList.InsertItem(11, _T("水仙"));
	m_songList.SetItemText(nIndex, 1, _T("JJ Lin"));
	m_songList.SetItemText(nIndex, 2, _T("新地球"));
	m_songList.SetItemText(nIndex, 3, _T("04:00"));

	nIndex = m_songList.InsertItem(12, _T("浪漫血液"));
	m_songList.SetItemText(nIndex, 1, _T("JJ Lin"));
	m_songList.SetItemText(nIndex, 2, _T("新地球"));
	m_songList.SetItemText(nIndex, 3, _T("04:32"));

	nIndex = m_songList.InsertItem(13, _T("黑鍵"));
	m_songList.SetItemText(nIndex, 1, _T("JJ Lin"));
	m_songList.SetItemText(nIndex, 2, _T("新地球"));
	m_songList.SetItemText(nIndex, 3, _T("05:28"));

	nIndex = m_songList.InsertItem(14, _T("手心的薔薇"));
	m_songList.SetItemText(nIndex, 1, _T("JJ Lin"));
	m_songList.SetItemText(nIndex, 2, _T("新地球"));
	m_songList.SetItemText(nIndex, 3, _T("04:40"));

	nIndex = m_songList.InsertItem(15, _T("可惜沒如果"));
	m_songList.SetItemText(nIndex, 1, _T("JJ Lin"));
	m_songList.SetItemText(nIndex, 2, _T("新地球"));
	m_songList.SetItemText(nIndex, 3, _T("04:58"));

	nIndex = m_songList.InsertItem(16, _T("生生"));
	m_songList.SetItemText(nIndex, 1, _T("JJ Lin"));
	m_songList.SetItemText(nIndex, 2, _T("新地球"));
	m_songList.SetItemText(nIndex, 3, _T("04:18"));
}

int ThirdSubDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}

void ThirdSubDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// 回報 Google analytics
	if (pGoogleAnalytics) {
		CGAEvent gaEvent;
		gaEvent.ec = _T("Api");
		gaEvent.ea = _T("PlaySong_ING");
		gaEvent.el = _T("PlaySong_List");
		gaEvent.ev = 1001;
		CString str = _T("cd1=") + GA_Cid + _T("&ua=(Windows NT ") + strOsVer + _T(")");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaEvent);

		CGAScreenView gaScreenView;
		gaScreenView.an = _T("GA_Demo");
		gaScreenView.av = _T("1.0");
		gaScreenView.aid = _T("identifier");
		gaScreenView.aiid = _T("installer identifier");
		gaScreenView.cd = _T("ITEM_ID_NOW_PLAYING");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaScreenView);
	}
	*pResult = 0;
}
