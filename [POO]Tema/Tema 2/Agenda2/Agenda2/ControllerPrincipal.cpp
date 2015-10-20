#include "ControllerPrincipal.h"

void ControllerPrincipal::Asociaza(AgendeSingleton *m, CAgenda2Dlg *v)
{
	model=m;
	view=v;
}

void ControllerPrincipal::incarcaAgendeInCB()
{
	view->cbAgende.ResetContent();
	std::list<ModelAgenda*>::iterator i;
	
	for(i=model->Agende.begin();i!=model->Agende.end();++i)
	{
		CString text;
		text.Empty();
		text=(*i)->nume_proprietar+_T(" ")+(*i)->prenume_proprietar;
		if(text!=_T(" "))
			view->cbAgende.AddString(text);
	}
}

void ControllerPrincipal::agendaNoua()
{
	adaugaAgenda *adAg=new adaugaAgenda;
	adAg->Asociaza(model);
	adAg->DoModal();

	incarcaAgendeInCB();

	CString text;
	text.Empty();
	view->cbAgende.GetWindowTextA(text);
	if(text==_T("")||text==_T(" "))
	{
		view->eNume.SetSel(0, -1);
		view->eNume.Clear();

		view->ePrenume.SetSel(0, -1);
		view->ePrenume.Clear();

		view->eNrTel.SetSel(0, -1);
		view->eNrTel.Clear();
	}
}

void ControllerPrincipal::deschideAgenda()
{
	CString text;
	text.Empty();
	view->cbAgende.GetWindowTextA(text);

	if(text!=_T("")&&text!=_T(" "))
	{
		std::list<ModelAgenda*>::iterator i;
		for(i=model->Agende.begin();i!=model->Agende.end()&&(*i)->toCStringnp()!=text;++i);
	
		Agenda *ag=new Agenda;
		ag->Asociaza((*i));
		ag->DoModal();
	}
	
	incarcaDetalii(text);
	incarcaAgendeInCB();
	view->cbAgende.SetWindowTextA(text);
}
	
void ControllerPrincipal::salveazaAgendele()
{
	std::list<ModelAgenda*>::iterator i;
	for(i=model->Agende.begin();i!=model->Agende.end();++i)
		(*i)->salvareContacte();
	
	if(!model->salveaza())
		view->MessageBox("Atentie! Lista de agende nu a putut  fi salvata!","Avertisment",MB_ICONERROR);
	else
		view->MessageBox("Lista si agendele au fost salvate cu succes!","Informare",MB_ICONINFORMATION);
}

void ControllerPrincipal::salveazaLista()
{
	if(!model->salveaza())
		view->MessageBox("Atentie! Lista de agende nu a putut fi salvata!","Avertisment",MB_ICONERROR);
	else
		view->MessageBox("Lista de agende a fost salvata cu succes.","Informare",MB_ICONINFORMATION);
}

void ControllerPrincipal::stergeAgendaa()
{
	CString text;
	int poz;
	poz=view->cbAgende.GetCurSel();
	if(poz!=0)
		poz=(poz+1)%poz;

	view->cbAgende.GetWindowTextA(text);
	if(text!=_T("")&&text!=_T(" "))
	{
		std::list<ModelAgenda*>::iterator i;
		for(i=model->Agende.begin();i!=model->Agende.end()&&(*i)->toCStringnp()!=text;++i);
	
		stergeAgenda *st=new stergeAgenda;
		st->Asociaza(model,(*i));
		st->DoModal();
	}
	
	incarcaAgendeInCB();
	view->cbAgende.GetLBText(poz,text);
	view->cbAgende.SetWindowTextA(text);
	incarcaDetalii(text);
}

void ControllerPrincipal::incarcaDetalii()
{
	CString text;
	text.Empty();
	view->cbAgende.GetLBText(view->cbAgende.GetCurSel(),text);

	if(text!=_T("")&&text!=_T(" "))
	{
		std::list<ModelAgenda*>::iterator i;
		for(i=model->Agende.begin();i!=model->Agende.end()&&(*i)->toCStringnp()!=text;++i);
	
		view->eNume.SetWindowTextA((*i)->nume_proprietar);
		view->ePrenume.SetWindowTextA((*i)->prenume_proprietar);
		view->eNrTel.SetWindowTextA((*i)->nr_tel_proprietar);
	}
}

void ControllerPrincipal::incarcaDetalii(const CString& txt)
{
	CString text;
	text=txt;

	if(text!=_T("")&&text!=_T(" "))
	{
		std::list<ModelAgenda*>::iterator i;
		for(i=model->Agende.begin();i!=model->Agende.end()&&(*i)->toCStringnp()!=text;++i);
	
		view->eNume.SetWindowTextA((*i)->nume_proprietar);
		view->ePrenume.SetWindowTextA((*i)->prenume_proprietar);
		view->eNrTel.SetWindowTextA((*i)->nr_tel_proprietar);
	}
}