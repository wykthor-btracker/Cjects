#include <stdio.h>
int mdc(int a,int b)
{
	int c;
	if(b == 0) return a;
	else
	{
		c = a%b;
		mdc(b,c);
	}
}
int main(int argc, char **argv)
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",mdc(a,b));
	return 0;
}

