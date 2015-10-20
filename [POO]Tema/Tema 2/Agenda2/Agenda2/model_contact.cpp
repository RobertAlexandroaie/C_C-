#include "model_contact.h"

ModelContact::ModelContact()
{
	nume="";
	prenume="";
	nr_tel="";
	atribut="";
	tip=Friend;
}

ModelContact::ModelContact(const ModelContact& cn)
{
	nume=cn.getNume();
	prenume=cn.getPrenume();
	nr_tel=cn.getNrTel();
	atribut=cn.getAtribut();
	tip=cn.getTip();
}

CString ModelContact::getNume() const
{
	return nume;
}

CString ModelContact::getPrenume() const
{
	return prenume;
}

CString ModelContact::getNrTel() const
{
	return nr_tel;
}

CString ModelContact::getAtribut() const
{
	return atribut;
}

Type ModelContact::getTip() const
{
	return tip;
}

CString ModelContact::toCString() const
{
	CString text;
	text=nume+_T(" ")+prenume+_T(" ")+nr_tel+_T(" ")+atribut;
	return text;
}
	
CString ModelContact::toCStringnp() const
{
	CString txt;
	txt=getNume()+_T(" ")+getPrenume();
	return txt;
}

bool ModelContact::setNume(CString& nume_nou)
{
	char n[20];
	strcpy(n,nume_nou.GetBuffer());
	n[0]=toupper(n[0]);
	
	nume=n;
	return true;
}

bool ModelContact::setPrenume(CString& prenume_nou)
{
	char p[20];
	strcpy(p,prenume_nou.GetBuffer());
	p[0]=toupper(p[0]);

	prenume=p;
	return true;
}

bool ModelContact::setNrTel(CString& nrtel_nou)
{
	nr_tel=nrtel_nou;
	return true;
}

bool ModelContact::setTip(const Type& tip_nou)
{
	tip=tip_nou;
	return true;
}

bool ModelContact::salvare(CString fisier)
{
	char fis[200];
	strcpy(fis,fisier.GetBuffer());
	std::ofstream fo(fis,std::ios::app);
	fo.flush();

	if(!fo.is_open())
		return false;

	CString linie;
	linie.Empty();
	switch(getTip())
	{
		case Friend:
			linie=_T("f"); break;
		case Colleague:
			linie=_T("c"); break;
		case Acquaintance:
			linie=_T("a"); break;
	}
	linie.Append("|");
	linie.Append(nume);
	linie.Append("|");
	linie.Append(prenume);
	linie.Append("|");
	linie.Append(nr_tel);
	linie.Append("|");
	linie.Append(atribut);

	char lin[300];
	strcpy(lin,linie.GetBuffer());
	fo<<lin<<"\n";
	return true;
}

ModelFriend::ModelFriend()
{
	this->setTip(Friend);
}

ModelFriend::ModelFriend(CString *date)
{
	setTip(Friend);
	setNume(date[0]);
	setPrenume(date[1]);
	setNrTel(date[2]);

	if(setAtribut(date[3])==false)
	{
		CString txt;
		txt="0/0/0";
		setAtribut(txt);
	}
}

ModelFriend::ModelFriend(CString linie)
{
	CString resToken[4];
	int curPos = 0;
	
	resToken[0]= linie.Tokenize(_T("|"),curPos);
	int i=0;
	while (resToken[i] != _T(""))
	{
		++i;
		resToken[i] = linie.Tokenize(_T("|"), curPos);
	}

	setNume(resToken[0]);
	setPrenume(resToken[1]);
	setNrTel(resToken[2]);
	setAtribut(resToken[3]);
}

