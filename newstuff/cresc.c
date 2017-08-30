#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node node;
typedef struct node 
{
	int val;
	node *next;
	node *prev;
	int ordered;
} node;

node *new()
{
	node *new = malloc(sizeof(node));
	new->val = 0;
	new->next = NULL;
	new->prev = NULL;
	new->ordered = 0;
	return(new);
}
void swapCell(node *first,node *second) //To be used when you have the pointers to the spefici cells.
{
	int middle;
	middle = first->val;
	first->val = second->val;
	second->val = middle;
}
node *firstNode(node *cell)
{
	if(cell->prev == NULL) return cell;
	else firstNode(cell->prev);
}

void bubble(node *cell,int swapp,int order)
{
	//order 0 for ascending, 1 for descending.
	if(cell->next == NULL && !swapp)
	{
		if(!order) firstNode(cell)->ordered = 1;
		return;
	}
	else if(swapp) bubble(firstNode(cell),0,order);
	else if(order && cell->val < cell->next->val)
	{
		swapCell(cell,cell->next);
		if(!swapp) swapp++;
		bubble(cell->next,swapp,order);
	}
	else if(!order && cell->val > cell->next->val)
	{
		swapCell(cell,cell->next);
		if(!swapp)swapp++;
		bubble(cell->next,swapp,order);
	}
	else bubble(cell->next,swapp,order);
}

void append(int val,node *head)
{
	while(head->next != NULL)
		head = head->next;
	node *new = malloc(sizeof(node));
	new->val = val;
	new->next = NULL;
	new->prev = head;
	head->next = new;
	return;
}

int contain(int val, node *stuff)
{
	while(stuff != NULL)
	{
		if(stuff->val == val) return 1;
		stuff = stuff->next;
	}
	return 0;
}

node *subc(node *first, node *second)
{
	node *new = malloc(sizeof(node));
	int mark;
	while(first != NULL)
	{
		if(contain(first->val,second) && !contain(first->val,new))
		{
			mark++;
			append(first->val,new);
		}
		first = first->next;
	}
	if(!mark) return NULL;
	else return new;
}
void pList(node *first)
{
	while(first != NULL)
	{
		printf("%d ",first->val);
		first = first->next;
	}
	printf("\n");
}
int main()
{
	node *first = new();
	int size,curr,i;
	while(scanf("%d",&curr)!= EOF)
		append(curr,first);
	bubble(first,0,0);
	pList(first->next);
	return 0;

}
