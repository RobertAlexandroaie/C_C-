// Agenda.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda2.h"
#include "Agenda.h"
#include "afxdialogex.h"


// Agenda dialog

IMPLEMENT_DYNAMIC(Agenda, CDialogEx)

Agenda::Agenda(CWnd* pParent /*=NULL*/)
	: CDialogEx(Agenda::IDD, pParent)
{

}

Agenda::~Agenda()
{
}

void Agenda::Asociaza(ModelAgenda *ag)
{
	agenda=ag;
}

BOOL Agenda::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Modificare=false;

	eTip.EnableWindow(0);
	eNume.EnableWindow(0);
	ePrenume.EnableWindow(0);
	eNrTel.EnableWindow(0);
	eAtribut.EnableWindow(0);

	ControllerAgenda *c=new ControllerAgenda;
	c->Asociaza(agenda,this);
	this->controller=c;

	controller->start();

	return true;
}

void Agenda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cbContacte);
	DDX_Control(pDX, IDC_BUTTON1, bContactNou);
	DDX_Control(pDX, IDC_BUTTON2, bEditeazaContact);
	DDX_Control(pDX, IDC_BUTTON3, bSalvareContacte);
	DDX_Control(pDX, IDC_BUTTON4, bInterogareContacte);
	DDX_Control(pDX, IDC_BUTTON5, bStergeContact);
	DDX_Control(pDX, IDC_BUTTON6, bRefresh);
	DDX_Control(pDX, IDC_EDIT4, eTip);
	DDX_Control(pDX, IDC_EDIT7, eNume);
	DDX_Control(pDX, IDC_EDIT5, ePrenume);
	DDX_Control(pDX, IDC_EDIT6, eNrTel);
	DDX_Control(pDX, IDC_EDIT8, eAtribut);
}

BEGIN_MESSAGE_MAP(Agenda, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Agenda::OnBnClickedContactNou)
	ON_BN_CLICKED(IDC_BUTTON2, &Agenda::OnBnClickedEditeazaContact)
	ON_BN_CLICKED(IDC_BUTTON3, &Agenda::OnBnClickedSalvareContacte)
	ON_BN_CLICKED(IDC_BUTTON4, &Agenda::OnBnClickedFiltCaut)
	ON_BN_CLICKED(IDC_BUTTON5, &Agenda::OnBnClickedstergeContact)
	ON_BN_CLICKED(IDC_BUTTON6, &Agenda::OnBnClickedRefresh)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Agenda::OnCbnSelchangeContact)
	ON_BN_CLICKED(IDOK, &Agenda::OnBnClickedOk)
END_MESSAGE_MAP()


// Agenda message handlers


void Agenda::OnBnClickedContactNou()
{
	// TODO: Add your control notification handler code here
	controller->contactNou();
	Modificare=true;
}


void Agenda::OnBnClickedEditeazaContact()
{
	// TODO: Add your control notification handler code here
	controller->editeazaContact();
	Modificare=true;
}

void Agenda::OnBnClickedSalvareContacte()
{
	// TODO: Add your control notification handler code here
	controller->salvareContacte();
	Modificare=false;
}

void Agenda::OnBnClickedFiltCaut()
{
	// TODO: Add your control notification handler code here
	controller->FilCaut();
}

void Agenda::OnBnClickedstergeContact()
{
	// TODO: Add your control notification handler code here
	controller->stergereContact();
	Modificare=true;
}

void Agenda::OnBnClickedRefresh()
{
	// TODO: Add your control notification handler code here
	controller->start();
}

void Agenda::OnCbnSelchangeContact()
{
	// TODO: Add your control notification handler code here
	controller->incarcaDetalii();
}


void Agenda::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	bool ok=false;

	if(Modificare==true)
		if(MessageBox("Doriti sa salvati modificarile?","Informare",MB_ICONINFORMATION|MB_CANCELTRYCONTINUE)==11)
		{
			controller->salvareContacte();
			Modificare=false;
		}

	CDialogEx::OnOK();
}
