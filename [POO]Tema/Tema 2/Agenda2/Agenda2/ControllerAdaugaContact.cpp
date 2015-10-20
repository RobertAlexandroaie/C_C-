#include "ControllerAdaugaContact.h"

void ControllerAdaugaContact::Asociaza(ModelAgenda *m, adaugaContact *v)
{
	model=m;
	view=v;
}

void ControllerAdaugaContact::start()
{
	view->eNume.EnableWindow(0);
	view->ePrenume.EnableWindow(0);
	view->eNrTelefon.EnableWindow(0);
	view->eAtribut.EnableWindow(0);
}

void ControllerAdaugaContact::selecteazaPrieten()
{
	view->rPrieten=true;
	view->rColeg=false;
	view->rCunostinta=false;
	CStatic *s=(CStatic*)view->GetDlgItem(IDC_STATIC);
	s->SetWindowTextA(_T("Data nasterii"));

	view->t=Friend;

	view->eNume.EnableWindow(1);
	view->ePrenume.EnableWindow(1);
	view->eNrTelefon.EnableWindow(1);
	view->eAtribut.EnableWindow(1);

}

void ControllerAdaugaContact::selecteazaColeg()
{
	view->rPrieten=false;
	view->rColeg=true;
	view->rCunostinta=false;
	view->t=Colleague;

	CStatic *s=(CStatic*)view->GetDlgItem(IDC_STATIC);
	s->SetWindowTextA(_T("Categorie"));

	view->eNume.EnableWindow(1);
	view->ePrenume.EnableWindow(1);
	view->eNrTelefon.EnableWindow(1);
	view->eAtribut.EnableWindow(1);
}

void ControllerAdaugaContact::selecteazaCunostinta()
{
	view->rPrieten=false;
	view->rColeg=false;
	view->rCunostinta=true;
	view->t=Acquaintance;

	CStatic *s=(CStatic*)view->GetDlgItem(IDC_STATIC);
	s->SetWindowTextA(_T("Profesie"));

	view->eNume.EnableWindow(1);
	view->ePrenume.EnableWindow(1);
	view->eNrTelefon.EnableWindow(1);
	view->eAtribut.EnableWindow(1);
}

void ControllerAdaugaContact::selecteazaOk()
{
	CString date_noi[4];
	view->eNume.GetWindowTextA(date_noi[0]);
	view->ePrenume.GetWindowTextA(date_noi[1]);
	view->eNrTelefon.GetWindowTextA(date_noi[2]);
	view->eAtribut.GetWindowTextA(date_noi[3]);

	model->addContact(view->t,date_noi);
}