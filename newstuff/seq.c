#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DEBUG if(0)
typedef struct node node;
typedef struct node 
{
	int val;
	node *next;
	node *prev;
	int ordered;
} node;
typedef struct stra str;
typedef struct stra
{
	char val;
	str *next;
} str;
node *new()
{
	node *new = malloc(sizeof(node));
	new->val = 0;
	new->next = NULL;
	new->prev = NULL;
	new->ordered = 0;
	return(new);
}
void swapCell(node *first,node *second) //To be used when you have the pointers to the specific cells.
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

void append(node *head,int val)
{
	node *new = malloc(sizeof(node));
	new-> val = val;
	new->next = NULL;
	new->ordered = 0;
	while(head->next != NULL)
		head = head->next;
	head->next = new;
	new->prev = head;
}

node *readtonode(char stop)
{
	node *first = new();
	int i;
	for(;;)
	{
		char current;
		scanf("%c",&current);
		if(current != stop)
			append(first,current-48);
		else
			break;
	}
	return first;
}
void bigseq(node *list)
{
	int max = 0;
	int str,end,set = 0;
	int mstr,mend;
	char curr,ind = 0;
	list = list->next;
	curr = 0;
	while(list->next != NULL)
	{
		if(list->val == 0 && !set)
		{
			set = 1;
			str = ind;
			DEBUG printf("str %d\n",str);
		}
		if(set) curr++;
		if((list->next->next == NULL || list->next->val == 1) && set)
		{
			set = 0;
			end = ind;
			DEBUG printf("end %d\n", end);
			if(max<curr)
			{
				DEBUG printf("curr %d\n",curr);
				max = curr;
				mstr = str;
				mend = end;
			}
			curr = 0;
		}
		ind++;
		list = list->next;
	}
	printf("%d %d\n",mstr+1,mend+1);

}
int main()
{
	for(;;)
	{
		node *new = readtonode('\n');
		new = new->next;
		if(new->val == 0 && new->next == NULL)
			break;
		bigseq(new);
	}
	return 0;
}
