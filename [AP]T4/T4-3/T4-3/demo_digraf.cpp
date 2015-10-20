#include<iostream>
#include<stdio.h>
#include"digraf.h"

int main()
{
	Digraf dig,transpus_dig;

	creeaza(&dig,"digraf.in");
	
	afisare(dig);

	/*
	printf("%d ",grad_int(dig,1));
	printf("\n%d ",grad_ext(dig,2));

	if(este_tare_conex(dig))
		printf("Digraful este tare conex!\n");
	else
		printf("Digraful nu este tare conex!\n");

	
	int vf_groapa=varf_groapa(dig);
	if(vf_groapa==-1)
		printf("Nu exista varfuri groapa!\n");
	else
		printf("Un varf groapa gasit este: %d.\n",vf_groapa);

	printf("%d ",lung_drum_minim(dig,3,2));
	
	transpus_dig=transpus(dig);
	afisare(transpus_dig);

	*/

	componente_tare_conexe(dig);
	

	system("pause");
	return 0;
}