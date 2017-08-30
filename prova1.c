#include <stdio.h>
int main(int argc, char **argv)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a==b||b==c||c==a)
	{
		printf("S");
	}
	else if(a+b==c||b+c==a||a+c==b)
	{
		printf("S");
	}
	else
	{
		printf("N");
	}
	printf("\n");
	return 0;
}

