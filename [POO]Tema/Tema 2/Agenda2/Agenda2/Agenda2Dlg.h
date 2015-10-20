
// Agenda2Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Agenda.h"
#include "Lista_Agende.h"
#include "ControllerPrincipal.h"

class ControllerPrincipal;

// CAgenda2Dlg dialog
class CAgenda2Dlg : public CDialogEx
{
// Construction
public:
	CAgenda2Dlg(CWnd* pParent = NULL);	// standard constructor
	

// Dialog Data
	enum { IDD = IDD_AGENDA2_DIALOG };

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
	bool Modificare;
	ControllerPrincipal *controller;

	CComboBox cbAgende;
	CButton bAgendaNoua;
	CButton bDeschideAgenda;
	CButton bSalveazaAgendele;
	CButton bStergeAgenda;
	afx_msg void OnBnClickedAgendaNoua();
	afx_msg void OnBnClickedDeschideAgenda();
	afx_msg void OnBnClickedSalveazaAgendele();
	afx_msg void OnBnClickedStergeAgenda();
	CButton bSalveazaLista;
	afx_msg void OnBnClickedSalveazaLista();
	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTel;
	afx_msg void OnCbnSelchangeAgenda();
	afx_msg void OnBnClickedOk();
};
