#include <stdio.h>
#include <stdlib.h>
typedef struct list list;
typedef struct list *node;
struct list
{
	int cont;
	node next;
	node prev;
};

void new(int x,node last)
{
	node cell;
	cell = malloc(sizeof(list));
	last->next = cell;
	cell->cont = x;
	cell->next = NULL;
	cell->prev = last;
}

node init(int size)
{
	node first,cell;
	first = malloc(sizeof(list));
	first->cont = 0;
	first->prev = NULL;
	cell = first;
	int i;
	for(i=1;i<=size;i++)
	{
		new(i,cell);
		cell = cell->next;
	}
	return first;
}

void iter(node cell)
{
	if(cell->next == NULL) printf("\n");
	else
	{
		printf("%d ",cell->cont);
		iter(cell->next);
	}
}
void insert(int val,node cell)
{
	node new;
	new = malloc(sizeof(list));
	new->next = cell->next;
	new->cont = val;
	new->prev = cell;
	cell->next = new;
}
node search(int sear,node cell)
{
	node null;
	null->cont = -1;
	null->prev = NULL;
	null->next = NULL;
	printf("%d %d\n",cell->cont,sear);
	if(cell->cont == sear) return cell;
	else if(cell->next != NULL) search(sear,cell->next);
}

void removeCell(node cell)
{
	if(cell->prev == NULL)
	{
		cell->cont = cell->next->cont;
		node copy = cell->next->next;
		free(cell->next);
		cell->next = copy;
	}
	else
	{ 
		cell->prev->next = cell->next;
		free(cell);
	}
}

void close(node cell)
{
	node next = cell->next;
	free(cell);
	if(cell->next != NULL) close(next);
}

int main(int argc, char **argv)
{
	node first;
	first = init(5);
	printf("%d",search(3,first)->cont);
	close(first);
	return 0;
}

