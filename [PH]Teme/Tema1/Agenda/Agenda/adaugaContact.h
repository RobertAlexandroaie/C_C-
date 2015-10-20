#pragma once
#include "afxwin.h"
#include "AgendaDlg.h"
#include "resource.h"
#include "lista.h"


// adaugaContact dialog

class adaugaContact : public CDialogEx
{
	DECLARE_DYNAMIC(adaugaContact)

public:
	Listac *agenda;

	adaugaContact(CWnd* pParent = NULL);   // standard constructor
	virtual void Asociaza(Listac *);
	virtual ~adaugaContact();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit editBoxNume;
	CEdit editBoxPrenume;
	CEdit editBoxNrTel;
	CEdit editBoxSpecial;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit4();
};