bool ModelFriend::setAtribut(CString& atribut_nou)
{
	atribut.Empty();
	int z,l,a;
	char data[11],zi[3],luna[34],an[5];

	strcpy(data,atribut_nou.GetBuffer());
	strcpy(zi,"");
	strcpy(luna,"");
	strcpy(an,"");

	int i=0;
	int j=0;
	while(isdigit(data[j])!=0)
		zi[i++]=data[j++];
	zi[i]=0;

	if(j==0)
		return false;

	data[j++]='/';


	i=0;
	while(isdigit(data[j])!=0)
		luna[i++]=data[j++];
	luna[i]=0;
		
	if(j==1)
		return false;

	data[j++]='/';


	i=0;
	while(isdigit(data[j])!=0)
		an[i++]=data[j++];
	an[i]=0;

	z=atoi(zi);
	l=atoi(luna);
	a=atoi(an);

	if(a<0)
		a=0;
	if(a>9999)
		a=9999;

	if(l<0)
		l=1;
	if(l>12)
		l=12;

	bool bisect;

	if(((a%4==0)&&(a%100!=0))||(a%400==0))
		bisect=true;

	if(z<0)
		z=1;

	switch(l)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case  12: if(z>31) z=31;
	case 2:
		if(bisect)
		{
			if(z>29)
				z=29;
		}
		else
			if(z>28)
				z=28;
	case 4: case 6: case 9: case 11: if(z>30) z=30;	
	}
		
	strcpy(data,"");

	strcpy(data,itoa(z,zi,10));
	strcat(data,"/");
	strcat(data,itoa(l,luna,10));
	strcat(data,"/");
	strcat(data,itoa(a,an,10));

	atribut=data;
	
	return true;
}


ModelColleague::ModelColleague()
{
	setTip(Colleague);
}

ModelColleague::ModelColleague(CString *date)
{
	setTip(Colleague);
	setNume(date[0]);
	setPrenume(date[1]);
	setNrTel(date[2]);
	setAtribut(date[3]);
}

ModelColleague::ModelColleague(CString linie)
{
	CString resToken[4];
	int curPos = 0;
	
	resToken[0]= linie.Tokenize(_T("|"),curPos);
	int i=0;
	while (resToken[i] != _T(""))
	{
		++i;
		resToken[i] = linie.Tokenize(_T("|"), curPos);
	}

	setNume(resToken[0]);
	setPrenume(resToken[1]);
	setNrTel(resToken[2]);
	setAtribut(resToken[3]);
}

bool ModelColleague::setAtribut(CString& atribut_nou)
{
	char atr[20];
	strcpy(atr,atribut_nou.GetBuffer());
	atr[0]=toupper(atr[0]);

	atribut=atr;
	return true;
}

ModelAcquaintance::ModelAcquaintance()
{
	setTip(Acquaintance);
}

ModelAcquaintance::ModelAcquaintance(CString *date)
{
	setTip(Acquaintance);
	setNume(date[0]);
	setPrenume(date[1]);
	setNrTel(date[2]);
	setAtribut(date[3]);
}

ModelAcquaintance::ModelAcquaintance(CString linie)
{
	CString resToken[4];
	int curPos = 0;
	
	resToken[0]= linie.Tokenize(_T("|"),curPos);
	int i=0;
	while (resToken[i] != _T(""))
	{
		++i;
		resToken[i] = linie.Tokenize(_T("|"), curPos);
	}

	setNume(resToken[0]);
	setPrenume(resToken[1]);
	setNrTel(resToken[2]);
	setAtribut(resToken[3]);
}

bool ModelAcquaintance::setAtribut(CString& atribut_nou)
{
	char atr[20];
	strcpy(atr,atribut_nou.GetBuffer());
	atr[0]=toupper(atr[0]);

	atribut=atr;
	return true;
}

ModelContact* ContactCreator::createContact(const Type& option )
{
	switch(option)
	{
	case Friend:
		{
			contact = new ModelFriend(date);
			break;
		}
	case Colleague:
		{
			contact = new ModelColleague(date);
			break;
		}
			
	case Acquaintance:
		{
			contact = new ModelAcquaintance(date);
			break;
		}
	}
	
	return contact;
}

ModelContact* ConcreteContactCreator::createContact(const Type& option )
{
	return ContactCreator::createContact( option );
}