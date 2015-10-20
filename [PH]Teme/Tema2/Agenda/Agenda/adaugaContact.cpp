// adaugaContact.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "adaugaContact.h"
#include "afxdialogex.h"


// adaugaContact dialog


IMPLEMENT_DYNAMIC(adaugaContact, CDialogEx)

CStatic *s;

adaugaContact::adaugaContact(CWnd* pParent /*=NULL*/)
	: CDialogEx(adaugaContact::IDD, pParent)
	, rNormal(false)
	, rPrieten(false)
	, rCunostinta(false)
	, rColeg(false)
{

}

adaugaContact::~adaugaContact()
{
}

void adaugaContact::Asociaza(Listac *ag)
{
	agenda=ag;
}

BOOL adaugaContact::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	eNume.EnableWindow(0);
	ePrenume.EnableWindow(0);
	eNrTel.EnableWindow(0);
	eAtribut.EnableWindow(0);

	s=(CStatic*)this->GetDlgItem(IDC_STATIC);
	return true;
}


void adaugaContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, eNume);
	DDX_Control(pDX, IDC_EDIT4, ePrenume);
	DDX_Control(pDX, IDC_EDIT5, eNrTel);
	DDX_Control(pDX, IDC_EDIT6, eAtribut);
}


BEGIN_MESSAGE_MAP(adaugaContact, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &adaugaContact::selecteazaNormal)
	ON_BN_CLICKED(IDC_RADIO3, &adaugaContact::selecteazaPrieten)
	ON_BN_CLICKED(IDC_RADIO2, &adaugaContact::selecteazaCunostinta)
	ON_BN_CLICKED(IDC_RADIO4, &adaugaContact::selecteazaColeg)
	ON_BN_CLICKED(IDOK, &adaugaContact::OnBnClickedOk)
END_MESSAGE_MAP()


// adaugaContact message handlers


void adaugaContact::selecteazaNormal()
{
	// TODO: Add your control notification handler code here
	rNormal=true;
	rColeg=rPrieten=rCunostinta=false;

	eAtribut.ShowWindow(0);
	s->ShowWindow(0);

	
	eNume.EnableWindow(1);
	ePrenume.EnableWindow(1);
	eNrTel.EnableWindow(1);
}


void adaugaContact::selecteazaPrieten()
{
	// TODO: Add your control notification handler code 
	rPrieten=true;
	rNormal=rColeg=rCunostinta=false;

	s->ShowWindow(1);
	s->SetWindowTextA("Data nasterii");
	eAtribut.ShowWindow(1);

	
	eNume.EnableWindow(1);
	ePrenume.EnableWindow(1);
	eNrTel.EnableWindow(1);
	eAtribut.EnableWindow(1);
}


void adaugaContact::selecteazaCunostinta()
{
	// TODO: Add your control notification handler code here
	
	rCunostinta=true;
	rNormal=rColeg=rPrieten=false;

	s->ShowWindow(1);
	s->SetWindowTextA("Profesia");
	eAtribut.ShowWindow(1);

	
	eNume.EnableWindow(1);
	ePrenume.EnableWindow(1);
	eNrTel.EnableWindow(1);
	eAtribut.EnableWindow(1);
}


void adaugaContact::selecteazaColeg()
{
	// TODO: Add your control notification handler code here	
	rColeg=true;
	rNormal=rCunostinta=rPrieten=false;

	s->ShowWindow(1);
	s->SetWindowTextA("Categoria");
	eAtribut.ShowWindow(1);

	
	eNume.EnableWindow(1);
	ePrenume.EnableWindow(1);
	eNrTel.EnableWindow(1);
	eAtribut.EnableWindow(1);
}


void adaugaContact::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString n,p,nr,a;
	
	eNume.GetWindowTextA(n);
	ePrenume.GetWindowTextA(p);
	eNrTel.GetWindowTextA(nr);
	eAtribut.GetWindowTextA(a);
	
	if(rNormal)
	{
		Contact *con=new Contact;
		con->setNrTel(nr.GetBuffer(nr.GetLength()));
		con->setNume(n.GetBuffer(n.GetLength()));
		con->setPrenume(p.GetBuffer(p.GetLength()));
		agenda->AdaugaContact(*con,'n');
	}
	else
		if(rPrieten)
		{
			Friend *fr=new Friend;
			fr->setNrTel(nr.GetBuffer(nr.GetLength()));
			fr->setNume(n.GetBuffer(n.GetLength()));
			fr->setPrenume(p.GetBuffer(p.GetLength()));
			fr->setAtribut(a.GetBuffer(a.GetLength()));
			agenda->AdaugaContact(*fr,'f');
		}
		else
			if(rColeg)
			{
				Colleague *col=new Colleague;
				col->setNrTel(nr.GetBuffer(nr.GetLength()));
				col->setNume(n.GetBuffer(n.GetLength()));
				col->setPrenume(p.GetBuffer(p.GetLength()));
				col->setAtribut(a.GetBuffer(a.GetLength()));
				agenda->AdaugaContact(*col,'c');
			}
			else
				if(rCunostinta)
				{
					Acquaintance *aq=new Acquaintance;
					aq->setNrTel(nr.GetBuffer(nr.GetLength()));
					aq->setNume(n.GetBuffer(n.GetLength()));
					aq->setPrenume(p.GetBuffer(p.GetLength()));
					aq->setAtribut(a.GetBuffer(a.GetLength()));
					agenda->AdaugaContact(*aq,'a');
				}


	CDialogEx::OnOK();
}
