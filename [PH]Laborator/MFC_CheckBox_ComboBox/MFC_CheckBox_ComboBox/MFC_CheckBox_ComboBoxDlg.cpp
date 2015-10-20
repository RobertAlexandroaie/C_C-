
// MFC_CheckBox_ComboBoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_CheckBox_ComboBox.h"
#include "MFC_CheckBox_ComboBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_CheckBox_ComboBoxDlg dialog




CMFC_CheckBox_ComboBoxDlg::CMFC_CheckBox_ComboBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_CheckBox_ComboBoxDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CheckBox_ComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, butonOK);
	DDX_Control(pDX, IDCANCEL, butonCancel);
	DDX_Control(pDX, IDC_CHECK5, check5);
	DDX_Control(pDX, IDC_CHECK4, check4);
	DDX_Control(pDX, IDC_CHECK3, check3);
	DDX_Control(pDX, IDC_CHECK2, check2);
	DDX_Control(pDX, IDC_CHECK1, check1);
	DDX_Control(pDX, IDC_EDIT1, editText1);
	DDX_Control(pDX, IDC_EDIT2, editText2);
	DDX_Control(pDX, IDC_EDIT3, editText3);
	DDX_Control(pDX, IDC_EDIT4, editText4);
	DDX_Control(pDX, IDC_EDIT5, editText5);
	DDX_Control(pDX, IDC_BUTTON1, addButon);
	DDX_Control(pDX, IDC_COMBO1, comboBox);
}

BEGIN_MESSAGE_MAP(CMFC_CheckBox_ComboBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CheckBox_ComboBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck5)
END_MESSAGE_MAP()


// CMFC_CheckBox_ComboBoxDlg message handlers

BOOL CMFC_CheckBox_ComboBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	editText1.EnableWindow(false);
	editText2.EnableWindow(false);
	editText3.EnableWindow(false);
	editText4.EnableWindow(false);
	editText5.EnableWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_CheckBox_ComboBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_CheckBox_ComboBoxDlg::OnPaint()
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
HCURSOR CMFC_CheckBox_ComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_CheckBox_ComboBoxDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString text;
	CString x;

	if(check1.GetCheck()==BST_CHECKED)
	{
		editText1.GetWindowTextW(x);
		text.Append(x);
	}
	
	if(check2.GetCheck()==BST_CHECKED)
	{
		editText2.GetWindowTextW(x);
		text.Append(x);
	}

	if(check3.GetCheck()==BST_CHECKED)
	{
		editText3.GetWindowTextW(x);
		text.Append(x);
	}
	
	if(check4.GetCheck()==BST_CHECKED)
	{
		editText4.GetWindowTextW(x);
		text.Append(x);
	}
	
	if(check5.GetCheck()==BST_CHECKED)
	{
		editText5.GetWindowTextW(x);
		text.Append(x);
	}

	comboBox.AddString(text);
}

void CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	if(check1.GetCheck()==BST_CHECKED)
		editText1.EnableWindow(true);
	else
		editText1.EnableWindow(false);
}

void CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck2()
{
	// TODO: Add your control notification handler code here
	if(check2.GetCheck()==BST_CHECKED)
		editText2.EnableWindow(true);
	else
		editText2.EnableWindow(false);
}

void CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
	if(check3.GetCheck()==BST_CHECKED)
		editText3.EnableWindow(true);
	else
		editText3.EnableWindow(false);
}

void CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck4()
{
	// TODO: Add your control notification handler code here
	if(check4.GetCheck()==BST_CHECKED)
		editText4.EnableWindow(true);
	else
		editText4.EnableWindow(false);
}

void CMFC_CheckBox_ComboBoxDlg::OnBnClickedCheck5()
{
	// TODO: Add your control notification handler code here
	if(check5.GetCheck()==BST_CHECKED)
		editText5.EnableWindow(true);
	else
		editText5.EnableWindow(false);
}
