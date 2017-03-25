#include <stdio.h>
void fibbo(int a, int b,int size)
{
	if(size==0) return;
	else
	{
		printf("%d\n",a);
		fibbo(b,a+b,size-1);
	}
}

int main(int argc, char **argv)
{
	fibbo(4,5,30);
	return 0;
}

