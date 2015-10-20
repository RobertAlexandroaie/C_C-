// mfc3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfc3.h"
#include "mfc3Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc3Dlg dialog




Cmfc3Dlg::Cmfc3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cmfc3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cb);
}

BEGIN_MESSAGE_MAP(Cmfc3Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &Cmfc3Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Cmfc3Dlg message handlers

BOOL Cmfc3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// initializarea listei din controlul Combo Box
	cb.AddString("item 1");
	cb.AddString("item 2");
	cb.AddString("item 3");
	cb.AddString("item 5");
	cb.AddString("item 4");
	cb.AddString("item 6");
	cb.AddString("item 7");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cmfc3Dlg::OnPaint()
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
HCURSOR Cmfc3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cmfc3Dlg::OnBnClickedOk()
{
	char s[25];
	int i;
	i = cb.GetCurSel();
	if(i != CB_ERR) {
		cb.GetLBText(i, s);
		MessageBox(s, "Combo Box", MB_OK);
	}

	// cod deja existent; a nu fi eliminat sau modificat
	//OnOK();
}
