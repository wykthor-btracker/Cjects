#include <stdio.h>
double walk(double base, int exp)
{
	if(exp == 1) return base;
	else base*=walk(base,exp-1);
	printf("%.0lf",base);
}
int main()
{
	double base;
	int exp;
	scanf("%lf %d",&base,&exp);
	walk(base,exp);
	return 0;
}

