#include <stdio.h>

int main()
{
	int i,start,end,curr,iter=0,highest = 0,last = 0;
	while(!feof(stdin))
	{
		//Checa se ainda existe entrada a ser lida
		scanf("%d %d",&start,&end);
		last = highest;// guarda o resultado do ultimo valor encontrado para maior valor de ciclo
		highest = 0; //reseta valor para proxima iteracao
		for(i=start;i<end;i++)
		{
			iter = 1;
			curr = i;//local para operacao do problema
			while(curr!=1)
			{
				if(curr%2==0) curr/=2;
				else
				{
					curr*=3;
					curr++;
				}
				iter++; //Contagem de quantos passos foram dados
			}
			if(iter>highest) highest = iter; //checa se o valor atual eh maior que o maior encontrado
		}
		if(last!=highest) printf("%d %d %d\n",start,end,highest); //se o valor nao ja tiver sido imprimido, imprima a saida requerida pelo problema 
	}
	return 0;
}

