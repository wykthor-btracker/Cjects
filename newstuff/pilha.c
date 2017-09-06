#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10
#define FINDSEG if(1) printf("NO SEGFAULT YET\n");
#define DEBUG if(0)
//structs
typedef struct node node;
typedef struct node
{
	int item;
	node *next;
}node;

typedef struct stack 
{
	node *top;
}stack;
//end of structs
//protypes
stack* create_stack();
void push(stack *stack, int item);
int pop(stack *stack);
int peek(stack *stack);
int is_empty(stack *stack);
//prototypes end
stack* create_stack()
{
	stack *new_stack = malloc(sizeof(stack));
	new_stack->top = NULL;
	return new_stack;
}

void push(stack *stack, int item)
{
	node *new_top = malloc(sizeof(node));
	new_top->item = item;
	new_top->next = stack->top;
	stack->top = new_top;
}
int pop(stack *stack)
{
	if(stack->top != NULL)
	{
		int val = stack->top->item;
		stack->top = stack->top->next;
		return val;
	}
	else
		return -1;
}

int peek(stack *stack)
{
	return stack->top->item;
}
void show(stack *stack)
{
	while(stack->top!=NULL)
		printf("%d ",pop(stack));
	printf("\n");
}

int  balance()
{
	char curr;
	stack *new = create_stack();
	for(;;)
	{
		scanf("%c",&curr);
		if(curr == '\n')
			break;
		else if(curr == '(' || curr == '[')
		{
			DEBUG printf("%c",curr);
			push(new,curr);
		}
		else if(curr == ')' || curr == ']')
		{
			if(new->top != NULL)
				pop(new);
			else
				return 0;
		}
	}
	if(new->top == NULL)
		return 1;
	else
		return 0;
}
int main()
{
	int i,size;
	scanf("%d",&size);
	getchar();
	for(i=0;i<=size;i++)
		if(balance())
			printf("Yes\n");
		else
			printf("No\n");
	return 0;
}
