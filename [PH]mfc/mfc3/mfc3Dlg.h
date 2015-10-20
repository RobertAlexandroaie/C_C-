// mfc3Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Cmfc3Dlg dialog
class Cmfc3Dlg : public CDialog
{
// Construction
public:
	Cmfc3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC3_DIALOG };

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
	CComboBox cb;
	afx_msg void OnBnClickedOk();
};
