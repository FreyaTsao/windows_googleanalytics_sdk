#pragma once
#include "afxwin.h"

#define WM_LOGIN_FINISH (WM_USER + 1)

// LoginDlg dialog

class LoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~LoginDlg();

// Dialog Data
	enum { IDD = IDD_DLG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_idEditBox;
	CString m_id;
	HWND m_parentHwnd;
	afx_msg void OnBnClickedButton1();
};
