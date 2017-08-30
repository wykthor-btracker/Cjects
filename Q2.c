#include <stdio.h>
#include <string.h>
#define notas_de_100 30
#define maximo 1000
int main(int argc, char **argv)
{
	char entrada;
	int valor;
	int i;
	int max = notas_de_100;
	int sacado[6] = {0};
	int total = 0;
	for(;;)
	{
		int inicial = 0;
		scanf("%c",&entrada);
		if(toupper(entrada) == 'E') break;
		scanf("%d",&valor);
		inicial = valor;
		int saque[6] = {0};
		while(valor>=100 && max > 0)
		{ 
			saque[0]++;
			sacado[0]++;
			valor-=100;
			total+=100;
			max--;
		}
		while(valor>=50)
		{
			sacado[1]++;
			saque[1]++;
			valor-=50;
			total+=50;
		}
		while(valor>=20) 
		{
			saque[2]++;
			sacado[1]++;
			valor-=20;
			total+=20;
		}
		while(valor>=10)
		{
			sacado[3]++;
			saque[3]++;
			total+=10;
			valor-=10;
		}
		while(valor>=5)
		{
			saque[4]++;
			sacado[4]++;
			valor-=5;
			total+=5;
		}
		while(valor>=2)
		{
			saque[5]++;
			sacado[5]++;
			valor-=2;
			total+=2;
		}
		if(valor!=0 || inicial > maximo) 
		{
			printf("Impossivel realizar transacao\n");
			for(i=0;i<6;i++)
			{
				sacado[i]-=saque[i];
			}
		}
		else printf("Notas de 100:%d\nNotas de 50:%d\nNotas de 20:%d\nNotas de 10:%d\nNotas de 5:%d\nNotas de 2:%d\n",saque[0],saque[1],saque[2],saque[3],saque[4],saque[5]);
	}
	printf("Notas de 100:%d\nNotas de 50:%d\nNotas de 20:%d\nNotas de 10:%d\nNotas de 5:%d\nNotas de 2:%d\n",sacado[0],sacado[1],sacado[2],sacado[3],sacado[4],sacado[5]);
	printf("Total sacado:%d\n",total);
	return 0;
}

