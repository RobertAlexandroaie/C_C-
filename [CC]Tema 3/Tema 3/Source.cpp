#include<iostream>
#include<fstream>
#include<string.h>
#include<ctime>
#include"desboxes.h"

using namespace std;

//functia forteaza copierea caracterelor speciale cu codurile ascii mici
void strcopy(int size, char *destination, char *source)
{
	for(int i=0;i<size;i++)
		destination[i]=source[i];
}

//functia  calculeaza in destinatie, pe lungimea size, xorul dintre elementele celor 2 vectori
void xor(int size,char *destination, char *source)
{
	for(int i=0;i<size;i++)
		destination[i]^=source[i];
}


//functia returneaza un octet, de la un sir de 7 biti, care are pe ultima pozitie un bit de verificare 
char getByte(char bit_string)
{
	char byte=0;
	byte=bit_string;

	int nr_de_1=0;
	while(bit_string)
	{
		if(bit_string%2==1)
			nr_de_1++;
		bit_string>>=1;
	}

	byte=byte<<1;
	if(nr_de_1%2==0)
		byte=byte|1;

	return byte;
}


//functia atribuie vectorului key[8] valori generate sau introduse de la tastatura
void getKey()
{
	memset(key,0,8);

	int optiune=0;
	while(optiune!=1&&optiune!=2)
	{
		cout<<"*******************************\n";
		cout<<"*******************************\n";
		cout<<"    Ce tip de cheie doriti?\n";
		cout<<"*******************************\n";
		cout<<"1. Generata\n";
		cout<<"2. Introdusa\n";
		cout<<"*******************************\n";
		cout<<"Optiune:";
		cin>>optiune;
		cout<<"*******************************\n";
		cout<<"*******************************\n";
	}

	if(optiune==1)
	{
		int i=0;
		char byte=0;
		srand ( time(NULL) );
		
		while(i<8)
		{
			byte=rand() %  128;//generez un numar reprezentabil pe 7 biti (maximul fiind 127, pe biti 01111111)
			byte=getByte(byte);//pun bitul de verificare
			key[i++]=byte;//pun octetul in cheie
		}
	}
	else
	{
		int tip=0;
		while(tip!=1&&tip!=2)
		{
			cout<<"1. Hexadecimal\n";
			cout<<"2. Decimal\n";
			cout<<"*******************************\n";
			cout<<"Tip: ";
			cin>>tip;
		}
		if(tip==2)
		{
			cout<<"Introduceti cheia (caractere sau numere naturale mai mici decat 257:\n";
			for(int i=0;i<8;i++)
			{
				cout<<"key["<<i<<"]";
				cin>>key[i];//citesc valori intregi in cheie
			}
		}
		else
		{
			char c=0;
			int val=0;
			int indice_hexa=0;
			char byte=0;
			int i=0;

			for(int hexa_c=0;hexa_c<16;hexa_c++)
			{
				if(hexa_c%2==0)
					cout<<"key["<<hexa_c/2<<"]=";
				cin>>c;
				c=toupper(c);//daca e caracter, pun litera mare
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
					key[i++]=byte;
					indice_hexa=0;
					byte=0;
				}
			}
		}
	}
}

void initial_permutation(char permuted_bit_string[8], char bit_string[8])
{
	//char permuted_bit_string[8];
	//memset(permuted_bit_string,0,8);

	char byte_permutat=0;
	char byte=0;

	int indice_bit_string=0;
	int indice_byte=0;

	int i,j=0;
	for(i=0;i<64;i++)
	{
		indice_bit_string=0;
		indice_byte=0;

		indice_bit_string=(P0[i]-1)/8;
		indice_byte=(P0[i]-1)%8;

		byte=0;
		byte=(bit_string[indice_bit_string]&(1<<(7-indice_byte)));
		byte=(byte>>(7-indice_byte))&1;
		byte_permutat|=byte<<(7-(i%8));

		if((i+1)%8==0)
		{
			permuted_bit_string[j++]=byte_permutat;
			byte_permutat=0;
		}
	}
	//return permuted_bit_string;
}

void getPC1Key(char PC1Key[7], char original_key[8])
{
	memset(PC1Key,0,7);

	char byte_permutat=0;
	char byte=0;

	int indice_cheie=0;
	int indice_byte=0;

	int i=0,j=0;
	for(i=0;i<56;i++)
	{
		indice_cheie=0;
		indice_byte=0;

		indice_cheie=(PC1[i]-1)/8;
		indice_byte=(PC1[i]-1)%8;

		byte=0;
		byte=(original_key[indice_cheie]&(1<<(7-indice_byte)));
		byte=(byte>>(7-indice_byte))&1;
		byte_permutat|=byte<<(7-(i%8));

		if((i+1)%8==0)
		{
			PC1Key[j++]=byte_permutat;
			byte_permutat=0;
		}
	}
}

