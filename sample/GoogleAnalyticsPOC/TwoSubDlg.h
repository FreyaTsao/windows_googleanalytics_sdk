#pragma once
#include "afxwin.h"
#include <memory>
#include "GoogleAnalyticsAPI.h"
#include "GoogleAnalytics.h"

using namespace std;

// TwoSubDlg dialog

class TwoSubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TwoSubDlg)

public:
	TwoSubDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~TwoSubDlg();

// Dialog Data
	enum { IDD = IDD_DLG_TWO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

private:
	CButton m_btn1;
	CButton m_btn2;
	CButton m_btn3;
	shared_ptr<GoogleAnalytics> pGoogleAnalytics;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString GetScreenNameById(int nCurItemID);
};
