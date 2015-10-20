#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;
using std::cout;

char key[26];
int cfreq[26];
int dfreq[26][26];
int tfreq[26][26][26];
int pifreq[26];
char pi[26];

bool nuExista(char c) {
	bool ok=true;
	for(int i=0;i<26;i++)
		if(pi[i]==c)
			ok=false;
	return ok;
}

void getKey(char *fisier) {
	ifstream fin(fisier);

	char c;

	int i;
	for(i=0;i<26;i++) {
		fin>>c;
		fin>>c;
		key[i]=c;
	}

	fin.close();
}

void makeKey() {
	int i=0;
	char c;
	bool ok=true;
	srand ( time(NULL) );

	while(i<26) {
		ok=true;
		c=rand() % 26;
		c=char(c+'A');

		for(int j=0;j<26;j++)
			if(key[j]==c) 
				ok=false; 

		if(ok)
			key[i++]=c;
	}
}

void getPlainText(char *text) {
	ifstream fin(text);
	ofstream fout("plaintext.txt");

	if(!fin.is_open())
	{
		fin.open("text.txt",std::ios_base::in);
		cout<<"Fisierul "<<text<<" nu exista! Se citeste din 'text.txt'!!!\n";
	}

	char c;

	while(fin>>c) {
		if(c>='a'&&c<='z') {
			c=toupper(c);
			fout<<c;
		}
		else
			if(c>='A'&&c<='Z') fout<<c;
	}

	fin.close();
	fout.close();
}

void getCryptoText() {
	ifstream fin("plaintext.txt");
	ofstream fout("criptotext.txt");

	char c,c2=-1,c3=-1;
	char pic;

	getKey("cheie.key");
	//====sau====
	/*
	makeKey();
	*/

	int i=0;

	while(fin>>c){
		i++;
		pic=key[c-'A'];

		cfreq[c-'A']++;
		fout<<pic;
		pifreq[pic-'A']++;
		
		if(i==1) {
			c2=pic;
		}

		if(i==2) {
			dfreq[c2-'A'][pic-'A']++;
			c3=c2;
			c2=pic;
		}

		if(i>=3) {
			dfreq[c2-'A'][pic-'A']++;
			tfreq[c3-'A'][c2-'A'][pic-'A']++;
			c3=c2;
			c2=pic;
		}
	}

	fin.close();
	fout.close();
}

int getA(char *fisier, char T,char H,char E )
{
	ifstream fin(fisier);

	char c4,c3,c2,c1;
	fin>>c1;
	fin>>c2;
	fin>>c3;
	int piA=0,max=0;

	int pos_A[26];

	for(int i=0;i<26;i++)
		pos_A[i]=0;

	while(fin>>c4) {
		if(c1==T&&c2==H&&c4==T&&c3!=E)
				pos_A[c3-'A']++;
		c1=c2;
		c2=c3;
		c3=c4;
	}
	fin.close();

	for(int i=0;i<26;i++)
		if(pos_A[i]>max) {
			max=pos_A[i];
			piA=i;
		}

	return piA;
}

int getW(char *fisier, char H,char A, char T, char *gasite) {
	ifstream fin(fisier);

	char c4,c3,c2,c1;
	fin>>c1;
	fin>>c2;
	fin>>c3;
	int piW=0,max=0;
	bool ok=true;

	int pos_W[26];

	for(int i=0;i<26;i++)
		pos_W[i]=0;

	while(fin>>c4) {
		ok=true;
		if(c2==H&&c3==A&&c4==T) {
			for(int i=0;i<26;i++)
				if(char(gasite[i])==c1)
					ok=false;
			if(ok) pos_W[c1-'A']++;
		}
		c1=c2;
		c2=c3;
		c3=c4;
	}
	fin.close();

	for(int i=0;i<26;i++)
		if(pos_W[i]>max) {
			max=pos_W[i];
			piW=i;
		}

	return piW;
}

int getM(char *fisier, char E,char N, char *gasite) {
	ifstream fin(fisier);

	char c3,c2,c1;
	fin>>c1;
	fin>>c2;
	fin>>c3;
	int piM=0,max=0;
	bool ok=true;

	int pos_M[26];

	for(int i=0;i<26;i++)
		pos_M[i]=0;

	while(fin>>c3) {
		ok=true;
		if(c2==E&&c3==N) {
			for(int i=0;i<26;i++)
				if(char(gasite[i])==c1)
					ok=false;
			if(ok) pos_M[c1-'A']++;
		}
		c1=c2;
		c2=c3;
	}
	fin.close();

	for(int i=0;i<26;i++)
		if(pos_M[i]>max) {
			max=pos_M[i];
			piM=i;
		}

	return piM;
}

