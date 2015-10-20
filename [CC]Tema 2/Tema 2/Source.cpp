#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

char ch_freq[26];

float norm_ch_freq[26];

int decript_ch_freq[26];
int decript_nr_ch;

char key[2000];
int dim_key;
char found_key[2000];

void getPlainText(char *nume_fisier_text, char *nume_fisier_plain) 
{
	ifstream fin(nume_fisier_text);
	ofstream fout(nume_fisier_plain);

	if(!fin.is_open())
	{
		fin.open("text.txt",std::ios_base::in);
		cout<<"Fisierul "<<nume_fisier_text<<" nu exista! Se citeste din 'text.txt'!!!\n";
	}

	char c;

	while(fin>>c)
		if(isalpha(c))
		{
			c=toupper(c);
			ch_freq[c-'A']++;
			fout<<c;
		}

	fin.close();
	fout.close();
}

void makeKey()
{
	int i=0;
	char c;
	srand ( time(NULL) );

	int n;

	cout<<"Dimensiunea cheii: ";
	cin>>n;
	dim_key=n;

	while(n)
	{
		c=rand() % 26;
		c=char(c+'A');

		key[i++]=c;
		n--;
	}
}

void getCryptoText(char *nume_fisier_plain, char *nume_fisier_criptat)
{
	ifstream fin(nume_fisier_plain);
	ofstream fout(nume_fisier_criptat);
	int i=0;

	char c;
	char pic;

	while(fin>>c)
	{
		pic=char((c+key[i])%26+'A');
		fout<<pic;
		i=(i+1)%dim_key;
	}

	fin.close();
	fout.close();
}

void shift(char *nume_fisier_criptat, char *nume_fisier_decriptat, int dim_key,int poz_start,char reverse_shift)
{
	ifstream fin(nume_fisier_criptat);
	ofstream fout(nume_fisier_decriptat);

	char c,cc;
	int i=0;

	while(fin>>c)
	{
		if(i==poz_start)
		{
			cc=char((c-'A'+reverse_shift)%26+'A');
			fout<<cc;
		}
		else 
			fout<<c;
		i=(i+1)%dim_key;
	}

	fin.close();
	fout.close();
}

float IC(char *nume_fisier, int lungime_hop, int poz_start)
{
	ifstream fin(nume_fisier);
	int i,nr=0;
	
	float ic=0.0;

	int pifreq[26];
	for(i=0;i<26;i++)
		pifreq[i]=0;

	char c;

	fin.seekg(poz_start,ios_base::cur);
	while(fin>>c)
	{
		nr++;
		pifreq[c-'A']++;
		fin.seekg(lungime_hop-1,ios_base::cur);
	}

	fin.close	();

	for(i=0;i<26;i++)
		ic=ic+((pifreq[i]*1.0/nr)*((pifreq[i]-1)*1.0/(nr-1)));

	return ic;
}

int getKeyLength(char *nume_fisier_criptat)
{
	int lungime=1;
	int rasp=0;
	int i;

	float media;

	do
	{
		
		cout<<"===============================================================================\n";
		cout<<"===============================================================================\n";

		media=0.0;

		for(i=0;i<lungime;i++)
		{
			media+=IC(nume_fisier_criptat,lungime,i);
		}
		

		cout<<"\t  IC: ";
		cout.precision(3);
		cout<<media/lungime;
		cout: 0.065\n";
		<<"\nComparati cu
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"Alegeti optiunea:\n";
		cout<<"1. Cresteti dimensiunea.\n";
		cout<<"2. Decrementati dimensiunea.\n";
		cout<<"3. Aceasta este cheia.\n\n";

		cout<<"Lungime actuala: "<<lungime<<endl;
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"Raspuns: ";
		cin>>rasp;
		cout<<"===============================================================================\n";
		cout<<"===============================================================================\n\n";

		switch(rasp) 
		{
			case 1: lungime++; break;
			case 2: lungime --; break;
		}	

	} while (rasp!=3);

	dim_key=lungime;
	return lungime;
}

float MIC(char *nume_fisier)
{
	ifstream fin(nume_fisier);

	char c;
	float mic=0.0;
	float v1,v2;

	for(int i=0;i<26;i++)
		decript_ch_freq[i]=0;
	decript_nr_ch=0;

	while(fin>>c)
	{
		decript_ch_freq[c-'A']++;
		decript_nr_ch++;
	}
	fin.close();

	for(int i=0;i<26;i++)
	{
		v1=norm_ch_freq[i];

		v2=decript_ch_freq[i]*1.0;
		v2=v2/decript_nr_ch;

		mic=mic+(v1*v2);
	}
	return mic;
}

