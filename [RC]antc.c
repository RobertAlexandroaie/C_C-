#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

extern int errno;

typedef struct Carte
{
	int cost;
	int val;
}Carte;

typedef struct Resources
{
	int b[2];
	int a[2];
	int m[2];
	
	int c[2];
}Resources;

typedef struct Player
{
	Resources status;
	char nume[50];
	int hand[8];
	int sd;
}Player;

Player p1,p2;
int s1,s2;
int socket_descriptor;
int r;

void recv_info()
{
	int sizeof_buffer=0;
	
	//p1 b
	if(read(socket_descriptor, p1.status.b, 8) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p1.status.b]\n");
		return ;
	}
	
	//p1 a
	if(read(socket_descriptor, p1.status.a, 8) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p1.status.a]\n");
		return ;
	}
	//p1 m
	if(read(socket_descriptor, p1.status.m, 8) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p1.status.m]\n");
		return ;
	}
	//p1 c
	if(read(socket_descriptor, p1.status.c, 8) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p1.status.c]\n");
		return ;
	}
	
	//p1 b
	if(read(socket_descriptor, p2.status.b, 8) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p2.status.b]\n");
		return ;
	}
	
	//p2 a
	if(read(socket_descriptor, p2.status.a, 8) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p1.status.a]\n");
		return ;
	}
	//p2 m
	if(read(socket_descriptor, p2.status.m, 8) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p2.status.m]\n");
		return ;
	}
	//p2 c
	if(read(socket_descriptor, p2.status.c, 8) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p2.status.c]\n");
		return ;
	}
	
	sizeof_buffer=0;
	//p1 sizeof.nume
	if(read(socket_descriptor, &sizeof_buffer, 4) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.(sizeof_buffer)\n");
		return ;
	}
	
	//p1.nume
	if(read(socket_descriptor, p1.nume, sizeof_buffer) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p1.nume]\n");
		return ;
	}	
	
	//p1 score
	if(read(socket_descriptor, &s1, 4) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[s1]\n");
		return ;
	}
	
	//p2 score2
	if(read(socket_descriptor, &s2, 4) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[s2]\n");
		return ;
	}
	
	//p1.hand
	if(read(socket_descriptor, p1.hand, 32) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p1.hand]\n");
		return ;
	}
	sizeof_buffer=0;
	
	//p2 sizeof.nume
	if(read(socket_descriptor, &sizeof_buffer, 4) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.(sizeof_buffer)\n");
		return ;
	}
	
	//p2.nume
	if(read(socket_descriptor, p2.nume, sizeof_buffer) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[p2.nume]\n");
		return ;
	}
	
	//rounds
	if(read(socket_descriptor, &r, 4) <= 0)
	{
		perror ("[client recv_info]Eroare la read() de la server.[r]\n");
		return ;
	}
	
}

void afisare()
{
	printf("%s\t%d-%d\t\t|%s\n",p1.nume,s1,s2,p2.nume);
	
	printf("B|%d\t\t\t|%d\n",p1.status.b[0],p2.status.b[0]);
	printf("  %d\t\t\t|%d\n",p1.status.b[1],p2.status.b[1]);
	
	printf("A|%d\t\t\t|%d\n",p1.status.a[0],p2.status.a[0]);
	printf("  %d\t\t\t|%d\n",p1.status.a[1],p2.status.a[1]);
	
	printf("M|%d\t\t\t|%d\n",p1.status.m[0],p2.status.m[0]);
	printf("  %d\t\t\t|%d\n",p1.status.m[1],p2.status.m[1]);
	
	printf("C|%d\t\t\t|%d\n",p1.status.c[0],p2.status.c[0]);
	printf("  %d\t\t\t|%d\n",p1.status.c[1],p2.status.c[1]);
	
	printf("carte1(%d), carte2(%d), carte3(%d), carte4(%d), carte5(%d), carte6(%d), carte7(%d), carte8(%d)\n", p1.hand[0], p1.hand[1], p1.hand[2], p1.hand[3], p1.hand[4], p1.hand[5], p1.hand[6], p1.hand[7]);
}

