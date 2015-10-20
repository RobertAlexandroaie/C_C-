#pragma once
#include "resource.h"
#include "lista.h"
#include "AgendaDlg.h"
#include "afxwin.h"

// adaugaProprietar dialog

class adaugaProprietar : public CDialogEx
{
	DECLARE_DYNAMIC(adaugaProprietar)

public:
	Listao *proprietari;

	adaugaProprietar(CWnd* pParent = NULL);   // standard constructor
	virtual void Asociaza(Listao *);
	virtual ~adaugaProprietar();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit ediBoxFisier;
	CEdit editBoxNume;
	CEdit editBoxPrenume;
	CEdit editBoxNrTel;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
};
