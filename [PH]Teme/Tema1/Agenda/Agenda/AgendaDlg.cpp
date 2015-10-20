
// AgendaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "AgendaDlg.h"
#include "afxdialogex.h"
#include "lista.h"
#include "contact.h"
#include <fstream>
#include "adaugaContact.h"
#include "adaugaProprietar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAgendaDlg dialog

using namespace std;
Listao agende; //declar un obiect al clasei Listao -> o lista cu noduri dublu inlantuite 
               //ce inmagazineaza agende, care sunt de asemenea liste dublu=inlantuite

CAgendaDlg::CAgendaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAgendaDlg::IDD, pParent)
	, Normal(false)
	, Coleg(false)
	, Prieten(false)
	, Cunostinta(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAgendaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON4, butStergeContact);
	DDX_Control(pDX, IDC_BUTTON5, butSalveazaDetalii);
	DDX_Control(pDX, IDC_BUTTON7, butStergeProprietar);
	DDX_Control(pDX, IDC_BUTTON8, butSalveazaAgenda);
	DDX_Control(pDX, IDC_BUTTON9, butAdaugaProprietar);
	DDX_Control(pDX, IDC_BUTTON10, butAdaugaContact);
	DDX_Control(pDX, IDC_BUTTON11, butSalveazaProprietari);
	DDX_Control(pDX, IDC_COMBO1, comboBoxProprietari);
	DDX_Control(pDX, IDC_COMBO2, comboBoxContacte);
	DDX_Control(pDX, IDC_EDIT1, editBoxNume);
	DDX_Control(pDX, IDC_EDIT2, editBoxPrenume);
	DDX_Control(pDX, IDC_EDIT3, editBoxNrTel);
	DDX_Control(pDX, IDC_EDIT4, editBoxSpecial);
}

BEGIN_MESSAGE_MAP(CAgendaDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAgendaDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CAgendaDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON5, &CAgendaDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CAgendaDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON4, &CAgendaDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CAgendaDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON11, &CAgendaDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &CAgendaDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CAgendaDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_RADIO4, &CAgendaDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO1, &CAgendaDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CAgendaDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CAgendaDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()

// CAgendaDlg message handlers

BOOL CAgendaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	
	editBoxNume.SetLimitText(20);
	editBoxPrenume.SetLimitText(20);
	editBoxNrTel.SetLimitText(20);
	editBoxSpecial.SetLimitText(20);



	//dezactivez elementele din interfata grafica ce nu ar avea vreun efect inaintea 
	//selectarii unei agende din primul Combo Box
	butSalveazaAgenda.EnableWindow(0);
	butAdaugaContact.EnableWindow(0);
	butStergeContact.EnableWindow(0);
	comboBoxContacte.EnableWindow(0);

	butSalveazaDetalii.EnableWindow(0);
	editBoxNume.EnableWindow(0);
	editBoxPrenume.EnableWindow(0);
	editBoxNrTel.EnableWindow(0);
	editBoxSpecial.EnableWindow(0);

	//initializez lista de agende cu lista vida
	agende.ListaVida();
	

	//apele functia care incarca agendele dintr-un fisier standard: Proprietari.txt (ce contine pe fiecare linie 
	//detaliile unui proprietar sub forma nume|prenume , detalii ce vor fi folosite in gasirea fisierului de tipul
	//nume!prenume.txt care la randul lui contine detalii despre contacte
	agende.Start();

	//se parcurge lista de agende si se adauga in primul combo box numele si prenumele proprietarilor
	Nodo *p;
	for(p=agende.primul;p!=NULL;p=p->urmator)
	{
		CString text;
		text.Append(p->informatie->ownerContact.getNume());
		text.Append(" ");
		text.Append(p->informatie->ownerContact.getPrenume());
		comboBoxProprietari.AddString(text);
	}
	
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

void CAgendaDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	//se activeaza butoanele si combo box-ul pentru contacte
	butSalveazaAgenda.EnableWindow(1);
	butAdaugaContact.EnableWindow(1);
	butStergeContact.EnableWindow(1);
	comboBoxContacte.EnableWindow(1);

	comboBoxContacte.ResetContent();

	//se ia pozitia sirului selectat din combo box
	int poz;
	poz=comboBoxProprietari.GetCurSel();
	poz++;//se incrementeaza pentru a se sincroniza cu ordinea din lista (care ia valori de la 1 la n)
	
	
	//se parcurg contactele agendei din pozitia poz si se adauga numele si prenumele contactelor in 
	//cel de-al doilea combo box
	Nodc *p;
	for(p=agende.getAgenda(poz)->primul;p!=NULL;p=p->urmator)
	{
		CString text;
		text.Append(p->informatie->getNume());
		text.Append(" ");
		text.Append(p->informatie->getPrenume());
		comboBoxContacte.AddString(text);
	}

	butSalveazaDetalii.EnableWindow(0);
	editBoxNume.EnableWindow(0);
	editBoxPrenume.EnableWindow(0);
	editBoxNrTel.EnableWindow(0);
	editBoxSpecial.EnableWindow(0);
}

