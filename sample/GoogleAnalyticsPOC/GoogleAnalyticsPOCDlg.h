
// GoogleAnalyticsPOCDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "OneSubDlg.h"
#include "TwoSubDlg.h"
#include <memory>
#include "GoogleAnalyticsAPI.h"
#include "ThirdSubDlg.h"
#include "LoginDlg.h"
#include "GoogleAnalytics.h"

using namespace std;

// CGoogleAnalyticsPOCDlg dialog
class CGoogleAnalyticsPOCDlg : public CDialogEx
{
// Construction
public:
	CGoogleAnalyticsPOCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GOOGLEANALYTICSPOC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	OneSubDlg m_inDlg1;
	TwoSubDlg m_inDlg2;
	ThirdSubDlg m_inDlg3;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOne();
	afx_msg void OnBnClickedButtonTwo();
	afx_msg void OnBnClickedButtonThree();
	afx_msg LRESULT UpdateClientID(WPARAM wParam, LPARAM lParam);

private:
	shared_ptr<GoogleAnalytics> pGoogleAnalytics;
public:
	afx_msg void OnBnClickedButtonLogin();
};
