#include <stdio.h>
#include <stdlib.h>
int procurar(int *a,int tam,int n,int ind)
{
	if(a[ind] == n) return(ind);
	else if(ind < tam-1) procurar(a,tam,n,ind+1);
	else return -1;
}

int maiorV(int *a,int tam, int maior, int ind)
{
	if(ind == tam) return maior;
	else
	{
		if(a[ind] > maior) maior = a[ind];
		maiorV(a,tam,maior,ind+1);
	}
}

void fibbo(int first, int second,int count)
{
	if(!count) return;
	else
	{
		printf("%d\n",first);
		fibbo(second,second+first,count-1);
	}
}
int main(int argc, char **argv)
{
	int size = 20,*arr = malloc(sizeof(int)*size);
	int i;
	for(i=0;i<size;i++) arr[i] = i+1;
	printf("%d\n",procurar(arr,size,5,0));
	printf("%d\n",maiorV(arr,size,0,0));
	fibbo(1,1,10);
	return 0;
}

