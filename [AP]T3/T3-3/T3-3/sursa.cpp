/*
Se consideră un tablou unidimensional de dimensiune mare care conţine elemente alocate  
        (ocupate) şi elemente nealocate (disponibile). Ne putem imagina că acest tablou reprezintă  
        memoria unui calculator (element al tabloului = cuvânt de memorie). Zonele ocupate (sau zonele  
        libere) din tablou sunt gestionate cu ajutorul unei liste înlănţuite. Asupra tabloului se execută  
        următoarele operaţii: 
        * aloca(m) - determină o secvenţă de m elemente succesive nealocate. Adresa şi lungimea  
        acesteia sunt adăugate ca un nou element la lista zonelor ocupate (sau o elimină din lista zonelor  
        libere). Funcţia returnează adresa zonei determinate. Dacă nu se poate aloca o asemenea  
        secvenţă funcţia returnează valoarea -1. 

        * elibereaza(a, m) - disponibilizează secvenţa de lungime m începând cu adresa a. Lista zonelor  
        ocupate (sau a zonelor libere) este actualizată corespunzător. 

        * defragmenteaza() - rearanjează zonele ocupate astfel încât să existe o singură zona disponibilă  
        (sau compactarea zonelor disponibile); Lista zonelor ocupate (sau a zonelor libere) va fi  
        actualizată corespunzător. Desigur, din motive de spaţiu insuficient, tabloul de dimensiune mare  
        nu va fi reţinut în programul dumneavoastră. 

         Exemple: Pentru un tablou de dimensiune 10 care alocă zonele cu adresele 0, 1, …, 8, 9, lista cu  
        zonele ocupate este iniţial Φ. După apelul funcţiei aloca(3), care va întoarce, spre exemplu,  
        adresa 4, lista cu zonele ocupate va fi <4, 3> → Φ (unde <x, y> poate însemna ocuparea a y  
        elemente succesive începând cu elementul de la adresa x), iar tabloul mare va avea forma [0, 0,  
        0, 0, 1, 1, 1, 0, 0, 0]. După apelul funcţiei aloca(2), care va întoarce, spre exemplu, adresa 8, lista  
        cu zonele ocupate va fi <4, 3> → <8, 2> → Φ, care va reprezenta tabloul mare de forma [0, 0, 0,  
        0, 1, 1, 1, 0, 1, 1]. Un apel al funcţiei aloca(5) va întoarce -1, deoarece nu există o secvenţă  
        continuă/contiguă de 5 zone nealocate. După apelul funcţiei elibereaza(5, 4), lista cu zonele  
        ocupate va fi <4, 1> → <9, 1> → Φ, iar tabloul mare de forma [0, 0, 0, 0, 1, 0, 0, 0, 0, 1]. După  
        apelul funcţiei defragmenteaza(), lista cu zonele ocupate va fi <0, 2>→ Φ, iar tabloul mare de  
        forma următoare: [1, 1, 0, 0, 0, 0, 0, 0, 0, 0]. Apelul funcţiei aloca(5) va întoarce de această dată o  
        adresă validă, deoarece în acest moment se poate aloca o secvenţă continuă/contiguă de 5  
        elemente. 

*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

typedef struct nod
{
	int adr, ap;
	nod *suc;
}nod;


typedef struct Llin
{
	nod *prim,*ult;
}Llin;

Llin ll,*pll;//ll=lista spatiilor libere
int numar_maxim_memorabil;


//initializeaza lista vida
Llin listaVida()
{
	Llin L;
	L.prim=NULL;
	L.ult=NULL;
	return L;
}
//


//initializeza lista corespunzatoare tabloului gol(0 de nr. maxim ori)
void inLista(Llin *L)
{
	nod *p=(nod*)malloc(sizeof(nod));
	L->prim=p;
	L->ult=p;
	p->adr=0;
	p->ap=numar_maxim_memorabil;
	p->suc=NULL;
}
//


//afiseaza lista
void afisare(Llin L)
{
	nod *p=(nod*)malloc(sizeof(nod));
	for(p=L.prim;p!=NULL;p=p->suc)
		printf("<%d,%d> ",p->adr,p->ap);
}
//


//calculeaza lungimea listei(nr de noduri din lista)
int lung(Llin L)
{
	int l=0;
	nod *p;
	for(p=L.prim;p!=NULL;p=p->suc)
		l++;
	return l;
}
//


//aloca, daca se poate, in "tablou" m numere (completeaza tabloul cu 1 pe m pozitii succesive) 
int aloca(int m)
{

	nod *p,*q;
	int ok=0;
	int k=0;
	int i,l=lung(ll);


	while(!ok)
	{
		int r=(rand()%l+k++)%l+1;//se alege un numar aleatoriu intre 1 si lungimea listei

		if(l==1)
		{
			r=1;
			ok=1;
		}
			
		for(i=1,p=ll.prim;i<=r;i++)
			if(i>2)
				p=p->suc;
		//se ajunge la nodul precedent celui ales aleatoriu
		if(p->suc==NULL)
			if((p->ap)>=m)
				ok=1;
		if(p->suc!=NULL)
			if(p->suc->ap>=m)
				ok=1;
		//daca numarul de aparitii este mai mare sau egal (suporta) m=numarul de "valori" introduse in tabel=extrase din lista
		//ok=1 deci ne oprim cu generarea de numere aleatorii si incheiem cautarea;
		if(k>m) 
			return -1;
	}

	int s;

	//daca lista are un singur nod(tabloul este impartit in 2 sau 3 zone)
	if(l==1)
	{
		
		s=rand()%(p->ap-m)+(p->adr)+1;
		//generam un alt numar aleatoriu care reprezinta de la ce numar din intervalul/nodul gasit introducem valori/scoatem m valori din tabel
		

		if(s==ll.prim->adr)
		{
			ll.prim->adr+=s;
			ll.prim->ap-=m;
			return s;
		}

		if(s==ll.prim->adr+ll.prim->ap-m-1)
		{
			ll.prim->ap-=m;
			return s;
		}

		if((s!=(ll.prim->adr+ll.prim->ap-m-1))&&(s!=(ll.prim->adr)))
		{
			p=(nod*)malloc(sizeof(nod));
			p->adr=s+m;
			p->ap=ll.prim->adr+ll.prim->ap-p->adr;

			ll.prim->suc=p;
			ll.prim->ap=ll.prim->ap+ll.prim->adr-s;
			ll.ult=p;
			return s;
		}
	}
	//<0,10>
	//daca lista are mai multe noduri
	
	s=rand()%(p->ap-m)+(p->adr)+1;
	nod *aux=p->suc;//pastram pozitia lui p separat si salvam in aux restul listei;
	q=(nod*)malloc(sizeof(nod));
	
	//daca s e extremitatea din stanga (adica adresa), scoatem din interval primele m numere;
	if(s==aux->adr)
	{
		aux->adr+=m;
		aux->ap-=m;
		return s;
	}

	//daca s e extremitatea din dreapta a intervalului
	if(s==aux->adr+aux->ap-m)
	{
		aux->ap-=m;
		return s;
	}

	//daca numarul nu este o extremitate, se imparte intervalul in 2 intervale care nu contin acele elemente introduse in lista
	if((s!=(aux->adr))&&(s!=(aux->adr)+(aux->ap)-m))
	{
		q=(nod*)malloc(sizeof(nod));
		q->adr=s+m;
		q->ap=aux->adr+aux->ap-q->adr;
		q->suc=aux->suc;

		aux->ap=s-aux->adr;
		aux->suc=q;
		return s;
	}

	return -1;
}


void elibereaza(int a,int m)
{
	int i,l;
	nod *p,*q,*t;
	
	int x=a+m-1;

	l=lung(ll);

	for(p=ll.prim;p!=NULL;p=p->suc)
		if((p->ap<=x)&&(p->ap+p->adr>x))
			return;

	for(i=1,p=ll.prim;i<=l;i++,p=p->suc)
	{
		if((p->suc->adr)>=a+m)
			i=l+1;
	}

	//cazul 1, se elibereaza o zona lipita de p;
	if((a==(p->adr+p->ap))&&(x<(p->suc->adr)))
	{
		p->adr+=m;
		return;
	}

	//cazul 2, se elibereaza o zona lipita de suc. lui p
	if((a>(p->adr+p->ap))&&((x+1)==(p->suc->adr)))
	{
		p->suc->adr=a;
		p->suc->ap+=m;
		return;
	}

	//cazul 3, se elibereaza o zona lipita ambelor noduri
	q=p->suc;
	if((a==(p->adr+p->ap))&&((x+1)==(p->suc->adr)))
	{
		p->ap+=m+q->ap;
		p->suc=q->suc;
		return;
	}

	//cazul 4, se elibereaza o zona de memorie diferita de cele doua noduri
	if((a>(p->adr+p->ap))&&(x<(p->suc->adr)))
	{
		t=(nod*)malloc(sizeof(nod));
		t->adr=a;
		t->ap=m;
		p->suc=t;
		t->suc=q;
		return;
	}
}


void defragmenteaza()
{
	int i=1,l=lung(ll),x=0;
	nod *p;
	for(p=ll.prim;p!=NULL;p=p->suc)
		x+=p->ap;
	
	ll=listaVida();
	p=(nod*)malloc(sizeof(nod));
	p->adr=numar_maxim_memorabil-x;
	p->ap=x;
	ll.prim=p;
	ll.ult=p;
}


int main()
{
	printf("Introduceti numarul maxim memorabil:");
	scanf("%d",&numar_maxim_memorabil);

	ll=listaVida();
	inLista(&ll);
	afisare(ll);

	
	aloca(2);
	afisare(ll);
	

	system("pause");
	return 0;
}