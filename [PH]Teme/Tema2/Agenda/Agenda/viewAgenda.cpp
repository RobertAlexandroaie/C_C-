// viewAgenda.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "viewAgenda.h"
#include "afxdialogex.h"
#include "adaugaContact.h"
#include "viewContact.h"
#include "filtreazaAgenda.h"
#include "stergeContact.h"
#include "cautaContact.h"


// viewAgenda dialog

IMPLEMENT_DYNAMIC(viewAgenda, CDialogEx)

viewAgenda::viewAgenda(CWnd* pParent /*=NULL*/)
	: CDialogEx(viewAgenda::IDD, pParent)
{

}

viewAgenda::~viewAgenda()
{
}

//functia asociaza argumenul unei variabile ale clasei stergContact pt a putea folosi argumentul mai tarziu
void viewAgenda::Asociaza(Listac *ag)
{
	agenda=ag;
}


//functia reseteaza optiunile din combo box asfel inact sa coincida cu agenda pe care se lucreaza
void viewAgenda::ResetCB()
{
	cbContacte.ResetContent();
	CString txt;
	Nodc *p=agenda->primul;
	while(p!=NULL)
	{
		txt.Empty();
		txt.Append(p->informatie->getNume());
		txt.Append(" ");
		txt.Append(p->informatie->getPrenume());

		cbContacte.AddString(txt);

		p=p->urmator;
	}
}

BOOL viewAgenda::PreTranslateMessage(MSG *pMsg)
{
	if(TranslateAccelerator(m_hWnd, hAccelerators, pMsg))
		return true;

	return CDialog::PreTranslateMessage(pMsg);
}

BOOL viewAgenda::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	hAccelerators=LoadAccelerators(AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));

	//se asociaza meniul acestui dialog
	CMenu meniu;
	meniu.LoadMenuA(IDR_MENU1);
	SetMenu(&meniu);
	meniu.Detach();

	//in textul static se incarca numele prenumle si numarul de telefon al proprietarului agendei
	CStatic *s=(CStatic *)this->GetDlgItem(IDC_STATIC);
	CString txt;
	txt.Empty();
	txt.Append(agenda->ownerContact.getNume());
	txt.Append(" ");
	txt.Append(agenda->ownerContact.getPrenume());
	txt.Append(" : ");
	txt.Append(agenda->ownerContact.getNrTel());

	s->SetWindowTextA(txt);//setarea propriu-zisa


	//parcurgerea agendei si actualizarea combo boxului cu noile date 
	ResetCB();


	//campurile sunt folosite doar pentru previzualizare si nu pentru editare, prin urmare le dezactivam
	eNume.EnableWindow(0);
	ePrenume.EnableWindow(0);
	eNrTel.EnableWindow(0);
	eAtribut.EnableWindow(0);
	eTip.EnableWindow(0);
	

	return true;
}

void viewAgenda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cbContacte);
	DDX_Control(pDX, IDC_BUTTON1, bAddContact);
	DDX_Control(pDX, IDC_BUTTON2, bEditeazaContact);
	DDX_Control(pDX, IDC_BUTTON3, bSterge);
	DDX_Control(pDX, IDC_BUTTON4, bSalveaza);
	DDX_Control(pDX, IDC_BUTTON5, bFiltreazaContact);
	DDX_Control(pDX, IDC_BUTTON6, bCautaContact);
	DDX_Control(pDX, IDC_EDIT5, eNume);
	DDX_Control(pDX, IDC_EDIT6, ePrenume);
	DDX_Control(pDX, IDC_EDIT8, eNrTel);
	DDX_Control(pDX, IDC_EDIT9, eAtribut);
	DDX_Control(pDX, IDC_EDIT10, eTip);
	DDX_Control(pDX, IDC_BUTTON7, bRefresh);
}


