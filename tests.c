#include <stdio.h>
#include <math.h>
#define size 10

int *primos(int *lista) 
{
  int primo = 0,achou = 0,u,i,primos = 0,index=0;
	for(i=2;primos<size;i++)
	{
	primo = i;
	for(u=2;u<=sqrt(primo);u++)
		{
		  achou = 0;
		  if(primo%u==0)
		  {
			achou = 1;
			break;
		  }
		}
		if(!achou)
		{
			lista[index] = primo;
			//printf("%d\n",primo);
			index++;
			primos++;
		}
	}
	return lista;
}

int fat(int val,int *lista)
{
	int ind = 0,md = 0,i;
	for(i=0;i<size;i++)
	{
		//printf("%d\n",lista[ind]);
		while(val%lista[ind]==0)
		{
			printf("%d*",lista[ind]);
			md = lista[ind];
			ind++;
		}
	}
	return(md);
}
int main(int argc, char **argv)
{	
	int lista[size];
	primos(lista);
	printf("\n%d\n",fat(12,lista));
	return 0;
}

