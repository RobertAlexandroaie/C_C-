#pragma once
#include "afxwin.h"
#include "resource.h"
#include "lista.h"
#include "contact.h"

// adaugaAgenda dialog

class adaugaAgenda : public CDialogEx
{
	DECLARE_DYNAMIC(adaugaAgenda)

public:
	adaugaAgenda(CWnd* pParent = NULL);   // standard constructor
	virtual ~adaugaAgenda();

	Listao *agende;
	virtual void Asociaza(Listao *);
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_adaugaAgenda };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit eCale;
	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTel;
	bool rFisier;
	bool rNou;
	afx_msg void selecteazaDinFisier();
	afx_msg void selecteazaNou();
	afx_msg void OnBnClickedOk();
};
