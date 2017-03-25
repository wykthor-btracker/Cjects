#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int i,ind = 0,*arr,size = 1,curr;
	arr = (int*)malloc((size)*sizeof(int));
	while(scanf("%d",&curr) != EOF)
	{
		arr[ind] = curr;
		ind++;
		size++;
		arr = (int*)realloc(arr,(size)*sizeof(int));
	}
	for(i=0;i<size;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}

