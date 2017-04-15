#include <stdio.h>
#include <stdlib.h>
#define DEBUG if(0)
typedef struct table table;
typedef struct table *node;
struct table
{
	int **array;
	int size;
	int cost; 						//Cost is relative to which state points to this, where you decide the cost by stating how much
	node next;						//this state is closer to the solution than the previous state.
	node prev;
};
void swap(node,int*,int*);
int *posi(int,int);
void printTable(node);
node init(int **array,int size)
{
	node first;
	int i;
	first = malloc(sizeof(table));
	first->array = malloc(sizeof(int*)*size);
	for(i=0;i<size;i++) first->array[i] = malloc(sizeof(int)*size);
	first->array = array;
	first->size = size;
	first->next = NULL;
	first->prev = NULL;
	DEBUG printf("hello! %p\n",first);
	return(first);
}
void newCell(node last,int cost,int **array)
{
	node new;
	new = init(array,last->size);	
	new->cost = cost;
	new->prev = last;
	last->next = new;
	DEBUG printf("%p %p\n",new->prev,new);
}

node *adjacent(int *index,node state)
{
	int size = state->size,i;
	printf("%d %d\n",index[0],index[1]);
	node *list = malloc(sizeof(node*)*4);
	for(i=0;i<state->size;i++) list[i] = init(state->array,state->size);
	for(i=0;i<state->size;i++) if(list[i] == NULL) printf("%d isn't initialized\n",i);
	printf("HI!\n");
	if(index[0]+1 < size) 	swap(list[0],	posi(index[0]+1,index[1]),	posi(index[0],index[1]));
	printf("HI!\n");	
	if(index[0]-1 >= 0) 	swap(list[1],	posi(index[0]-1,index[1]),	posi(index[0],index[1]));
	printf("HI!\n");	
	if(index[1]+1 < size) 	swap(list[2],	posi(index[0],index[1]+1),	posi(index[0],index[1]));
	printf("HI!\n");	
	if(index[1]-1 >= 0) 	swap(list[3],	posi(index[0],index[1]-1),	posi(index[0],index[1]));
	printf("HI!\n");
	return(list);
}

int *posi(int y, int x)
{	
	int *pos = malloc(sizeof(int)*2);
	pos[0] = y;
	pos[1] = x;
	return pos;
}
int *findZero(node state)
{
	int i,j;
	for(i=0;i<state->size;i++) for(j=0;j<state->size;j++) if(state->array[i][j] == 0) return(posi(i,j));
}

void swap(node state, int *indexFirst,int *indexSecond)
{
	int middle;
	printf("Test\n");
	printf("(%d,%d) <-> (%d,%d)\n",indexFirst[0],indexFirst[1],indexSecond[0],indexSecond[1]);
	if(state != NULL)
	{
		middle = state->array[indexFirst[0]][indexFirst[1]];
		state->array[indexFirst[0]][indexFirst[1]] = state->array[indexSecond[0]][indexSecond[1]];
		state->array[indexSecond[0]][indexSecond[1]] = middle;
		printTable(state);	
		printf("Test end\n");
	}	
	else printf("Passed state is invalid.\n");
}
void printTable(node state)
{
	int i,j;
	for(i=0;i<state->size;i++)
	{
		for(j=0;j<state->size;j++) printf("%d ",state->array[i][j]);
		printf("\n");
	}
}
int **initArray(int size)
{
	int i,j,**array;
	array = malloc(sizeof(int*)*size);
	for(i=0;i<size;i++) array[i] = malloc(sizeof(int)*size);
	for(i=0;i<size;i++) for(j=0;j<size;j++) scanf("%d",&array[i][j]);
	return array;
}
int mod(int value)
{
	if(value >= 0) return value;
	else return -value;
}
int distance(node state,int *index)
{
	int i,j,*dis,sum = 0;
	if(state->array[index[0]][index[1]])
	{ 
		for(i=0;i<state->size;i++) 
		for(j=0;j<state->size;j++) 
		if(((i*state->size)+j)+1 == state->array[index[0]][index[1]]) dis = posi(i,j);
		sum = mod(dis[0]-index[0])+mod(dis[1]-index[1]);
		DEBUG printf("%d is %d steps away from home\n",state->array[index[0]][index[1]],sum);
		free(dis);
	}
	return(sum);
}
int steps(node state)
{
	int i,j,sum = 0;
	for(i=0;i<state->size;i++) for(j=0;j<state->size;j++) sum+=distance(state,posi(i,j));
	return sum;
}
int main(int argc, char **argv)
{
	node first;
	node *list;
	int **array,size = 3,i;
	array = initArray(size);
	first = init(array,size);
	printTable(first);
	list = adjacent(findZero(first),first);
	for(i=0;i<4;i++) if(list[i] != NULL) printf("%d\n",steps(list[i]));
	return 0;
}

