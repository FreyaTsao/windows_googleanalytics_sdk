// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GoogleAnalyticsPOC.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// LoginDlg dialog

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(LoginDlg::IDD, pParent)
{
	m_parentHwnd = NULL;
	if (pParent) {
		m_parentHwnd = pParent->GetSafeHwnd();
	}
}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_idEditBox);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LoginDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// LoginDlg message handlers


void LoginDlg::OnBnClickedButton1()
{
	m_idEditBox.GetWindowTextW(m_id);
	// ¶Ç°e°T®§
	::SendMessage(m_parentHwnd, WM_LOGIN_FINISH, 0, (LPARAM)new CString(m_id));
	OnCancel();
}
