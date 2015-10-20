#include<stdio.h>

void minor(int *src, int *dst,int dim, int x, int y)
{
	_asm{
		mov edi,[ebp+12]//eax=p=src
		mov ebx,[ebp+8]//ebx=q=dst
		xor ecx,ecx//contoar pt i
		xor edx,edx//contoar pt j
		xor esi,esi
bucla_for1:
		cmp ecx,[ebp+24]
		jae finish_for1
bucla_for2:
		cmp edx,[ebp+24]
		jae finish_for2
		mov eax,[ebp+24]
		push edx
		mul ecx
		pop edx
		add eax,edx
		mov esi,dword ptr[edi+eax*4]//esi preia adresa src
		mov eax,[ebp+24]
		dec eax
		cmp ecx,[ebp+20]
		jae i_depaseste
		push edx
		mul ecx
		pop edx
		jmp continuare_i
i_depaseste:
		dec ecx
		push edx
		mul ecx
		pop edx
		inc ecx
continuare_i:
		add eax,edx
		cmp edx,[ebp+16]
		jb continuare_j
		dec eax
continuare_j:
		mov [ebx+eax*4],esi
		inc edx
		jmp bucla_for2
finish_for2:
		inc ecx
		xor edx,edx
		jmp bucla_for1

finish_for1:


	}

}




int main()
{
	int i,j,x=2,y=3,n=5;
	int a[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	int b[4][4];
	int *p,*q;
	p=a[0];
	q=b[0];
	for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
	    printf("\n\n");
	    }
	_asm{
		push n
		push x
		push y
		push p
		push q
		call minor
		add esp,20
	}

	for(i=0;i<n-1;i++)
		{for(j=0;j<n-1;j++)
			printf("%d ",b[i][j]);
	    printf("\n\n");
	    }

	getchar();
	return 0;
}