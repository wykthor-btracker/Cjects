#include <stdio.h>

int main(int argc, char **argv)
{
	int i,curr,soma=0,size;
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&curr);
		if(curr%2==0) curr=1;
		else curr=-1;
		soma+=curr;
	}
	printf("%d\n",soma);
	return 0;
}

