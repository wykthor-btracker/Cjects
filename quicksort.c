#include <stdio.h>
#include <stdlib.h>
void swap(int **array,int first, int second)
{
	int middle;
	printf("swapping these indexes:%d %d\n",first,second);
	middle = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = middle;
}
void printArray(int *array,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
int *init(int *p)
{
	int *new,*tmp;
	int val;
	int size = 1;
	new = malloc(sizeof(int));
	while(1)
	{
		scanf("%d",&val);
		if(val == -1) break;
		tmp = realloc(new,sizeof(int)*size*2);
		if(tmp!=NULL) new = tmp;
		else
		{ 
			printf("Something went down my brother.\n");
			break;
		}
		printf("Allocation for %p worked.\n",new);
		new[size-1] = val;
		size++;
		*p = size;
	}
	return new;
}
int separate(int **array,int start,int end)
{
	int Pstart,Pend,Pivot,handle;
	//printf("Test. %p %d\n",(*array),(*array)[0]);
	printf("start : %d end : %d\n",start,end);
	Pstart = (*array)[start+1];
	Pivot = start;
	Pend = Pstart;
	handle = Pstart;
	printf("Test. %p %d\n",(*array),(*array)[0]);
	scanf(" %*s");	
	while(handle <= end)
	{
		scanf(" %*s");
		printf("HI! These are my values: handle = %d, end = %d\n",(*array)[handle],(*array)[end]);
		if((*array)[handle] < (*array)[Pivot])
		{
			printArray((*array),5);
			printf("swapping %d by %d pivot is %d\n",(*array)[handle],(*array)[Pend],(*array)[Pivot]);
			swap(array,handle,Pend);
			printf("handle %d Pend %d\n",handle,Pend);
			Pend++;
			Pstart = Pend-1;
		}
		handle++;
		printf("handle =%d\n",handle);
	}
	printf(" array[pivot] = %d array[Pstart] = %d\n",(*array)[Pivot],(*array)[Pstart]);
	if(Pend != Pstart) swap(array,Pivot,Pstart);
	return(start);
}
void quicksort(int **array,int start,int end)
{
	int pivot = separate(array,start,end);
	if(start+1 == end) return;
	else
	{
		quicksort(array,start,pivot);
		quicksort(array,pivot,end);
	}
}
int main(int argc, char **argv)
{
	int size;
	int *new = init(&size);
	quicksort(&new,0,size-1);
	printArray(new,size);
	return 0;
}

