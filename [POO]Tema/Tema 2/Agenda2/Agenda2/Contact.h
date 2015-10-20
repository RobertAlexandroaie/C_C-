#pragma once
#include "afxwin.h"
#include "resource.h"
#include "model_contact.h"
#include "ControllerContact.h"

class ControllerContact;
class ModelContact;
// Contact dialog

class Contact : public CDialogEx
{
	DECLARE_DYNAMIC(Contact)

public:
	Contact(CWnd* pParent = NULL);   // standard constructor
	virtual ~Contact();

	void Asociaza(ModelContact *c);
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_CONTACT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	ModelContact *contact;
	ControllerContact *controller;
	Type t;

	bool rPrieten;
	bool rColeg;
	bool rCunostinta;
	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTel;
	CEdit eAtribut;
	afx_msg void OnBnClickedPrieten();
	afx_msg void OnBnClickedColeg();
	afx_msg void OnBnClickedCunostinta();
	afx_msg void OnBnClickedOk();
};