void cicle(char cicled_key[7], char roundPC1Key[7])
{
	char first_bits[4];
	memset(first_bits,0,4);

	char first_middle_byte=roundPC1Key[3];//punem octetul de mijloc
	char second_middle_byte=roundPC1Key[3];//in doi alti octeti

	first_middle_byte&=0xF0;//selectam doar primii 4 biti
	second_middle_byte&=0x0F;//selectam doar ultimii 4 biti

	first_bits[0]=roundPC1Key[0]&0xF0;//selectam primul bit din primul octet
	first_bits[0]=(first_bits[0]>>7)&1;//il deplasam la dreapta

	first_bits[1]=roundPC1Key[1]&0xF0;//selectam primul bit din al doilea octet
	first_bits[1]=(first_bits[1]>>7)&1;//il deplasam la dreapta
	
	first_bits[2]=roundPC1Key[2]&0xF0;//selectam primul bit din al 3-lea octet
	first_bits[2]=(first_bits[2]>>7)&1;//il deplasam la dreapta

	first_bits[3]=first_middle_byte&0xF0;//selectam primul bit din prima jumatate a octetului din mijloc
	first_bits[3]=(first_bits[3]>>7)&1;//il deplasam la dreapta

	roundPC1Key[0]=roundPC1Key[0]<<1;//shiftam la stanga primul octet, pierdem ultimul bit
	roundPC1Key[0]|=first_bits[1];//punem ca ultim bit primul bit din al doilea octet
	cicled_key[0]=roundPC1Key[0];//punem octetul format in sirul "ciclat"

	roundPC1Key[1]=roundPC1Key[1]<<1;//shiftam la stanga al doilea octet, pierdem ultimul bit
	roundPC1Key[1]|=first_bits[2];//punem ca ultim bit primul bit din al 3-lea octet
	cicled_key[1]=roundPC1Key[1];//punem octetul format in sirul "ciclat"

	roundPC1Key[2]=roundPC1Key[2]<<1;//shiftam la stanga al 3-lea octet, pierdem ultimul bit
	roundPC1Key[2]|=first_bits[3];//punem ca ultim bit primul bit din prima jumata-te al octetului din mijloc
	cicled_key[2]=roundPC1Key[2];//punem octetul format in sirul "ciclat"
	
	first_middle_byte=first_middle_byte<<1;//shiftam prima jumatate la stanga, pierdem al 5-lea octet
	first_middle_byte|=((first_bits[0]<<4)&0x10);//punem pe pozitia 5 primul bit din primul octet

	first_bits[0]=second_middle_byte&8;//selectam primul bit din a doua jumatate a octetului dn mijloc
	first_bits[0]=(first_bits[0]>>3)&1;//deplasam maxim la dreapta

	first_bits[1]=roundPC1Key[4]&0xF0;//selectam primul bit din al 5-lea octet
	first_bits[1]=(first_bits[1]>>7)&1;//il deplasam maxim la dreapta
	
	first_bits[2]=roundPC1Key[5]&0xF0;//selectam primul bit din al 6-lea octet
	first_bits[2]=(first_bits[2]>>7)&1;//il deplasam maxim la dreapta

	first_bits[3]=roundPC1Key[6]&0xF0;//selectam primul bit din ultimul octet
	first_bits[3]=(first_bits[3]>>7)&1;//il deplasam maxim la dreapta

	second_middle_byte=second_middle_byte<<1;//shiftam la stanga a doua jumatate a octetului din mijloc
	second_middle_byte&=0x0F;//ne asiguram ca pastram doar ultimile pozitii din octet (a doua jumatate)
	second_middle_byte|=first_bits[1];//punem pe ultimul bit, primul bit din al 5-lea octet

	roundPC1Key[4]=roundPC1Key[4]<<1;//shiftam la stanga al 5-lea octet, pierdem ultimul bit
	roundPC1Key[4]|=first_bits[2];//punem ca ultim bit, primul bit din al 6-lea octet
	cicled_key[4]=roundPC1Key[4];//salvam octetul format

	roundPC1Key[5]=roundPC1Key[5]<<1;//shiftam la stanga al 6-lea octet, pierdem ultimul bit
	roundPC1Key[5]|=first_bits[3];//punem ca ultim bit, primul bit din al 7-lea octet
	cicled_key[5]=roundPC1Key[5];//salvam octetul
	
	roundPC1Key[6]=roundPC1Key[6]<<1;//shiftam la stanga ultimul octet, pierdem ultimul bit
	roundPC1Key[6]|=first_bits[0];//punem ca ultim bit, primul bit din a doua jumatate al octetului din mijloc
	cicled_key[6]=roundPC1Key[6];//salvam octetul

	cicled_key[3]=0;
	cicled_key[3]|=(first_middle_byte&0xF0);
	cicled_key[3]|=(second_middle_byte&0x0F);
}

