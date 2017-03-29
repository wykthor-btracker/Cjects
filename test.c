#include <stdio.h>
int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen("input.dat","r");
	int d;
	int i,j;
	char array[6][3];
	for(i=1;i<=2;i++)
	{
		for(j=0;j<3;j++)
		{
			fscanf(fp,"%s",array[i*j]);
		}
		printf("\n");
	}
	fclose(fp);
	fp = fopen("input.dat","w");
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=3;j++)
		{
			fprintf(fp,"%s",array[i*j]);
			printf("%s ",array[i*j]);
		}
	}
	fclose(fp);
	return 0;
}

