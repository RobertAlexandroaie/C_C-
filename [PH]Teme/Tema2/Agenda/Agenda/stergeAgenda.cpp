// stergeAgenda.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "stergeAgenda.h"
#include "afxdialogex.h"


// stergeAgenda dialog

IMPLEMENT_DYNAMIC(stergeAgenda, CDialogEx)

stergeAgenda::stergeAgenda(CWnd* pParent /*=NULL*/)
	: CDialogEx(stergeAgenda::IDD, pParent)
{

}

stergeAgenda::~stergeAgenda()
{
}

//se asociaza lista de agende si agenda curenta variabilelor membre ale clasei curente
void stergeAgenda::Asociaza(Listao *ags,Nodo *ag)
{
	agende=ags;
	agenda=ag;
}

void stergeAgenda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL stergeAgenda::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//se formuleaza textul ce va aparea in dialog
	CString txt;
	txt.Append("Sunteti sigur/-a ca doriti sa stergeti agenda proprietarului: \"");
	txt.Append(agenda->informatie->ownerContact.getNume());
	txt.Append(" ");
	txt.Append(agenda->informatie->ownerContact.getPrenume());
	txt.Append("\"?");

	CStatic *s=(CStatic *)this->GetDlgItem(IDC_STATIC);
	s->SetWindowTextA(txt);

	return true;
}


BEGIN_MESSAGE_MAP(stergeAgenda, CDialogEx)
	ON_BN_CLICKED(IDOK, &stergeAgenda::OnBnClickedOk)
END_MESSAGE_MAP()


// stergeAgenda message handlers


void stergeAgenda::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//in cazul acordului, se sterge agenda curenta
	agende->StergeAgenda(agenda);

	CDialogEx::OnOK();
}
