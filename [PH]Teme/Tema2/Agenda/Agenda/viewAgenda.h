#pragma once
#include "resource.h"
#include "lista.h"
#include "contact.h"
#include "afxwin.h"

// viewAgenda dialog

class viewAgenda : public CDialogEx
{
	DECLARE_DYNAMIC(viewAgenda)

public:
	viewAgenda(CWnd* pParent = NULL);   // standard constructor
	virtual ~viewAgenda();

	virtual void ResetCB();
	Listac *agenda;
	virtual void Asociaza(Listac *);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG *pMsg);
	HACCEL hAccelerators;

// Dialog Data
	enum { IDD = IDD_viewAgenda };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox cbContacte;
	CButton bAddContact;
	afx_msg void addContact();
	CButton bEditeazaContact;
	afx_msg void editeazaContact();
	CButton bSterge;
	afx_msg void stergereContact();
	CButton bSalveaza;
	afx_msg void salveazaAgenda();
	CButton bFiltreazaContact;
	CButton bCautaContact;
	afx_msg void filtrareAgenda();
	afx_msg void schimbaContact();
	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTel;
	CEdit eAtribut;
	CEdit eTip;
	afx_msg void cautareContact();
	CButton bRefresh;
	afx_msg void refresh();
	afx_msg void Nou();
	afx_msg void Deschide();
	afx_msg void Salveaza();
	afx_msg void Inchide();
	afx_msg void Filtreaza();
	afx_msg void Cauta();
	afx_msg void Sterge();
	afx_msg void Refresh();
	afx_msg void ctrlshifts();
	afx_msg void ctrld();
	afx_msg void ctrln();
	afx_msg void ctrlx();
	afx_msg void ctrlq();
	afx_msg void ctrlr();
	afx_msg void ctrlf();
	afx_msg void ctrlshiftf();
};
