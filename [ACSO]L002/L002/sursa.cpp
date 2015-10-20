/*
#include <stdio.h>
#define LEAST_SEMNIF 55607
#define SEMNIF 1

//Sa se scrie codul in limbaj de asamblare care calculeaza suma: 1+2+3+...+n, unde n = 92682 
//Atentie, aceasta suma nu se poate reprezenta folosind doar 32 de biti.

void main(){
	int n;
	n = 92682;
	int least_semnif,semnif;
	_asm{
		/*In acest bloc scrieti codul ASM
	}
	if( least_semnif == LEAST_SEMNIF && SEMNIF == semnif){
		printf("Ok!\n");
	}else{
		printf("Failed! Your result is: %d*pow(2,32)+%d\n",semnif, least_semnif);
	}	
}

*/


#include <stdio.h>
#define LEAST_SEMNIF 55607
#define SEMNIF 1

//Sa se scrie codul in limbaj de asamblare care calculeaza suma: 1+2+3+...+n, unde n = 92682 
//Atentie, aceasta suma nu se poate reprezenta folosind doar 32 de biti.

void main(){
	int n;
	n = 92682;
	int least_semnif,semnif;
	_asm{
	 mov eax, n;
	 mov ebx,eax;
	 add eax,1;
	 mul ebx;
	 mov ecx,2;
	 div ecx;
     mov x,eax;
	}
	if( least_semnif == LEAST_SEMNIF && SEMNIF == semnif){
		printf("Ok!\n");
	}else{
		printf("Failed! Your result is: %d*pow(2,32)+%d\n",semnif, least_semnif);
	}	
}