// viewContact.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "viewContact.h"
#include "afxdialogex.h"


// viewContact dialog

CString n,p,nr,a;

IMPLEMENT_DYNAMIC(viewContact, CDialogEx)


viewContact::viewContact(CWnd* pParent /*=NULL*/)
	: CDialogEx(viewContact::IDD, pParent)
	, rNormal(false)
	, rPrieten(false)
	, rColeg(false)
	, rCunostinta(false)
{

}

viewContact::~viewContact()
{
}


//functia face asocierea membrului clasei cu argumentul functiei pentru a putea folosi argumentul mai tarziu. 
void viewContact::Asociaza(Nodc *n)
{
	nod=n;
}

void viewContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, eNume);
	DDX_Control(pDX, IDC_EDIT7, ePrenume);
	DDX_Control(pDX, IDC_EDIT2, eNrTel);
	DDX_Control(pDX, IDC_EDIT3, eAtribut);
}


BEGIN_MESSAGE_MAP(viewContact, CDialogEx)	
	ON_BN_CLICKED(IDC_RADIO1, &viewContact::selecteazaNormal)
	ON_BN_CLICKED(IDC_RADIO5, &viewContact::selecteazaPrieten)
	ON_BN_CLICKED(IDC_RADIO6, &viewContact::selecteazaColeg)
	ON_BN_CLICKED(IDC_RADIO7, &viewContact::selecteazaCunostinta)
	ON_BN_CLICKED(IDOK, &viewContact::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL viewContact::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	//se seteaza limita de caractere pt campuri
	eNume.SetLimitText(20);
	ePrenume.SetLimitText(20);
	eNrTel.SetLimitText(20);
	eAtribut.SetLimitText(20);


	//se preia in txt datele specifice unui contact si se seteaza in campurile de editare pentru nume
	CString txt;
	txt.Append(nod->informatie->getNume());					//aici se preia si se seteaza numele
	eNume.SetWindowTextA(txt);

	txt.Empty();
	txt.Append(nod->informatie->getPrenume());				//aici se preia si se seteaza prenumele
	ePrenume.SetWindowTextA(txt);

	txt.Empty();
	txt.Append(nod->informatie->getNrTel());				//aici se preia si se seteaza numarul de telefon
	eNrTel.SetWindowTextA(txt);

	char t=nod->getTip();
	CStatic *s=(CStatic*)this->GetDlgItem(IDC_STATIC);		//pt atributul special, avem nevoie de un CStatic * pentru a putea modifica textul dintr-un
															//static text
	if(t=='n')												
	{
		selecteazaNormal();
		s->ShowWindow(0);									//pt un contact normal, se ignora(se face invizibil) campul special (labelul si editboxul)
		eAtribut.ShowWindow(0);
	}
	else
	{
		txt.Empty();
		txt.Append(nod->informatie->getAtribut());
		eAtribut.ShowWindow(1);
		eAtribut.SetWindowTextA(txt);
	}

	if(t=='f')
	{
		selecteazaPrieten();
		s->ShowWindow(1);								
		s->SetWindowTextA("Data nasterii");					//se seteaza labelul specific atributului special pt Prieten
	}
	if(t=='a')
	{
		selecteazaCunostinta();
		s->ShowWindow(1);									//se seteaza labelul specific atributului special pt Cunostinta
		s->SetWindowTextA("Profesia");
	}
	if(t=='c')
	{
		selecteazaColeg();
		s->ShowWindow(1);									//se seteaza labelul specific atributului special pt Coleg
		s->SetWindowTextA("Categoria");
	}
	
	//rolul initializarii este de a incarca datele contactului ales pt editare

	return true;
}


// viewContact message handlers


