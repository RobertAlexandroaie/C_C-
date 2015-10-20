typedef struct NodArboreBinar
{
	char info;
	NodArboreBinar *st,*dr;
}NodArboreBinar;

typedef struct nodst
{
	NodArboreBinar *element;
	nodst *pred;
}nodst;

typedef struct nodq
{
	NodArboreBinar *element;
	nodq *suc;
}nodq;

typedef struct stiva
{
	nodst *top;
}stiva;

typedef struct coada
{
	nodq *pr,*ul;
}coada;


stiva stivaVida();
void push(stiva *s, NodArboreBinar *x);
NodArboreBinar *top(stiva s);
void pop(stiva *s);

coada coadaVida();
void insereaza(coada *C, NodArboreBinar *x);
int esteVida(coada C);
void citeste(coada C, NodArboreBinar *x);
void elimina(coada *C);

NodArboreBinar* construiesteArb(char a[], int n);
void RSD(NodArboreBinar *radacina);
void SRD(NodArboreBinar *radacina);
void SDR(NodArboreBinar *radacina);
void BFS(NodArboreBinar *radacina);



//PROBLEMA 2

void oglindireArb(NodArboreBinar *radacina);
int numarNoduriArb(char a[],int n);
void afisareNiv(char a[],int n,int nivel);
int nrNoduri_cu_un_singur_fiu(char a[],int n);
void afisareKSRD(NodArboreBinar *radacina, int k);


