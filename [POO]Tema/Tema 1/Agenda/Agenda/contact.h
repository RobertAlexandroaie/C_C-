#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
protected:
	char Nume[20], Prenume[20], NrTel[20];
	
public:
//----------------------CONSTRUCTORI--------------------
	Contact(const Contact &c);
	Contact(const char* ,const char* ,const char* );
	Contact(const char* ,const char* );
	Contact(const char* );
	Contact();
//------------------------------------------------------

//-----------------------DESTRUCTOR---------------------
	~Contact();
//------------------------------------------------------

//-------------------------GETERI-----------------------	
	char* getNume() const; 
	char* getPrenume() const;
	char* getNrTel() const;
	virtual char* getAtribut();
	virtual void Afisare();
	virtual void Salveaza(char *);
//------------------------------------------------------

//-------------------------SETERI-----------------------
	void setNume(char* );
	void setPrenume(char *);
	void setNrTel(char *);
	virtual void Incarca(char *);
	virtual bool Switch(char&,char*);
//------------------------------------------------------
};

class Colleague:public Contact
{
	char Categorie[50];

public:
//----------------------CONSTRUCTORI--------------------
	Colleague(const Contact &);
	Colleague(const Colleague &);
	Colleague(const char *,const char *,const char *,const char *);
	Colleague(const char *,const char *,const char *);
	Colleague(const char *,const char *);
	Colleague(const char *);
	Colleague();
//------------------------------------------------------

//------------------------DESTRUCTOR--------------------
//------------------------------------------------------

//------------------------GETERI-----------------------
	virtual void Afisare();
	char* getCategorie() const;
	char* getAtribut();
//-----------------------------------------------------

//------------------------SETERI-----------------------
	void setCategorie(const char *);
	void Salveaza(char *);
	virtual void Incarca(char *);
	bool Switch(char&,char*);
//-----------------------------------------------------
};

class Friend:public Contact
{
	char Data[10];

public:
//----------------------CONSTRUCTORI--------------------
	Friend(const Contact &);
	Friend(const Friend &);
	Friend(char *,char *,char *,char *);
	Friend(char *,char *,char *);
	Friend(char *,char *);
	Friend(char *);
	Friend();
//------------------------------------------------------

//------------------------DESTRUCTOR--------------------
//------------------------------------------------------

//------------------------GETERI------------------------
	virtual void Afisare();
	char *getData() const;
	char* getAtribut();
//-----------------------------------------------------

//------------------------SETERI-----------------------
	void setData(const char *);
	void Salveaza(char *);
	virtual void Incarca(char *);
	bool Switch(char&,char*);
//-----------------------------------------------------
};

class Acquaintance:public Contact
{
	char Profesie[20];
	
public:
//----------------------CONSTRUCTORI--------------------
	Acquaintance(const Contact &);
	Acquaintance(const Acquaintance &);
	Acquaintance(char *,char *,char *,char *);
	Acquaintance(char *,char *,char *);
	Acquaintance(char *,char *);
	Acquaintance(char *);
	Acquaintance();
//------------------------------------------------------

//------------------------DESTRUCTOR--------------------
//------------------------------------------------------

//------------------------GETERI-----------------------
	virtual void Afisare();
	char* getProfesie()const;
	char* getAtribut();
//-----------------------------------------------------

//------------------------SETERI-----------------------
	void setProfesie(const char *);
	void Salveaza(char *);
	virtual void Incarca(char *);
	bool Switch(char&,char*);
//-----------------------------------------------------
};

#endif