void getPC2Key(char PC2Key[6], char roundPC1Key[7])
{		
	char byte_permutat=0;
	char byte=0;

	int indice_cheie=0;
	int indice_byte=0;

	int i,j=0;
	for(i=0;i<48;i++)
	{
		indice_cheie=0;
		indice_byte=0;

		indice_cheie=(PC2[i]-1)/8;
		indice_byte=(PC2[i]-1)%8;

		byte=0;
		byte=(roundPC1Key[indice_cheie]&(1<<(7-indice_byte)));
		byte=(byte>>(7-indice_byte))&1;
		byte_permutat|=byte<<(7-(i%8));

		if((i+1)%8==0)
		{
			PC2Key[j++]=byte_permutat;
			byte_permutat=0;
		}
	}
}

void getRoundKeys (char key[8])
{
	char PC1Key[7];
	memset(PC1Key,0,7);
	
	getPC1Key(PC1Key,key);

	char roundPC1Keys[16][7];
	
	char aux1[7];
	memset(aux1,0,7);
	
	int i=0;

	for(i=0;i<16;i++)
	{
		memset(round_keys[i],0,6);
		memset(roundPC1Keys[i],0,7);
	}
	
	strcopy(7,aux1,PC1Key);
	cicle(roundPC1Keys[0],aux1);

	for(i=1;i<16;i++)
	{
		memset(aux1,0,7);
		if(i==1||i==8||i==15)
		{
			strcopy(7,aux1,roundPC1Keys[i-1]);
			cicle(roundPC1Keys[i], aux1);
		}
		else
		{
			strcopy(7,aux1,roundPC1Keys[i-1]);
			cicle(roundPC1Keys[i],aux1);
			strcopy(7,aux1,roundPC1Keys[i]);
			cicle(roundPC1Keys[i],aux1);
		}
	}

	for(i=0;i<16;i++)
	{
		memset(aux1,0,7);
		strcopy(7,aux1,roundPC1Keys[i]);
		getPC2Key(round_keys[i], aux1);
	}
}

void expand( char expanded_right_half[6], char right[4])
{
	memset(expanded_right_half,0,6);

	char byte_permutat=0;
	char byte=0;

	int indice_cheie=0;
	int indice_byte=0;

	int i,j=0;
	for(i=0;i<48;i++)
	{
		indice_cheie=0;
		indice_byte=0;

		indice_cheie=(E[i]-1)/8;
		indice_byte=(E[i]-1)%8;

		byte=0;
		byte=(right[indice_cheie]&(1<<(7-indice_byte)));
		byte=(byte>>(7-indice_byte))&1;
		byte_permutat|=byte<<(7-(i%8));

		if((i+1)%8==0)
		{
			expanded_right_half[j++]=byte_permutat;
			byte_permutat=0;
		}
	}

}

void s_permutation(char &s_permutation, char block_string,int indice)
{
	int row=0, column=0;

	row=block_string&0x20;
	row=(row>>4)&0x02;
	row=row|(block_string&0x01);
	row&=0x03;

	column=block_string&0x1E;
	column=column>>1;
	column=column&0x0F;
	
	switch(indice)
	{
		case 0: s_permutation=M1[row][column]; break;
		case 1: s_permutation=M2[row][column]; break;
		case 2: s_permutation=M3[row][column]; break;
		case 3: s_permutation=M4[row][column]; break;
		case 4: s_permutation=M5[row][column]; break;
		case 5: s_permutation=M6[row][column]; break;
		case 6: s_permutation=M7[row][column]; break;
		case 7: s_permutation=M8[row][column]; break;
	}
}

void p_permutation(char permuted_string[4], char *c_string)
{
	memset(permuted_string,0,4);
	
	char byte_permutat=0;
	char byte=0;

	int indice_bit_string=0;
	int indice_byte=0;

	int i,j=0;
	for(i=0;i<32;i++)
	{
		indice_bit_string=0;
		indice_byte=0;

		indice_bit_string=(P[i]-1)/8;
		indice_byte=(P[i]-1)%8;

		byte=0;
		byte=(c_string[indice_bit_string]&(1<<(7-indice_byte)));
		byte=(byte>>(7-indice_byte))&1;
		byte_permutat|=byte<<(7-(i%8));

		if((i+1)%8==0)
		{
			permuted_string[j++]=byte_permutat;
			byte_permutat=0;
		}
	}
}

void get_blocks(char blocks_string[8], char string[6])
{
	char byte=0;
	
	byte=string[0]&0xfc;
	byte>>=2;
	byte&=0x3F;
	blocks_string[0]=byte;

	byte=0;
	byte=string[0]&0x03;
	byte<<=4;
	byte&=0x30;
	byte|=(((string[1]&0xF0)>>4)&0x0F);
	byte&=0x3F;
	blocks_string[1]=byte;

	byte=0;
	byte=string[1]&0x0F;
	byte<<=2;
	byte&=0x3C;
	byte|=(((string[2]&0xC0)>>6)&0x03);
	byte&=0x3F;
	blocks_string[2]=byte;
	
	byte=0;
	byte=string[2]&0x3F;
	blocks_string[3]=byte;

	byte=0;
	byte=string[3]&0xfc;
	byte>>=2;
	byte&=0x3F;
	blocks_string[4]=byte;

	byte=0;
	byte=string[3]&0x03;
	byte<<=4;
	byte&=0x30;
	byte|=(((string[4]&0xF0)>>4)&0x0F);
	byte&=0x3F;
	blocks_string[5]=byte;

	byte=0;
	byte=string[4]&0x0F;
	byte<<=2;
	byte&=0x3C;
	byte|=(((string[5]&0xC0)>>6)&0x03);
	byte&=0x3F;
	blocks_string[6]=byte;

	byte=0;
	byte=string[5]&0x3F;
	blocks_string[7]=byte;
}

