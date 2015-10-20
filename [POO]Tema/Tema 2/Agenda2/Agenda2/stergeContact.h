#pragma once

#include "resource.h"
#include "model_agenda.h"
#include "model_contact.h"

// stergeContact dialog

class stergeContact : public CDialogEx
{
	DECLARE_DYNAMIC(stergeContact)

public:
	stergeContact(CWnd* pParent = NULL);   // standard constructor
	virtual ~stergeContact();

	void Asociaza(ModelAgenda *ag, ModelContact *con);
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_STERGECONTACT_DIALOG };

protected:
	ModelAgenda *agenda;
	ModelContact *contact;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
