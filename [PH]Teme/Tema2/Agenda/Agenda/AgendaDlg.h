
// AgendaDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CAgendaDlg dialog
class CAgendaDlg : public CDialogEx
{
// Construction
public:

	virtual void ResetCB();
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
	virtual BOOL PreTranslateMessage(MSG *pMsg);
	DECLARE_MESSAGE_MAP()

	HACCEL hAccelerators;
public:
	CComboBox cbProprietari;
	afx_msg void selecteazaProprietar();
	afx_msg void adaugaProprietar();
	afx_msg void salveazaProprietari();
	CButton bSalveaza;
	CButton bAdauga;
	CButton bSelecteaza;
	CButton bSterge;
	afx_msg void stergereAgenda();
	afx_msg void Nou();
	afx_msg void Deschide();
	afx_msg void SalveazaTot();
	afx_msg void SalveazaLista();
	afx_msg void Sterge();
	afx_msg void Inchide();
	afx_msg void Refresh();
	afx_msg void ctrls();
	afx_msg void ctrlshifts();
	afx_msg void ctrld();
	afx_msg void ctrln();
	afx_msg void ctrlx();
	afx_msg void ctrlq();
	afx_msg void ctrlr();
};
