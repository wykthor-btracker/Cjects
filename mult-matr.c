#include <stdio.h>

int main(int argc, char **argv)
{
	int i,j,lin,col,square=0,pos = 0,neg = 0;
	scanf("%d %d",&lin,&col);
	if(lin==col) square++;
	int array[lin][col];
	printf("Matriz formada:\n");
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&array[i][j]);
			if(array[i][j]<0) neg++;
			else pos++;
			if(j==col-1) printf("%d",array[i][j]);
			else printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	int sum = 0,s_sum = 0;
	if(square)
	{
		for(i=0;i<lin;i++)
		{
			sum+=array[i][i];
		}
		int x = lin-1,y = 0;
		for(i=0;i<lin;i++)
		{
			s_sum+=array[x][y];
			x--;
			y++;
		}
		printf("A diagonal principal e secundaria tem valor(es) %d e %d respectivamente.",sum,s_sum);	
	}
	else printf("A diagonal principal e secundaria nao pode ser obtida.");
	printf("\n");
	printf("A matriz possui %d numero(s) menor(es) que zero.\n",neg);
	printf("A matriz possui %d numero(s) maior(es) que zero.\n",pos);	
	return 0;
}

