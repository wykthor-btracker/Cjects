#include <stdio.h>
#include <stdlib.h>
typedef struct map map;
typedef struct map *point;
struct map
{
	char name; //only one char is needed to identify a point.
	int *distance;
	point *nodes;
	int size;
};

point init(char name)
{
	point new;
	new = malloc(sizeof(map));
	new->name = name;
	new->distance = malloc(sizeof(int));
	new->nodes = malloc(sizeof(point*));
	new->size = 1;
	return new;
}

void add(int count,int *distance,point *list,point node)
{
	node->nodes = realloc(node->nodes,sizeof(point*)*(node->size+count));
	node->distance = realloc(node->distance,sizeof(int*)*(node->size+count));
	int i;
	for(i=0;i<count;i++)
	{ 
		node->distance[node->size+i] = distance[i];
		node->nodes[node->size+i] = list[i];
	}
}

void close(point kill)
{
	kill->distance = NULL;
	free(kill->distance);
	kill->nodes = NULL;
	free(kill->nodes);
	free(kill);
}

int main(int argc, char **argv)
{
	point first;
	int size = 3;
	int i,*dis = malloc(sizeof(int)*size);
	point *list = malloc(sizeof(point*)*size);
	for(i=0;i<size;i++)
	{ 
		list[i] = init('a'+i);
		dis[i] = i;
	}
	first = init('z');
	add(size,dis,list,first);
	printf("%c",first->nodes[0]->name);
	return 0;
}

