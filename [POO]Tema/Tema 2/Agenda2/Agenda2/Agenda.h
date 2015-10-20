#pragma once
#include "afxwin.h"
#include "resource.h"
#include "Agenda2Dlg.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "ControllerAgenda.h"
#include "Strategy.h"
#include "filtrareCautare.h"

class ControllerAgenda;

// Agenda dialog

class Agenda : public CDialogEx
{
	DECLARE_DYNAMIC(Agenda)

public:
	Agenda(CWnd* pParent = NULL);   // standard constructor
	virtual ~Agenda();


	void Asociaza(ModelAgenda *ag);
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_AGENDA_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	bool Modificare;
	ModelAgenda *agenda;
	ControllerAgenda *controller;
	CComboBox cbContacte;
	CButton bContactNou;
	CButton bEditeazaContact;
	CButton bSalvareContacte;
	CButton bInterogareContacte;
	CButton bStergeContact;
	afx_msg void OnBnClickedContactNou();
	afx_msg void OnBnClickedEditeazaContact();
	afx_msg void OnBnClickedSalvareContacte();
	afx_msg void OnBnClickedFiltCaut();
	afx_msg void OnBnClickedstergeContact();
	CButton bRefresh;
	afx_msg void OnBnClickedRefresh();
	CEdit eTip;
	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTel;
	CEdit eAtribut;
	afx_msg void OnCbnSelchangeContact();
	afx_msg void OnBnClickedOk();
};
