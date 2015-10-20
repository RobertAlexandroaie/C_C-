#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>


int prim(int n)
{
    int k=5;
    
    if(n==2)
	return 1;
    if(n%2==0)
	return 0;
	
    if(n==3)
	return 1;
	
    while(k<=n/2)
    {
	if(n%k==0)
	    return 0;
	else
	    k+=2;
    }
    return 1;
}

int main()
{

    pid_t pid;
    int ret_fiu;

    int i,j,l,k1,k2;
    i=598;
    j=5;
    
    switch(pid=fork()) {
    case -1:
	perror("fork");
	exit(1);
    case 0:
	printf("PRIME: 2\n");
	printf("PRIME: 3\n");
	while(i>0)
	{
	    if(prim(j))
	    {
		i--;
		printf("PRIME: %d\n",j);
	    }
	    j+=2;
	}
	exit(ret_fiu);
	
    default:
	for(i=0;i<=2000;i+=2)
	    printf("pare: %d\n",i);
	wait(&ret_fiu);
    }
    return 0;
}