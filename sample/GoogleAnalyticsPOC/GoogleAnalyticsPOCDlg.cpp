
// GoogleAnalyticsPOCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GoogleAnalyticsPOC.h"
#include "GoogleAnalyticsPOCDlg.h"
#include "afxdialogex.h"
#include "OneSubDlg.h"
#include "OSDetector.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// GA Client ID
extern CString GA_Cid;
// OS version
CString strOsVer = COSDetector::GetOSVerString();

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGoogleAnalyticsPOCDlg dialog



CGoogleAnalyticsPOCDlg::CGoogleAnalyticsPOCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGoogleAnalyticsPOCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGoogleAnalyticsPOCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGoogleAnalyticsPOCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CGoogleAnalyticsPOCDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CGoogleAnalyticsPOCDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CGoogleAnalyticsPOCDlg::OnBnClickedButtonThree)
	ON_MESSAGE(WM_LOGIN_FINISH, &CGoogleAnalyticsPOCDlg::UpdateClientID)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CGoogleAnalyticsPOCDlg::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// CGoogleAnalyticsPOCDlg message handlers

BOOL CGoogleAnalyticsPOCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_inDlg1.Create(IDD_DLG_ONE, this);
	m_inDlg2.Create(IDD_DLG_TWO, this);
	m_inDlg3.Create(IDD_DLG_THIRD, this);
	m_inDlg3.InitialUI();
	pGoogleAnalytics = shared_ptr<GoogleAnalytics>(new GoogleAnalytics());
	GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("User: ") + GA_Cid);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGoogleAnalyticsPOCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGoogleAnalyticsPOCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGoogleAnalyticsPOCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGoogleAnalyticsPOCDlg::OnBnClickedButtonOne()
{
	m_inDlg2.ShowWindow(SW_HIDE);
	m_inDlg3.ShowWindow(SW_HIDE);
	CRect rc, dlgRect;
	GetDlgItem(IDC_BUTTON_ONE)->GetClientRect(&rc);
	dlgRect.left = rc.right + 20;
	dlgRect.top = rc.top;
	GetClientRect(&rc);
	dlgRect.right = rc.right;
	dlgRect.bottom = rc.bottom;
	m_inDlg1.SetWindowPos(NULL, dlgRect.left, dlgRect.top, dlgRect.right, dlgRect.bottom, SWP_SHOWWINDOW);

	// 回報 Google analytics
	if (pGoogleAnalytics) {
		CGAEvent gaEvent;
		gaEvent.ec = _T("Api");
		gaEvent.ea = _T("Online_DEMO");
		gaEvent.el = _T("Online_Label");
		gaEvent.ev = 50;
		CString str = _T("cd1=") + GA_Cid + _T("&ua=(Windows NT ") + strOsVer + _T(")");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaEvent);

		CGAScreenView gaScreenView;
		gaScreenView.an = _T("GA_Demo");
		gaScreenView.av = _T("1.0");
		gaScreenView.aid = _T("identifier");
		gaScreenView.aiid = _T("installer identifier");
		gaScreenView.cd = _T("ITEM_ID_ONLINE_BROWSE");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaScreenView);
	}
}

void CGoogleAnalyticsPOCDlg::OnBnClickedButtonTwo()
{
	m_inDlg1.ShowWindow(SW_HIDE);
	m_inDlg3.ShowWindow(SW_HIDE);
	CRect rc, dlgRect;
	GetDlgItem(IDC_BUTTON_ONE)->GetClientRect(&rc);
	dlgRect.left = rc.right + 20;
	dlgRect.top = rc.top;
	GetClientRect(&rc);
	dlgRect.right = rc.right;
	dlgRect.bottom = rc.bottom;
	m_inDlg2.SetWindowPos(NULL, dlgRect.left, dlgRect.top, dlgRect.right, dlgRect.bottom, SWP_SHOWWINDOW);

	// 回報 Google analytics
	if (pGoogleAnalytics) {
		CGAEvent gaEvent;
		gaEvent.ec = _T("Api");
		gaEvent.ea = _T("Follow_DEMO");
		gaEvent.el = _T("Follow_Label");
		gaEvent.ev = 50;
		CString str = _T("cd1=") + GA_Cid + _T("&ua=(Windows NT ") + strOsVer + _T(")");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaEvent);

		CGAScreenView gaScreenView;
		gaScreenView.an = _T("GA_Demo");
		gaScreenView.av = _T("1.0");
		gaScreenView.aid = _T("identifier");
		gaScreenView.aiid = _T("installer identifier");
		gaScreenView.cd = _T("ITEM_ID_RADIO");
		pGoogleAnalytics->SetOtherParameters(str);
		pGoogleAnalytics->Send(gaScreenView);
	}
}


void CGoogleAnalyticsPOCDlg::OnBnClickedButtonThree()
{
	m_inDlg1.ShowWindow(SW_HIDE);
	m_inDlg2.ShowWindow(SW_HIDE);
	CRect rc, dlgRect, btnRect;
	GetDlgItem(IDC_BUTTON_ONE)->GetClientRect(&btnRect);
	dlgRect.left = btnRect.right + 20;
	dlgRect.top = btnRect.top;
	GetClientRect(&rc);
	dlgRect.right = rc.right - btnRect.right -30;
	dlgRect.bottom = rc.bottom - 10;
	m_inDlg3.SetWindowPos(NULL, dlgRect.left, dlgRect.top, dlgRect.right, dlgRect.bottom, SWP_SHOWWINDOW);

	// 回報 Google analytics
	if (pGoogleAnalytics) {
		CGAEvent gaEvent;
		gaEvent.ec = _T("Api");
		gaEvent.ea = _T("Playsong_DEMO");
		gaEvent.el = _T("Playsong_Label");
		gaEvent.ev = 50;
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
}

LRESULT CGoogleAnalyticsPOCDlg::UpdateClientID(WPARAM wParam, LPARAM lParam)
{
	CString *pStrTemp = (CString*)lParam;
	GA_Cid.Format(_T("%s"), *pStrTemp);
	GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("User: ") + *pStrTemp);
	delete pStrTemp;
	return 0;
}


void CGoogleAnalyticsPOCDlg::OnBnClickedButtonLogin()
{
	LoginDlg loginDlg(this);
	loginDlg.DoModal();
}
 