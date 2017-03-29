#include <stdio.h>
#include <math.h>
int ordem(int bolas)
{
	int i = 0 , smaller = 0,last = 0,next,curr;
	while(curr<smaller)
	{
		curr = pow(10,i)-bolas;
		i++;
	}
	return i;
}
int main(int argc, char **argv)
{
	printf("%d",ordem(12));
	return 0;
}

