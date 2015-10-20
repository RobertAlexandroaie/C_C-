// stergeContact.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda2.h"
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

void stergeContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void stergeContact::Asociaza(ModelAgenda *ag, ModelContact *con)
{
	agenda=ag;
	contact=con;
}

BOOL stergeContact::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CStatic *s=(CStatic *)this->GetDlgItem(IDC_STATIC);
	CString av;

	av=_T("Sunteti sigur ca doriti sa stergeti contactul: \"")+contact->toCStringnp()+_T("\" ?");
	s->SetWindowTextA(av);

	return true;
}

BEGIN_MESSAGE_MAP(stergeContact, CDialogEx)
	ON_BN_CLICKED(IDOK, &stergeContact::OnBnClickedOk)
END_MESSAGE_MAP()


// stergeContact message handlers


void stergeContact::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	agenda->Contacte.remove(contact);

	CDialogEx::OnOK();
}
