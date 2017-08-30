#include <stdio.h>
float f_to_c(float f)
{
	return (f-32)/1.8;
}

int main(int argc, char **argv)
{
	float inp;
	scanf("%f",&inp);
	printf("%.2f",f_to_c(inp));
	return 0;
}

