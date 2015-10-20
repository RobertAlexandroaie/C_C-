#include <NTL/ZZ.h>
#include<fstream>
NTL_CLIENT

long witness(const ZZ& n, const ZZ& x)
{
   ZZ m, y, z;
   long j, k;

   if (x == 0) return 0;

   // compute m, k such that n-1 = 2^k * m, m odd:

   k = 1;
   m = n/2;
   while (m % 2 == 0) {
      k++;
      m /= 2;
   }

   z = PowerMod(x, m, n); // z = x^m % n
   if (z == 1) return 0;

   j = 0;
   do {
      y = z;
      z = (y*y) % n; 
      j++;
   } while (j < k && z != 1);

   return z != 1 || y != n-1;
}

long PrimeTest(const ZZ& n, long t)
{
   if (n <= 1) return 0;

   // first, perform trial division by primes up to 2000

   PrimeSeq s;  // a class for quickly generating primes in sequence
   long p;

   p = s.next();  // first prime is always 2
   while (p && p < 2000) {
      if ((n % p) == 0) return (n == p);
      p = s.next();  
   }

   // second, perform t Miller-Rabin tests

   ZZ x;
   long i;

   for (i = 0; i < t; i++) {
      x = RandomBnd(n); // random number between 0 and n-1

      if (witness(n, x)) 
         return 0;
   }

   return 1;
}

class RSA
{
public:
    ZZ n,fi_n,e,cript,put,decript;
	void generate_p_q();
	void set_p_q();
	void calc_n_fi_n();
	void set_e();
	void put_e(ZZ a);
	void calc_d();
	void set_plain(ZZ i);
	ZZ Exponentiere(const ZZ& a, const ZZ& e, const ZZ& n);
	void Encrypt(char input[20],char output[20]);
	void Decrypt(int mode,char input[20],char output[20]);
	void view(int mode);
    bool Wiener();

private:
	ZZ p,q,plain,d,dP,dQ,qInv;
};

ZZ RSA::Exponentiere(const ZZ& a, const ZZ& e, const ZZ& n)
{
   if (e == 0) return to_ZZ(1);

   long k = NumBits(e);

   ZZ res;
   res = 1;

   for (long i = k-1; i >= 0; i--) {
      res = (res*res) % n;
      if (bit(e, i) == 1) res = (res*a) % n;
   }

   if (e < 0)
      return InvMod(res, n);
   else
      return res;
}


void RSA::generate_p_q()
{
   GenGermainPrime(p,512);
   GenGermainPrime(q,512);
   while(p==q)
    {
	 GenGermainPrime(q,512);
     SetSeed(to_ZZ(10));
    }
   cout<<endl<<"p:"<<p<<endl;
   cout<<endl<<"q:"<<q<<endl;
}

void RSA::set_p_q()
{
	cout<<"Enter 'p':";
	cin>>p;
	cout<<"Enter 'q':";
	cin>>q;
	while(PrimeTest(p,10)!=1 || PrimeTest(q,10)!=1 || p==q)
	 {cout<<"Primes and different!"<<endl;
	  cout<<"Enter 'p':";
	  cin>>p;
	  cout<<"Enter 'q':";
	  cin>>q;
	}
}

void RSA::calc_n_fi_n()
{
n = p*q;
cout<<endl<<"n:"<<n<<endl;
fi_n=(p-1)*(q-1);
cout<<endl<<char(232)<<"(n):"<<fi_n<<endl;
}

void RSA::set_e()
{
	cout<<"Do you want fast encryption?\n";
	char answer[4];
	cin>>answer;
	if(strcmp(strupr(answer),"YES")==0)
		{
			cout<<"Choose from: 3, 17 and 65537\n";
			cin>>e;
			while(GCD(e,fi_n)!=1)
			{
			cout<<"Try again:";
			cin>>e;
			}
		}
	else 
	{ cout<<"Set the 'e':";
		cin>>e;
		while(GCD(e,fi_n)!=to_ZZ(1))
		{
			cout<<"Try again:";
			cin>>e;
		}
	}
	calc_d();
}

void RSA::calc_d()
{
	d=Exponentiere(e,to_ZZ(-1),fi_n);
}

void RSA::set_plain(ZZ i)
{
	plain=i;
}