void make_move()
{
	char msg_rec[50];
	bzero(msg_rec,50);
	int opt=0;
	int card_id=0;
	
	printf("1. Use.\n");
	printf("2. Drop.\n");
	printf("Option: ");
	scanf("%d",&opt);
	
	printf("Ce carte alegeti?\n");
	scanf("%d",&card_id);
	card_id--;
	printf("------------------------------------------------------\n");
	
	if(write(socket_descriptor,&opt,4)<0)
	{
		perror("[client make-move]Eroare la scrierea optiunii catre srv.\n");
		return ;
	}
	
	if(write(socket_descriptor,&p1.hand[card_id],4)<0)
	{
		perror("[client make-move]Eroare la scrierea card_id catre srv.\n");
		return ;
	}
}

int main ()
{
	struct sockaddr_in socket_server;
	char msg_snd[100];
	char msg_rec[150];
	
	int sizeof_buffer=0;
	int sizeof_send=0;
	
	if ((socket_descriptor = socket (AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror ("[client] Eroare la socket().\n");
		return errno;
	}

	socket_server.sin_family = AF_INET;
	socket_server.sin_addr.s_addr = inet_addr((char *)"127.0.0.1");
	socket_server.sin_port = htons (3334);

	if (connect (socket_descriptor, (struct sockaddr *) &socket_server,sizeof (struct sockaddr)) == -1)
	{
		perror ("[client]Eroare la connect().\n");
		return errno;
	}

	bzero(msg_snd,50);
	bzero(msg_rec,100);
	
	//protocol de autentificare a clientului
	
	bzero(msg_snd,50);
	strcpy(msg_snd,"opensessamy");
	
	if (write (socket_descriptor, msg_snd, 11) < 0)
	{
		perror ("[client]Eroare la write() spre server.--autentificare\n");
		return errno;
	}
	
	if(read(socket_descriptor, msg_rec, 2) < 0)
	{
		perror ("[client]Eroare la read() de la server.[msg_rec]\n");
		return errno;
	}
	
	if(strcmp(msg_rec,"OK")==0)
	{
		bzero(msg_snd,50);
		bzero(msg_rec,100);
		
		/* inroducem numele */
		printf ("[client]Introduceti un nume: ");
		fflush (stdout);
		scanf("%s", msg_snd);
		
		sizeof_send=strlen(msg_snd);
		
		if(write(socket_descriptor, &sizeof_send, 4) < 0)
		{
			perror("[client]Eroare la write() spre server.(sizeof_send)\n");
			return errno;
		}
		
		if (write (socket_descriptor, msg_snd, sizeof_send) < 0)
		{
			perror ("[client]Eroare la write() spre server.[msg_snd]\n");
			return errno;
		}
		
		sizeof_buffer=0;
		if(read(socket_descriptor, &sizeof_buffer, 4) < 0)
		{
			perror ("[client]Eroare la read() de la server.(sizeof_buffer)\n");
			return errno;
		}
		
		bzero(msg_rec,100);
		if(read(socket_descriptor, msg_rec, sizeof_buffer) < 0)
		{
			perror ("[client]Eroare la read() de la server.[msg_rec]\n");
			return errno;
		}
		
		printf("%s\n",msg_rec);
		
		//incepem jocul propriu-zis
		
		
		recv_info();
		afisare();
		
		while(r)
		{
			recv_info();
			afisare();
			
			if(read(socket_descriptor,msg_rec,16)<0)
			{
				perror("[client make-move]Eroare la citire cerere.\n");
				return ;
			}
			else
			{
				printf("Este randul tau!\n");
				make_move();
			}
			recv_info();
			afisare();
		}
	}
	else
	{
		close(socket_descriptor);
	}
	
	return 0;
}