#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int **array,int size)
{
	int sorted=0,swap = 0;
	int middle,i;
	while(sorted == 0)
	{
		swap = 0;
		for(i = 0;i<size-1;i++)
		{
			if((*array)[i] > (*array)[i+1])
			{
			middle = (*array)[i];
			(*array)[i] = (*array)[i+1];
			(*array)[i+1] = middle;
			swap = 1;
			}
		}
		if(swap==0) sorted = 1;
	}
}
int *init(int size)
{
	int *arr = calloc(sizeof(int),size);
	return(arr);
}

void populate(int **arr, int size)
{
	int i;
	for(i=0;i<size;i++) scanf("%d",&(*arr)[i]);
}

int contains(int val,int *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(val == arr[i]) return 1;
	}
	return 0;
}
void append(int **arr,int val,int ind)
{
	(*arr)[ind] = val;
}
int main()
{
	int size;
	scanf("%d",&size);
	int *first,*second,*array;
	first = init(size);
	second = init(size);
	array = init(size);
	populate(&first,size);
	populate(&second,size);
	int i,ind = 0;
	for(i=0;i<size;i++)
	{ 
		if(contains(first[i],second,size) && !contains(first[i],array,size)) 
		{
			append(&array,first[i],ind);
			ind++;
		}
	}
	append(&array,-1,ind);
	bubbleSort(&array,size);
	for(i=0;array[i]<size;i++) if(array[i] != -1 && array[i] != 0) printf("%d\n",array[i]);
	return 0;
}
