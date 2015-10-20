// mfc4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfc4.h"
#include "mfc4Dlg.h"

#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc4Dlg dialog




Cmfc4Dlg::Cmfc4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cmfc4Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, chk1);
	DDX_Control(pDX, IDC_CHECK2, chk2);
	DDX_Control(pDX, IDC_RADIO1, rd1);
	DDX_Control(pDX, IDC_RADIO2, rd2);
}

BEGIN_MESSAGE_MAP(Cmfc4Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &Cmfc4Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Cmfc4Dlg message handlers

BOOL Cmfc4Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// initializare check boxes si radio buttons
	chk1.SetCheck(BST_CHECKED);
	chk2.SetCheck(BST_UNCHECKED);
	rd1.SetCheck(BST_CHECKED);
	rd2.SetCheck(BST_UNCHECKED);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cmfc4Dlg::OnPaint()
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
HCURSOR Cmfc4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cmfc4Dlg::OnBnClickedOk()
{
	int a1,a2,b1,b2;
	char s[50];
	a1 = chk1.GetCheck();
	a2 = chk2.GetCheck();
	b1 = rd1.GetCheck();
	b2 = rd2.GetCheck();
	sprintf(s, "buton 1 %s\nbuton 2 %s\n%s validat", (a1==BST_CHECKED)?"validat":"invalidat",
		(a2==BST_CHECKED)?"validat":"invalidat", (b1==BST_CHECKED)?"r1":"r2");
	MessageBox(s, "Check Box", MB_OK);

	// cod deja existent; a nu fi eliminat sau modificat
	OnOK();
}
