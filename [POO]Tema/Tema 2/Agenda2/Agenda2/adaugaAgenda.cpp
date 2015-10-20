// adaugaAgenda.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda2.h"
#include "adaugaAgenda.h"
#include "afxdialogex.h"


// adaugaAgenda dialog

IMPLEMENT_DYNAMIC(adaugaAgenda, CDialogEx)

adaugaAgenda::adaugaAgenda(CWnd* pParent /*=NULL*/)
	: CDialogEx(adaugaAgenda::IDD, pParent)
	, rFisier(false)
	, rNou(false)
{

}

adaugaAgenda::~adaugaAgenda()
{
}

void adaugaAgenda::Asociaza(AgendeSingleton *lista_noua)
{
	agende=lista_noua;
	
}

BOOL adaugaAgenda::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	eNume.SetLimitText(20);
	ePrenume.SetLimitText(20);
	eNrTel.SetLimitText(20);

	eFisier.EnableWindow(0);
	eNume.EnableWindow(0);
	ePrenume.EnableWindow(0);
	eNrTel.EnableWindow(0);

	
	ControllerAdaugaAgenda *c=new ControllerAdaugaAgenda;
	c->Asociaza(agende,this);
	this->controller=c;

	return true;
}

void adaugaAgenda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, eFisier);
	DDX_Control(pDX, IDC_EDIT2, eNume);
	DDX_Control(pDX, IDC_EDIT3, ePrenume);
	DDX_Control(pDX, IDC_EDIT4, eNrTel);
}


BEGIN_MESSAGE_MAP(adaugaAgenda, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &adaugaAgenda::OnBnClickedDinFisier)
	ON_BN_CLICKED(IDC_RADIO2, &adaugaAgenda::OnBnClickedAgendaNoua)
	ON_BN_CLICKED(IDOK, &adaugaAgenda::OnBnClickedOk)
END_MESSAGE_MAP()


// adaugaAgenda message handlers


void adaugaAgenda::OnBnClickedDinFisier()
{
	// TODO: Add your control notification handler code here
	controller->selectareDinFisier();
}


void adaugaAgenda::OnBnClickedAgendaNoua()
{
	// TODO: Add your control notification handler code here
	controller->selectareNou();
}


void adaugaAgenda::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	controller->selectareOK();

	CDialogEx::OnOK();
}