void getLetters(char *fisier) {

	for(int i=0;i<26;i++)
		pi[i]=-1;

	int max_ap=0,max_ap2=0;
	int piE=0,piT=0,piH=0,piR=0,piA=0,piN=0,piI=0,piG=0,piD=0,piO=0,piF=0,piS=0,piL=0,piW=0,piU=0,piY=0,piM=0,piV=0,piB=0;
	int i;
	//----------------------E si T-----------------------------------
	for(i=0;i<26;i++) {
		if(pifreq[i]>max_ap) {
			piE=i;
			max_ap=pifreq[i];
		}
		else
			if(pifreq[i]>max_ap2) {
				piT=i;
				max_ap2=pifreq[i];
			}
	}
	pi['E'-'A']=(char)(piE+'A');
	pi['T'-'A']=(char)(piT+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//-----------------------------H---------------------------------
	for(i=0;i<26;i++) {
		if(tfreq[piT][i][piE]>max_ap&&nuExista(i+'A')) {
			max_ap=tfreq[piT][i][piE];
			piH=i;
		}
	}
	pi['H'-'A']=char(piH+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//------------------------------R--------------------------------
	for(i=0;i<26;i++) {
		if((dfreq[i][piE]>max_ap)&&(dfreq[piH][i])>0&&nuExista(i+'A')) {
			max_ap=dfreq[i][piE];
			piR=i;
		}
	}
	pi['R'-'A']=char(piR+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//------------------------------A--------------------------------
	piA=getA(fisier,piT+'A',piH+'A',piE+'A');
	pi[0]=char(piA+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//------------------------------N--------------------------------
	for(i=0;i<26;i++) {
		if(dfreq[piA][i]>max_ap&&nuExista(i+'A')) {
			max_ap=dfreq[piA][i];
			piN=i;
		}
	}
	pi['N'-'A']=char(piN+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//------------------------------I--------------------------------
	for(i=0;i<26;i++){
		if(dfreq[i][piN]>max_ap&&nuExista(i+'A')) {
			max_ap=dfreq[i][piN];
			piI=i;
		}
	}
	pi['I'-'A']=char(piI+'A');
	//--------------------------------------------------------------
	max_ap=0;
	//-----------------------------G-------------------------------
	for(i=0;i<26;i++) {
		if(tfreq[piI][piN][i]>max_ap&&nuExista(i+'A')) {
			max_ap=tfreq[piI][piN][i];
			piG=i;
		}
	}
	pi['G'-'A']=char(piG+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//-------------------------------D-------------------------------
	for(i=0;i<26;i++) {
		if(tfreq[piA][piN][i]>max_ap&&nuExista(i+'A')) {
			max_ap=tfreq[piA][piN][i];
			piD=i;
		}
	}
	pi['D'-'A']=char(piD+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//--------------------------------O------------------------------
	for(i=0;i<26;i++) {
		if(dfreq[i][piN]>max_ap&&nuExista(i+'A')) {
			max_ap=dfreq[piT][i];
			piO=i;
		}
	}
	pi['O'-'A']=char(piO+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//-----------------------------U---------------------------------
	for(i=0;i<26;i++) {
		if((tfreq[piO][i][piR]>max_ap)&&nuExista(i+'A')) {
			max_ap=tfreq[piO][i][piR];
			piU=i;
		}
	}
	pi['U'-'A']=char(piU+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//--------------------------------F------------------------------
	for(i=0;i<26;i++) {
		if(tfreq[i][piO][piR]>max_ap&&nuExista(i+'A')) {
			max_ap=tfreq[i][piO][piR];
			piF=i;
		}
	}
	pi['F'-'A']=char(piF+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//--------------------------------S------------------------------
	for(i=0;i<26;i++) {
		if(dfreq[piE][i]>max_ap&&nuExista(i+'A')) {
			max_ap=dfreq[piE][i];
			piS=i;
		}
	}
	pi['S'-'A']=char(piS+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//------------------------------L--------------------------------
	for(i=0;i<26;i++) {
		if((dfreq[i][i]>max_ap)&&nuExista(i+'A')) {
			max_ap=dfreq[i][i];
			piL=i;
		}
	}
	pi['L'-'A']=char(piL+'A');
	//---------------------------------------------------------------
	//------------------------------W-------------------------------
	piW=getW(fisier,piH+'A',piA+'A',piT+'A',pi);
	pi['W'-'A']=char(piW+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//-------------------------------Y-------------------------------
	for(i=0;i<26;i++) {
		if((dfreq[piL][i]>max_ap)&&nuExista(i+'A')) {
			max_ap=dfreq[piL][i];
			piY=i;
		}
	}
	pi['Y'-'A']=char(piY+'A');
	//---------------------------------------------------------------
	//-------------------------------V-------------------------------
	for(i=0;i<26;i++) {
		if(tfreq[i][piE][piR]>max_ap&&nuExista(i+'A')) {
			max_ap=tfreq[i][piE][piR];
			piV=i;
		}
	}
	pi['V'-'A']=char(piV+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//-------------------------------B-------------------------------
	for(i=0;i<26;i++) {
		if(dfreq[i][piE]>max_ap&&nuExista(i+'A')) {
			max_ap=dfreq[i][piE];
			piB=i;
		}
	}
	pi['B'-'A']=char(piB+'A');
	//---------------------------------------------------------------
	max_ap=0;
	//--------------------------------M------------------------------
	piM=getM(fisier,piE+'A',piN+'A',pi);
	pi['M'-'A']=char(piM+'A');
	//---------------------------------------------------------------
}

char revPi(char c) {
	bool ok=false;
	int i,poz;
	for(i=0;i<26;i++)
		if(pi[i]==c) {
			ok=true;
			poz=i;
		}
	if(ok) return tolower(char(poz+'A'));
	else return c;
}

void afisare(char *numetext){
	ifstream fin;
	ofstream fout;

	char c;

	fin.open(numetext,std::ios_base::in);
	fout.open("decode_text.txt",std::ios_base::out);
	while(fin>>c)
			fout<<revPi(c);
	fin.close();
	fout.close();

	fin.open("decode_text.txt",std::ios_base::in);
	
	for(int i=0;i<5000;i++)
		if(fin>>c)
			cout<<c;
	fin.close();

}

void decode(char *numetext){

	ifstream fin(numetext);

	if(!fin.is_open()) {
		cout<<"Se citeste din fisierul \"criptotext.txt!!!\"\n";
		fin.open("criptotext.txt",std::ios_base::in);
	}

	char c1,c2=-1,c3=-1;
	int i=0;

	while(fin>>c1){
		i++;
		pifreq[c1-'A']++;
		
		if(i==1) {
			c2=c1;
		}

		if(i==2) {
			dfreq[c2-'A'][c1-'A']++;
			c3=c2;
			c2=c1;
		}

		if(i>=3) {
			dfreq[c2-'A'][c1-'A']++;
			tfreq[c3-'A'][c2-'A'][c1-'A']++;
			c3=c2;
			c2=c1;
		}
	}

	getLetters(numetext);

	cout<<"Cheia gasita:\n";
	for(int i=0;i<26;i++)
		cout<<char(i+'A');
	cout<<"\n";
	for(int i=0;i<26;i++)
		cout<<pi[i];
	cout<<"\n\n";

	char c;
	fin.close();

	
	ofstream fout;
	/*("decode_text.txt")
	fin.open("criptotext.txt",std::ios_base::in);
	for(int i=1;i<=2000;i++)
	{
		fin>>c;
		fout<<revPi(c);
	}
	fin.close();
	fout.close();
	*/

	c=-1;
	cout<<"\n";
	while((c != 'n') || (c!='N')) {
		if((c=='y')||(c=='d')||(c=='D')||(c=='Y')||(c==-1))
			afisare(numetext);

		cout<<"\nDoriti sa interschimbati vreo litera? y/n\n";
		cin>>c;

		if(c=='y'||c=='d'||c=='D'||c=='Y') {
			cout<<"Litera: ";
			cin>>c1;
			c1=toupper(c1);
			cout<<"se inlocuieste cu: ";
			cin>>c2;
			c2=toupper(c2);

			for(int i=0;i<26;i++)
				if(pi[i]==c1)
					pi[i]=-1;

			pi[c2-'A']=c1;
		}
		else
			if(c=='n'||c=='N')
				break;
	}
	
	cout<<"Cheia finala gasita:\n";
	for(int i=0;i<26;i++)
		cout<<char(i+'A');
	cout<<"\n";
	for(int i=0;i<26;i++)
		cout<<pi[i];
	cout<<"\n\n";
}

int main() {
	getPlainText("text1.txt");
	getCryptoText();

	cout<<"\nFrecvente in plaintext \t Frecvente in criptotext.\n";
	for(int i=0;i<26;i++)
		cout<<(char)(i+'A')<<"->"<<cfreq[i]<<"\t\t\t "<<(char)(i+'A')<<"->"<<pifreq[i]<<"\n";

	getLetters("criptotext.txt");

	
	cout<<"\n\nCheia dupa care este criptat textul.\n";
	for(int i=0;i<26;i++) {
		cout<<char(i+'A');
	}
	cout<<"\n";
	for(int i=0;i<26;i++) {
		cout<<key[i];
	}
	cout<<"\n";

	
	cout<<"\n\nCheia gasita:\n";
	for(int i=0;i<26;i++) {
		cout<<char(i+'A');
	}
	cout<<"\n";
	for(int i=0;i<26;i++) {
		if(pi[i]>0)
			cout<<pi[i];
		else cout<<'*';
	}

	cout<<"\n\nComparatia intre cheia originala si cea gasita\n";
	for(int i=0;i<26;i++) {
		cout<<char(i+'A');
	}
	cout<<"\n";
	for(int i=0;i<26;i++) {
		cout<<key[i];
	}
	cout<<"\n";
	for(int i=0;i<26;i++) {
		if(pi[i]>0)
			cout<<pi[i];
		else cout<<'*';
	}
	
	
	cout<<"\n\n\n===============DECODARE================\n";
	
	decode("criptotext.txt");
	
	system("pause");
	return 0;
}