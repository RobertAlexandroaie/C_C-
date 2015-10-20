#pragma once

#include <cstring>
#include "stdafx.h"
#include <fstream>

typedef enum Type {Friend=0,Colleague,Acquaintance} ;

class ModelContact
{
protected:
	CString nume;
	CString prenume;
	CString nr_tel;
	CString atribut;
	Type tip;

public:
	//contructor
	ModelContact();
	ModelContact(const ModelContact& cn);
	//getteri
	CString getNume() const;
	CString getPrenume() const;
	CString getNrTel() const;
	CString getAtribut() const;
	CString toCString() const;
	CString toCStringnp() const;
	Type getTip() const;


	//setteri
	bool setNume(CString& nume_nou);
	bool setPrenume(CString& prenume_nou);
	bool setNrTel(CString& nrtel_nou);
	virtual bool setAtribut(CString& atribut_nou)=0;
	bool setTip(const Type& tip_nou);
	bool salvare(CString fisier);
};

class ModelFriend:public ModelContact
{
public:
	ModelFriend();
	ModelFriend(CString *date);
	ModelFriend(CString linie);

	bool setAtribut(CString& atribut_nou);
};

class ModelColleague:public ModelContact
{
public:
	ModelColleague();
	ModelColleague(CString *date);
	ModelColleague(CString linie);

	bool setAtribut(CString& atribut_nou);
};

class ModelAcquaintance:public ModelContact
{
public:
	ModelAcquaintance();
	ModelAcquaintance(CString *date);
	ModelAcquaintance(CString linie);

	bool setAtribut(CString& atribut_nou);
};


class ContactCreator 
{
protected :
	CString *date;
	ModelContact *contact;

public:
	ContactCreator( CString date_noi[]) : date(date_noi) {}

	virtual ModelContact* createContact(const Type& option ) = 0;
};


class ConcreteContactCreator: public ContactCreator
{
public:
	ConcreteContactCreator( CString date_noi[] ) : ContactCreator(date_noi) {}
	ModelContact* createContact(const Type& option );
};