void f(char f_string[4], char right[4], char round_key[6])
{
	memset(f_string,0,4);

	char s_string[8];
	memset(s_string,0,8);

	char c_string[4];
	memset(c_string,0,4);

	char expanded_right[6];
	memset(expanded_right,0,6);
	
	expand(expanded_right, right);

	char string[6];
	memset(string,0,6);

	for(int i=0;i<6;i++)
		string[i]=expanded_right[i]^round_key[i];

	char blocks_string[8];
	memset(blocks_string,0,8);

	get_blocks(blocks_string,string);

	for(int i=0;i<8;i++)
		s_permutation(s_string[i], blocks_string[i],i);
	
	for(int i=0,j=0;i<4;i++)
	{
		c_string[i]=s_string[j++];
		c_string[i]=c_string[i]<<4;
		c_string[i]|=s_string[j++];
	}

	p_permutation(f_string, c_string);
}

void inv_initial_permutation(char permuted_bit_string[8], char left[4], char right[4])
{
	memset(permuted_bit_string,0,8);

	char bit_string[8];
	memset(bit_string,0,8);

	char byte_permutat=0;
	char byte=0;

	int indice_bit_string=0;
	int indice_byte=0;

	int i=0,j=0;

	for(i=0;i<8;i++)
		if(i<4)	bit_string[i]=left[i];
		else  bit_string[i]=right[i-4];

	for(i=0;i<64;i++)
	{
		indice_bit_string=0;
		indice_byte=0;

		indice_bit_string=(P0inv[i]-1)/8;
		indice_byte=(P0inv[i]-1)%8;

		byte=0;
		byte=(bit_string[indice_bit_string]&(1<<(7-indice_byte)));
		byte=(byte>>(7-indice_byte))&1;
		byte_permutat|=byte<<(7-(i%8));

		if((i+1)%8==0)
		{
			permuted_bit_string[j++]=byte_permutat;
			byte_permutat=0;
		}
	}
}

void afisare(ofstream *fout, char bit_string[8])
{
	char caracter=0;
	short int val=0;

	for(int i=0;i<8;i++)
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

void showKey(char key[8])
{
	char caracter=0;
	short int val=0;

	for(int i=0;i<8;i++)
	{
		val=key[i]&0xF0;
		val>>=4;
		val&=0x0F;
		if(val>9)
			caracter=char(val-10+'A');
		else
			caracter=char(val+48);
		cout<<caracter;

		val=key[i]&0x0F;
		val&=0x0F;
		if(val>9)
			caracter=char(val-10+'A');
		else
			caracter=char(val+48);
		cout<<caracter;
	}

}

void get_Hextext(char *nume_fisier_plain)
{
	ifstream fin(nume_fisier_plain);
	ofstream fout("hextext.txt");
	
	fin.unsetf(std::ios_base::skipws);

	char byte=0;
	int i=0;
	char bit_string[8];
	memset(bit_string,0,8);

	while(fin>>byte)
	{
		bit_string[i++]=byte;

		if(i==8)
		{
			i=0;
			afisare(&fout,bit_string);
			memset(bit_string,0,8);
		}
	}

	if(i!=0)
		afisare(&fout,bit_string);

	fin.close();
	fout.close();
}

void get_Criptotext(char *nume_fisier_plain)
{
	ifstream fin(nume_fisier_plain);
	ofstream fout("criptotext.txt");
	fin.unsetf(std::ios_base::skipws);
	fout.unsetf(std::ios_base::skipws);
	char l[4];
	memset(l,0,4);

	char r[4];
	memset(r,0,4);

	char aux[4];
	memset(aux,0,4);
	
	int i=0,round=0;

	char bit_string[8];
	memset(bit_string,0,8);
	
	char ip_bit_string[8];
	memset(ip_bit_string,0,8);
	
	char f_string[4];
	memset(f_string,0,4);

	char inv_init_permutation[8];
	memset(inv_init_permutation,0,8);

	getRoundKeys(key);
	char c=0;
	int val=0;
	int indice_hexa=0;
	char byte=0;

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

		if(i==8)
		{
			i=0;
			initial_permutation(ip_bit_string, bit_string);
			memset(bit_string,0,8);

			for(int j=0;j<8;j++)
				if(j<4)
					l[j]=ip_bit_string[j];
				else
					r[j-4]=ip_bit_string[j];
			//am salvat cei 64 biti in 2 vectori de cate 4 octeti;

			for(round=0;round<16;round++)
			{
				memset(aux,0,4);
				strcopy(4, aux,l);
				strcopy(4, l,r);
				memset(f_string,0,4);
				f(f_string,r,round_keys[round]);
				memset(r,0,4);
				strcopy(4, r, f_string);
				xor(4,r,aux);
			}
			inv_initial_permutation(inv_init_permutation,r,l);
			afisare(&fout,inv_init_permutation);
		}
	}

	fin.close();
	fout.close();
}

