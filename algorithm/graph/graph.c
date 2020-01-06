/*
 * 对邻接表的深度优先搜索和广度优先搜索
 */
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX 8

void dfs(int vertex);
typedef struct graph_node *graph_point;
typedef struct graph_node{
	int vertex;
	graph_point link;
}graph_node;

graph_point graph[MAX] = {NULL};
int visit[MAX]={FALSE};
void initial_graph(graph_node graph[]);

int main(int argc,char *argv[])
{
	

}

void initial_graph(graph_point graph[])
{
	int i;
	graph_point temp = NULL;
	for(i=0;i<MAX;i++){
		graph[i]->vertex = i;
		graph[i]->link = NULL;
	}

	//temp = (graph_point)malloc(sizeof(graph_point));
}

void dfs(int v)
{
	graph_point w;
	visit[v] = TURE;//表示访问过了
	printf("%d ",graph[i]->vertex);
	for(w=graph[v];w;w=w->link){
		if(!visit[v])
			dfs(w->vertex);
	}
}





