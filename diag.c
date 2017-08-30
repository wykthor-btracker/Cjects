#include <stdio.h>

int main(int argc, char **argv)
{
	for(;;)
	{
		int i,j,size = 4,k,array[4][4];
		scanf("%d",&k);
		if(k==0) break;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				scanf("%d",&array[j][i]);
				if(j==i) array[j][i]*=k;
			}
		}
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				printf("%d ",array[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

