typedef struct nod
{
	int info;
	nod *leg;
}nod;

typedef struct Graf
{
	int numar_noduri;
	nod *lista[50];
}Graf;


void creeaza(Graf *gr, char *nume_fisier);
void afisare(Graf gr);
void test_arbore(Graf gr,int varf);
void este_arbore(Graf gr);