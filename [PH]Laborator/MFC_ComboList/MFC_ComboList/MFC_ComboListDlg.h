
// MFC_ComboListDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFC_ComboListDlg dialog
class CMFC_ComboListDlg : public CDialogEx
{
// Construction
public:
	CMFC_ComboListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_COMBOLIST_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	CEdit EditBox;
	CButton AddButton;
	CComboBox ComboBox;
};
