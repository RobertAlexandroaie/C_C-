#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int fd[2], nbytes;
    pid_t pid;
    char readbuffer[14];
    char readc[1];
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
	close(fd[0]); //parintele doar scrie, asadar isi inchide capatul de citire
	char c[1];
	c[0]=-1;
	while (c[0]!='q'){
		c[0]=getchar();
		write(fd[1], c, 1);
	}
	//inainte de terminarea procesului, inchidem si capatul de scriere 
	wait(NULL);
	close(fd[1]);

    }else {//suntem in fiu
	close(fd[1]); //fiul doar citeste, asadar isi inchide capatul de scriere
	readc[0]=-1;
	while(readc[0]!='q'){
		read(fd[0], readc, 1);
		if(isalpha(readc[0])) 
			putchar(toupper(readc[0]));
	}

	//inainte de terminarea procesului, inchidem si capatul de citire
	close(fd[0]);
	exit(0);
    }
    return 0;
}
