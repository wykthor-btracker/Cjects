#include <stdio.h>
int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen("input.dat","w+");
	printf("%ld",ftell(fp));
	return 0;
}

