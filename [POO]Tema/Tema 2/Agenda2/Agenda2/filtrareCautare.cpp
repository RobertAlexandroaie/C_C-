// filtrareCautare.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda2.h"
#include "filtrareCautare.h"
#include "afxdialogex.h"


// filtrareCautare dialog

IMPLEMENT_DYNAMIC(filtrareCautare, CDialogEx)

filtrareCautare::filtrareCautare(CWnd* pParent /*=NULL*/)
	: CDialogEx(filtrareCautare::IDD, pParent)
	, rCautare(false)
	, rFiltrare(false)
{

}

filtrareCautare::~filtrareCautare()
{
}

void filtrareCautare::Asociaza(ModelAgenda *ag,CComboBox *cb)
{
	agenda=ag;
	cbContacte=cb;
}

BOOL filtrareCautare::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	eCriteriu.EnableWindow(0);
	cPrieten.EnableWindow(0);
	cColeg.EnableWindow(0);
	cCunostinta.EnableWindow(0);
	cVodafone.EnableWindow(0);
	cOrange.EnableWindow(0);
	cCosmote.EnableWindow(0);
	cProprietar.EnableWindow(0);

	return true;
}

void filtrareCautare::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, cPrieten);
	DDX_Control(pDX, IDC_CHECK2, cColeg);
	DDX_Control(pDX, IDC_CHECK3, cCunostinta);
	DDX_Control(pDX, IDC_CHECK4, cVodafone);
	DDX_Control(pDX, IDC_CHECK5, cOrange);
	DDX_Control(pDX, IDC_CHECK6, cCosmote);
	DDX_Control(pDX, IDC_CHECK7, cProprietar);
	DDX_Control(pDX, IDC_EDIT1, eCriteriu);
}


BEGIN_MESSAGE_MAP(filtrareCautare, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &filtrareCautare::OnBnClickedCautare)
	ON_BN_CLICKED(IDC_RADIO2, &filtrareCautare::OnBnClickedFiltrare)
	ON_BN_CLICKED(IDOK, &filtrareCautare::OnBnClickedOk)
END_MESSAGE_MAP()


// filtrareCautare message handlers


void filtrareCautare::OnBnClickedCautare()
{
	// TODO: Add your control notification handler code here
	rCautare=true;
	rFiltrare=false;

	eCriteriu.EnableWindow(1);
	cPrieten.EnableWindow(0);
	cColeg.EnableWindow(0);
	cCunostinta.EnableWindow(0);
	cVodafone.EnableWindow(0);
	cOrange.EnableWindow(0);
	cCosmote.EnableWindow(0);
	cProprietar.EnableWindow(0);

	t=cautare;
}

void filtrareCautare::OnBnClickedFiltrare()
{
	// TODO: Add your control notification handler code here
	rCautare=false;
	rFiltrare=true;

	eCriteriu.EnableWindow(0);
	cPrieten.EnableWindow(1);
	cColeg.EnableWindow(1);
	cCunostinta.EnableWindow(1);
	cVodafone.EnableWindow(1);
	cOrange.EnableWindow(1);
	cCosmote.EnableWindow(1);
	cProprietar.EnableWindow(1);

	t=filtrare;
}

void filtrareCautare::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	Context contextt(t);
	contextt.Asociaza(agenda,this);
	contextt.DoStrategy();

	CDialogEx::OnOK();
}
