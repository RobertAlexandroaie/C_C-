// adaugaProprietar.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "adaugaProprietar.h"
#include "afxdialogex.h"

CString txt;//un buffer
Listac *agenda_noua=new Listac;// se creeaza agenda noua

// adaugaProprietar dialog

IMPLEMENT_DYNAMIC(adaugaProprietar, CDialogEx)

adaugaProprietar::adaugaProprietar(CWnd* pParent /*=NULL*/)
	: CDialogEx(adaugaProprietar::IDD, pParent)
{

}

void adaugaProprietar::Asociaza(Listao *lpr)
{
	proprietari=lpr;//se asociaza lista de proprietari(lista de agende)
}

adaugaProprietar::~adaugaProprietar()
{
}

void adaugaProprietar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, ediBoxFisier);
	DDX_Control(pDX, IDC_EDIT2, editBoxNume);
	DDX_Control(pDX, IDC_EDIT3, editBoxPrenume);
	DDX_Control(pDX, IDC_EDIT4, editBoxNrTel);
}


BEGIN_MESSAGE_MAP(adaugaProprietar, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &adaugaProprietar::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &adaugaProprietar::OnBnClickedRadio2)
	ON_BN_CLICKED(IDOK, &adaugaProprietar::OnBnClickedOk)
END_MESSAGE_MAP()


// adaugaProprietar message handlers


void adaugaProprietar::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	
	//se activeaza, in functie de tipul de adaugare selectat (din fisier sau de la tastatura), edit boxurile specifice
	ediBoxFisier.EnableWindow(1);//pt numele fisierului

	editBoxNume.EnableWindow(0);//pt numele proprietarului
	editBoxPrenume.EnableWindow(0);//pt prenumele acestuia
	editBoxNrTel.EnableWindow(0);//pt numarul de telefon
}

void adaugaProprietar::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	//similar cu radio1 numai ca se inverseaza zonele vizibile
	//corespuznator alegerii adaugarii unui proprietar de la tastatura

	ediBoxFisier.EnableWindow(0);

	editBoxNume.EnableWindow(1);
	editBoxPrenume.EnableWindow(1);
	editBoxNrTel.EnableWindow(1);
}

void adaugaProprietar::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	//se initializeaza o agenda noua (pt noul proprietar)
	agenda_noua->ListaVida();

	//in funcite de zonele vizibile, se prelucreaza datele
	if(ediBoxFisier.IsWindowEnabled())
	{
		ediBoxFisier.GetWindowTextA(txt);//se ia fisierul din primul edit box
		agenda_noua->Incarca(txt.GetBuffer(txt.GetLength()));//se incarca agenda cu detaliile din fisierul selectat
	}
	else
	{
		editBoxNume.GetWindowTextA(txt);//se ia numele 
		agenda_noua->ownerContact.setNume(txt.GetBuffer(txt.GetLength()));
		
		editBoxPrenume.GetWindowTextA(txt);//prenumele
		agenda_noua->ownerContact.setPrenume(txt.GetBuffer(txt.GetLength()));

		editBoxNrTel.GetWindowTextA(txt);//si numarul de telefon
		agenda_noua->ownerContact.setNrTel(txt.GetBuffer(txt.GetLength()));

		//si se seteaza imediat ca atribute ale noului proprietar
	}
	
	proprietari->AdaugaAgenda(agenda_noua);//se adauga in lista de agende acest nou proprietar

	CDialogEx::OnOK();
}
