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
	while(curr > head->val && head->next != NULL)
		head = head->next;
	if(head->next == NULL)
		append(curr,head);
	else
		insert(curr,head);
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
int main()
{
	node *first = new();
	append(0,first);
	node *second = new();
	append(0,second);
	int size;
	scanf(" %d",&size);
	fill(first->next,size);
	scanf(" %d",&size);
	fill(second->next,size);
	pList(first->next);
	pList(second->next);
	return 0;
}
