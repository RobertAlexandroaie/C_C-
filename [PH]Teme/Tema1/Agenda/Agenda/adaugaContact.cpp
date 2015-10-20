// adaugaContact.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "adaugaContact.h"
#include "afxdialogex.h"
#include "contact.h"
#include "lista.h"
#include "AgendaDlg.h"

CStatic *cs;//pt eticheta atributului special
CString text;//un buffer
char t;//pt tipul contactului

// adaugaContact dialog

IMPLEMENT_DYNAMIC(adaugaContact, CDialogEx)

adaugaContact::adaugaContact(CWnd* pParent /*=NULL*/)
	: CDialogEx(adaugaContact::IDD, pParent)
{

}



void adaugaContact::Asociaza(Listac *ag)
{
	agenda=ag;//se asociaza acestei clase agenda transmisa ca parametru
}

adaugaContact::~adaugaContact()
{
}

void adaugaContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, editBoxNume);
	DDX_Control(pDX, IDC_EDIT3, editBoxPrenume);
	DDX_Control(pDX, IDC_EDIT2, editBoxNrTel);
	DDX_Control(pDX, IDC_EDIT4, editBoxSpecial);
}


BEGIN_MESSAGE_MAP(adaugaContact, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &adaugaContact::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &adaugaContact::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &adaugaContact::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &adaugaContact::OnBnClickedRadio4)
	ON_BN_CLICKED(IDOK, &adaugaContact::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &adaugaContact::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &adaugaContact::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &adaugaContact::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &adaugaContact::OnEnChangeEdit4)
END_MESSAGE_MAP()


// adaugaContact message handlers



void adaugaContact::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	//se dezactiveaza si se ascund eticheta+edit boxul specific atributului special 
	//in cazul in care adaugam un contact simplu
	cs=(CStatic*)this->GetDlgItem(IDC_STATIC);
	cs->EnableWindow(0);
	editBoxSpecial.EnableWindow(0);
	editBoxSpecial.ShowWindow(0);

	//se seteaza tipul
	t='n';
}

void adaugaContact::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	//se seteaza eticheta specifica
	cs=(CStatic*)this->GetDlgItem(IDC_STATIC);
	cs->SetWindowTextA("Categorie");
	cs->EnableWindow(1);
	editBoxSpecial.EnableWindow(1);
	editBoxSpecial.ShowWindow(1);

	//si tipul contactului
	t='c';
}

void adaugaContact::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	//similar radio2
	cs=(CStatic*)this->GetDlgItem(IDC_STATIC);
	cs->SetWindowTextA("Profesie");
	cs->EnableWindow(1);
	editBoxSpecial.EnableWindow(1);
	editBoxSpecial.ShowWindow(1);

	t='a';
}

void adaugaContact::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	//similar radio2/3
	cs=(CStatic*)this->GetDlgItem(IDC_STATIC);
	cs->SetWindowTextA("Data Nasterii");
	cs->EnableWindow(1);
	editBoxSpecial.EnableWindow(1);
	editBoxSpecial.ShowWindow(1);

	t='f';
}

void adaugaContact::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	Nodc *nod=new Nodc;//se creaza un nou nod pt lista de contacte(agenda curenta)
	nod->setTip(t);//se seteza tipul
	
	text.Empty(); editBoxSpecial.GetWindowTextA(text);//se preia textul din edit boxul pt atributul special

	//in functie de tipul de contact ales, se creeaz un cotnact de tipul respectiv, se atribuie ca informatie
	//nodului creat mai sus si se modica atributul acestuia
	if(t=='a')
	{
		Acquaintance *a=new Acquaintance;
		nod->informatie=a;
		a->setAtribut(text.GetBuffer(text.GetLength())); 
	}
	if(t=='c')
	{
		Colleague *c=new Colleague;
		nod->informatie=c;
		c->setAtribut(text.GetBuffer(text.GetLength()));
	}
	if(t=='f')
	{
		Friend *f=new Friend;
		nod->informatie=f;
		f->setAtribut(text.GetBuffer(text.GetLength()));
	}
	if(t=='n')
	{
		Contact *con=new Contact;
		nod->informatie=con;
	}
	
	//se completeaza si celelalte atribute ale contactului (nume,prenume,nrtel)
	text.Empty();
	editBoxNume.GetWindowTextA(text);
	nod->informatie->setNume(text.GetBuffer(text.GetLength()));	

	text.Empty();
	editBoxPrenume.GetWindowTextA(text);
	nod->informatie->setPrenume(text.GetBuffer(text.GetLength()));
	
	text.Empty();
	editBoxNrTel.GetWindowTextA(text);
	nod->informatie->setNrTel(text.GetBuffer(text.GetLength()));

	//se adauga in agenda contactul si tipul returnat
	agenda->AdaugaContact(*(nod->informatie),t);
	CDialogEx::OnOK();
}


void adaugaContact::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void adaugaContact::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	
}

void adaugaContact::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	
}

void adaugaContact::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