BEGIN_MESSAGE_MAP(viewAgenda, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &viewAgenda::addContact)
	ON_BN_CLICKED(IDC_BUTTON2, &viewAgenda::editeazaContact)
	ON_BN_CLICKED(IDC_BUTTON3, &viewAgenda::stergereContact)
	ON_BN_CLICKED(IDC_BUTTON4, &viewAgenda::salveazaAgenda)
	ON_BN_CLICKED(IDC_BUTTON5, &viewAgenda::filtrareAgenda)
	ON_CBN_SELCHANGE(IDC_COMBO1, &viewAgenda::schimbaContact)
	ON_BN_CLICKED(IDC_BUTTON6, &viewAgenda::cautareContact)
	ON_BN_CLICKED(IDC_BUTTON7, &viewAgenda::refresh)
	ON_COMMAND(ID_FISIER_NOU, &viewAgenda::Nou)
	ON_COMMAND(ID_FISIER_DESCHIDE, &viewAgenda::Deschide)
	ON_COMMAND(ID_SALVEAZA_TOT, &viewAgenda::Salveaza)
	ON_COMMAND(ID_FISIER_INCHIDE, &viewAgenda::Inchide)
	ON_COMMAND(ID_FILTREAZACAUTA_FILTREAZA, &viewAgenda::Filtreaza)
	ON_COMMAND(ID_FILTREAZACAUTA_CAUTA, &viewAgenda::Cauta)
	ON_COMMAND(ID_EDITARE_STERGE, &viewAgenda::Sterge)
	ON_COMMAND(ID_EDITARE_REFRESH, &viewAgenda::Refresh)
	ON_COMMAND(ID_ACCELERATOR32792, &viewAgenda::ctrlshifts)
	ON_COMMAND(ID_ACCELERATOR32793, &viewAgenda::ctrld)
	ON_COMMAND(ID_ACCELERATOR32794, &viewAgenda::ctrln)
	ON_COMMAND(ID_ACCELERATOR32795, &viewAgenda::ctrlx)
	ON_COMMAND(ID_ACCELERATOR32796, &viewAgenda::ctrlq)
	ON_COMMAND(ID_ACCELERATOR32798, &viewAgenda::ctrlr)
	ON_COMMAND(ID_ACCELERATOR32799, &viewAgenda::ctrlf)
	ON_COMMAND(ID_ACCELERATOR32800, &viewAgenda::ctrlshiftf)
END_MESSAGE_MAP()


// viewAgenda message handlers


void viewAgenda::addContact()
{
	// TODO: Add your control notification handler code here
	
	//functia delcara un obiect de tipul adaugaContact si porneste dialogul specific, asociem agenda curenta dupa care se actualizeaza combo boxul
	adaugaContact *adC=new adaugaContact;
	adC->Asociaza(agenda);
	adC->DoModal();
	

	ResetCB();
}


void viewAgenda::editeazaContact()
{
	// TODO: Add your control notification handler code here

	//folosim doua CString pentru a prelua stringul ales din combo box si inca unul pentru a incarca datele din agenda
	CString txt1,txt2;
	txt1.Empty();
	txt2.Empty();

	cbContacte.GetLBText(cbContacte.GetCurSel(),txt1);

	//parcurgem agenda si incarcam in txt2 datele specifice, apoi comparam cu textul initial ales
	Nodc *p=agenda->primul;
	while(p!=NULL&&txt1!=txt2)
	{
		txt2.Empty();
		txt2.Append(p->informatie->getNume());
		txt2.Append(" ");
		txt2.Append(p->informatie->getPrenume());
		if(txt1!=txt2)
			p=p->urmator;
	}

	//pornim dialogul specific editarii unui contact, asociem contactul ales iar apoi actualizam combo boxul
	viewContact *vwC=new viewContact;
	vwC->Asociaza(p);
	vwC->DoModal();


	ResetCB();
}


void viewAgenda::stergereContact()
{
	// TODO: Add your control notification handler code here
	
	//folosim doua cstringuri pt a pastra stringul ales din combo box iar celalalt pt a incarca in el datele unui contact din agenda
	CString txt1,txt2;
	txt1.Empty();
	txt2.Empty();

	cbContacte.GetLBText(cbContacte.GetCurSel(),txt1);

	//parcurgem agenda si comparam stringul ales din combo box cu stringul format din datele contactului la care am ajuns
	Nodc *p=agenda->primul;
	while(p!=NULL&&txt1!=txt2)
	{
		txt2.Empty();
		txt2.Append(p->informatie->getNume());
		txt2.Append(" ");
		txt2.Append(p->informatie->getPrenume());
		if(txt1!=txt2)
			p=p->urmator;
	}

	//dupa parcurgere, asociem contactul gasit si pornim dialogul specific stergerii contactului iar apoi actualizam lista de contacte
	stergeContact *stC=new stergeContact;
	stC->Asociaza(agenda,p);
	stC->DoModal();
	ResetCB();
}


void viewAgenda::salveazaAgenda()
{
	// TODO: Add your control notification handler code here
	//apelam functia de salvare a agendei
	agenda->Salveaza();
}


void viewAgenda::filtrareAgenda()
{
	// TODO: Add your control notification handler code here
	//asociem combo boxul si agenda curenta dialogului nou creat si pornim acest dialog
	filtreazaAgenda *flAg=new filtreazaAgenda;
	flAg->Asociaza(agenda,&cbContacte);
	flAg->DoModal();
}


