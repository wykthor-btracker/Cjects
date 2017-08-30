#include <stdio.h>

int main(int argc, char **argv)
{
	int size;
	scanf("%d",&size);
	int i,array[size];
	for(i=0;i<size;i++)
	{ 
		scanf("%d",&array[i]);
	}
	int steps;
	scanf("%d",&steps);
	for(i=0;i<size;i++)
	{
		printf("%d",array[(i+steps)%size]);
	}
	return 0;
}

