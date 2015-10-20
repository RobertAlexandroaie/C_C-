// cautaContact.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "cautaContact.h"
#include "afxdialogex.h"


// cautaContact dialog

IMPLEMENT_DYNAMIC(cautaContact, CDialogEx)

cautaContact::cautaContact(CWnd* pParent /*=NULL*/)
	: CDialogEx(cautaContact::IDD, pParent)
{

}

BOOL cautaContact::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	return true;
}

void cautaContact::Asociaza(Listac *ag, CComboBox *cb)
{
	agenda=ag;
	cbContacte=cb;
}

cautaContact::~cautaContact()
{
}

void cautaContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, eCriteriu);
}


BEGIN_MESSAGE_MAP(cautaContact, CDialogEx)
	ON_BN_CLICKED(IDOK, &cautaContact::OnBnClickedOk)
END_MESSAGE_MAP()


// cautaContact message handlers


void cautaContact::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	//se preia in txt textul din edit box
	CString txt;
	eCriteriu.GetWindowTextA(txt);

	CString resToken[4];
	int curPos = 0;
	
	//se imparte textul din edit box in cuvinte (siruri de caractere ce nu contin spatiu)
	resToken[0]= txt.Tokenize(_T(" "),curPos);
	int i=0;
	while (resToken[i] != _T(""))
	{
		i++;
		resToken[i] = txt.Tokenize(_T(" "), curPos);
	}

	//se resetea combo boxul
	cbContacte->ResetContent();

	Nodc *p;
	p=agenda->primul;
	
	bool ok=false;

	while(p!=NULL)
	{
		ok=false;
		CString nume,prenume,nrtel,atribut;

		nume.Empty(); prenume.Empty(); nrtel.Empty(); atribut.Empty();

		nume.Append(p->informatie->getNume());
		prenume.Append(p->informatie->getPrenume());
		nrtel.Append(p->informatie->getNrTel());
		atribut.Append(p->informatie->getAtribut());
		txt=nume+_T(" ")+prenume;
		for(i=0;resToken[i] != _T("");i++)
		{
			
			if(nume.Find(resToken[i])!=-1||prenume.Find(resToken[i])!=-1||nrtel.Find(resToken[i])!=-1||atribut.Find(resToken[i])!=-1)
				ok=true;
		}
		
		if(ok)
			cbContacte->AddString(txt);
		p=p->urmator;
	}


	CDialogEx::OnOK();
}
