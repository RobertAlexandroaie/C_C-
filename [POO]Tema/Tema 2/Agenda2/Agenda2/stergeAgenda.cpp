// stergeAgenda.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda2.h"
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

void stergeAgenda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void stergeAgenda::Asociaza(AgendeSingleton *ags, ModelAgenda *ag)
{
	agende=ags;
	agenda=ag;
}

BOOL stergeAgenda::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CStatic *s=(CStatic *)this->GetDlgItem(IDC_STATIC);
	CString nume_ag=agenda->toCStringnp();
	CString av;
	av=(_T("Sunteti sigur ca doriti sa stergeti agenda proprietarului: \""))+nume_ag+(_T("\" ?"));

	s->SetWindowTextA(av);
	return true;
}

BEGIN_MESSAGE_MAP(stergeAgenda, CDialogEx)
	ON_BN_CLICKED(IDOK, &stergeAgenda::OnBnClickedOk)
END_MESSAGE_MAP()


// stergeAgenda message handlers


void stergeAgenda::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	agende->Agende.remove(agenda);

	CDialogEx::OnOK();
}
