#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 1000

 struct Edge{
    int s,d,w;
};


struct Graph{
    int V,E;
    Edge edges[MAX_VERTICES];
};

void initialise(Graph *graph,int V,int E){
    graph->V =V;
    graph->E=E;
}

void relax(int distance[],int u,int v,int weight)
{
   if(distance[u]!=INT_MAX &&distance[u]+weight<distance[v])
   {
        distance[v] = distance[u] +weight;
   }
}

void bellmanFord(struct Graph graph, int source) {
    int distance[MAX_VERTICES];
    
   
    for (int i = 0; i < graph.V; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    
    
    for (int i = 0; i < graph.V - 1; i++) {
        for (int j = 0; j < graph.E; j++) {
            int u = graph.edges[j].source;
            int v = graph.edges[j].destination;
            int weight = graph.edges[j].weight;
            relax(distance, u, v, weight);
        }
    }


int main()
{
    int V,E;
    scanf("%d%d",&V,&E);
    Graph graph;
    initialise(&graph,V,E);
    cout<<"Enter edge details (source vertex, destination vertex, weight)\n";
    for(int i=0;i<E;i++){c
        int u,v,w;
        cin>>u>>v>>w;
        graph.edges[i].s=u;
        graph.edges[i].d=v;
        graph.edges[i].w=w;
    }
    int source=0;
    bellmanFord(graph,source);
    return 0;
}