void get_Decriptohextext( char *nume_criptotext)
{
	char l[4];
	memset(l,0,4);

	char r[4];
	memset(r,0,4);

	char aux[4];
	memset(aux,0,4);
	
	int i=0,round=0;
	
	ifstream fin(nume_criptotext);
	ofstream fout("decriptohextext.txt");

	fin.unsetf(std::ios_base::skipws);

	char bit_string[8];
	memset(bit_string,0,8);
	
	char ip_bit_string[8];
	memset(ip_bit_string,0,8);
	
	char f_string[4];
	memset(f_string,0,4);

	char inv_init_permutation[8];
	memset(inv_init_permutation,0,4);
	
	char c=0;
	int val=0;
	int indice_hexa=0;
	char byte=0;

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
		
		if(i==8)
		{
			i=0;
			initial_permutation(ip_bit_string, bit_string);
			memset(bit_string,0,8);

			for(int j=0;j<8;j++)
				if(j<4)
					l[j]=ip_bit_string[j];
				else
				r[j-4]=ip_bit_string[j];
			//am salvat cei 64 biti in 2 vectori de cate 4 octeti;

			for(round=15;round>=0;round--)
			{
				memset(aux,0,4);
				strcopy(4, aux,l);
				strcopy(4, l,r);
				memset(f_string,0,4);
				f(f_string,r,round_keys[round]);
				memset(r,0,4);
				strcopy(4, r, f_string);
				xor(4,r,aux);
			}
			inv_initial_permutation(inv_init_permutation,r,l);
			afisare(&fout,inv_init_permutation);
		}
	}
	fin.close();
	fout.close();
}

