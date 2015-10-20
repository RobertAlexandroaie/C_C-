// mfc4Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Cmfc4Dlg dialog
class Cmfc4Dlg : public CDialog
{
// Construction
public:
	Cmfc4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton chk1;
	CButton chk2;
	afx_msg void OnBnClickedOk();
	CButton rd1;
	CButton rd2;
};
