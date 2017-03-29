#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	int sum,inp,i;
	char name[100];
	for(;;)
	{
		scanf("%d %s",&inp,name);
		if(strcmp(name,"sair")==0) break;
	}
	return 0;
}

