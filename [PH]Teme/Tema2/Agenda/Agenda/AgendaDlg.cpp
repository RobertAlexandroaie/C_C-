
// AgendaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "AgendaDlg.h"
#include "afxdialogex.h"
#include "lista.h"
#include "contact.h"
#include <fstream>
#include "viewAgenda.h"
#include "adaugaAgenda.h"
#include "stergeAgenda.h"
#include <string>
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAgendaDlg dialog

using namespace std;
Listao agende; //declar un obiect al clasei Listao -> o lista cu noduri dublu inlantuite 
               //ce inmagazineaza agende, care sunt de asemenea liste dublu=inlantuite


CAgendaDlg::CAgendaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAgendaDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAgendaDlg::ResetCB()
{
	cbProprietari.ResetContent();
	Nodo *p;
	for(p=agende.primul;p!=NULL;p=p->urmator)
	{
		CString text;
		text.Append(p->informatie->ownerContact.getNume());
		text.Append(" ");
		text.Append(p->informatie->ownerContact.getPrenume());
		cbProprietari.AddString(text);
	}
}

void CAgendaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cbProprietari);
	DDX_Control(pDX, IDC_BUTTON2, bSalveaza);
	DDX_Control(pDX, IDC_BUTTON1, bAdauga);
	DDX_Control(pDX, IDC_BUTTON3, bSelecteaza);
	DDX_Control(pDX, IDC_BUTTON4, bSterge);
}

BEGIN_MESSAGE_MAP(CAgendaDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CAgendaDlg::selecteazaProprietar)
	ON_BN_CLICKED(IDC_BUTTON1, &CAgendaDlg::adaugaProprietar)
	ON_BN_CLICKED(IDC_BUTTON2, &CAgendaDlg::salveazaProprietari)
	ON_BN_CLICKED(IDC_BUTTON4, &CAgendaDlg::stergereAgenda)
	ON_COMMAND(ID_FISIER_NOU, &CAgendaDlg::Nou)
	ON_COMMAND(ID_FISIER_DESCHIDE, &CAgendaDlg::Deschide)
	ON_COMMAND(ID_SALVEAZA_TOT, &CAgendaDlg::SalveazaTot)
	ON_COMMAND(ID_SALVEAZA_LISTAAGENDE, &CAgendaDlg::SalveazaLista)
	ON_COMMAND(ID_EDITARE_STERGE, &CAgendaDlg::Sterge)
	ON_COMMAND(ID_FISIER_INCHIDE, &CAgendaDlg::Inchide)
	ON_COMMAND(ID_EDITARE_REFRESH, &CAgendaDlg::Refresh)
	ON_COMMAND(ID_ACCELERATOR32791, &CAgendaDlg::ctrls)
	ON_COMMAND(ID_ACCELERATOR32792, &CAgendaDlg::ctrlshifts)
	ON_COMMAND(ID_ACCELERATOR32793, &CAgendaDlg::ctrld)
	ON_COMMAND(ID_ACCELERATOR32794, &CAgendaDlg::ctrln)
	ON_COMMAND(ID_ACCELERATOR32795, &CAgendaDlg::ctrlx)
	ON_COMMAND(ID_ACCELERATOR32796, &CAgendaDlg::ctrlq)
	ON_COMMAND(ID_ACCELERATOR32798, &CAgendaDlg::ctrlr)
END_MESSAGE_MAP()


// CAgendaDlg message handlers

