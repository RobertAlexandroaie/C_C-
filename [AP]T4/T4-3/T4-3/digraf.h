typedef struct nod
{
	int info;
	nod *leg;
}nod;

typedef struct Digraf
{
	int numar_noduri;
	nod *lista[50];
}Digraf;

typedef struct nodq
{
	int element;
	nodq *suc;
}nodq;

typedef struct coada
{
	nodq *pr,*ul;
}coada;


void creeaza(Digraf *dig, char *nume_fisier);
void afisare(Digraf dig);
int grad_int(Digraf dig, int varf);
int grad_ext(Digraf dig, int varf);
void succesori(Digraf dig,int varf);
void predecesori(Digraf dig,int varf);
int este_tare_conex(Digraf dig);


//Problema 4
coada *coadaVida();
void insereaza(coada *queue, int val);
void elimina(coada *queue);

int varf_groapa(Digraf dig);
int lung_drum_minim(Digraf dig,int varf1,int varf2);
Digraf transpus(Digraf dig);
void componente_tare_conexe(Digraf dig);