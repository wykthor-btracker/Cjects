#include <stdio.h>
#include <math.h>
float mmc(int x, int y)
{
	int middle;
	if(y>x)
	{
		middle = x;
		x = y;
		y = middle;
	}
	else if(y==x) return x;
	if(x%y==0) return x;
	else return (float)(x*y)/10;
}
int main(int argc, char **argv)
{
	int size;
	scanf("%d",&size);
	int i,first = 0,last = 1;
	float array[size];
	float curr;
	for(i=0;i<size;i++)
	{ 
		scanf("%f",&curr);
		array[i] = curr*10;
	}
	for(i=0;i<size-1;i++)
	{
		array[last] = mmc((int)array[first],(int)array[last]);
		first++;
		last++;
	}
	printf("O tempo para o alinhamento dos planetas e %.2lf minutos\n",array[last-1]/10);
	return 0;
}

