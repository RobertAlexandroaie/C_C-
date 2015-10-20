typedef struct nodcuv
{
	char info[20];
	nodcuv *leg;
}nodcuv;

void init(int *a);
void caps(char *cuvant);
void adauga_cuv(nodcuv **a, char *c);
void creare_cuvinte(nodcuv **a,char *fisier_in);
void afisare_cuv(nodcuv **a);
void set_litere(int *a,char *cuvant);
void reset_litere(int *a,char *cuvant);
int e_ananagrama(int *a);
void ad_ananagrama(char *cuvant);
void ananagrame(nodcuv **a);
void sort_ananagrame(nodcuv *x);
void scrie_ananagrame(char *fisier_out);