#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int *array,i,size = 1;
	array = (int*)malloc(sizeof(int)*size);
	if(array==NULL)
	{
		printf("misallocation, exiting...\n");
		return 1;
	}
	for(i=0;i<10;i++)
	{
		printf("current size is %d\n",size);
		array = (int*)realloc(array,sizeof(int)*size+1);
		array[size] = i;
		printf("%d\n",array[size]);
		size++;
	}
	return 0;
}

