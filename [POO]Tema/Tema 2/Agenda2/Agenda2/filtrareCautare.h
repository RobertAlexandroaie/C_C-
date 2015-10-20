#pragma once
#include "afxwin.h"
#include "model_agenda.h"
#include "model_contact.h"
#include "Agenda.h"
#include "Strategy.h"
#include "resource.h"

// filtrareCautare dialog
class ModelAgenda;
class Context;
typedef enum Strategie;

class filtrareCautare : public CDialogEx
{
	DECLARE_DYNAMIC(filtrareCautare)

public:
	filtrareCautare(CWnd* pParent = NULL);   // standard constructor
	virtual ~filtrareCautare();

	void Asociaza(ModelAgenda *ag,CComboBox *cb);
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_FILTRARECAUTARE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	Strategie t;

	ModelAgenda *agenda;
	CComboBox *cbContacte;

	bool rCautare;
	bool rFiltrare;
	CButton cPrieten;
	CButton cColeg;
	CButton cCunostinta;
	CButton cVodafone;
	CButton cOrange;
	CButton cCosmote;
	CButton cProprietar;
	CEdit eCriteriu;
	afx_msg void OnBnClickedCautare();
	afx_msg void OnBnClickedFiltrare();
	afx_msg void OnBnClickedOk();
};
