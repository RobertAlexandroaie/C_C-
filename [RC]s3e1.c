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
	close(fd[0]); //parintele doar scrie, asadar isi inchide capatul de citire
	write(fd[1], string, strlen(string));
	write(fd[1], string, strlen(string));
	write(fd[1], string, strlen(string));
	write(fd[1], string, strlen(string));
	//inainte de terminarea procesului, inchidem si capatul de scriere 
	close(fd[1]);
	wait(NULL);

    }else {//suntem in fiu
	close(fd[1]); //fiul doar citeste, asadar isi inchide capatul de scriere
	int i=0;
	for(i=0; i<4;i++){    
	    nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
	    printf("read %s \n ", readbuffer);
	}
	//inainte de terminarea procesului, inchidem si capatul de citire
	close(fd[0]);
	exit(0);
    }
    return 0;
}
