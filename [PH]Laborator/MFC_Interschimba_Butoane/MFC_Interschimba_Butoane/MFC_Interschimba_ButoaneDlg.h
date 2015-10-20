
// MFC_Interschimba_ButoaneDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFC_Interschimba_ButoaneDlg dialog
class CMFC_Interschimba_ButoaneDlg : public CDialogEx
{
// Construction
public:
	CMFC_Interschimba_ButoaneDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_INTERSCHIMBA_BUTOANE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CButton BA;
	CButton B2;
	CButton BB;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
