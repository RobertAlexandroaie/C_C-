void bubble_sort(int nr, int* v)
{
	int ok,i,temp;
	do{
		ok = 1;
		for(i=0;i<nr-1;i++)
			if(*(v+i) > *(v+i+1))
			{
				temp	= *(v+i);
				*(v+i)	= *(v+i+1);
				*(v+i+1)= temp;
				ok = 0;
			}
	}while(!ok);
}