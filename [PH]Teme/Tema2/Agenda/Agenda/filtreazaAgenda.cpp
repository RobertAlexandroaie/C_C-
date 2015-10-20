// filtreazaAgenda.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "filtreazaAgenda.h"
#include "afxdialogex.h"


// filtreazaAgenda dialog

IMPLEMENT_DYNAMIC(filtreazaAgenda, CDialogEx)

filtreazaAgenda::filtreazaAgenda(CWnd* pParent /*=NULL*/)
	: CDialogEx(filtreazaAgenda::IDD, pParent)
{

}

filtreazaAgenda::~filtreazaAgenda()
{
}

//se face asocierea argumentelor 
void filtreazaAgenda::Asociaza(Listac *ag, CComboBox *cb)
{
	agenda=ag;
	comboBoxContacte=cb;
}

void filtreazaAgenda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, cNormal);
	DDX_Control(pDX, IDC_CHECK2, cPrieten);
	DDX_Control(pDX, IDC_CHECK3, cColeg);
	DDX_Control(pDX, IDC_CHECK4, cCunostinta);
	DDX_Control(pDX, IDC_CHECK5, cOrange);
	DDX_Control(pDX, IDC_CHECK6, cVodafone);
	DDX_Control(pDX, IDC_CHECK7, cCosmote);
	DDX_Control(pDX, IDC_CHECK8, cProprietar);
	DDX_Control(pDX, IDC_EDIT2, eAtribut);
}


BEGIN_MESSAGE_MAP(filtreazaAgenda, CDialogEx)
	ON_BN_CLICKED(IDOK, &filtreazaAgenda::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL filtreazaAgenda::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	return true;
}


// filtreazaAgenda message handlers


void setTxt(CString &text, Nodc *p)
{
	//se seteaza text dat ca argument cu numele si prenumele celui de-al doilea argument
	text.Empty();
	text.Append(p->informatie->getNume());
	text.Append(" ");
	text.Append(p->informatie->getPrenume());
}

void filtreazaAgenda::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	Nodc *p;
	p=agenda->primul;

	Listac *aux;
	Listac *aux2;

	comboBoxContacte->ResetContent();

	CString txt;

	//in cauzul in care toate casutele sunt bifate sau toate debifate agenda auxiliara in care se va cauta un anumit numar de telefon este chiar agenda originala
	if(cNormal.GetCheck()==cPrieten.GetCheck()&&cPrieten.GetCheck()==cColeg.GetCheck()&&cColeg.GetCheck()==cCunostinta.GetCheck())
	{
		aux=agenda;
	}
	else //altfel formam o noua lista cu nodurile ce au tipurile selectate prin bifare
	{	
		aux=new Listac;
		aux->ListaVida();
		while(p!=NULL)
		{
			if((cNormal.GetCheck()==BST_CHECKED)&&(p->getTip()=='n')) aux->AdaugaContact(*p->informatie,'n');
			if((cPrieten.GetCheck()==BST_CHECKED)&&(p->getTip()=='f')) aux->AdaugaContact(*p->informatie, 'f');
			if((cColeg.GetCheck()==BST_CHECKED)&&(p->getTip()=='c')) aux->AdaugaContact(*p->informatie, 'c');
			if((cCunostinta.GetCheck()==BST_CHECKED)&&(p->getTip()=='a')) aux->AdaugaContact(*p->informatie, 'a');

			p=p->urmator;
		}
	}

	p=aux->primul;

	//daca toate tipurile de telefon sunt bifate/debifate <=> agenda auxiliara secundara in care cautam un anumit atribut este agenda secundara principala
	if(cOrange.GetCheck()==cVodafone.GetCheck()&&cVodafone.GetCheck()==cCosmote.GetCheck()&&cCosmote.GetCheck()==cProprietar.GetCheck())
	{
		aux2=aux;
	}
	else //altfel mai formam o agenda din agenda precedenta, agenda ce va contine contacte de tipurile bifate si cu numerele de telefon din reteaua bifate
	{
		aux2=new Listac;
		aux2->ListaVida();

		while(p!=NULL)
		{
			char c=p->getTip();
			if((cOrange.GetCheck()==BST_CHECKED)&&(p->informatie->getNrTel()[2]=='4'||p->informatie->getNrTel()[2]=='5')) aux2->AdaugaContact(*p->informatie,c);
			if((cVodafone.GetCheck()==BST_CHECKED)&&(p->informatie->getNrTel()[2]=='2'||p->informatie->getNrTel()[2]=='3')) aux2->AdaugaContact(*p->informatie,c);
			if((cCosmote.GetCheck()==BST_CHECKED)&&(p->informatie->getNrTel()[2]=='6')) aux2->AdaugaContact(*p->informatie,c);
			if((cProprietar.GetCheck()==BST_CHECKED)&&(p->informatie->getNrTel()[2]==agenda->ownerContact.getNrTel()[2])) aux2->AdaugaContact(*p->informatie,c);
			p=p->urmator;
		}
	}
	eAtribut.GetWindowTextA(txt);
	CString txt2;

	//se parcurge lista in cautarea unor contacte ce corespund atributului scris in edit box, in cazul in care este scris ceva altfel se incarca in 
	//combo box contactele din agenda auxiliara
	p=aux2->primul;
	if(!txt.IsEmpty())
	{
		while(p!=NULL)
		{
			if(strstr(p->informatie->getAtribut(),txt.GetBuffer(txt.GetLength()))!=NULL)
			{
				setTxt(txt2,p);
				comboBoxContacte->AddString(txt2);
			}
			p=p->urmator;
		}
	}
	else
	{
		while(p!=NULL)
		{
			setTxt(txt2,p);
			comboBoxContacte->AddString(txt2);
			p=p->urmator;
		}
	}


	CDialogEx::OnOK();
}
