#include <stdio.h>
#include <stdlib.h>
typedef struct mob mob;
typedef struct mob *point;
struct mob
{
	char nome[20];
	int id;
	int level;
	int vida;
	int ataque;
	int defesa;
};
int main(int argc, char **argv)
{
	point list;
	char *c;
	c = malloc(sizeof(char)*20);
	int i,size,curr;
	scanf("%d",&size);
	list = malloc(sizeof(mob)*size);
	for(i=0;i<size;i++)
	{
		curr = 0;
		scanf(" %[^\n]",list[i].nome);
		scanf("%d %d %d %d %d",&list[i].id,&list[i].level,&list[i].vida,&list[i].ataque,&list[i].defesa);
	}
	for(i=0;i<size;i++)
		printf("Nome: %s\nID: %d\nLevel: %d\nVida: %d\nAtaque: %d\nDefesa: %d\n",
		list[i].nome,
		list[i].id,
		list[i].level,
		list[i].vida,
		list[i].ataque,
		list[i].defesa);
	return 0;
}

