#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char **argv)
{
	int sum = 0,i,inp;
	char name[100];
	for(;;)
	{
		sum++;
		scanf("%d %s",&inp,name);
		sum+=inp;
		for(i=0;i<3;i++) name[i] = tolower(name[i]);
		if(strcmp(name,"sair")==0) break;
	}
	printf("%d\n%.2f\n",sum,(float)sum*14);
	return 0;
}

