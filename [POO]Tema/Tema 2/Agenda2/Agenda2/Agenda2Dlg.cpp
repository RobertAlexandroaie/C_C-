
// Agenda2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda2.h"
#include "Agenda2Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAgenda2Dlg dialog


AgendeSingleton *Agende=new AgendeSingleton;

CAgenda2Dlg::CAgenda2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAgenda2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAgenda2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cbAgende);
	DDX_Control(pDX, IDC_BUTTON1, bAgendaNoua);
	DDX_Control(pDX, IDC_BUTTON2, bDeschideAgenda);
	DDX_Control(pDX, IDC_BUTTON3, bSalveazaAgendele);
	DDX_Control(pDX, IDC_BUTTON4, bStergeAgenda);
	DDX_Control(pDX, IDC_BUTTON5, bSalveazaLista);
	DDX_Control(pDX, IDC_EDIT3, eNume);
	DDX_Control(pDX, IDC_EDIT4, ePrenume);
	DDX_Control(pDX, IDC_EDIT7, eNrTel);
}

BEGIN_MESSAGE_MAP(CAgenda2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAgenda2Dlg::OnBnClickedAgendaNoua)
	ON_BN_CLICKED(IDC_BUTTON2, &CAgenda2Dlg::OnBnClickedDeschideAgenda)
	ON_BN_CLICKED(IDC_BUTTON3, &CAgenda2Dlg::OnBnClickedSalveazaAgendele)
	ON_BN_CLICKED(IDC_BUTTON4, &CAgenda2Dlg::OnBnClickedStergeAgenda)
	ON_BN_CLICKED(IDC_BUTTON5, &CAgenda2Dlg::OnBnClickedSalveazaLista)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAgenda2Dlg::OnCbnSelchangeAgenda)
	ON_BN_CLICKED(IDOK, &CAgenda2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAgenda2Dlg message handlers

BOOL CAgenda2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	Modificare=false;

	eNume.EnableWindow(0);
	ePrenume.EnableWindow(0);
	eNrTel.EnableWindow(0);

	Agende->incarca();
	ControllerPrincipal *c=new ControllerPrincipal;
	c->Asociaza(Agende,this);
	this->controller=c;

	controller->incarcaAgendeInCB();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAgenda2Dlg::OnPaint()
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
HCURSOR CAgenda2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAgenda2Dlg::OnBnClickedAgendaNoua()
{
	// TODO: Add your control notification handler code here
	controller->agendaNoua();
	Modificare=true;
}

void CAgenda2Dlg::OnBnClickedDeschideAgenda()
{
	// TODO: Add your control notification handler code here
	
	controller->deschideAgenda();
}

void CAgenda2Dlg::OnBnClickedSalveazaAgendele()
{
	// TODO: Add your control notification handler code here
	controller->salveazaAgendele();
	Modificare=false;
}

void CAgenda2Dlg::OnBnClickedStergeAgenda()
{
	// TODO: Add your control notification handler code here
	controller->stergeAgendaa();
	Modificare=true;
}

void CAgenda2Dlg::OnBnClickedSalveazaLista()
{
	// TODO: Add your control notification handler code here
	controller->salveazaLista();
	Modificare=true;
}

void CAgenda2Dlg::OnCbnSelchangeAgenda()
{
	// TODO: Add your control notification handler code here
	controller->incarcaDetalii();
}

void CAgenda2Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	if(Modificare)
		if(MessageBox("Doriti sa salvati modificarile?","Informare",MB_ICONQUESTION|MB_CANCELTRYCONTINUE)==11)
		{
			controller->salveazaAgendele();
			Modificare=false;
		}

	CDialogEx::OnOK();
}
