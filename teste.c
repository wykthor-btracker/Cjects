#include <stdio.h>
void arr_read(int arry[][size],int x)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<size;j++)
		{
			scanf("%d",&arry[i][j]);
			printf("%d ",arry[i][j]);
		}
		printf("\n");
	}
}
int main(int argc, char **argv)
{
	int size = 5;
	int array[4][size];
	arr_read(array,4);
	return 0;
}

