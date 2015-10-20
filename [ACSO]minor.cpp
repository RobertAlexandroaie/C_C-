#include <cstdio>
#include <cstdlib>

void minor(int *src,int *dst,int dim,int x,int y)
{
	_asm
	{
		mov edi,0
		mov esi,0
for_1:
		mov ebx,dim
		dec ebx
		cmp edi, ebx
		jae end
		mov ebx, dim
		dec ebx
		cmp esi,ebx
		jae inc_edi
		jmp for_2
inc_edi:
		inc edi
		mov esi,0
		jmp for_2
for_2:
		mov ebx, x
		mov ecx,0
		cmp edi,ebx
		jae minor_x
		jmp for_3

minor_x:
		mov ecx,1
		jmp for_3
for_3:
		push ecx
		mov ecx,y
		mov ebx,0
		cmp esi,ecx
		jae minor_y
		jmp for_4
minor_y:
		mov ebx,1
		jmp for_4
for_4:
		pop ecx
		add ecx,edi
		mov eax,4
		mov edx,0
		mul ecx
		add eax,esi
		add eax,ebx
		mov ecx,eax
		mov eax,4
		mov edx,0
		mul ecx
		mov edx,src
		mov ebx, dword ptr [eax+edx]
		push ebx
		mov eax,3
		mov edx,0
		mul edi
		add eax,esi
		shl eax,2
		mov edx,dst
		pop ebx
		mov [eax+edx],ebx
		inc esi
		jmp for_1

end:
	}

}


int main()
{
	int src[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	int dst[3][3];
	minor((int*)src,(int*)dst,4,2,2);	

	printf("a");
	for(int i=0;i<3;i++)
		{for(int j=0;j<3;j++)
      		  printf("%d ",src[i][j]);
	printf("\n");}



    printf("\n");
	system("pause");
	return 0;
}