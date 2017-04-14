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

node firstNode(node cell)
{
	if(cell->prev == NULL) return cell;
	else firstNode(cell->prev);
}
void new(int x,node last)
{
	node cell;
	cell = malloc(sizeof(list));
	last->next = cell;
	cell->cont = x;
	cell->next = NULL;
	cell->prev = last;
}

node init()
{
	node new;
	new = malloc(sizeof(list));
	new->cont = 0;
	new->prev = NULL;
	return new;
}
node initList(int size)
{
	node first,cell;
	first = init();
	cell = first;
	int i;
	for(i=1;i<size;i++)
	{
		new(i,cell);
		cell = cell->next;
	}
	return first;
}
void iterAddr(node cell)
{
	printf("%p ",cell);
	if(cell->next == NULL) printf("\n");
	else iterAddr(cell->next);
}
void iter(node cell)
{
	printf("%d ",cell->cont);	
	if(cell->next == NULL) printf("\n");
	else iter(cell->next);
}
void iterCounter(node cell)
{
	printf("%d ",cell->cont);	
	if(cell->prev == NULL) printf("\n");
	else iterCounter(cell->prev);
}
void preInsert(int val,node cell)
{
	node new;
	new = malloc(sizeof(list));
	if(cell->prev != NULL)
	{ 
		cell->prev->next = new;
		new->cont = val;
		new->prev = cell->prev;
		new->next = cell;
		cell->prev = new;
	}
	else
	{
			new->cont = cell->cont;
			cell->cont = val;
			new->next = cell->next;
			cell->next = new;
	}
}
void postInsert(int val,node cell)
{
	node new;
	new = malloc(sizeof(list));
	new->next = cell->next;
	new->cont = val;
	new->prev = cell;
	new->next->prev = new;
	cell->next = new;
}
node search(int sear,node cell)
{
	if(cell->cont == sear)
	{ 
		return(cell);
	}	
	else if(cell->next != NULL) 
	{
		search(sear,cell->next);
	}
	else return NULL;
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
		cell->next->prev = cell->prev;
		cell->prev->next = cell->next;
		free(cell);
	}
}

void close(node cell)
{
	node next = cell->next;
	cell->next = NULL;
	cell->prev = NULL;
	free(cell);
	if(next != NULL) close(next);
}

void searchAndInsert(int sea,int ins,node cell)
{
	node handle;
	handle = search(sea,cell);
	if(handle->next != NULL || handle->prev != NULL) postInsert(ins,handle);
	else printf("%d not found in list.\n",sea);
}

void searchAndRemove(int sea,node cell)
{
	node handle;
	handle = search(sea,cell);
	if(handle->next != NULL || handle->prev != NULL) removeCell(handle);
	else printf("%d not found in list.\n",sea);
}

int valid(node cell)
{
	if(cell != NULL) return 1;
	else return 0;
}
void swapVal(int val1, int val2,node cell)
{
	node first,second;
	int middle;
	first = search(val1,cell);
	second = search(val2,cell);
	if(valid(first) && valid(second))
	{	
		middle = first->cont;
		first->cont = second->cont;
		second->cont = middle;
	}
	else printf("Operation impossible.\n");
}
void swapCell(node first,node second)
{
	int middle;
	middle = first->cont;
	first->cont = second->cont;
	second->cont = middle;
}
node last(node cell)
{
	if(cell->next == NULL) return cell;
	else last(cell->next);
}

node sub(int start, int end, node cell)
{
	node firstCell,lastCell,newList;
	newList = init();
	firstCell = search(start,cell);
	lastCell = search(end,cell);
	if(valid(firstCell) && valid(lastCell))
	{
		while(firstCell != lastCell->next)
		{
			new(firstCell->cont,newList);
			firstCell = firstCell->next;
			newList = newList->next;
		}	
		while(newList->prev !=NULL)
		{
			newList = newList->prev;
		}
		removeCell(newList);
		return(newList);
	}
}
void bubble(node cell,int swapp,int order)
{
	//order 0 for ascending, 1 for descending.
	if(cell->next == NULL && !swapp) return;
	else if(swapp) bubble(firstNode(cell),0,order);
	else if(order && cell->cont < cell->next->cont)
	{
		swapCell(cell,cell->next);
		if(!swapp) swapp++;
		bubble(cell->next,swapp,order);
	}
	else if(!order && cell->cont > cell->next->cont)
	{
		swapCell(cell,cell->next);
		if(!swapp)swapp++;
		bubble(cell->next,swapp,order);
	}
	else bubble(cell->next,swapp,order);
}
int main(int argc, char **argv)
{
	node firstCell;
	firstCell = initList(10);
	iter(firstCell);
	close(firstCell);
	return 0;
}

