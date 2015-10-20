// Contact.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda2.h"
#include "Contact.h"
#include "afxdialogex.h"


// Contact dialog

IMPLEMENT_DYNAMIC(Contact, CDialogEx)

Contact::Contact(CWnd* pParent /*=NULL*/)
	: CDialogEx(Contact::IDD, pParent)
	, rPrieten(false)
	, rColeg(false)
	, rCunostinta(false)
{

}

Contact::~Contact()
{
}

void Contact::Asociaza(ModelContact *c)
{
	contact=c;
}

BOOL Contact::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	eNume.SetLimitText(20);
	ePrenume.SetLimitText(20);
	eNrTel.SetLimitText(20);


	ControllerContact *c=new ControllerContact;
	c->Asociaza(contact,this);
	this->controller=c;

	switch(contact->getTip())
	{
		case Friend: controller->selecteazaPrieten(); break;
		case Colleague: controller->selecteazaColeg(); break;
		case Acquaintance: controller->selecteazaCunostinta(); break;
	}

	c->start();
	return true;
}

void Contact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, eNume);
	DDX_Control(pDX, IDC_EDIT3, ePrenume);
	DDX_Control(pDX, IDC_EDIT4, eNrTel);
	DDX_Control(pDX, IDC_EDIT7, eAtribut);
}


BEGIN_MESSAGE_MAP(Contact, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &Contact::OnBnClickedPrieten)
	ON_BN_CLICKED(IDC_RADIO2, &Contact::OnBnClickedColeg)
	ON_BN_CLICKED(IDC_RADIO3, &Contact::OnBnClickedCunostinta)
	ON_BN_CLICKED(IDOK, &Contact::OnBnClickedOk)
END_MESSAGE_MAP()


// Contact message handlers


void Contact::OnBnClickedPrieten()
{
	// TODO: Add your control notification handler code here
	controller->selecteazaPrieten();
	eNrTel.SetLimitText(10);
}


void Contact::OnBnClickedColeg()
{
	// TODO: Add your control notification handler code here
	controller->selecteazaColeg();
	eNrTel.SetLimitText(20);
}


void Contact::OnBnClickedCunostinta()
{
	// TODO: Add your control notification handler code here
	controller->selecteazaCunostinta();
	eNrTel.SetLimitText(20);
}


void Contact::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	controller->selecteazaOk();
	CDialogEx::OnOK();
}
