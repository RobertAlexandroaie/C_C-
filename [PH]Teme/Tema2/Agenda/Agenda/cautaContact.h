#pragma once
#include "afxwin.h"
#include "resource.h"
#include "lista.h"
#include "contact.h"

// cautaContact dialog

class cautaContact : public CDialogEx
{
	DECLARE_DYNAMIC(cautaContact)

public:
	Listac *agenda;
	CComboBox *cbContacte;
	virtual void Asociaza(Listac *, CComboBox *);
	virtual BOOL OnInitDialog();
	cautaContact(CWnd* pParent = NULL);   // standard constructor
	virtual ~cautaContact();

// Dialog Data
	enum { IDD = IDD_CautaContact };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit eCriteriu;
	afx_msg void OnBnClickedOk();
};
