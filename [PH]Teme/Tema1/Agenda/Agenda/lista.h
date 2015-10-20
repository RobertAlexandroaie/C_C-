#ifndef LISTA_H
#define LISTA_H
#include "contact.h"

class Nodc
{
	char tip;
public:
	Contact *informatie;
	Nodc *urmator,*precedent;

	Nodc();
	Nodc(Contact *info,Nodc *urm, Nodc *prec):informatie(info),urmator(urm),precedent(prec){}
	Nodc(Contact *info):informatie(info){ urmator=NULL; precedent=NULL;}

	char getTip();
	void setTip(char);
};

class Listac
{
	bool modificare;
	int p;
public:

	Contact ownerContact;
	Nodc *primul,*ultimul;

	Listac();

	Listac(const Contact &);

	Listac(char *);

	~Listac();

	void ListaVida();
	int EsteVida();
	int Lungime();
	void AdaugaContact(Contact &,char);
	void AdaugaContact();
	void StergeContact();
	void Modificare();
	bool getModificare();
	void setModificare(bool);
	void Salveaza();
	void Incarca(char *);
	int getP();
	void setP(int );
	Nodc *getContact(int );
	Listac *Filtrare();
	Listac *Cautare();
private:
	void InsereazaInFata(Nodc *p, Nodc *q);
	void InsereazaDupa(Nodc *p, Nodc *q);
};

class Nodo
{
public:
	Listac *informatie;
	Nodo *urmator,*precedent;

	Nodo();
	Nodo(Listac *info,Nodo *urm, Nodo *prec):informatie(info),urmator(urm),precedent(prec){}
	Nodo(Listac *info):informatie(info){ urmator=NULL; precedent=NULL;}	
};

class Listao
{

public:
	int nr_owneri;
	int poz;
	Nodo *primul;
	Nodo *ultimul;
	
	Listao();
	~Listao();

	void setNrOwneri(int);
	int getNrOwneri();

	void setPoz(int);
	int getPoz();

	void ListaVida();
	int EsteVida();
	int Lungime();
	void AdaugaAgenda(Listac *);
	void StergeAgenda();
	Listac *getAgenda(int );
	void Start();
	void Salveaza();
private:
	void InsereazaInaintePr(Nodo *, Nodo *);
	void InsereazaDupaPr(Nodo *, Nodo *);
};

#endif