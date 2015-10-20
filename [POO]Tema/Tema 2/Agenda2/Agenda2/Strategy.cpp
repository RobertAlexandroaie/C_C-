#include "Strategy.h"

void Strategy::Asociaza( ModelAgenda* m ,  filtrareCautare* v )
{
	model=m;
	view=v;
}

void searchStrategy::ListaNoua ()
{		
	CString txt;
	view->eCriteriu.GetWindowTextA( txt );

	CString resToken[4];
	int curPos = 0;
	
	//se imparte textul din edit box in cuvinte (siruri de caractere ce nu contin spatiu)
	resToken[0]= txt.Tokenize(_T(" "),curPos);
	int i=0;
	while (resToken[i] != _T(""))
	{
		i++;
		resToken[i] = txt.Tokenize(_T(" "), curPos);
	}

	//se reseteaza combo boxul
	view->cbContacte->ResetContent();

	std::list<ModelContact*>::iterator it;
	
	bool ok=false;

	it=model->Contacte.begin();
	while(it!=model->Contacte.end())
	{
		ok=false;
		CString nume,prenume,nrtel,atribut;

		nume.Empty(); prenume.Empty(); nrtel.Empty(); atribut.Empty();

		nume=(*it)->getNume();
		prenume=(*it)->getPrenume();
		nrtel=(*it)->getNrTel();
		atribut=(*it)->getAtribut();
		txt=nume+_T(" ")+prenume;

		for(i=0;resToken[i] != _T("");i++)
		{
			if(nume.Find(resToken[i])!=-1||prenume.Find(resToken[i])!=-1||nrtel.Find(resToken[i])!=-1||atribut.Find(resToken[i])!=-1)
				ok=true;
		}
		
		if(ok)
			view->cbContacte->AddString(txt);

		++it;
	}	
}

void filterStrategy::ListaNoua ()
{
	std::list<ModelContact*>::iterator it;
	it=model->Contacte.begin();

	ModelAgenda *aux;
	ModelAgenda *aux2;

	view->cbContacte->ResetContent();

	CString txt;

	//in cauzul in care toate casutele sunt bifate sau toate debifate agenda auxiliara in care se va cauta un anumit numar de telefon este chiar agenda originala
	if(view->cPrieten.GetCheck()==view->cColeg.GetCheck()&&view->cColeg.GetCheck()==view->cCunostinta.GetCheck())
	{
		aux=model;
	}
	else //altfel formam o noua lista cu nodurile ce au tipurile selectate prin bifare
	{	
		aux=new ModelAgenda;
		aux->nume_proprietar=model->nume_proprietar;
		aux->prenume_proprietar=model->prenume_proprietar;
		aux->nr_tel_proprietar=model->nr_tel_proprietar;
		aux->Contacte.clear();

		while(it!=model->Contacte.end())
		{
			if((view->cPrieten.GetCheck()==BST_CHECKED)&&((*it)->getTip()==Friend)) aux->addContact((*it));
			if((view->cColeg.GetCheck()==BST_CHECKED)&&((*it)->getTip()==Colleague)) aux->addContact((*it));
			if((view->cCunostinta.GetCheck()==BST_CHECKED)&&((*it)->getTip()==Acquaintance)) aux->addContact((*it));

			++it;
		}
	}

	it=aux->Contacte.begin();

	//daca toate tipurile de telefon sunt bifate/debifate <=> agenda auxiliara secundara in care cautam un anumit atribut este agenda secundara principala
	if(view->cOrange.GetCheck()==view->cVodafone.GetCheck()&&view->cVodafone.GetCheck()==view->cCosmote.GetCheck()&&view->cCosmote.GetCheck()==view->cProprietar.GetCheck())
	{
		aux2=aux;
	}
	else //altfel mai formam o agenda din agenda precedenta, agenda ce va contine contacte de tipurile bifate si cu numerele de telefon din retelele bifate
	{
		aux2=new ModelAgenda;
		aux2->Contacte.clear();

		while(it!=aux->Contacte.end())
		{
			Type t=(*it)->getTip();
			if((view->cOrange.GetCheck()==BST_CHECKED)&&((*it)->getNrTel()[2]=='4'||(*it)->getNrTel()[2]=='5')) aux2->addContact((*it));
			if((view->cVodafone.GetCheck()==BST_CHECKED)&&((*it)->getNrTel()[2]=='2'||(*it)->getNrTel()[2]=='3')) aux2->addContact((*it));
			if((view->cCosmote.GetCheck()==BST_CHECKED)&&((*it)->getNrTel()[2]=='6')) aux2->addContact((*it));

			char nrtel[20];
			strcpy(nrtel,model->nr_tel_proprietar.GetBuffer());
			if((view->cProprietar.GetCheck()==BST_CHECKED)&&((*it)->getNrTel()[2]==nrtel[2])) aux2->addContact((*it));
			
			++it;
		}
	}

	it=aux2->Contacte.begin();

	while(it!=aux2->Contacte.end())
	{
		view->cbContacte->AddString((*it)->toCStringnp());
		++it;
	}
}

Context::Context(Strategie tip_nou)
{
	tip=tip_nou;
}

void Context::Asociaza(ModelAgenda *m, filtrareCautare *v)
{
	switch(tip)
	{
	case filtrare: strt=new filterStrategy; break;
	case cautare: strt=new searchStrategy; break;
	}

	strt->Asociaza(m,v);
}

void Context::setStrategie(Strategie str)
{
	tip=str;
}

void Context::DoStrategy()	
{
	strt->ListaNoua();
}