BOOL CAgendaDlg::PreTranslateMessage(MSG *pMsg)
{
	if(TranslateAccelerator(m_hWnd, hAccelerators, pMsg))
		return true;

	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CAgendaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	CMenu meniu;
	meniu.LoadMenuA(IDR_MENU1);
	SetMenu(&meniu);
	meniu.Detach();

	hAccelerators=LoadAccelerators(AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));

	//initializez lista de agende cu lista vida
	agende.ListaVida();
	

	//apele functia care incarca agendele dintr-un fisier standard: Proprietari.txt (ce contine pe fiecare linie 
	//detaliile unui proprietar sub forma nume|prenume , detalii ce vor fi folosite in gasirea fisierului de tipul
	//nume!prenume.txt care la randul lui contine detalii despre contacte
	agende.Start();

	//se parcurge lista de agende si se adauga in combo box numele si prenumele proprietarilor
	ResetCB();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAgendaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAgendaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAgendaDlg::selecteazaProprietar()
{
	// TODO: Add your control notification handler code here
	CString txt1,txt2;
	txt1.Empty();
	txt2.Empty();

	cbProprietari.GetLBText(cbProprietari.GetCurSel(),txt1);

	Nodo *p=agende.primul;
	while(p!=NULL&&txt1!=txt2)
	{
		txt2.Empty();
		txt2.Append(p->informatie->ownerContact.getNume());
		txt2.Append(" ");
		txt2.Append(p->informatie->ownerContact.getPrenume());
		if(txt1!=txt2)
			p=p->urmator;
	}
	
	viewAgenda *vwAg=new viewAgenda;
	vwAg->Asociaza(p->informatie);
	vwAg->DoModal();
}

void CAgendaDlg::adaugaProprietar()
{
	// TODO: Add your control notification handler code here
	adaugaAgenda *adAg=new adaugaAgenda;
	adAg->Asociaza(&agende);
	adAg->DoModal();
	
	ResetCB();
}

void CAgendaDlg::salveazaProprietari()
{
	// TODO: Add your control notification handler code here
	agende.Salveaza();
}

void CAgendaDlg::stergereAgenda()
{
	// TODO: Add your control notification handler code here
	CString txt1,txt2;
	txt1.Empty();
	txt2.Empty();

	cbProprietari.GetLBText(cbProprietari.GetCurSel(),txt1);

	Nodo *p=agende.primul;
	while(p!=NULL&&txt1!=txt2)
	{
		txt2.Empty();
		txt2.Append(p->informatie->ownerContact.getNume());
		txt2.Append(" ");
		txt2.Append(p->informatie->ownerContact.getPrenume());
		if(txt1!=txt2)
			p=p->urmator;
	}
	
	stergeAgenda *stAg=new stergeAgenda;
	stAg->Asociaza(&agende,p);
	stAg->DoModal();

	ResetCB();
}


void CAgendaDlg::Nou()
{
	// TODO: Add your command handler code here
	adaugaProprietar();
}

void CAgendaDlg::Deschide()
{
	// TODO: Add your command handler code here
	selecteazaProprietar();
}

void CAgendaDlg::SalveazaTot()
{
	// TODO: Add your command handler code here
	salveazaProprietari();
}

void CAgendaDlg::SalveazaLista()
{
	// TODO: Add your command handler code here
	
	Nodo *p;
	
	ofstream fout("Proprietari.txt");

	for(p=agende.primul;p!=NULL;p=p->urmator)
	{
		fout<<p->informatie->ownerContact.getNume()<<"|"<<p->informatie->ownerContact.getPrenume()<<"\n";
	}
	fout.close();
}

void CAgendaDlg::Sterge()
{
	// TODO: Add your command handler code here
	stergereAgenda();
}

void CAgendaDlg::Inchide()
{
	// TODO: Add your command handler code here
	OnCancel();
}

void CAgendaDlg::Refresh()
{
	// TODO: Add your command handler code here
	ResetCB();
}


void CAgendaDlg::ctrls()
{
	// TODO: Add your command handler code here
	SalveazaLista();
}


void CAgendaDlg::ctrlshifts()
{
	// TODO: Add your command handler code here
	agende.Salveaza();
}


void CAgendaDlg::ctrld()
{
	// TODO: Add your command handler code here
	selecteazaProprietar();
}


void CAgendaDlg::ctrln()
{
	// TODO: Add your command handler code here
	adaugaProprietar();
}


void CAgendaDlg::ctrlx()
{
	// TODO: Add your command handler code here
	stergereAgenda();
}


void CAgendaDlg::ctrlq()
{
	// TODO: Add your command handler code here
	OnCancel();
}


void CAgendaDlg::ctrlr()
{
	// TODO: Add your command handler code here
	ResetCB();
}