void viewContact::selecteazaNormal()
{
	// TODO: Add your control notification handler code here

	//pt selectia unui contact de tip normal, se seteaza tipul contactului si variabila de tip bool = true iar restul false
	//apoi se face invizibil editboxul si labelul specific atributului (contactul de tip normal nu are atribut special) 
	rNormal=true;
	rColeg=rPrieten=rCunostinta=false;
	nod->setTip('n');

	CStatic *s=(CStatic*)this->GetDlgItem(IDC_STATIC);
	s->ShowWindow(0);
	eAtribut.ShowWindow(0);
}


void viewContact::selecteazaPrieten()
{
	// TODO: Add your control notification handler code here
	//setam variabilele bool si tipul nodului
	rPrieten=true;
	rColeg=rNormal=rCunostinta=false;
	nod->setTip('f');


	//modificam labelul si editboxul pt atribuul special specific unui Prieten
	CStatic *s=(CStatic*)this->GetDlgItem(IDC_STATIC);
	s->ShowWindow(1);
	s->SetWindowTextA("Data nasterii");
	eAtribut.ShowWindow(1);
}


void viewContact::selecteazaColeg()
{
	// TODO: Add your control notification handler code here
	
	//asemanator ca la Prieten
	rColeg=true;
	rNormal=rPrieten=rCunostinta=false;
	nod->setTip('c');

	CStatic *s=(CStatic*)this->GetDlgItem(IDC_STATIC);
	s->ShowWindow(1);
	s->SetWindowTextA("Categoria");
	eAtribut.ShowWindow(1);
}


void viewContact::selecteazaCunostinta()
{
	// TODO: Add your control notification handler code here
	
	//asemanator ca la Prieten
	rCunostinta=true;
	rColeg=rPrieten=rNormal=false;
	nod->setTip('a');

	CStatic *s=(CStatic*)this->GetDlgItem(IDC_STATIC);
	s->ShowWindow(1);
	s->SetWindowTextA("Profesia");
	eAtribut.ShowWindow(1);
}


void viewContact::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	//La apasarea butonului ok se preiau datele din editboxuri si se atribuie unui contact de tipul ales (in cazul in care a fost modificat)

	//preluarea datelor
	eNume.GetWindowTextA(n);
	ePrenume.GetWindowTextA(p);
	eNrTel.GetWindowTextA(nr);
	if(eAtribut.IsWindowEnabled()&&eAtribut.IsWindowVisible())
		eAtribut.GetWindowTextA(a);


	//verificarea radiourilor si in functie de schimbare, crearea si setarea contactului nou ales
	if(rNormal)
	{
		nod->setTip('n');
		Contact *c=new Contact;
		
		c->setNume(n.GetBuffer(n.GetLength()));
		c->setPrenume(p.GetBuffer(p.GetLength()));
		c->setNrTel(nr.GetBuffer(nr.GetLength()));
		nod->informatie=c;
	}
	else
		if(rPrieten)
		{
			nod->setTip('f');
			Friend *fr=new Friend;
		
			fr->setNume(n.GetBuffer(n.GetLength()));
			fr->setPrenume(p.GetBuffer(p.GetLength()));
			fr->setNrTel(nr.GetBuffer(nr.GetLength()));
			fr->setAtribut(a.GetBuffer(a.GetLength()));
			nod->informatie=fr;		
		}
		else
			if(rColeg)
			{
				nod->setTip('c');
				Colleague *col=new Colleague;
		
				col->setNume(n.GetBuffer(n.GetLength()));
				col->setPrenume(p.GetBuffer(p.GetLength()));
				col->setNrTel(nr.GetBuffer(nr.GetLength()));
				col->setAtribut(a.GetBuffer(a.GetLength()));
				nod->informatie=col;			
			}
			else
				if(rCunostinta)
				{
					nod->setTip('a');
					Acquaintance *aq=new Acquaintance;
		
					aq->setNume(n.GetBuffer(n.GetLength()));
					aq->setPrenume(p.GetBuffer(p.GetLength()));
					aq->setNrTel(nr.GetBuffer(nr.GetLength()));
					aq->setAtribut(a.GetBuffer(a.GetLength()));
					nod->informatie=aq;
				}
	
	CDialogEx::OnOK();
}
