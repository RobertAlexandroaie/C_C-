#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main()
{
	pid_t pid,pid2,pid3;
    int pip[2];
	int pip2[2];
	int pip3[2];

	int raspuns_fiu;
	char optiune[50];
	int logged;
	logged=0;
	
	int nr_de_linii=0;
			
	do
	{
		strcpy(optiune,"");
		printf("Comanda: ");
		scanf("%s",optiune);
		
		if(strcmp(optiune,"quit")==0)
		{
			unlink("fifo");
			return 0;
		}
		
		if(strcmp(optiune,"login")==0)
		{
			logged=0;
			if(pipe(pip)<0)//error
			{
				perror("pipe error");
				exit(3);
			}
			
			char user[50];
			
			char buffer[50];
			int lungime=0;
			
			printf("User: ");
			scanf("%s", user);
			
			int l=strlen(user);
			
			write(pip[1],&l,4);
			write(pip[1],user,l);
						
			switch(pid=fork())
			{
				case -1:
					perror("fork");
					exit(2);
				case 0:
					//fiu
					//verifica daca exista userul;
					//returneaza 1 (linie)in pipe daca exista;
					lungime=0;
					strcpy(buffer,"");
					read(pip[0],&lungime,4);
					read(pip[0],buffer,lungime);
					
					buffer[lungime]=0;
					
					//do grep username /etc/passwd
					
					FILE *fi;
					fi=fopen("/etc/passwd","r");
										
					char linie[1000];
					
					while(fgets(linie,1000,fi))
						if(strstr(linie,buffer)!=0)
							nr_de_linii++;
					
					write(pip[1],&nr_de_linii,4);
					exit(0);
				default://tatal
					//scrie userul care trebuie cautat 
					//asteapta raspunsul de la copil
					//daca exista userul, continua cu ascultari de comenzi
					
					/* tatal isi inchide capatul Write,
					   pentru ca fiul sa poata citi EOF din pipe */
					/* asteapta terminarea fiului */
					wait(NULL);
					
					raspuns_fiu=0;
					close(pip[1]);
					read(pip[0],&raspuns_fiu,4);
					close(pip[0]);
					if(raspuns_fiu==1)
						logged=1;
					if(logged==1)
						printf("V-ati logat cu succes!\n");
			}
		}
		
		if(strcmp(optiune,"grep")==0)
		{
			if(logged==1)
			{
				if(pipe(pip2)<0)//error
				{
					perror("pipe error");
					exit(3);
				}
				
				int l1,l2;
				
				char pattern[200];
				char fisier[200];
				
				printf("Pattern: ");
				scanf("%s",pattern);
				l1=strlen(pattern);
				
				printf("Fisier: ");
				scanf("%s", fisier);
				l2=strlen(fisier);
				
				if(write(pip2[1],&l1,4)==-1)
					printf("Eroare la scriere in pip2!\n");
				if(write(pip2[1],pattern,l1)==-1)
					printf("Eroare la scriere in pip2!\n");
				if(write(pip2[1],&l2,4)==-1)
					printf("Eroare la scriere in pip2!\n");
				if(write(pip2[1],fisier,l2)==-1)
					printf("Eroare la scriere in pip2!\n");
								
				char buffer1[200];
				char buffer2[200];
				int lungime2=0;
				int lungime1=0;
				
				strcpy(buffer1,"");
				strcpy(buffer2,"");
				
				switch(pid2=fork())
				{
					case -1:
						perror("fork");
						exit(2);
					case 0:
						//fiul;
						read(pip[0],&lungime1,4);
						read(pip[0],buffer1,lungime1);
						buffer1[lungime1]=0;
						
						read(pip[0],&lungime2,4);
						read(pip[0],buffer2,lungime2);
						buffer2[lungime2]=0;
												
						FILE *fi;
						fi=fopen(fisier,"r");								
					
						char linie[1000];
						
						while(fgets(buffer2,1000,fi))
						{
							if(strstr(buffer2,buffer1)!=0)
							{
								nr_de_linii++;
							}
						}
						
						write(pip[1],&nr_de_linii,4);
						exit(0);
					default:
						//tata;
						//am citit optiunea si nu e nici quit, nici login -> grep sau ls;
						
						wait(NULL);
						
						raspuns_fiu=0;
						close(pip2[1]);
						read(pip2[0],&raspuns_fiu,4);
						close(pip2[0]);
						
						printf("Numarul de linii semnificante este: %d.\n",raspuns_fiu);
				}
			}
			else
				printf("Nu v-ati logat!\n");
		}

		if(strcmp(optiune,"ls")==0)
		{
			if(logged==1)
			{
				char linie[1000];
				char c;
				int i;
				
				if(pipe(pip3)<0)//error
				{
					perror("pipe error");
					exit(3);
				}
				printf("Fac fork.\n");
				switch(pid3=fork())
				{
					case -1:
						perror("fork");
						exit(2);
					case 0:
						//fiul;
						printf("Sunt in fiu. Execut ls.\n");
						dup2(pip3[1],1);
						execlp("ls","ls",NULL);
					default:
						//tata;
						//am citit optiunea si nu e nici quit, nici login -> grep sau ls;
						printf("Astept ca fiul sa scrie.\n");
						wait(NULL);
						close(pip3[1]);
						sleep(1);
						printf("Fiul a terminat.\n");
						i=0;
						while(read(pip3[0],&c,1))
						{
							if(c!='\n')
								linie[i++]=c;
							else
							{
								linie[i]=0;
								printf("%s\n",linie);
								i=0;
							}
						}
						close(pip3[0]);
				}
			}
			else
				printf("Nu v-ati logat!\n");
		}
		
	}while(strcmp(optiune,"quit")!=0);
	
	unlink("fifo");
	return 0;
}