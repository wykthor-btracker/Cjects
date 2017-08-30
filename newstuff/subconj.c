#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node node;
typedef struct node 
{
	int val;
	node *next;
} node;

node *new()
{
	node *new = malloc(sizeof(node));
	new->val = 0;
	new->next = NULL;
	return(new);
}

void append(int val,node *head)
{
	while(head->next != NULL)
		head = head->next;
	node *new = malloc(sizeof(node));
	new->val = val;
	new->next = NULL;
	head->next = new;
	return;
}

void insert(int val, node *head)
{
	node *new = malloc(sizeof(node));
	new->val = val;
	new->next = head;
	return;
}

void pList(node *head);
void fill(node *head,int size)
{
	int i;
	int curr;
	node *first = head;
	for(i=0;i<size;i++)
	{
		scanf(" %d",&curr);
		append(curr,head);
	}
}
void pList(node *head)
{
	while(head != NULL)
	{
		printf("%d ",head->val);
		head = head->next;
	}
	printf("\n");
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
int subc(node *first, node *second)
{
	while(first != NULL)
	{
		if(!contain(first->val,second)) return 0;
		first = first->next;
	}
	return 1;
}
int main()
{
	node *first = new();
	node *second = new();
	int size;
	scanf(" %d",&size);
	fill(first,size);
	scanf(" %d",&size);
	fill(second,size);
	printf("%d\n",subc(second,first));
	return 0;
}
