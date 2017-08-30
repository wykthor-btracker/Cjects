#include <stdio.h>
#include <stdlib.h>

typedef struct tree tree;
typedef struct tree *node;
struct tree
{
	int cont;
	node *list;
};

node init()
{
	node new;
	new = malloc(sizeof(tree));
	new->cont = 0;
	new->list = malloc(sizeof(node*)*3);
	int i;
	for(i=0;i<3;i++) new->list[i] = malloc(sizeof(tree));
	return(new);
}
int main(int argc, char **argv)
{
	node new = init();
	printf("%d",new->list[0]->cont);
	return 0;
}

