#pragma once
#include "resource.h"
#include "lista.h"
#include "contact.h"
#include "afxwin.h"


// filtreazaAgenda dialog

class filtreazaAgenda : public CDialogEx
{
	DECLARE_DYNAMIC(filtreazaAgenda)

public:
	Listac *agenda;
	CComboBox *comboBoxContacte;

	virtual void Asociaza(Listac *,CComboBox *);
	virtual BOOL OnInitDialog();

	filtreazaAgenda(CWnd* pParent = NULL);   // standard constructor
	virtual ~filtreazaAgenda();

// Dialog Data
	enum { IDD = IDD_filtreazaAgenda };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton cNormal;
	CButton cPrieten;
	CButton cColeg;
	CButton cCunostinta;
	CButton cOrange;
	CButton cVodafone;
	CButton cCosmote;
	CButton cProprietar;
	CEdit eAtribut;
	afx_msg void OnBnClickedOk();
};