void RSA::Encrypt(char input[20],char output[20])
{
	ZZ in;
	int i=0;
	unsigned char p[1024];
	ifstream f(input);
    ofstream g(output);
	int dimensiune=NumBytes(n)+1;
	
    while(!f.eof())
	if(i==dimensiune)
	{
		p[i]=NULL;
		i=0;
		//conv(in,p);
		ZZFromBytes(in,p,i-1);
		set_plain(in);
		cript=Exponentiere(plain,e,n);
		g<<cript;
		g<<"|";
		//strcpy(p,"");
	}
	else
		f>>p[i++];

	if(i>1)
	{
		p[i-1]=0;
		//conv(in,p);
		ZZFromBytes(in,p,i-1);
		set_plain(in);
		cript=Exponentiere(plain,e,n);
		//g<<cript;
		BytesFromZZ(p,cript,i-1);
		g<<p;
		g<<"|";
	}
	f.close();
	g.close();
}
void RSA::Decrypt(int mode,char input[20],char output[20])
{  
	switch (mode)
	{
	case 1:
		{int i=0;unsigned char p[1024];
		ifstream f(input);
		ofstream g(output);

		while(!f.eof())
		{ 
			f>>p[i];
			 if(p[i]=='|')
				{
				p[i]=NULL;
				i=0;
				//conv(cript,p);
                ZZFromBytes(cript,p,i);
				decript=Exponentiere(cript,d,n);
				BytesFromZZ(p,decript,i);
				g<<p;
				//strcpy(p,"");
				}
			 else i++;
		}
		
		break;
		}
	case 2:
		{
			int i=0;char s[1024];
			ifstream f(input);
			ofstream g(output);

			while(!f.eof())
			{ 
				f>>s[i];
				if(s[i]=='|')
				{
					s[i]=NULL;
					i=0;
					conv(cript,s);

					dP=Exponentiere(e,to_ZZ(-1),p-1);
					dQ=Exponentiere(e,to_ZZ(-1),q-1);
				
					qInv=Exponentiere(q,to_ZZ(-1),p);
					ZZ m1,m2,h;
				
					m1=Exponentiere(cript,dP,p);
					m2=Exponentiere(cript,dQ,q);
				
					h=(qInv*(m1-m2))%p;
				
					decript=m2+h*q;
					g<<decript;
					strcpy(s,"");
				}
				else 
					i++;
			}
			break;
		}
	default:break;
	}
}
void RSA::view(int mode)
{
	if(mode==1) cout<<"CRIPT:"<<cript<<"\n";
	else
		if(mode==2)
	 cout<<"DECRIPT:"<<decript<<"\n";	
}
bool RSA::Wiener()
{
 bool ok=0,ok2=0;
 ZZ e_temp,fi_temp,cat,rest,diferenta,fractii[50];
 e_temp=e;fi_temp=n;
 int i=0;
 while(ok!=1)
	{
    cat=e_temp/fi_temp;
    diferenta=e_temp-cat*fi_temp;
	if(diferenta==0)
	{
		ok=1;
		fractii[i++]=e_temp;
	}
	else
		if(diferenta!=0)
		{
			fractii[i++]=cat;
			e_temp=fi_temp;
			fi_temp=diferenta;
		}
	}
 cout<<"Fractiile continue:";
 for(int j=0;j<i;j++)
	  cout<<fractii[j]<<" ";
cout<<endl;
 int index,lim_dr;
 ZZ x,y,aux;
 for(index=1;index<i;index++)
	{
	 lim_dr=index;
	 x=fractii[index-1];
	 y=fractii[index];
	 x=x*y+1;
	 lim_dr--;
	 while(lim_dr!=0)
	  {
        aux=y;
		y=x;
		x=aux;
		x=fractii[lim_dr-1]*y+x;
		lim_dr--;
	  } 
	 fi_n=(e*y-1)/x;
	 ZZ a,b,c,delta,p1,p2;
	 a=1;
	 b=(n-fi_n+1);
	 c=n;
	 delta=b*b-4*a*c;
	 if(delta>0)
	  {
        p1=(b+SqrRoot(delta))/2;
		p2=(b-SqrRoot(delta))/2;
		if(p1>0&&p2>0&&(p1*p2)==n)
		{
		 cout<<x<<"/"<<y<<endl;
		 cout<<"\nWe found p:"<<p1<<" q:"<<p2<<endl;
		 q=p1;
		 p=p2;
	     ok2=1;
		 return 1;
		}
	}
     //

	}
 return 0;
}

int main()
{   SetSeed(to_ZZ(6));
	RSA A;int option;
	bool ok=true;
	while(ok)
	{
	cout<<"\n************ SELECT ***************\n";
	  cout<<"*1.Safe encrypt/decrypt           *\n";
	  cout<<"*2.Unsafe encrypt->Wiener's attack*\n";
	  cout<<"*3.Encrypt/decrypt->T.C.R         *\n";
	  cout<<"*4.Exit                           *\n";
	  cout<<"***********************************\n";
	  cout<<"OPTION:";
	  cin>>option;
	  switch (option)
	  {
	  case 1:
		  {     A.generate_p_q();
				A.calc_n_fi_n();
				A.set_e();
				A.Encrypt("input.txt","crypt.txt");
				A.Decrypt(1,"crypt.txt","decrypt.txt");
				system("notepad crypt.txt");
				system("notepad decrypt.txt");
				break;}
	  case 2: 
       	  {     A.set_p_q();
				A.calc_n_fi_n();
				A.set_e();
				A.Encrypt("input.txt","crypt.txt");
				A.Decrypt(1,"crypt.txt","decrypt.txt");
				RSA B;
				B.n=A.n;
				B.e=A.e;
				if(B.Wiener()==1)
				{
				 B.calc_d();
				 B.Decrypt(1,"crypt.txt","decrypt_attack.txt");
				 system("notepad decrypt_attack.txt");
				 }
				else cout<<"\nWe can't find p & q;\n";
				
				break;}
        case 3:
		  {     A.generate_p_q();
				A.calc_n_fi_n();
				A.set_e();
				A.Encrypt("input.txt","crypt.txt");
				A.Decrypt(2,"crypt.txt","decrypt.txt");
				system("notepad crypt.txt");
				system("notepad decrypt.txt");
				break;}
		case 4:ok=0; 
			   break;
	  default: break;
	  }
	}

}