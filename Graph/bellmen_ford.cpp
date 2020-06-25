#include <iostream>
#include<climits> 
using namespace std;
struct Edge { 
	int src, dest, weight; 
}; 


struct Graph { 
	int V, E; 

	struct Edge* edge; 
}; 

// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 
	graph->edge = new Edge[E]; 
	return graph; 
} 


int BellmanFord(struct Graph* graph, int src) 
{ 
	int V = graph->V; 
	int E = graph->E; 
	int dist[V]; 

	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX; 
	dist[src] = 0; 

	for (int i = 1; i <= V - 1; i++) { 
		for (int j = 0; j < E; j++) { 
			int u = graph->edge[j].src; 
			int v = graph->edge[j].dest; 
			int weight = graph->edge[j].weight; 
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				dist[v] = dist[u] + weight; 
		} 
	} 

	for (int i = 0; i < E; i++) { 
		int u = graph->edge[i].src; 
		int v = graph->edge[i].dest; 
		int weight = graph->edge[i].weight; 
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
			return 1; // If negative cycle is detected, simply return 
		} 
	} 
	return 0; 
} 

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        struct Graph* graph=createGraph(v,e);
        for(int i=0;i<e;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            graph->edge[i].src = a; 
	        graph->edge[i].dest = b; 
	        graph->edge[i].weight = c; 
        }
        cout<<BellmanFord(graph, 0)<<endl; 
    }

	return 0; 
} 
