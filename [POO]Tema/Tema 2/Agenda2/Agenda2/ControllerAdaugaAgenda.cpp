#include "ControllerAdaugaAgenda.h"


ControllerAdaugaAgenda::ControllerAdaugaAgenda()
{
	model=NULL;
	view=NULL;
}

void ControllerAdaugaAgenda::Asociaza(AgendeSingleton *m, adaugaAgenda*v)
{
	model=m;
	view=v;
}

void ControllerAdaugaAgenda::selectareDinFisier()
{
	view->rFisier=true;
	view->rNou=false;

	view->eFisier.EnableWindow(1);
	view->eNume.EnableWindow(0);
	view->ePrenume.EnableWindow(0);
	view->eNrTel.EnableWindow(0);
}

void ControllerAdaugaAgenda::selectareNou()
{
	view->rFisier=false;
	view->rNou=true;

	view->eFisier.EnableWindow(0);
	
	view->eNume.EnableWindow(1);
	view->ePrenume.EnableWindow(1);
	view->eNrTel.EnableWindow(1);
}

void ControllerAdaugaAgenda::selectareOK()
{
	if(view->rFisier==true)
	{
		CString fisier;
		view->eFisier.GetWindowTextA(fisier);
		
		ModelAgenda *ag_noua=new ModelAgenda;

		if(!ag_noua->incarcaContacte(fisier))
		{
			CString mesaj;
			mesaj=_T("Nu exista fisierul: \"")+fisier+_T("\"!");
			view->MessageBox(mesaj,"Avertisment",MB_ICONEXCLAMATION);
		}
		else
			model->Agende.push_back(ag_noua);
	}
	else
	{
		CString nume,prenume,nrtel;
		view->eNume.GetWindowTextA(nume);
		view->ePrenume.GetWindowTextA(prenume);
		view->eNrTel.GetWindowTextA(nrtel);

		ModelAgenda *ag_noua=new ModelAgenda(nume,prenume,nrtel);

		model->Agende.push_back(ag_noua);
	}
}