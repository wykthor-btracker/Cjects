#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char **argv)
{
	char nome[100],maior[100];
	float sum = 0,max = 0,curr;
	int i;
	for(;;)
	{
		fgets(nome,100,stdin);
		int i = 0;
		while(nome[i]!='\0')
		{
			nome[i] = tolower(nome[i]);
			i++;
		}
		if(nome[0] == 'f' && nome[2] == 'm') break; 
		scanf("%f",&curr);
		sum+=curr;
		if(curr>max && curr-max > 1)
		{ 
			strcpy(maior,nome);
			max = curr;
		}
	}
	i = 0;
	while(maior[i]!='\0')
	{ 
		maior[i] = toupper(maior[i]);
		i++;
	}
	printf("%.2f\n%s\n",sum/2,maior);
	return 0;
}

