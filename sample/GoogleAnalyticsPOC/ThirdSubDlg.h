#pragma once
#include "afxcmn.h"
#include "GoogleAnalyticsAPI.h"
#include <memory>
#include "GoogleAnalytics.h"

using namespace std;

// ThirdSubDlg dialog

class ThirdSubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ThirdSubDlg)

public:
	ThirdSubDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ThirdSubDlg();
	void InitialUI();

// Dialog Data
	enum { IDD = IDD_DLG_THIRD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_songList;
	shared_ptr<GoogleAnalytics> pGoogleAnalytics;
	void InsertSong();
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
