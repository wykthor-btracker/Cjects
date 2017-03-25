#include <stdio.h>
#include <math.h>
int main(int argc, char **argv)
{
	double f = 0,i,last=2;
	for(i=0;i<100;i++)
	{
		f+=pow(2,-i);
		printf("%lf\n",f);
	}
	if(f==last)
	{
		printf("fail");
	}
	return 0;
}

