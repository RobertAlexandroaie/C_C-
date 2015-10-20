#include<stdio.h>
#include<iostream>
#include<math.h>
#include<cmath>

int prime[100],x[100],m,s,n;

int valid(int k)
{
	if((s+prime[x[k]])<=n)
	{
		s=s+prime[x[k]];
		return 1;
	}
	return 0;
}

void back(int k)
{
	int i;
	if(s==n)
	{
		for(i=1; i<k;i++)
			printf("%d ", prime[x[i]]);
		printf("\n");
	}
	else
		for(i=x[k-1];i<=m;i++)
		{
			x[k]=i;
			if(valid(k)==1)
			{
				back(k+1);
				s=s-prime[x[k]];
			}
		}  
}

int prim(int x)
{
	int i;
	if(x==0||x==1)
		return 0;

	if(x==2)
		return 1;

	if(x%2==0)
		return 0;

	for(i=3;i<=(int)(sqrt((float)(x)));i+=2)
		if(x%i==0)
			return 0;

	return 1;
}

int main()
{
	int i;

	printf("Introduceti n:");
	scanf("%d",&n);

	for(i=2;i<=n;i++)
		if(prim(i)==1)
		{
			m++;
			prime[m]=i;
		}

	for(i=1;i<=m;i++)
	{
		s=prime[i];
		x[1]=i;
		back(2);
	}

	system("pause");
	return 0;
}
                 
