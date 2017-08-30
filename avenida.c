#include <stdio.h>

int main(int argc, char **argv)
{
	int x,y;
	scanf("%d %d",&x,&y);
	int i,j,array[x][y];
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	int soma = 0,min = 0,flag = 0;
	for(j=0;j<y;j++)
	{
		soma = 0;
		for(i=0;i<x;i++)
		{
			//printf("%d %d\n",j,i);
			soma+=array[i][j];
		}
		if(!flag){ 
			min = soma;
			flag++;
		}
		if(soma<min) min = soma;
	}
	printf("%d\n",min);
	return 0;
}

