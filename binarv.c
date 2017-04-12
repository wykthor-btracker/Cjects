#include <stdio.h>
#include <stdlib.h>
typedef struct lE lE;
typedef struct lE *cell;
struct lE
{
	int cont;
	cell next;
	cell prev;
};

void iterPos(cell node,int count)
{
	if(count == 0)printf("\n");
	else
	{
		printf("%d ",node->cont);
		iterPos(node->next,count-1);
	}
}

void iterNeg(cell node,int count)
{
	if(count == 0)printf("\n");
	else
	{
		printf("%d ",node->cont);
		iterNeg(node->prev,count-1);
	}
}

void insert(int x,cell node,int *size)
{
	cell new;
	new = malloc(sizeof(lE));
	new->cont = x;
	new->next = node->next;
	node->next = new;
	(*size)++;
}

void removeb(cell node,int *size)
{
	cell lixo;
	lixo = malloc(sizeof(lE));
	lixo = node->next->next;
	lixo->prev = node;
	node->next = lixo;
	(*size)--;
}

cell search(int x,cell node,int count)
{
	cell nullCell;
	nullCell = malloc(sizeof(lE));
	nullCell->next = NULL;
	nullCell->cont = -1;
	if(count == -1) return nullCell;
	else if(node->cont == x) return node;
	else search(x,node->next,count-1);
}

void init(cell *list,int size)
{
	(*list) = malloc(size*sizeof(lE));
	int i;
	for(i=0;i<size;i++)
	{
		(*list)[i].cont = i;
		(*list)[i].next = &(*list)[((i+1)%size+size)%size];
		(*list)[i].prev = &(*list)[((i-1)%size+size)%size];
	}
}

cell prec(cell node,int count,int x)
{
	cell np;
	np = malloc(sizeof(lE));
	np->cont = -1;
	np->next = NULL;
	if(count == -1) return np;
	else if(node->next->cont == x) return node;
	else prec(node->next,count-1,x);
}
void searchAndInsert(int sear,int inse,cell node,int *size)
{
	cell ins;
	ins = malloc(sizeof(lE));
	ins = search(sear,node,*size);
	if(ins->cont == -1) printf("%d not found in list\n",sear);
	else insert(inse,ins,size);
}
void searchAndRemove(int sear,cell node, int *size)
{
	cell rem;
	rem = malloc(sizeof(lE));
	rem = prec(node,*size,sear);
	if(rem->cont == -1) printf("%d not found in list\n",sear);
	else{ 
		printf("removed %d\n",rem->next->cont);
		removeb(rem,size);
	}
}
int main(int argc,char **argv)
{
	int size;
	scanf("%d",&size);
	cell list;
	init(&list,size);
	iterPos(list,size);
	iterNeg(&list[size-1],size);
	free(list);
	return 0;
}

