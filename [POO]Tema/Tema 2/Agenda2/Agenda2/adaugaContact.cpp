// adaugaContact.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda2.h"
#include "adaugaContact.h"
#include "afxdialogex.h"


Type t;
// adaugaContact dialog

IMPLEMENT_DYNAMIC(adaugaContact, CDialogEx)

adaugaContact::adaugaContact(CWnd* pParent /*=NULL*/)
	: CDialogEx(adaugaContact::IDD, pParent)
	, rPrieten(false)
	, rColeg(false)
	, rCunostinta(false)
{

}

adaugaContact::~adaugaContact()
{
}

void adaugaContact::Asociaza(ModelAgenda *ag)
{
	agenda=ag;
}

BOOL adaugaContact::OnInitDialog()
{	
	CDialogEx::OnInitDialog();

	eNume.SetLimitText(20);
	ePrenume.SetLimitText(20);
	eNrTelefon.SetLimitText(20);

	ControllerAdaugaContact *c=new ControllerAdaugaContact;
	c->Asociaza(agenda,this);
	this->controller=c;

	controller->start();
	return true;
}
void adaugaContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, eNume);
	DDX_Control(pDX, IDC_EDIT3, ePrenume);
	DDX_Control(pDX, IDC_EDIT5, eNrTelefon);
	DDX_Control(pDX, IDC_EDIT6, eAtribut);
}


BEGIN_MESSAGE_MAP(adaugaContact, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &adaugaContact::OnBnClickedPrieten)
	ON_BN_CLICKED(IDC_RADIO2, &adaugaContact::OnBnClickedColeg)
	ON_BN_CLICKED(IDC_RADIO3, &adaugaContact::OnBnClickedCunostinta)
	ON_BN_CLICKED(IDOK, &adaugaContact::OnBnClickedOk)
END_MESSAGE_MAP()


// adaugaContact message handlers


void adaugaContact::OnBnClickedPrieten()
{
	// TODO: Add your control notification handler code here
	controller->selecteazaPrieten();
	eAtribut.SetLimitText(10);
}


void adaugaContact::OnBnClickedColeg()
{
	// TODO: Add your control notification handler code here
	controller->selecteazaColeg();
	eAtribut.SetLimitText(20);
}


void adaugaContact::OnBnClickedCunostinta()
{
	// TODO: Add your control notification handler code here
	controller->selecteazaCunostinta();
	eAtribut.SetLimitText(20);
}


void adaugaContact::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	controller->selecteazaOk();

	CDialogEx::OnOK();
}
