#include "ControllerContact.h"

void ControllerContact::Asociaza(ModelContact *m, Contact *v)
{
	model=m;
	view=v;
}

void ControllerContact::start()
{
	view->eNume.SetWindowTextA(model->getNume());
	view->ePrenume.SetWindowTextA(model->getPrenume());
	view->eNrTel.SetWindowTextA(model->getNrTel());
	view->eAtribut.SetWindowTextA(model->getAtribut());

	view->t=model->getTip();

	CStatic *s=(CStatic *)view->GetDlgItem(IDC_STATIC);
	switch(view->t)
	{
	case Friend:
		s->SetWindowTextA(_T("Data nasterii")); break;
	case Colleague:
		s->SetWindowTextA(_T("Categoria")); break;
	case Acquaintance:
		s->SetWindowTextA(_T("Profesia")); break;
	}
}

void ControllerContact::selecteazaPrieten()
{
	view->rPrieten=true;
	view->rColeg=false;
	view->rCunostinta=false;
	view->t=Friend;

	CStatic *s=(CStatic *)view->GetDlgItem(IDC_STATIC);
	s->SetWindowTextA("Data");
}

void ControllerContact::selecteazaColeg()
{
	view->rPrieten=false;
	view->rColeg=true;
	view->rCunostinta=false;
	view->t=Colleague;

	CStatic *s=(CStatic *)view->GetDlgItem(IDC_STATIC);
	s->SetWindowTextA("Categoria");
}

void ControllerContact::selecteazaCunostinta()
{
	view->rPrieten=false;
	view->rColeg=false;
	view->rCunostinta=true;
	view->t=Acquaintance;

	CStatic *s=(CStatic *)view->GetDlgItem(IDC_STATIC);
	s->SetWindowTextA("Profesia");
}

void ControllerContact::selecteazaOk()
{
	CString nume,prenume,nrtel,atribut;
	view->eNume.GetWindowTextA(nume);
	view->ePrenume.GetWindowTextA(prenume);
	view->eNrTel.GetWindowTextA(nrtel);
	view->eAtribut.GetWindowTextA(atribut);
	
	model->setTip(view->t);
	model->setNume(nume);
	model->setPrenume(prenume);
	model->setNrTel(nrtel);

	if(!model->setAtribut(atribut))
	{
		view->MessageBox("Atentie!\nNu ati introdus o data corecta.","Avertisment",MB_ICONEXCLAMATION);
		CString data;
		data=_T("0/0/0");
		model->setAtribut(data);
	}
}