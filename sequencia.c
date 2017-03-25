#include <stdio.h>

int main(int argc, char **argv)
{
	int size,ind = 0;
	scanf("%d",&size);
	int i,j,array[size],start = 0,sum = 0,curr = 0,inte = 0,start,end,found = 0;
	for(i=0;i<size;i++) scanf("%d",&array[i]);
	for(i=0;i<2*size;i++)
	{
		curr = 0;
		for(j=0;j<size;j++)
		{
			if(array[j]<0) start = j;
		}
		if(curr>sum) sum = curr;
		ind = (ind+size-1)%size;
	}
	printf("%d\n",sum);
	return 0;
}

