#include <stdio.h>

int main(int argc, char **argv)
{
	int i,j,size = 3,size_2=4,array[size][size_2];
	float precos[size_2];
	for(i=0;i<size;i++)
	{
		for(j=0;j<size_2;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	for(i=0;i<size_2;i++)
	{
		scanf("%f",&precos[i]);
	}
	float sum;
	for(i=0;i<size;i++)
	{
		sum = 0;
		for(j=0;j<size_2;j++)
		{
			sum+=array[i][j]*precos[j];
		}
		printf("%.2f\n",sum);
	}
	return 0;
}

