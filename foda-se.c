#include <stdio.h>
void boo(int a)
{
	printf("%d+1=%d\n",a,a+1);
}

void far(int a)
{
	printf("%d-1=%d\n",a,a-1);
}

int main(int argc, char **argv)
{	
	void (*fPtrArr[])(int) = {boo,far},(*bla)(int) = far;
	(*fPtrArr[0])(3);
	(*fPtrArr[1])(3);
	bla(10);
	return 0;
}

