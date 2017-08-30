#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int i;
	int *list,size = 1,curr,ind = 0;
	list = (int*)malloc(size*2*sizeof(int));
	while(scanf("%d",&curr) != EOF)
	{
		size++;
		list = (int*)realloc(list,size*2*sizeof(int));
		list[ind] = curr;
		ind++;
	}
	int *temp = (int*)malloc(size*2*sizeof(int));
	for(i=0;i<ind;i++)
	{
		temp[i] = list[(ind-1)-i];
		printf("%d ",temp[i]);
	}
	return 0;
}

