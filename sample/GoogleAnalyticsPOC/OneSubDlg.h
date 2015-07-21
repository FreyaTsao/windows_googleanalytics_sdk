#pragma once


// OneSubDlg dialog

class OneSubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(OneSubDlg)

public:
	OneSubDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~OneSubDlg();

// Dialog Data
	enum { IDD = IDD_DLG_ONE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
