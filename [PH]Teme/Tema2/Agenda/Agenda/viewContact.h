#pragma once
#include "resource.h"
#include "lista.h"
#include "contact.h"
#include "afxwin.h"


// viewContact dialog

class viewContact : public CDialogEx
{
	DECLARE_DYNAMIC(viewContact)

public:
	Nodc *nod;
	virtual void Asociaza(Nodc *);
	virtual BOOL OnInitDialog();

	viewContact(CWnd* pParent = NULL);   // standard constructor
	virtual ~viewContact();

// Dialog Data
	enum { IDD = IDD_viewContact };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	bool rNormal;
	bool rPrieten;
	bool rColeg;
	bool rCunostinta;
	afx_msg void selecteazaNormal();
	afx_msg void selecteazaPrieten();
	afx_msg void selecteazaColeg();
	afx_msg void selecteazaCunostinta();
	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTel;
	CEdit eAtribut;
	afx_msg void OnBnClickedOk();
};
