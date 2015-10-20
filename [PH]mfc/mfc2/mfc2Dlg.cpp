// mfc2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfc2.h"
#include "mfc2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc2Dlg dialog




Cmfc2Dlg::Cmfc2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cmfc2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, editbox);
}

BEGIN_MESSAGE_MAP(Cmfc2Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &Cmfc2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Cmfc2Dlg message handlers

BOOL Cmfc2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// se stabileste numarul maxim de caractere acceptat de controlul editabil
	editbox.SetLimitText(5);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cmfc2Dlg::OnPaint()
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
HCURSOR Cmfc2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cmfc2Dlg::OnBnClickedOk()
{
	char s[6];
	int i;
	i = editbox.GetLine(0, s);
	s[i] = '\0';
	MessageBox(s, "Edit Box", MB_OK);

	// cod deja existent; a nu fi eliminat sau modificat
	OnOK();
}
