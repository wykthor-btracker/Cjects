#include <stdio.h>

int main(int argc, char **argv)
{
	int size;
	scanf("%d",&size);
	int i,j,sum,array[size][size],curr = 0,flag = 0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++) scanf("%d",&array[i][j]);
	}
	printf("%d \n",curr);
	return 0;
}

