#pragma once

#include "resource.h"
#include "Lista_Agende.h"
#include "model_agenda.h"

// stergeAgenda dialog

class stergeAgenda : public CDialogEx
{
	DECLARE_DYNAMIC(stergeAgenda)

public:
	stergeAgenda(CWnd* pParent = NULL);   // standard constructor
	virtual ~stergeAgenda();

	void Asociaza(AgendeSingleton *ags, ModelAgenda *ag);
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_STERGEAGENDA_DIALOG };

protected:
	AgendeSingleton *agende;
	ModelAgenda *agenda;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
