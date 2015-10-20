#pragma once


// viewAgenda dialog

class viewAgenda : public CDialogEx
{
	DECLARE_DYNAMIC(viewAgenda)

public:
	viewAgenda(CWnd* pParent = NULL);   // standard constructor
	virtual ~viewAgenda();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
