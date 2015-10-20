// mfc2Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Cmfc2Dlg dialog
class Cmfc2Dlg : public CDialog
{
// Construction
public:
	Cmfc2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC2_DIALOG };

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
	CEdit editbox;
	afx_msg void OnBnClickedOk();
};
