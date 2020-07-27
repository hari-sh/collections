#include "list.h"

typedef struct Graph graph;
struct Graph
{ 
	int V; 
	list** array;
	int* visited;
};

graph* graph_create(int V) 
{ 
	graph* graph = malloc(sizeof(graph));
	graph->V = V;

    graph->array = (list**)malloc(V * sizeof(list)); 
    graph->visited = (int*)malloc(V * sizeof(int));
  
	int i; 
	for (i = 0; i < V; i++) {
		graph->array[i] = list_create(sizeof(int)); 
		graph->visited[i] = 0; 
	}

	return graph; 
} 
/*
void graph_dfs(graph* graph, int v)	{
	graph_dfs_util(graph, v);
	printf("\n");
	for(int i=0; i<graph->V; i++)	{
		graph->visited[i] = 0;
	}
}

void graph_dfs_util(graph* graph, int v)	{
	graph->visited[v] = 1;
	printf("%d ", v);
	list_node* array = graph->array[v]->head;
	while(array != NULL)
	{ 
		int* data = array->data;
		if (!graph->visited[*data]) 
			graph_dfs_util(graph, *data);
		else	{
			array = array->next;
		}
	}	
}
*/


void graph_bfs_util(graph* g, int v)	{
	list_node* temp = g->array[v]->head;
	
	if(temp!=NULL)	{
		list_node* p= temp;
		while(p!=NULL){
			int data = *(int*)(temp->data);
			if(!g->visited[data])	{
				printf("%d\n", data);
			}
		g->visited[data]=1;
		p=p->next;
		}
		/*
		while(temp!=NULL){
			int* data = (int*)(temp->data);
			graph_bfs_util(g, *data);
			temp=temp->next;
		}
		*/
	}
}

void graph_bfs(graph* graph, int v)	{
	graph_bfs_util(graph, v);
	printf("\n");
	for(int i=0; i<graph->V; i++)	{
		graph->visited[i] = 0;
	}
}

void graph_add_edge(graph* graph, int src, int dest) 
{ 
    list_push((graph->array[src]), &dest);
    list_push((graph->array[dest]), &src);
} 

void print_vertex(void* vert)    {
    printf("%d  ", *(int*)vert);
}

void graph_print(graph* graph) 
{ 
	int v; 
	for (v = 0; v < graph->V; ++v) 
	{ 
        printf("vertex %d  visited %d........",v, graph->visited[v]);
		list_print((graph->array[v]), print_vertex);
        
	}
} 

void main() 
{
	graph* graph = graph_create(5); 

	graph_add_edge(graph, 0, 1); 
	graph_add_edge(graph, 0, 4); 
	graph_add_edge(graph, 1, 2); 
	graph_add_edge(graph, 1, 3); 
	graph_add_edge(graph, 1, 4); 
	graph_add_edge(graph, 2, 3); 
	graph_add_edge(graph, 3, 4); 
    
	graph_bfs(graph, 0);
	graph_print(graph);
} 

