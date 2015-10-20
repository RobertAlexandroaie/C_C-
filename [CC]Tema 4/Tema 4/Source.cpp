#include<NTL/ZZ.h>
#include<iostream>
#include<fstream>
#include<string.h>

NTL_CLIENT

ZZ n,phi_n,p,q,e,d;
ZZ phi_n_gasit, p_gasit, q_gasit, d_gasit;

//~~~~~~~~~~~~~FUNCTII PENTRU NUMERE PRIME~~~~~~~~~~~~~~~~~~~~~~~

long witness(const ZZ& n, const ZZ& x)
{
   ZZ m, y, z;
   long j, k;

   if (x == 0) return 0;

   k = 1;
   m = n/2;
   while (m % 2 == 0)
   {
      k++;
      m /= 2;
   }

   z = PowerMod(x, m, n);
   if (z == 1) return 0;

   j = 0;
   do
   {
      y = z;
      z = (y*y) % n; 
      j++;
   } while (j < k && z != 1);

   return z != 1 || y != n-1;
}

long PrimeTest(const ZZ& n, long t)
{
   if (n <= 1) return 0;

   PrimeSeq s;  
   long p;

   p = s.next();
   while (p && p < 2000) {
      if ((n % p) == 0) return (n == p);
      p = s.next();  
   }

   ZZ x;
   long i;

   for (i = 0; i < t; i++)
   {
      x = RandomBnd(n); 

      if (witness(n, x)) 
         return 0;
   }

   return 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~~~~~~FUNCTII PENTRU CRIPTARE/DECRIPTARE~~~~~~~~~~~~~~
void gen_p_q_n_phi_n()
{
	SetSeed(to_ZZ(6));

	GenGermainPrime(p,512);
	q=p;

	while(p==q)
	{
		GenGermainPrime(q,512);
		SetSeed(to_ZZ(10));
	}

	n=p*q;
	phi_n=(p-1)*(q-1);
}

ZZ get_PowerMod(const ZZ& numar, const ZZ& exponent, const ZZ& baza)
{
	if (exponent == 0) 
		return to_ZZ(1);

	long k = NumBits(exponent);

	ZZ res;
	res = 1;

	for (long i = k-1; i >= 0; i--)
	{
		res = (res*res) % baza;
		if (bit(exponent, i) == 1)
			res = (res*numar) % n;
	}

	if (exponent < 0)
		return InvMod(res, baza);
	else
		return res;
}

void gen_e_d()
{
	int raspuns=5;

	cout<<endl<<"**************************\n";
	cout<<"Ce fel de criptare doriti?\n";
	cout<<"1. Criptare cu \"e\" generat de la tastatura.\n";
	cout<<"2. Criptare cu \"e\" generat aleator.\n";
	cout<<"**************************\n";
	cout<<"Raspuns: ";
	cin>>raspuns;

	while(raspuns!=1&&raspuns!=2)
	{
		cout<<"Raspuns: ";
		cin>>raspuns;
	}

	if(raspuns==1)
	{
		cout<<"Introduceti valoarea lui \"e\". Alegeti: 3, 17, 65537 pentru criptare rapida sau 0 pentru generare aleatoare.\n";
		cout<<"**************************\n";
		cout<<"e=";
		cin>>e;
		while(GCD(e,phi_n)!=1&&e!=0)
		{
			cout<<"Incercati alt numar:";
			cin>>e;
		}
		if(e==0)
			raspuns=2;
	}
	
	if(raspuns==2)
	{
		e=19;
		while(GCD(e,phi_n)!=1)
			e+=2;
		cout<<e<<endl;
	}

	d=get_PowerMod(e,to_ZZ(-1),phi_n);
}

void write_HexaBlock(ofstream *fout, char *bit_string, int size)
{
	char caracter=0;
	short int val=0;

	for(int i=0;i<size;i++)
	{
		val=bit_string[i]&0xF0;
		val>>=4;
		val&=0x0F;
		if(val>9)
			caracter=char(val-10+'A');
		else
			caracter=char(val+48);
		(*fout)<<caracter;

		val=bit_string[i]&0x0F;
		val&=0x0F;
		if(val>9)
			caracter=char(val-10+'A');
		else
			caracter=char(val+48);
		
		(*fout)<<caracter;
	}
}

void get_PlainHexText(char *nume_fisier_plain)
{
	ifstream fin(nume_fisier_plain);
	ofstream fout("PlainHexText.txt");
	
	fin.unsetf(std::ios_base::skipws);
	fout.unsetf(std::ios_base::skipws);

	char byte=0;
	int i=0;

	char bit_string[128];
	memset(bit_string,0,128);

	while(fin>>byte)
	{
		bit_string[i++]=byte;

		if(i==128)
		{
			write_HexaBlock(&fout,bit_string,128);
			memset(bit_string,0,128);
			i=0;
		}
	}

	if(i!=0)
		write_HexaBlock(&fout,bit_string,128);

	fin.close();
	fout.close();
}

void get_CriptoHexText(char *nume_fisier_plain)
{
	gen_p_q_n_phi_n();
	gen_e_d();

	ifstream fin(nume_fisier_plain);
	if(!fin.is_open())
		fin.open("PlainHexText.txt",std::ios_base::in);

	ofstream fout("CriptoHexText.txt");
	
	fin.unsetf(std::ios_base::skipws);
	fout.unsetf(std::ios_base::skipws);
	
	char bit_string[128];
	memset(bit_string,0,128);

	char cripted_bit_string[128];
	memset(cripted_bit_string,0,128);

	int i=0;
	char c=0;
	int val=0;
	int indice_hexa=0;
	char byte=0;

	ZZ cripted_1024_block;

	while(fin>>c)
	{
		val=int(c);
		if(val<58)
			val-=48;
		else
			val=val+10-'A';

		indice_hexa++;
		
		if(indice_hexa==1)
		{
			byte=0;
			byte=val;
			byte<<=4;
			byte&=0xF0;
		}
		
		if(indice_hexa==2)
		{
			byte|=val;
			bit_string[i++]=char(byte);
			indice_hexa=0;
		}

		if(i==128)
		{
			cripted_1024_block=to_ZZ(0x00);
			cripted_1024_block=ZZFromBytes((const unsigned char *)bit_string,128);
			cripted_1024_block=get_PowerMod(cripted_1024_block,e,n);
		
			memset(cripted_bit_string,0,128);
			BytesFromZZ((unsigned char *)cripted_bit_string,cripted_1024_block,128);
			write_HexaBlock(&fout,cripted_bit_string,i);
			memset(cripted_bit_string,0,128);
			memset(bit_string,0,128);
			i=0;
		}
	}

	fin.close();
	fout.close();
}

void get_DecriptoHexText()
{
	ifstream fin("CriptoHexText.txt");
	ofstream fout("DecriptoHexText.txt");
	
	fin.unsetf(std::ios_base::skipws);
	fout.unsetf(std::ios_base::skipws);
	
	char bit_string[128];
	memset(bit_string,0,128);

	char decripted_bit_string[128];
	memset(decripted_bit_string,0,128);

	int i=0;
	char c=0;
	int val=0;
	int indice_hexa=0;
	char byte=0;


	ZZ cripted_1024_block;
	ZZ decripted_1024_block;
	
	while(fin>>c)
	{
		val=int(c);
		if(val<58)
			val-=48;
		else
			val=val+10-'A';

		indice_hexa++;
		if(indice_hexa==1)
		{
			byte=0;
			byte=val;
			byte<<=4;
			byte&=0xF0;
		}
		
		if(indice_hexa==2)
		{
			byte|=val;
			bit_string[i++]=char(byte);
			indice_hexa=0;
		}

		if(i==128)
		{
			cripted_1024_block=to_ZZ(0x00);
			cripted_1024_block=ZZFromBytes((const unsigned char *)bit_string,128);
			decripted_1024_block=get_PowerMod(cripted_1024_block,d,n);

			memset(decripted_bit_string,0,128);
			BytesFromZZ((unsigned char *)decripted_bit_string,decripted_1024_block,128);
			
			write_HexaBlock(&fout,decripted_bit_string,i);
			
			memset(decripted_bit_string,0,128);
			memset(bit_string,0,128);
			i=0;
		}
	}

	fin.close();
	fout.close();
}

void get_TCR_DecriptoHexText()
{
	ifstream fin("CriptoHexText.txt");
	ofstream fout("DecriptoHexText.txt");
	
	fin.unsetf(std::ios_base::skipws);
	fout.unsetf(std::ios_base::skipws);
	
	char bit_string[128];
	memset(bit_string,0,128);

	char decripted_bit_string[128];
	memset(decripted_bit_string,0,128);

	int i=0;
	char c=0;
	int val=0;
	int indice_hexa=0;
	char byte=0;


	ZZ cripted_1024_block;
	ZZ decripted_1024_block;
	ZZ m1,m2,b1,b2,m1_inv,m2_inv,x1,x2;

	while(fin>>c)
	{
		val=int(c);
		if(val<58)
			val-=48;
		else
			val=val+10-'A';

		indice_hexa++;
		if(indice_hexa==1)
		{
			byte=0;
			byte=val;
			byte<<=4;
			byte&=0xF0;
		}
		
		if(indice_hexa==2)
		{
			byte|=val;
			bit_string[i++]=char(byte);
			indice_hexa=0;
		}

		if(i==128)
		{
			cripted_1024_block=to_ZZ(0x00);
			cripted_1024_block=ZZFromBytes((const unsigned char *)bit_string,128);
						
			memset(decripted_bit_string,0,128);
			
			//~~~~~~~~~~~~~~~~~~~~~TCR Magic~~~~~~~~~~~~~~~~~~
			
			m1=q;
			m2=p;

			b1=get_PowerMod(cripted_1024_block%p,d%(p-1),p);
			b2=get_PowerMod(cripted_1024_block%q,d%(q-1),q);

			m1_inv=get_PowerMod(m1%p,to_ZZ(-1),p);
			m2_inv=get_PowerMod(m2%q,to_ZZ(-1),q);

			x1=(b1%p*m1_inv%p)%p;
			x2=(b2%q*m2_inv%q)%q;

			decripted_1024_block=m1*x1+m2*x2;
			decripted_1024_block%=n;

			//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~S
			
			BytesFromZZ((unsigned char *)decripted_bit_string,decripted_1024_block,128);
			
			write_HexaBlock(&fout,decripted_bit_string,i);
			
			memset(decripted_bit_string,0,128);
			memset(bit_string,0,128);
			i=0;
		}
	}

	fin.close();
	fout.close();
}

void get_DecriptoText()
{
	ifstream fin("DecriptoHexText.txt");
	ofstream fout("DecriptoText.txt");
	fin.unsetf(std::ios_base::skipws);
	fout.unsetf(std::ios_base::skipws);

	char c=0;
	int val=0;
	int indice_hexa=0;
	char byte=0;
	int i=0;

	while(fin>>c)
	{
		i++;
		val=int(c);
		if(val<58)
			val-=48;
		else
			val=val+10-'A';

		indice_hexa++;
		if(indice_hexa==1)
		{
			byte=val;
			byte<<=4;
			byte&=0xF0;
		}
		
		if(indice_hexa==2)
		{
			byte|=val;
			if(byte>6)
				fout<<byte;
			indice_hexa=0;
			byte=0;
		}
	}

	fin.close();
	fout.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~FUNCTII PENTRU WIENER~~~~~~~~~~~~~~~~~~~~~~~~~
void gen_Wiener_p_q_n_phi_n()
{
	p=q=n=phi_n=0;

	SetSeed(to_ZZ(6));

	GenGermainPrime(p,256);
	q=p;

	bool ok;
	ok=false;

	while(!ok)
	{
		GenGermainPrime(q,256);
		SetSeed(to_ZZ(10));
		
		if(q<p&&p<2*q)
			ok=true;
	}

	n=p*q;
	phi_n=(p-1)*(q-1);
}

void gen_Wiener_e_d()
{
	gen_Wiener_p_q_n_phi_n();

	bool ok;
	ok=false;

	ZZ a;
	a=0;
	d=0;
	e=0;

	while(!ok)
	{	
		a=SqrRoot(n);
		a=SqrRoot(a);
		a=a/3;

		d=NTL::RandomBnd(a-1);
		d=to_ZZ(d);
		
		if(GCD(d,phi_n)==1)
		{
			e=InvMod(d,phi_n);

			if(GCD(e,d)==1)
				ok=true;
		}
	}
}

void get_Cont_Frac_Conv(ZZ a, ZZ b, ZZ *q, int &i)//convergentele fractiei continue
{
	ZZ cat,rest;

	cat=a/b;
	rest=a%b;

	q[i++]=cat;

	while(rest!=0)
	{
		a=b;
		b=rest;
		cat=a/b;
		rest=a%b;
		q[i++]=cat;
	}
}

void get_Cont_Asoc_Frac(ZZ a, ZZ b, ZZ *q, int &i, ZZ frac[50][2])
{
	get_Cont_Frac_Conv(a,b,q,i);
	int j=0;

	ZZ numitor, numarator;

	numarator=q[0];
	numitor=1;

	frac[0][0]=numarator;
	frac[0][1]=numitor;

	numarator=q[0]*q[1]+1;
	numitor=q[1];

	frac[1][0]=numarator;
	frac[1][1]=numitor;

	j=2;
	for(;j<i;j++)
	{
		numarator=q[j]*frac[j-1][0]+frac[j-2][0];
		numitor=q[j]*frac[j-1][1]+frac[j-2][1];

		frac[j][0]=numarator;
		frac[j][1]=numitor;
	}
}

bool criteriu(ZZ a, ZZ b)
{
	if(a==0) return false;
	if(b>(SqrRoot(SqrRoot(n)))/3) return false;

	ZZ phi_n_gasit;
	phi_n_gasit=(e*b-1)/a;

	ZZ x1,x2,delta,b_ec;

	b_ec=-(n+1-phi_n_gasit);
	delta=b_ec*b_ec-4*n;

	x1=(-b_ec-SqrRoot(delta))/2;
	x2=(-b_ec+SqrRoot(delta))/2;
	
	if(x1*x2==n)
	{
		if(x1<x2)
		{
			q_gasit=x1;
			p_gasit=x2;
		}
		else
		{
			p_gasit=x1;
			q_gasit=x2;
		}
		return true;
	}
	else
		return false;
}

void Wiener()
{
	ZZ a,b;
	a=e;
	b=n;

	ZZ frac[1000][2];
	int indice_max=0;

	ZZ q[1000];

	get_Cont_Asoc_Frac(a,b,q,indice_max,frac);

	/*
	for(int j=0;j<indice_max;j++)
		cout<<q[j]<<" ";
	cout<<endl;

	for(int j=0;j<indice_max;j++)
	{
		cout<<frac[j][0]<<endl<<frac[j][1]<<"\n\n";
	}
	//*/

	ZZ l;

	int i=0;
	do
	{
		l=frac[i][0];
		d_gasit=frac[i][1];
		i++;
	}while(criteriu(l,d_gasit)==false);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
	///*
	//~~~~~~~~~~~~~~CRIPTARE SI DECRIPTARE~~~~~~~~~~~~~~~~~~~~~~~~
	get_PlainHexText("PlainText.txt");
	get_CriptoHexText("PlainHexText.txt");
	//get_DecriptoHexText();//DECRIPTARE NORMALA
	get_TCR_DecriptoHexText();//DECRIPTARE CU TCR
	get_DecriptoText();
	//*/

	///*
	//e=60728973;
	//n=160523347;

	gen_Wiener_e_d();

	Wiener();
	
	cout<<endl;
	cout<<"p generat:"<<p<<endl<<"p gasit:  "<<p_gasit<<endl<<endl<<"q generat:"<<q<<endl<<"q gasit:  "<<q_gasit<<endl<<endl<<"d generat: "<<d<<endl<<"d gasit:   "<<d_gasit<<endl;
	//*/

	system("pause");
	return 0;
}