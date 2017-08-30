#include <stdio.h>
void iter(int *arr,int ind,int counter,int size)
{
	if(counter==0) return;
	else
	{
		printf("%d\n",arr[ind]);
		ind = (ind+1)%size;
		counter--;
		iter(arr,ind,counter,size);
	}
}
int main(int argc, char **argv)
{
	int a[] = {1,2,3,4,5,6};
	iter(a,0,12,6);
	return 0;
}

