#include <stdio.h>
int main(int argc, char **argv)
{
	int size;
	scanf("%d",&size);
	int i,ind = 0,start,count,array[size],sum = 0;
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	scanf("%d %d",&start,&count);
	ind = start;
	ind = ind%size;
	while(count>0)
	{
		sum+=array[ind];
		count--;
		ind = (ind+1)%size;
	}
	printf("%d\n",sum);
	return 0;
}
