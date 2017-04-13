#include <stdio.h>
#include <stdlib.h>

typedef struct arvore arvore;
typedef struct arvore *node;
struct arvore
{
	int cont;
	node esq;
	node dir;
};
node init()
{
	node new;
	new = malloc(sizeof(arvore));
	new->esq = NULL;
	new->dir = NULL;
	return new;
}

void new(int val,node root)
{
	node new;
	new = init();
	printf("%d %d\n",val,root->cont);
	if(val > root->cont)
	{ 
		root->dir = new;
		printf("right\n");
	}
	else if(val < root->cont) root->esq = new;
} 

void erd(node root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->cont);
		erd(root->esq);
		erd(root->dir);
	}
}

int main(int argc, char **argv)
{
	node root;
	root = init();
	root->cont = 1;
	new(2,root);
	new(0,root);
	erd(root);
	return 0;
}

