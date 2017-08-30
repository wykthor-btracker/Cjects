#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	char *nome[10],letra[1];
	int i,u,size = 10;
	for(i=0;i<size;i++)
	{
		nome[i] = (char*)malloc(size*sizeof(char));	
		scanf("%s",nome[i]);
	}
	scanf("%s",letra);
	letra[0] = toupper(letra[0]);
	for(i=0;i<size;i++)
	{
		for(u=0;u<size;u++)
		{
			if(toupper(nome[i][u]) == letra[0])
			{
				printf("%s\n",nome[i]);
				break;
			}
		}
	}
	
	return 0;
}

