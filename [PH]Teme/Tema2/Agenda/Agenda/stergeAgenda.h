#pragma once
#include "resource.h"
#include "lista.h"
#include "contact.h"


// stergeAgenda dialog

class stergeAgenda : public CDialogEx
{
	DECLARE_DYNAMIC(stergeAgenda)

public:
	Listao *agende;
	Nodo *agenda;
	virtual void Asociaza(Listao *,Nodo *);
	virtual BOOL OnInitDialog();
	stergeAgenda(CWnd* pParent = NULL);   // standard constructor
	virtual ~stergeAgenda();

// Dialog Data
	enum { IDD = IDD_stergeAgenda };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
