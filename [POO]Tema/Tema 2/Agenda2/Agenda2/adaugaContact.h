#pragma once
#include "afxwin.h"
#include "resource.h"
#include "model_contact.h"
#include "model_agenda.h"
#include "ControllerAdaugaContact.h"

class ControllerAdaugaContact;

// adaugaContact dialog
class adaugaContact : public CDialogEx
{
	DECLARE_DYNAMIC(adaugaContact)

public:
	adaugaContact(CWnd* pParent = NULL);   // standard constructor
	virtual ~adaugaContact();

	void Asociaza(ModelAgenda *ag);
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_ADAUGACONTACT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	ModelAgenda *agenda;
	ControllerAdaugaContact *controller;
	Type t;

	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTelefon;
	CEdit eAtribut;
	bool rPrieten;
	bool rColeg;
	bool rCunostinta;
	afx_msg void OnBnClickedPrieten();
	afx_msg void OnBnClickedColeg();
	afx_msg void OnBnClickedCunostinta();
	afx_msg void OnBnClickedOk();
};
