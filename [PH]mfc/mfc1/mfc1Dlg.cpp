// mfc1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfc1.h"
#include "mfc1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc1Dlg dialog




Cmfc1Dlg::Cmfc1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cmfc1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cmfc1Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &Cmfc1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Cmfc1Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// Cmfc1Dlg message handlers

BOOL Cmfc1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cmfc1Dlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cmfc1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cmfc1Dlg::OnBnClickedOk()
{
	// codul care implementeaza comportamentul specific aplicatiei la apasarea tastei "OK"
	MessageBox("S-a apasat butonul OK", "OK", MB_OK);

	// cod deja existent; a nu fi eliminat sau modificat
	OnOK();
}

void Cmfc1Dlg::OnBnClickedCancel()
{
	// codul care implementeaza comportamentul specific aplicatiei la apasarea tastei "Cancel"
	MessageBox("S-a apasat butonul Cancel", "Cancel", MB_OK);

	// cod deja existent; a nu fi eliminat sau modificat
	OnCancel();
}
