#include <stdio.h>
int fibbo(int first,int second,int limit)
{
	if(limit==0) return 0;
	else
	{
		printf("%d\n",first);
		fibbo(second,first+second,limit-1);
	}
}
int main(int argc, char **argv)
{
	int first,second,limit;
	scanf("%d %d %d",&first,&second,&limit);
	fibbo(first,second,limit);
	return 0;
}

