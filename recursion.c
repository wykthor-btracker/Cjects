#include <stdio.h>
#include <stdlib.h>
void iter(int *list,int size)
{
	if(size == 0) return;
	else
	{
		printf("%d\n",*list);
		iter(list+1,size-1); //list++ != list+1
	}
}
int main()
{
	int size = 10;
	int *list = malloc(sizeof(int)*size);
	int i;
	for(i=0;i<size;i++) list[i] = i+2;
	iter(list,size);
	return 0;
}

