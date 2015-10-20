#pragma once
#include "afxwin.h"
#include "stdafx.h"
#include "resource.h"
#include "Agenda2Dlg.h"
#include "Lista_Agende.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "ControllerAdaugaAgenda.h"

class ControllerAdaugaAgenda;
class AgendeSingleton;

// adaugaAgenda dialog

class adaugaAgenda : public CDialogEx
{
	DECLARE_DYNAMIC(adaugaAgenda)

public:
	adaugaAgenda(CWnd* pParent = NULL);   // standard constructor
	virtual ~adaugaAgenda();

	virtual void Asociaza(AgendeSingleton *lista_noua);
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_ADAUGAAGENDA_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	ControllerAdaugaAgenda *controller;
	AgendeSingleton *agende;
	bool rFisier;
	bool rNou;
	CEdit eFisier;
	CEdit eNume;
	CEdit ePrenume;
	CEdit eNrTel;
	afx_msg void OnBnClickedDinFisier();
	afx_msg void OnBnClickedAgendaNoua();
	afx_msg void OnBnClickedOk();
};
