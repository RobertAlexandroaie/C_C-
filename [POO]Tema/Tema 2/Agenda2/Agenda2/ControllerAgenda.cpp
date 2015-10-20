#include "ControllerAgenda.h"

void ControllerAgenda::Asociaza(ModelAgenda *m, Agenda *v)
{
	model=m;
	view=v;
}

void ControllerAgenda::start()
{
	CStatic *s=(CStatic*)view->GetDlgItem(IDC_STATIC);
	CString txt;
	txt=model->nume_proprietar+_T(" ")+model->prenume_proprietar+_T(" : ")+model->nr_tel_proprietar;
	s->SetWindowTextA(txt);

	view->cbContacte.ResetContent();

	std::list<ModelContact*>::iterator i;
	for(i=model->Contacte.begin();i!=model->Contacte.end();i++)
	{
		CString txt;
		txt=(*i)->toCStringnp();

		if(txt!=_T(" "))
			view->cbContacte.AddString(txt);
	}
}

void ControllerAgenda::contactNou()
{
	adaugaContact *adC=new adaugaContact;
	adC->Asociaza(model);
	adC->DoModal();

	start();
	
	CString text;
	text.Empty();
	view->cbContacte.GetWindowTextA(text);
	if(text==_T("")||text==_T(" "))
	{
		view->eNume.SetSel(0, -1);
		view->eNume.Clear();

		view->ePrenume.SetSel(0, -1);
		view->ePrenume.Clear();

		view->eNrTel.SetSel(0, -1);
		view->eNrTel.Clear();

		view->eTip.SetSel(0,-1);
		view->eTip.Clear();

		view->eAtribut.SetSel(0,-1);
		view->eAtribut.Clear();
	}
}

void ControllerAgenda::editeazaContact()
{
	CString text;
	view->cbContacte.GetWindowTextA(text);
	
	std::list<ModelContact*>::iterator i;
	if(text!=_T("")&&text!=_T(" "))
	{
		for(i=model->Contacte.begin();i!=model->Contacte.end()&&(*i)->toCStringnp()!=text;++i);

		Contact *c=new Contact;
		c->Asociaza((*i));
		c->DoModal();
		
		start();
		view->cbContacte.SetWindowTextA((*i)->toCStringnp());
		incarcaDetalii((*i)->toCStringnp());
	}

}

void ControllerAgenda::salvareContacte()
{
	if(model->salvareContacte())
	{
		view->MessageBox("S-au salvat contactele.","Informare",MB_ICONINFORMATION);
		model->incarcaContacte();
	}
	else
		view->MessageBox("Nu s-au salvat contactele.","Informare",MB_ICONERROR);
}

void ControllerAgenda::FilCaut()
{
	filtrareCautare *flC=new filtrareCautare;
	flC->Asociaza(model,&(view->cbContacte));
	flC->DoModal();
}

void ControllerAgenda::stergereContact()
{
	int poz;
	poz=view->cbContacte.GetCurSel();
	if(poz!=0)
		poz=(poz+1)%poz;

	CString text;
	view->cbContacte.GetWindowTextA(text);

	if(text!=_T("")&&text!=_T(" "))
	{
		std::list<ModelContact*>::iterator i;
		for(i=model->Contacte.begin();i!=model->Contacte.end()&&(*i)->toCStringnp()!=text;++i);

		
		stergeContact *st=new stergeContact();
		st->Asociaza(model,(*i));
		st->DoModal();
		start();
	}

	view->cbContacte.GetLBText(poz,text);
	view->cbContacte.SetWindowTextA(text);
	incarcaDetalii(text);
}

void ControllerAgenda::incarcaDetalii()
{
	CString text;
	view->cbContacte.GetLBText(view->cbContacte.GetCurSel(),text);
	
	if(text!=_T("")&&text!=_T(" "))
	{
		std::list<ModelContact*>::iterator i;
		for(i=model->Contacte.begin();i!=model->Contacte.end()&&(*i)->toCStringnp()!=text;++i);
		
		switch((*i)->getTip())
		{
		case Friend: view->eTip.SetWindowTextA(_T("Prieten")); break;
		case Colleague: view->eTip.SetWindowTextA(_T("Coleg")); break;
		case Acquaintance: view->eTip.SetWindowTextA(_T("Cunostinta")); break;
		}

		view->eNume.SetWindowTextA((*i)->getNume());
		view->ePrenume.SetWindowTextA((*i)->getPrenume());
		view->eNrTel.SetWindowTextA((*i)->getNrTel());
		view->eAtribut.SetWindowTextA((*i)->getAtribut());
	}
}

void ControllerAgenda::incarcaDetalii(const CString& txt)
{
	CString text;
	text=txt;

	if(text!=_T("")&&text!=_T(" "))
	{
		std::list<ModelContact*>::iterator i;
		for(i=model->Contacte.begin();i!=model->Contacte.end()&&(*i)->toCStringnp()!=text;++i);
		
		switch((*i)->getTip())
		{
		case Friend: view->eTip.SetWindowTextA(_T("Prieten")); break;
		case Colleague: view->eTip.SetWindowTextA(_T("Coleg")); break;
		case Acquaintance: view->eTip.SetWindowTextA(_T("Cunostinta")); break;
		}

		view->eNume.SetWindowTextA((*i)->getNume());
		view->ePrenume.SetWindowTextA((*i)->getPrenume());
		view->eNrTel.SetWindowTextA((*i)->getNrTel());
		view->eAtribut.SetWindowTextA((*i)->getAtribut());
	}
}