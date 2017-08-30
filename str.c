#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	char *str1,*str2,b;
	str1 = malloc(sizeof(char)*100);
	str2 = malloc(sizeof(char)*100);
	int i = 0;
	while((b = getchar())!=-1)
	{
		if(b!='\n')
		{ 
			printf("%c",b);
			str1[i] = b;
			i++;
		}
	}
	printf("\n%s",str1);
	/*while(scanf("%s",str1)!=EOF)
	{
		char *c = str1;
		while(*c != '\0')
		{
			str2[i] = *c;
			c++;
			i++;
		}
		if(*(c-1)=='\n') printf("ha\n");
		printf("%d\n",*c);
		str2[i] = ' ';
		i++;
	}
	str2[i] = '\0';
	printf("%s",str2);*/
	return 0;
}

