
// MFC_CheckBox_ComboBoxDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFC_CheckBox_ComboBoxDlg dialog
class CMFC_CheckBox_ComboBoxDlg : public CDialogEx
{
// Construction
public:
	CMFC_CheckBox_ComboBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_CHECKBOX_COMBOBOX_DIALOG };

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
	CButton butonOK;
	CButton butonCancel;
	CButton check5;
	CButton check4;
	CButton check3;
	CButton check2;
	CButton check1;
	CEdit editText1;
	CEdit editText2;
	CEdit editText3;
	CEdit edittext4;
	CEdit editText5;
	CButton addButon;
	afx_msg void OnBnClickedButton1();
	CEdit editText4;
	CComboBox comboBox;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
};
