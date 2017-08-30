#include <stdio.h>
#include <stdlib.h>
struct adj_list {
	int item;
	adj_list *next;
};

struct graph {
	adj_list *vertices[MAX_SIZE];
	short visited[MAX_SIZE];
};
//PROTOTYPES
graph* create_graph();
void add_edge(graph *graph, int vertex1, int vertex2);
void dfs(graph *graph, int source);
void bfs(graph *graph, int source);
void print_graph(graph *graph);
//PROTOTYPES END


