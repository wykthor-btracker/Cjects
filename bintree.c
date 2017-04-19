#include <stdio.h>
#include <stdlib.h>
#define DEBUG if(1)
typedef struct tree tree;
typedef struct tree *node;
struct tree
{
	int val;
	node pai;
	node esq;
	node dir;
};
//Function prototypes.
void insert(int,node);
node init()
{
	node new = malloc(sizeof(tree));
	new->val = 0;
	new->pai = NULL;
	new->esq = NULL;
	new->dir = NULL;
	return new;
}
void new(int val,node pai)
{
	node branch = init();
	branch->val = val;
	branch->pai = pai;
	if(val > pai->val)
	{									
		if(pai->dir == NULL) pai->dir = branch;
		else if(val < pai->dir->val)
		{
			free(branch);
			DEBUG printf("Inserting %d at %d\n",val,pai->dir->val);
			insert(val,pai->dir);
		}
		else if(val > pai->dir->val)
		{
			free(branch);
			DEBUG printf("Sending %d down branch %d\n",val,pai->dir->val);			
			new(val,pai->dir);
		}
	}
	else if(val < pai->val)
	{
		if(pai->esq == NULL) pai->esq = branch;
		else if(val > pai->esq->val)
		{ 
			DEBUG printf("Inserting %d at %d\n",val,pai->esq->val);			
			free(branch);
			insert(val,pai->esq);
		}
		else if(val < pai->esq->val)
		{
			free(branch);
			new(val,pai->esq);
			DEBUG printf("Sending %d down branch %d\n",val,pai->esq->val);					
		}
	}
	else free(branch);
}
void swap(node pai, node filho)
{
	int middle;
	middle = pai->val;
	pai->val = filho->val;
	filho->val = middle;
}
void insert(int val,node pai)
{
	node filho = init();
	filho->pai = pai;
	filho->val = val;
	if(filho->val > pai->val)
	{
		 pai->dir = filho;
		 swap(pai,filho);
	 }
	 else if(filho->val < pai->val)
	 {
		pai->esq = filho;
		swap(pai,filho);
	}
}
void erd(node root)
{
	if(root == NULL) return;
	else
	{
		printf("Pre-left\n");
		erd(root->esq);
		printf("Mid\n");
		printf("%d\n",root->val);
		printf("Pre-right\n");			
		erd(root->dir);
	}
}
int main(int argc, char **argv)
{
	node first = init();
	int arr[9] = {8,7,3,1,10,5,4,2,6};
	int i;
	for(i=0;i<9;i++) new(arr[i],first);
	erd(first);
	return 0;
}
