
// AgendaDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CAgendaDlg dialog
class CAgendaDlg : public CDialogEx
{
// Construction
public:
	CAgendaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_AGENDA_DIALOG };

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
	CButton butIncarcaProprietari;
	CButton butSelecteazaProprietar;
	CButton butAdaugaProprietar;
	CButton butStergeProprietar;
	CButton butSalveazaProprietari;
	CButton butAdaugaContact;
	CButton butStergeContact;
	CButton butSelecteazaContact;
	CButton butSalveazaAgenda;
	CButton butSalveazaDetalii;
	CButton butStergeCampuri;
	CComboBox comboBoxProprietari;
	CComboBox comboBoxContacte;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	CEdit editBoxName;
	CEdit editBoxPrenume;
	CEdit editBoxNrTel;
	CEdit editBoxSpecial;
	afx_msg void OnBnClickedButton6();
	CEdit editBoxNume;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton9();
	bool Normal;
	bool Coleg;
	bool Prieten;
	bool Cunostinta;
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
};
