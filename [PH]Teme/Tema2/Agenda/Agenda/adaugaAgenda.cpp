// adaugaAgenda.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "adaugaAgenda.h"
#include "afxdialogex.h"


Listac *ag_noua=new Listac;

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

void adaugaAgenda::Asociaza(Listao *ag)
{
	agende=ag;
}

BOOL adaugaAgenda::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	eCale.EnableWindow(0);
	eNume.EnableWindow(0);
	ePrenume.EnableWindow(0);
	eNrTel.EnableWindow(0);

	return true;
}

void adaugaAgenda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, eCale);
	DDX_Control(pDX, IDC_EDIT2, eNume);
	DDX_Control(pDX, IDC_EDIT3, ePrenume);
	DDX_Control(pDX, IDC_EDIT4, eNrTel);
}


BEGIN_MESSAGE_MAP(adaugaAgenda, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &adaugaAgenda::selecteazaDinFisier)
	ON_BN_CLICKED(IDC_RADIO2, &adaugaAgenda::selecteazaNou)
	ON_BN_CLICKED(IDOK, &adaugaAgenda::OnBnClickedOk)
END_MESSAGE_MAP()


// adaugaAgenda message handlers


void adaugaAgenda::selecteazaDinFisier()
{
	// TODO: Add your control notification handler code here
	rFisier=true;
	rNou=false;

	eCale.EnableWindow(1);
	eNume.EnableWindow(0);
	ePrenume.EnableWindow(0);
	eNrTel.EnableWindow(0);
}

void adaugaAgenda::selecteazaNou()
{
	// TODO: Add your control notification handler code here
	rFisier=false;
	rNou=true;

	
	eCale.EnableWindow(0);
	eNume.EnableWindow(1);
	ePrenume.EnableWindow(1);
	eNrTel.EnableWindow(1);
}

void adaugaAgenda::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if(rFisier==true)
	{
		CString fisier;
		eCale.GetWindowTextA(fisier);
		if(fisier=="")
		{
			CString x;
			x.Append("Camp gol!");
			MessageBox(x,"",MB_ICONINFORMATION);
		}
		else
		{
			fisier.Append(".txt");
			ag_noua->Incarca(fisier.GetBuffer(fisier.GetLength()));
			agende->AdaugaAgenda(ag_noua);
		}
	}
	else
		if(rNou==true)
		{
			CString txt;
			
			eNume.GetWindowTextA(txt);
			ag_noua->ownerContact.setNume(txt.GetBuffer(txt.GetLength()));

			txt.Empty();
			ePrenume.GetWindowTextA(txt);
			ag_noua->ownerContact.setPrenume(txt.GetBuffer(txt.GetLength()));

			txt.Empty();
			eNrTel.GetWindowTextA(txt);
			ag_noua->ownerContact.setNrTel(txt.GetBuffer(txt.GetLength()));
		}
	
	agende->AdaugaAgenda(ag_noua);
	CDialogEx::OnOK();
}