void get_Decriptotext()
{
	ifstream fin("decriptohextext.txt");
	ofstream fout("decriptotext.txt");
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

void get_CriptoString(char source[8], char destination[8])
{
	char l[4];
	memset(l,0,4);

	char r[4];
	memset(r,0,4);

	char aux[4];
	memset(aux,0,4);
	
	int i=0,round=0;

	char f_string[4];
	memset(f_string,0,4);
	
	char c=0;
	int val=0;
	int indice_hexa=0;
	char byte=0;

	for(int j=0;j<8;j++)
		if(j<4)
			l[j]=source[j];
		else
			r[j-4]=source[j];
	//am salvat cei 64 biti in 2 vectori de cate 4 octeti;

	for(round=0;round<3;round++)
	{
		memset(aux,0,4);
		strcopy(4, aux,l);
		strcopy(4, l,r);
		memset(f_string,0,4);
		f(f_string,r,round_keys[round]);
		memset(r,0,4);
		strcopy(4, r, f_string);
		xor(4,r,aux);
	}

	for(int j=0;j<8;j++)
		if(j<4)
			destination[j]=l[j];
		else
			destination[j]=r[j-4];
}

void get_3RoundCriptoStrings()
{
	get_CriptoString(lr1,cripto_lr1);
	get_CriptoString(lr2,cripto_lr2);
	get_CriptoString(lr3,cripto_lr3);
	get_CriptoString(lr1_star,cripto_lr1_star);
	get_CriptoString(lr2_star,cripto_lr2_star);
	get_CriptoString(lr3_star,cripto_lr3_star);
}

void rev_p_permutation(char permuted_string[4], char *c_string)
{
	memset(permuted_string,0,4);
	
	char byte_permutat=0;
	char byte=0;

	int indice_bit_string=0;
	int indice_byte=0;

	int i,j=0;
	for(i=0;i<32;i++)
	{
		indice_bit_string=0;
		indice_byte=0;

		indice_bit_string=(Rev_P[i]-1)/8;
		indice_byte=(Rev_P[i]-1)%8;

		byte=0;
		byte=(c_string[indice_bit_string]&(1<<(7-indice_byte)));
		byte=(byte>>(7-indice_byte))&1;
		byte_permutat|=byte<<(7-(i%8));

		if((i+1)%8==0)
		{
			permuted_string[j++]=byte_permutat;
			byte_permutat=0;
		}
	}
}

void get_c_string(int pair, char rev_c[4])
{
	char c[8];
	memset(c,0,8);

	char l[4];
	memset(l,0,4);

	char l_star[4];
	memset(l_star,0,4);

	char cripto_r[4];
	memset(cripto_r,0,4);

	char cripto_r_star[4];
	memset(cripto_r_star,0,4);

	switch(pair)
	{
	case 1:
		strcopy(4,l,lr1);
		strcopy(4,l_star,lr1_star);
		strcopy(4,cripto_r,cripto_lr1+4);
		strcopy(4,cripto_r_star,cripto_lr1_star+4);
		break;
	case 2:
		strcopy(4,l,lr2);
		strcopy(4,l_star,lr2_star);
		strcopy(4,cripto_r,cripto_lr2+4);
		strcopy(4,cripto_r_star,cripto_lr2_star+4);
		break;
	case 3:
		strcopy(4,l,lr3);
		strcopy(4,l_star,lr3_star);
		strcopy(4,cripto_r,cripto_lr3+4);
		strcopy(4,cripto_r_star,cripto_lr3_star+4);
		break;
	}

	strcopy(4,c,l);
	xor(4,c,l_star);
	xor(4,c,cripto_r);
	xor(4,c,cripto_r_star);

	rev_p_permutation(rev_c,c);
}

void get_c_blocks(char c_blocks[8], char c[4])
{
	memset(c_blocks,0,8);

	c_blocks[0]=c[0]&0xF0;
	c_blocks[0]>>=4;
	c_blocks[0]&=0x0F;	
	
	c_blocks[1]=c[0]&0x0F;
	c_blocks[1]&=0x0F;

	c_blocks[2]=c[1]&0xF0;
	c_blocks[2]>>=4;
	c_blocks[2]&=0x0F;

	c_blocks[3]=c[1]&0x0F;
	c_blocks[3]&=0x0F;

	c_blocks[4]=c[2]&0xF0;
	c_blocks[4]>>=4;
	c_blocks[4]&=0x0F;

	c_blocks[5]=c[2]&0x0F;
	c_blocks[5]&=0x0F;

	c_blocks[6]=c[3]&0xF0;
	c_blocks[6]>>=4;
	c_blocks[6]&=0x0F;

	c_blocks[7]=c[3]&0x0F;
	c_blocks[7]&=0x0F;
}

void get_terms(int pair,char e_blocks[8], char e_star_blocks[8], char c_blocks[8])
{
	char l[4];
	memset(l,0,4);

	char l_star[4];
	memset(l_star,0,4);

	switch(pair)
	{
	case 1:
		strcopy(4,l,cripto_lr1);
		strcopy(4,l_star,cripto_lr1_star);
		break;
	case 2:
		strcopy(4,l,cripto_lr2);
		strcopy(4,l_star,cripto_lr2_star);
		break;
	case 3:
		strcopy(4,l,cripto_lr3);
		strcopy(4,l_star,cripto_lr3_star);
		break;
	}

	char e[6];
	memset(e,0,4);
	expand(e,l);

	memset(e_blocks,0,6);
	get_blocks(e_blocks,e);

	char e_star[6];
	memset(e_star,0,6);
	expand(e_star,l_star);

	memset(e_star_blocks,0,8);
	get_blocks(e_star_blocks,e_star);

	char c[4];
	memset(c,0,4);
	get_c_string(pair,c);
	get_c_blocks(c_blocks,c);
}

void cicle_right(char cicled_key[7], char key[7])
{
	char byte=0;

	char last_bits[4];
	memset(last_bits,0,4);

	char first_middle_byte=key[3];
	char second_middle_byte=key[3];

	first_middle_byte&=0xF0;
	second_middle_byte&=0x0F;

	last_bits[0]=key[0]&0x01;
	last_bits[1]=key[1]&0x01;
	last_bits[2]=key[2]&0x01;
	last_bits[3]=key[3]&0x10;
	last_bits[3]>>=4;
	last_bits[3]&=0x01;

	byte=key[0]>>1;
	byte&=0x7F;
	byte|=(last_bits[3]<<7)&0x80;
	cicled_key[0]=byte;

	byte=key[1]>>1;
	byte&=0x7F;
	byte|=(last_bits[0]<<7)&0x80;
	cicled_key[1]=byte;

	byte=key[2]>>1;
	byte&=0x7F;
	byte|=(last_bits[1]<<7)&0x80;
	cicled_key[2]=byte;
	
	first_middle_byte=first_middle_byte>>1;
	first_middle_byte&=0x70;
	first_middle_byte|=((last_bits[2]<<7)&0x80);

	last_bits[0]=second_middle_byte&0x01;
	last_bits[1]=key[4]&0x01;
	last_bits[2]=key[5]&0x01;
	last_bits[3]=key[6]&0x01;
	
	second_middle_byte=second_middle_byte>>1;
	second_middle_byte&=0x07;
	second_middle_byte|=(last_bits[3]<<3)&0x08;

	byte=key[4]>>1;
	byte&=0x7F;
	byte|=(last_bits[0]<<7)&0x80;
	cicled_key[4]=byte;

	byte=key[5]>>1;
	byte&=0x7F;
	byte|=(last_bits[1]<<7)&0x80;
	cicled_key[5]=byte;
	
	byte=key[6]>>1;
	byte&=0x7F;
	byte|=(last_bits[2]<<7)&0x80;
	cicled_key[6]=byte;
	
	cicled_key[3]=0;
	cicled_key[3]|=(first_middle_byte&0xF0);
	cicled_key[3]|=(second_middle_byte&0x0F);
}

void compress(char compr_key[6],char key[8])
{
	compr_key[0]=key[0];
	compr_key[0]<<=2;
	compr_key[0]&=0xFC;
	compr_key[0]|=((key[1]&&0x30)>>4)&0x03;

	compr_key[1]=key[1];
	compr_key[1]<<=4;
	compr_key[1]&=0xF0;
	compr_key[1]|=(((key[2]&0x3C)>>2)&0x0F);

	compr_key[2]=(key[2]&0x03);
	compr_key[2]<<=6;
	compr_key[2]&=0xC0;
	compr_key[2]|=key[3];

	compr_key[3]=key[4];
	compr_key[3]<<=2;
	compr_key[3]&=0xFC;
	compr_key[3]|=((key[5]&0x30)>>4)&0x03;

	compr_key[4]=(key[5]<<4)&0xF0;
	compr_key[4]|=((key[6]&0x3C)>>2)&0x0F;

	compr_key[5]=(key[6]&0x03);
	compr_key[5]<<=6;
	compr_key[5]&=0xC0;
	compr_key[5]|=key[7];
}

void get_revPC2Key(char roundPC1Key[7], char PC2Key[6])
{		
	char byte_permutat=0;
	char byte=0;

	int indice_cheie=0;
	int indice_byte=0;

	int i,j=0;
	for(i=0;i<56;i++)
	{
		indice_cheie=0;
		indice_byte=0;

		if(Rev_PC2[i]!=0)
		{
			indice_cheie=(Rev_PC2[i]-1)/8;
			indice_byte=(Rev_PC2[i]-1)%8;

			byte=0;
			byte=(PC2Key[indice_cheie]&(1<<(7-indice_byte)));
			byte=(byte>>(7-indice_byte))&1;
			byte_permutat|=byte<<(7-(i%8));
		}
		else
		{
			byte=0;
			byte_permutat|=byte<<(7-(i%8));
		}


		if((i+1)%8==0)
		{
			roundPC1Key[j++]=byte_permutat;
			byte_permutat=0;
		}
	}
}

void get_revPC1Key(char original_key[8],char PC1Key[7])
{
	char byte_permutat=0;
	char byte=0;

	int indice_cheie=0;
	int indice_byte=0;

	int i=0,j=0;
	for(i=0;i<64;i++)
	{
		indice_cheie=0;
		indice_byte=0;

		if(Rev_PC1[i]!=0)
		{
			indice_cheie=(Rev_PC1[i]-1)/8;
			indice_byte=(Rev_PC1[i]-1)%8;

			byte=0;
			byte=(PC1Key[indice_cheie]&(1<<(7-indice_byte)));
			byte=(byte>>(7-indice_byte))&1;
			byte_permutat|=byte<<(7-(i%8));
		}
		else
		{
			byte=0;
			byte_permutat|=byte<<(7-(i%8));
		}

		if((i+1)%8==0)
		{
			original_key[j++]=byte_permutat;
			byte_permutat=0;
		}		
	}
}

void setParityBits(char possible_key[8])
{
	int i=0;
	int j=0;
	int contor=0;
	for(i=0;i<8;i++)
	{
		contor=0;
		for(j=2;j<=128;j<<=1)
			if((possible_key[i]&j)!=0)
				contor++;

		if(contor%2==0)
			possible_key[i]|=0x01;
	}
}

void get_3RoundCripto(char possible_key[8], char source[8], char destination[8])
{
	getRoundKeys(possible_key);

	char l[4];
	memset(l,0,4);

	char r[4];
	memset(r,0,4);

	char aux[4];
	memset(aux,0,4);
	
	int i=0,round=0;

	char f_string[4];
	memset(f_string,0,4);
	
	memset(destination,0,8);

	char c=0;
	int val=0;
	int indice_hexa=0;
	char byte=0;

	for(int j=0;j<8;j++)
		if(j<4)
			l[j]=source[j];
		else
			r[j-4]=source[j];

	for(round=0;round<3;round++)
	{
		memset(aux,0,4);
		strcopy(4, aux,l);
		strcopy(4, l,r);
		memset(f_string,0,4);
		f(f_string,r,round_keys[round]);
		memset(r,0,4);
		strcopy(4, r, f_string);
		xor(4,r,aux);
	}

	for(int j=0;j<8;j++)
		if(j<4)
			destination[j]=l[j];
		else
			destination[j]=r[j-4];
}

bool compare(char a[8], char b[8])
{
	if(a[0]==b[0]&&
		a[1]==b[1]&&
		a[2]==b[2]&&
		a[3]==b[3]&&
		a[4]==b[4]&&
		a[5]==b[5]&&
		a[6]==b[6]&&
		a[7]==b[7])
		return true;
	return false;
}

void get_Key()
{
	get_3RoundCriptoStrings();

	int pereche=0;
	int bit_bloc=0;
	int key=0;

	char e_blocks[8];
	memset(e_blocks,0,8);

	char e_star_blocks[8];
	memset(e_star_blocks,0,8);
	
	char c_blocks[8];
	memset(c_blocks,0,8);
	
	char key_blocks[8];
	memset(key_blocks,0,8);

	char s_e;
	char s_e_star;
	char comp;
	char aux=0;

	for(bit_bloc=0;bit_bloc<8;bit_bloc++)
		for(key=0;key<64;key++)
			key_contor[bit_bloc][key]=0;

	for(pereche=0;pereche<3;pereche++)
	{
		get_terms(pereche+1,e_blocks,e_star_blocks,c_blocks);

		for(bit_bloc=0;bit_bloc<8;bit_bloc++)
			for(key=0;key<64;key++)
			{
				aux=0;
				s_e=0;
				s_e_star=0;

				aux=e_blocks[bit_bloc]^key;
				s_permutation(s_e,aux,bit_bloc);

				aux=e_star_blocks[bit_bloc]^key;
				s_permutation(s_e_star,aux,bit_bloc);

				s_e^=s_e_star;
				if(s_e==c_blocks[bit_bloc])
					key_contor[bit_bloc][key]++;
			}
	}

	int i=0;
	for(bit_bloc=0;bit_bloc<8;bit_bloc++)
		for(key=0;key<64;key++)
			if(key_contor[bit_bloc][key]==3)
				key_blocks[i++]=key;

	char compressed_key[6];
	compress(compressed_key,key_blocks);

	char rev_pc2_key[7];
	get_revPC2Key(rev_pc2_key,compressed_key);

	char cicled_key[7];
	char aux1[7];

	cicle_right(cicled_key,rev_pc2_key);
	

	strcopy(7,aux1,cicled_key);
	cicle_right(cicled_key,aux1);
	
	strcopy(7,aux1,cicled_key);
	cicle_right(cicled_key,aux1);
	
	strcopy(7,aux1,cicled_key);
	cicle_right(cicled_key,aux1);

	char possible_key[8];
	memset(possible_key,0,8);
	get_revPC1Key(possible_key,cicled_key);

	char b_key[8];
	strcopy(8,b_key,possible_key);

	int b1,b2,b3,b4,b5,b6,b7,b8;
	b1=b2=b3=b4=b5=b6=b7=b8=0;

	char octet=0;
	char cripted_text[8];

	for(b1=0;b1<2;b1++)
		for(b2=0;b2<2;b2++)
			for(b3=0;b3<2;b3++)
				for(b4=0;b4<2;b4++)
					for(b5=0;b5<2;b5++)
						for(b6=0;b6<2;b6++)
							for(b7=0;b7<2;b7++)
								for(b8=0;b8<2;b8++)
								{
									strcopy(8,b_key,possible_key);

									octet=0x00;
									octet|=b1<<7;
									octet&=0x80;
									b_key[7]|=octet;

									octet=0x00;
									octet|=b2<<6;
									octet&=0x40;
									b_key[3]|=octet;
									
									octet=0x00;
									octet|=b3<<5;
									octet&=0x20;
									b_key[2]|=octet;
									
									octet=0x00;
									octet|=b4<<4;
									octet&=0x10;
									b_key[6]|=octet;
								
									octet=0x00;
									octet|=b5<<3;
									octet&=0x08;
									b_key[5]|=octet;
									
									octet=0x00;
									octet|=b6<<2;
									octet&=0x04;
									b_key[5]|=octet;
									
									octet=0x00;
									octet|=b7<<1;
									octet&=0x02;
									b_key[6]|=octet;

									octet=0x00;
									octet|=b8<<2;
									octet&=0x04;
									b_key[2]|=octet;

									get_3RoundCripto(b_key,lr1,cripted_text);

									if(compare(cripted_text,cripto_lr1))
									{
										setParityBits(b_key);
										strcopy(8,found_key,b_key);
										return ;
									}
								}
}

int main()
{
	//getKey();

	///*
	key[0]=0x1A;
	key[1]=0x62;
	key[2]=0x4C;
	key[3]=0x89;
	key[4]=0x52;
	key[5]=0x0D;
	key[6]=0xEC;
	key[7]=0x46;
	//*/
	cout<<"Cheia initiala: ";
	showKey(key);

	get_Hextext("plaintext.txt");
	get_Criptotext("hextext.txt");
	get_Decriptohextext("criptotext.txt");
	get_Decriptotext();
	
	get_Key();
	cout<<"\nCheia gasita:   ";
	showKey(found_key);
	cout<<"\n";

	system("pause");
	return 0;
}