void getKey(char *nume_fisier_criptat)
{
	int dim_cheie, shift_bun;
	float mic;
	dim_cheie=getKeyLength(nume_fisier_criptat);

	float val[26], min=1.0;

	char nume_fisier_shiftat[50];
	
	norm_ch_freq[0]=0.08167;
	norm_ch_freq[1]=0.01492;
	norm_ch_freq[2]=0.02782;
	norm_ch_freq[3]=0.04253;
	norm_ch_freq[4]=0.12702;
	norm_ch_freq[5]=0.02228;
	norm_ch_freq[6]=0.02015;
	norm_ch_freq[7]=0.06094;
	norm_ch_freq[8]=0.06966;
	norm_ch_freq[9]=0.00153;
	norm_ch_freq[10]=0.00772;
	norm_ch_freq[11]=0.04025;
	norm_ch_freq[12]=0.02406;
	norm_ch_freq[13]=0.06749;
	norm_ch_freq[14]=0.07507;
	norm_ch_freq[15]=0.01929;
	norm_ch_freq[16]=0.00095;
	norm_ch_freq[17]=0.05987;
	norm_ch_freq[18]=0.06327;
	norm_ch_freq[19]=0.09056;
	norm_ch_freq[20]=0.02758;
	norm_ch_freq[21]=0.00978;
	norm_ch_freq[22]=0.02360;
	norm_ch_freq[23]=0.00150;
	norm_ch_freq[24]=0.01974;
	norm_ch_freq[25]=0.00074;
	

	strcpy(nume_fisier_shiftat,"shift.txt");

	ifstream fin(nume_fisier_criptat);
	ofstream fout(nume_fisier_shiftat);

	char c;
	while(fin>>c)
		fout<<c;

	fin.close();
	fout.close();

	int i,rev_shift;
	int rasp=-1;
	
	for(i=0;i<26;i++)
		val[i]=1.0;

	for(i=0;i<dim_cheie;i++)
	{
		rev_shift=0;
		do
		{
			shift(nume_fisier_criptat, nume_fisier_shiftat, dim_cheie,i,rev_shift);

			mic=MIC(nume_fisier_shiftat);
			if(mic>0.065)
				val[rev_shift++]=mic-0.065;
			else
				val[rev_shift++]=0.065-mic;

			/*
			cout<<"===============================================================================\n";
			cout<<"===============================================================================\n";

			
			cout<<"MIC: "<<mic;
			cout<<"\nComparati cu: 0.065\n";
			
			cout<<"-------------------------------------------------------------------------------\n";
			cout<<"Alegeti optiunea:\n";
			cout<<"1. Litera urmatoare.\n";
			cout<<"2. Litera precedenta.\n";
			cout<<"3. Aceasta este litera.\n\n";

			cout<<"Litera actuala: "<<char(rev_shift+'A')<<endl;
			cout<<"-------------------------------------------------------------------------------\n";
			cout<<"Raspuns: ";
			cin>>rasp;
			cout<<"===============================================================================\n";

			switch(rasp) 
			{
				case 1: rev_shift++; rev_shift%=26; break;
				case 2: rev_shift--; if(rev_shift<0) rev_shift=25; break;
			}
			*/

		}while(rev_shift<26);
		
		min=1.0;
		shift_bun=0;
		for(int j=0;j<26;j++)
			if(val[j]<min)
			{
				min=val[j];
				shift_bun=j;
			}
		found_key[i]=char((26-shift_bun)%26+'A');
	}
}

void getDecript(char *nume_fisier_criptat, char *nume_fisier_decriptat, char *key)
{
	ifstream fin(nume_fisier_criptat);
	ofstream fout(nume_fisier_decriptat);

	char c;
	int k;
	int i=0;
	int lk=dim_key;

	while(fin>>c)
	{
		k=c-'A';
		k=k+26-(key[i]-'A');
		k%=26;
		c=char(k+'A');
		fout<<c;
		i=(i+1)%lk;
	}

	fin.close();
	fout.close();
}

int main() 
{
	int optiune=0;
	int lunime;
	char c;

	getPlainText("text2.txt","plaintext.txt");
	
	while(optiune!=1&&optiune!=2)
	{
		cout<<"===============================================================================\n";
		cout<<"Mod de generare a cheii: \n";
		cout<<"1. Aleator.\n";
		cout<<"2. De la tastatura.\n";

		
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"Optiune: ";
		cin>>optiune;
		cout<<"-------------------------------------------------------------------------------\n";
	}
	
	if(optiune==1)
		makeKey();
	else
	{
		cout<<"Lungime: ";
		cin>>dim_key;

		for(int i=0;i<dim_key;i++)
		{
			cin>>c;
			key[i]=toupper(c);
		}
	}
	
	cout<<"===============================================================================\n";

	getCryptoText("plaintext.txt","criptotext.txt");
	for(int i=0;isalpha(key[i]);i++)
		cout<<key[i];
	cout<<"\n";
	

	cout<<"\n";
	getKey("criptotext.txt");
	cout<<"Cheia initiala: ";
	for(int i=0;isalpha(key[i]);i++)
		cout<<key[i];
	cout<<"\n";
	cout<<"Cheia gasita  : ";
	for(int i=0;i<dim_key;i++)
		cout<<found_key[i];
	cout<<"\n";

	getDecript("criptotext.txt","decriptotext.txt", found_key);

	system("pause");
	return 0;
}