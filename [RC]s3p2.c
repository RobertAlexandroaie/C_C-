#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int fd[2], nbytes;
    pid_t pid;
    char readbuffer[14];
    char string[] = "Hello World! \n";
    
    if(pipe(fd)<0)//error
    {
	perror("pipe error");
	exit(1);
    }
    if((pid = fork()) < 0 )
    {
	perror("fork error");
	exit(1);
    }
    
    if(pid){//suntem in parinte
	int n;
	char rasp[3];
	printf("Numarul este: ");
	scanf("%d",&n);
	
	write(fd[1],&n,4);

	wait(NULL);

	read(fd[0],rasp,3);
	close(fd[0]);
	close(fd[1]);
	printf("\n%s\n",rasp);
    }else {//suntem in fiu
	int nr,i,ok=1;
	char raspuns[3];

	strcpy(raspuns,0);

	read(fd[0],&nr,4);

	if(nr==2) 
		strcpy(raspuns,"YES");

	if(nr%2==0) 
		strcpy(raspuns,"NO");
	else
	{
		if(nr!=3)
			for(i=3;i<=nr/2;i=i+2)
				if(nr%i==0)
					ok=0;

		if(ok)
			strcpy(raspuns,"YES");
		else
			strcpy(raspuns,"NO");
	}

	write(fd[1],raspuns,strlen(raspuns));
	exit(0);
    }
    return 0;
}
