#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#define DEBUG if(0)
#define FINDSEG if(0) printf("No segfault yet.\n");
typedef struct node node;
typedef struct node 
{
	int primo;
	int exp;
	node *next;
} node;
node *new()
{
	node *new = malloc(sizeof(node));
	new->primo = -1;
	new->exp = -1;
	new->next = NULL;
	return new;
}
node *append(node *tail, int val,int exp)
{
	node *new = malloc(sizeof(node));
	new->primo = val;
	new->next = NULL;
	new->exp = exp;
	tail->next = new;
	return new;
}
int powr(int x, int y)
{
	if(y == 0) return 1;
	else if(y == 1) return x;
	else return x*powr(x,y-1);
}
void printList(node *head)
{
	while(head != NULL)
	{
		printf("powr(%d,%d) ",head->primo,head->exp);
		head = head->next;
	}
	printf("\n");
}
node *decomp(int val)
{
	int list[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int ind = 0;
	node *first = new();
	node *current = first;
	while(val!=1)
	{
		int curr = 0;
		while(val%list[ind]==0)
		{ 
			val/=list[ind];
			curr++;
		}
		current = append(current,list[ind],curr);
		ind++;
	}
	return(first->next);
	
}
int min(int x, int y)
{
	if(x<y) return x;
	else return y;
}
int max(int x, int y)
{
	if(x>y) return x;
	else return y;
}
int mmc(node *first, node *second)
{
	int acc = 1;
	int f = 0,s = 0;
	DEBUG printList(first);
	DEBUG printList(second);
	FINDSEG
	while(first != NULL && second != NULL)
	{
		FINDSEG
		acc*= powr(first->primo,max(first->exp,second->exp));
		first = first->next;
		second = second->next;
		
	}
	if(first == NULL) f++;
	if(second == NULL) s++;
	while(!f || !s)
	{
		if(!f)
		{
			acc*= powr(first->primo,first->exp);
			first = first->next;
			if(first == NULL) f++;
			DEBUG printf("%d segundo f\n", acc);
		}
		if(!s)
		{ 
			acc*= powr(second->primo,first->exp);
			second = second->next;
			if(second == NULL) s++;
			DEBUG printf("%d segundo s\n", acc);		
		}
	}
	return acc;
}
int mdc(node *first, node *second)
{
	int acc = 1;
	int f = 0,s = 0;
	DEBUG printList(first);
	DEBUG printList(second);
	while(first != NULL && second != NULL)
	{
		acc*= powr(first->primo,min(first->exp,second->exp));
		first = first->next;
		second = second->next;
		
	}
	if(first == NULL) f++;
	if(second == NULL) s++;
	while(!f || !s)
	{
		if(!f)
		{
			acc*= powr(first->primo,0);
			first = first->next;
			if(first == NULL) f++;
			DEBUG printf("%d segundo f\n", acc);
		}
		if(!s)
		{ 
			acc*= powr(second->primo,0);
			second = second->next;
			if(second == NULL) s++;
			DEBUG printf("%d segundo s\n", acc);		
		}
	}
	return acc;
}
int run(node *first,node *second,int flag)
{
	//flag 1, run mdc, flag 0, run mmc
	node *bkpf = first;
	node *bkps = second;
	int sizeF = 0,sizeS = 0;
	while(first != NULL)
	{
		sizeF++;
		first = first->next;
	}
	while(second != NULL)
	{
		sizeS++;
		second = second->next;
	}
	if(sizeF>sizeS)
		{
	if(!flag)
		return mmc(bkpf,bkps);
	else
		return mdc(bkpf,bkps);
	}
	else
	{
	if(!flag)
		return mmc(bkps,bkpf);
	else
		return mdc(bkps,bkpf);
	}
}
int main()
{
	int first,second;
	scanf("%d %d",&first,&second);
	printf("mmc(%d,%d) = %d\n",first,second,run(decomp(first),decomp(second),0));
	printf("mdc(%d,%d) = %d\n",first,second,run(decomp(first),decomp(second),1));
	return 0;
}

