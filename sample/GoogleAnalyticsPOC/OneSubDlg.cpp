// OneSubDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GoogleAnalyticsPOC.h"
#include "OneSubDlg.h"
#include "afxdialogex.h"


// OneSubDlg dialog

IMPLEMENT_DYNAMIC(OneSubDlg, CDialogEx)

OneSubDlg::OneSubDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(OneSubDlg::IDD, pParent)
{

}

OneSubDlg::~OneSubDlg()
{
}

void OneSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OneSubDlg, CDialogEx)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// OneSubDlg message handlers


BOOL OneSubDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(255, 255, 255));    // dialog background color
	CBrush *pOld = pDC->SelectObject(&myBrush);
	BOOL bRes  = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;
}
