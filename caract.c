#include <stdio.h>
#include <stdlib.h>
#define MAX_PESSOAS 100
typedef struct pessoa pessoa;
typedef struct pessoa *node;
struct pessoa
{
	char sexo;
	char olho;
	char cabelo;
	int idade;
};
node init()
{
	node new = malloc(sizeof(pessoa));
	return new;
}
void iter()
{
	node list = malloc(sizeof(node*)*MAX_PESSOAS);
	int idade,maior = 0,cont = 0,index = 0;
	while(1)
	{
		scanf("%d",&idade);
		if(idade==-1) break;
		char arr[6];
		getchar();
		scanf(" %[^\n]",arr);
		list[index].sexo = arr[0];
		list[index].cabelo = arr[2];
		list[index].olho = arr[4];
		if(idade>maior) maior = idade;
		list[index].idade = idade;
		if(list[index].idade >= 18 && list[index].idade <= 35 &&
		list[index].sexo == 'f' &&
		list[index].olho == 'v' &&
		list[index].cabelo == 'l') cont++;
		index++;
	}
	printf("Mais velho: %d\n",maior);
	float x = (float) (cont*100)/(float)index;
	printf("Mulheres com olhos verdes, loiras com 18 a 35 anos: %.2f%%\n",x);
}
	
int main(int argc, char **argv)
{
	iter();
	return 0;
}

