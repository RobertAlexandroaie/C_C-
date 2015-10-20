// viewAgenda.cpp : implementation file
//

#include "stdafx.h"
#include "Agenda.h"
#include "viewAgenda.h"
#include "afxdialogex.h"


// viewAgenda dialog

IMPLEMENT_DYNAMIC(viewAgenda, CDialogEx)

viewAgenda::viewAgenda(CWnd* pParent /*=NULL*/)
	: CDialogEx(viewAgenda::IDD, pParent)
{

}

viewAgenda::~viewAgenda()
{
}

void viewAgenda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(viewAgenda, CDialogEx)
END_MESSAGE_MAP()


// viewAgenda message handlers
