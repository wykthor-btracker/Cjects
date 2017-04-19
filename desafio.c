#include <stdio.h>
#include <stdlib.h>

int recSum(int ind, int sum,int *arr)
{
	if(ind == -1) return sum;
	else
	{ 
		sum+=arr[ind];
		ind--;		
		return recSum(ind,sum,arr);
	}
}
int main(int argc, char **argv)
{
	int *arr = malloc(sizeof(int)*10);
	int i;
	for(i=0;i<10;i++)
	{
		arr[i] = i+1;
	}
	printf("%d",recSum(9,0,arr));
	free(arr);
	return 0;
}

