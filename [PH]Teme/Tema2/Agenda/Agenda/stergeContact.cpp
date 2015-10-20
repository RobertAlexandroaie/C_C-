// stergeContact.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "stergeContact.h"
#include "afxdialogex.h"


// stergeContact dialog

IMPLEMENT_DYNAMIC(stergeContact, CDialogEx)

stergeContact::stergeContact(CWnd* pParent /*=NULL*/)
	: CDialogEx(stergeContact::IDD, pParent)
{

}

stergeContact::~stergeContact()
{
}


//se asociaza argumentele functiei variabilelor membre ale clasei curente
void stergeContact::Asociaza(Listac *ag,Nodc *nod)
{
	agenda=ag;
	nod_de_sters=nod;
}

BOOL stergeContact::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//se formuleaza textul ce va aparea in centrul dialogului
	CStatic *s=(CStatic *)this->GetDlgItem(IDC_STATIC);
	CString txt;
	txt.Append("Sunteti sigur ca doriti sa stergeti contactul: \"");
	txt.Append(nod_de_sters->informatie->getNume());
	txt.Append(" ");
	txt.Append(nod_de_sters->informatie->getPrenume());
	txt.Append("\"?");

	s->SetWindowTextA(txt);

	return true;
}

void stergeContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(stergeContact, CDialogEx)
	ON_BN_CLICKED(IDOK, &stergeContact::OnBnClickedOk)
END_MESSAGE_MAP()


// stergeContact message handlers


void stergeContact::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//in cazul in care utilizatorul este de acord, se sterge contactul ales
	agenda->StergeContact(nod_de_sters);
	CDialogEx::OnOK();
}
