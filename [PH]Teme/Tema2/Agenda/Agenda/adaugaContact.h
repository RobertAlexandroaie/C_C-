#pragma once
#include "afxwin.h"
#include "resource.h"
#include "lista.h"
#include "contact.h"


// adaugaContact dialog

class adaugaContact : public CDialogEx
{
	DECLARE_DYNAMIC(adaugaContact)

public:
	Listac *agenda;
	virtual void Asociaza(Listac *);
	virtual BOOL OnInitDialog();
	adaugaContact(CWnd* pParent = NULL);   // standard constructor
	virtual ~adaugaContact();

// Dialog Data
	enum { IDD = IDD_adaugaContact };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	bool rNormal;
	bool rPrieten;
	bool rCunostinta;
	bool rColeg;
	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTel;
	CEdit eAtribut;
	afx_msg void selecteazaNormal();
	afx_msg void selecteazaPrieten();
	afx_msg void selecteazaCunostinta();
	afx_msg void selecteazaColeg();
	afx_msg void OnBnClickedOk();
};