void viewAgenda::schimbaContact()
{
	// TODO: Add your control notification handler code here
	//la modificarea selectiei din combo box, trebuie sa actualizam campurile de previzualizare a datelor
	//se preia stringul ales din combo box si se combpara cu un altul format pentru fiecare contact
	CString txt1,txt2;
	txt1.Empty();
	txt2.Empty();

	cbContacte.GetLBText(cbContacte.GetCurSel(),txt1);
	
	
	//se parcurge lista pt a gasit contactul ce corespunde stringului ales din combo box
	Nodc *p=agenda->primul;
	while(p!=NULL&&txt1!=txt2)
	{
		txt2.Empty();
		txt2.Append(p->informatie->getNume());
		txt2.Append(" ");
		txt2.Append(p->informatie->getPrenume());
		if(txt1!=txt2)
			p=p->urmator;
	}
	
	CString txt;


	//se actualizeaza campurile pentru nume,prenume,nr tel si atribut
	txt.Empty();
	txt.Append(p->informatie->getNume());
	eNume.SetWindowTextA(txt);

	txt.Empty();
	txt.Append(p->informatie->getPrenume());
	ePrenume.SetWindowTextA(txt);

	txt.Empty();
	txt.Append(p->informatie->getNrTel());
	eNrTel.SetWindowTextA(txt);

	txt.Empty();
	char c=p->getTip();
	if(c=='n')
		txt.Append("Normal");
	if(c=='a')
		txt.Append("Cunostinta");
	if(c=='c')
		txt.Append("Coleg");
	if(c=='f')
		txt.Append("Prieten");
	eTip.SetWindowTextA(txt);

	txt.Empty();
	txt.Append(p->informatie->getAtribut());
	eAtribut.SetWindowTextA(txt);
}


void viewAgenda::cautareContact()
{
	// TODO: Add your control notification handler code here
	//se asociaza comboboxul si agenda curenta iar apoi pornim dialogul pentru cautare
	cautaContact *ctC=new cautaContact;
	ctC->Asociaza(agenda,&cbContacte);
	ctC->DoModal();
}


void viewAgenda::refresh()
{
	// TODO: Add your control notification handler code here
	//se apeleaza functia de actualizare a comboboxului
	ResetCB();
}


void viewAgenda::Nou()
{
	// TODO: Add your command handler code here
	//se apeleaza din meniu functia de adaugare a unui contact 
	addContact();
}


void viewAgenda::Deschide()
{
	// TODO: Add your command handler code here
	//se apeleaza din meniu functia de editare a unui contact
	editeazaContact();
}


void viewAgenda::Salveaza()
{
	// TODO: Add your command handler code here
	//se apeleaza din meniu functia de salvare a agendei
	salveazaAgenda();
}


void viewAgenda::Inchide()
{
	// TODO: Add your command handler code here
	//se apeleaza din meniu functia de inchidere a dialogului
	OnCancel();
}


void viewAgenda::Filtreaza()
{
	// TODO: Add your command handler code here
	//se apeleaza din meniu functia de filtrare a agendei
	filtrareAgenda();
}


void viewAgenda::Cauta()
{
	// TODO: Add your command handler code here
	//se apeleaza din meniu functia de cautare a unui contact
	cautareContact();
}


void viewAgenda::Sterge()
{
	// TODO: Add your command handler code here
	//se apeleaza din meniu functia de stergere a unui contact
	stergereContact();
}


void viewAgenda::Refresh()
{
	// TODO: Add your command handler code here
	//se apeleaza din meniu functia de actualizare a comboboxului
	ResetCB();
}


//accelerator pentru salvare totala;
void viewAgenda::ctrlshifts()
{
	// TODO: Add your command handler code here
	salveazaAgenda();
}

//accelerator pentru editarea contactului
void viewAgenda::ctrld()
{
	// TODO: Add your command handler code here
	editeazaContact();
}

//accelerator pentru adaugarea unui contact
void viewAgenda::ctrln()
{
	// TODO: Add your command handler code here
	addContact();
}

//accelerator petru stergerea contactului
void viewAgenda::ctrlx()
{
	// TODO: Add your command handler code here
	stergereContact();
}

//accelerator pentru inchiderea dialogului
void viewAgenda::ctrlq()
{
	// TODO: Add your command handler code here
	OnCancel();
}

//accelerator pentru actualizarea comboboxului
void viewAgenda::ctrlr()
{
	// TODO: Add your command handler code here
	ResetCB();
}

//accelerator pentru filtrarea comboboxului
void viewAgenda::ctrlf()
{
	// TODO: Add your command handler code here
	filtrareAgenda();
}

//accelerator pentru cautarea unui contact
void viewAgenda::ctrlshiftf()
{
	// TODO: Add your command handler code here
	cautareContact();
}
