#pragma once
#include "resource.h"
#include "contact.h"
#include "lista.h"

// stergeContact dialog

class stergeContact : public CDialogEx
{
	DECLARE_DYNAMIC(stergeContact)

public:
	Nodc *nod_de_sters;
	Listac *agenda;
	virtual void Asociaza(Listac *,Nodc *);
	virtual BOOL OnInitDialog();
	stergeContact(CWnd* pParent = NULL);   // standard constructor
	virtual ~stergeContact();

// Dialog Data
	enum { IDD = IDD_stergeContact };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