void CAgendaDlg::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	
	//se activeaza campurile specifice detaliilor contactelor si butoanele aferente
	butSalveazaDetalii.EnableWindow(1);
	editBoxNume.EnableWindow(1);
	editBoxPrenume.EnableWindow(1);
	editBoxNrTel.EnableWindow(1);
	editBoxSpecial.EnableWindow(1);

	//se salveaza pozitia sirului selectat din cel de-al doilea combo box (numele si prenumele unui contact)
	int poz;
	poz=comboBoxContacte.GetCurSel();
	poz++;

	//se selecteaza nodul din lista de contacte (agenda) care corespunde pozitiei salvate mai sus
	Nodc *c=agende.getAgenda(comboBoxProprietari.GetCurSel()+1)->getContact(poz);


	//se creeaza pointerul CStatic pt modificarea unui static text
	CStatic *s;
	s=(CStatic*)this->GetDlgItem(IDC_STATIC);
	
	CString text; 
	char t=c->getTip();//se identifica tipul contactului


	//textul static (eticheta ultimului camp) se modifica in functie de fiecare tip de contact in parte
	switch(t)
	{
		case 'a': s->EnableWindow(1); editBoxSpecial.EnableWindow(1); text.Append("Profesie"); break;
		case 'f': s->EnableWindow(1); editBoxSpecial.EnableWindow(1); text.Append("Zi nastere"); break;
		case 'c': s->EnableWindow(1); editBoxSpecial.EnableWindow(1); text.Append("Categorie"); break;
		case 'n': s->EnableWindow(0); editBoxSpecial.EnableWindow(0); break;
	}

	if(t!='n') s->SetWindowTextA(text);

	//se incarca edit boxurile cu detaliile contactului (nume, prenume, nr tel, camp special)
	text.Empty();
	text.Append(c->informatie->getNume());
	editBoxNume.SetWindowTextA(text);

	text.Empty();
	text.Append(c->informatie->getPrenume());
	editBoxPrenume.SetWindowTextA(text);

	text.Empty();
	text.Append(c->informatie->getNrTel());
	editBoxNrTel.SetWindowTextA(text);

	text.Empty();
	text.Append(c->informatie->getAtribut());
	editBoxSpecial.SetWindowTextA(text);
}

void CAgendaDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	CStatic *s=(CStatic*)this->GetDlgItem(IDC_STATIC);
	CString text;

	int pozp=comboBoxProprietari.GetCurSel()+1;
	int pozc=comboBoxContacte.GetCurSel()+1;

	//se selecteaza contactul corespunzator stringului selectat in cel de-al doilea combo box
	Nodc *c=agende.getAgenda(pozp)->getContact(pozc);

	//se modifica detaliile contactului respectiv corespunzator fiecarui edit box in parte 
	editBoxNume.GetWindowTextA(text);
	c->informatie->setNume(text.GetBuffer(text.GetLength()));

	editBoxPrenume.GetWindowTextA(text);
	c->informatie->setPrenume(text.GetBuffer(text.GetLength()));

	editBoxNrTel.GetWindowTextA(text);
	c->informatie->setNrTel(text.GetBuffer(text.GetLength()));

	editBoxSpecial.GetWindowTextA(text);
	c->informatie->setAtribut(text.GetBuffer(text.GetLength()));

	if(Normal) { s->EnableWindow(0); c->setTip('n'); }
	if(Coleg) { s->SetWindowTextA("Categorie"); c->setTip('c'); }
	if(Cunostinta) { s->SetWindowTextA("Profesie"); c->setTip('a'); }
	if(Prieten) { s->SetWindowTextA("Zi de nastere"); c->setTip('f'); }
	
	OnCbnSelchangeCombo1();
	text.Empty();
	text.Append(c->informatie->getNume());
	text.Append(" ");
	text.Append(c->informatie->getPrenume());
	comboBoxContacte.SetWindowText(text);

	//se activeaza campurile specifice detaliilor contactelor si butoanele aferente
	butSalveazaDetalii.EnableWindow(1);
	editBoxNume.EnableWindow(1);
	editBoxPrenume.EnableWindow(1);
	editBoxNrTel.EnableWindow(1);
	editBoxSpecial.EnableWindow(1);

}

void CAgendaDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	//se apeleaza functia de salvare a agendei curente
	agende.getAgenda(comboBoxProprietari.GetCurSel()+1)->Salveaza();
}

void CAgendaDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	//Evenimentul sterge un contact din lista si din combo box(al doilea)
	if(comboBoxContacte.GetCount()>0)
	{
		int poz=comboBoxContacte.GetCurSel()+1;//se ia pozitia din combo box si se adapteaza la lista(prin incrementare)
		comboBoxContacte.DeleteString(poz-1);//se sterge stringul din combo box

		agende.getAgenda(comboBoxProprietari.GetCurSel()+1)->setP(poz);//se seteaza pozitia in lista 
		agende.getAgenda(comboBoxProprietari.GetCurSel()+1)->StergeContact();//pentru a se "cunoaste" care !nod! trebuie sters
	}
}

void CAgendaDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	//evenimentul sterge o agenda in totalitate (si din combo box si din lista de agende si fisierul .txt specific
	if(comboBoxProprietari.GetCount()>0)//se verifica daca avem ce sterge
	{
		int poz=comboBoxProprietari.GetCurSel()+1;//se ia pozitia
		CString fisier;

		//se formeaza fisierul
		fisier.Append(agende.getAgenda(poz)->ownerContact.getNume());
		fisier.Append("!");
		fisier.Append(agende.getAgenda(poz)->ownerContact.getPrenume());
		fisier.Append(".txt");

		comboBoxProprietari.DeleteString(poz-1);//se sterge stringul
		comboBoxProprietari.Clear();
		CFile::Remove(fisier);//se sterge fisierul de pe hard
		agende.setPoz(poz);//se seteaza pozitia in lista de agende
		agende.StergeAgenda();//se sterge agenda din lista
	}
	else
		comboBoxProprietari.Clear();
}

void CAgendaDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	//se apeleaza functia de salvare a listei de agende
	agende.Salveaza();
}

void CAgendaDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	//Evenimentul declanseaza un nou dialog pentru a putea creea conditiile necesare adaugarii unui nou contact
	//se creeaza obiectul din clasa adaugaContact 
	adaugaContact *addC=new adaugaContact();

	//se asociaza acestui obiect agenda curenta pentru care se adauga contactul
	addC->Asociaza(agende.getAgenda(comboBoxProprietari.GetCurSel()+1));
	
	//se declanseaza dialogul nou
	addC->DoModal();
	
	//se actualizeaza al doilea combo box prin reapelarea evenimentului de selectie a unei agende din primul combo box
	CAgendaDlg::OnCbnSelchangeCombo1();
}

void CAgendaDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	//Evenimentul declanseaza un nou dialog, asemanator celui pt adaugarea unui contact
	//se creeaza un obiect al clasei adaugaProprietar
	adaugaProprietar *addP=new adaugaProprietar;
	
	//se asociaza lista de agende
	addP->Asociaza(&agende);
	
	//se declanseaza dialogul
	addP->DoModal();
	
	//se reseateaza primul combo box 
	comboBoxProprietari.ResetContent();

	//se reactualizeaza combo boxul cu noii proprietari (o lista ce contine si ultimul proprietar adaugat)
	Nodo *p;
	for(p=agende.primul;p!=NULL;p=p->urmator)
	{
		CString text;
		text.Append(p->informatie->ownerContact.getNume());
		text.Append(" ");
		text.Append(p->informatie->ownerContact.getPrenume());
		comboBoxProprietari.AddString(text);
	}
}

void CAgendaDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	Normal=true;
	Coleg=false;
	Cunostinta=false;
	Prieten=false;
}

void CAgendaDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	
	Normal=false;
	Coleg=true;
	Cunostinta=false;
	Prieten=false;
}

void CAgendaDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	
	Normal=false;
	Coleg=false;
	Cunostinta=false;
	Prieten=true;
}

void CAgendaDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	
	Normal=false;
	Coleg=false;
	Cunostinta=true;
	Prieten=false;
}
