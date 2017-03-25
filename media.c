#include <stdio.h>

int main(int argc, char **argv)
{
	int answers = 0;
	int i;
	char bool[5];
	for(i=0;i<5;i++)
	{
		scanf("%s",bool);
		if(bool[0] == 'T') answers++;
	}
	printf("Telefonou para a vitima?\nEsteve no local do crime?\nMora perto da vitima?\nDevia para a vitima?\nJa trabalhou com a vitima?\n");
	if(answers<2) printf("Inocente");
	else if(answers==2) printf("Suspeita");
	else if(answers>=3 && answers<=4) printf("Cúmplice");
	else if(answers>=5) printf("Assassino");
	printf("\n");
	return 0;
}

