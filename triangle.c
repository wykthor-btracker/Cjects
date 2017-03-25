#include <stdio.h>

int main(int argc, char **argv)
{
	int i,u,inp;
	scanf("%d",&inp);
	for(i=1;i<=inp;i++)
	{
		for(u=1;u<=i;u++) printf("%d",i);
		printf("\n");
	}
	return 0;
}

