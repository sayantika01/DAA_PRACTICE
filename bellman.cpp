#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src;
    int dest;
    int weight;
};
struct Graph{
    int V;
    int E;
    struct Edge* edge;
};
struct Graph* createGraph(int V,int E){
    struct Graph* graph=new Graph;
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[E];
    return graph;
}
void print(int dist[],int V){
    cout<<"Vertices \t Distance from the src"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<" \t\t "<<dist[i]<<endl;
    }
}
void bellman(struct Graph* graph, int src){
    int V=graph->V;
    int E=graph->E;
    int dist[V];

    for(int i=0;i<V;i++){
        dist[V]=INT_MAX;
    }
    dist[src]=0;

    for(int i=0;i<E;i++){
        int u=graph->edge[i].src;
        int v=graph->edge[i].dest;
        int w=graph->edge[i].weight;

        if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
            dist[v]=dist[u]+w;
        }
    }

    //for negative edges
    for(int i=0;i<E;i++){
        int u=graph->edge[i].src;
        int v=graph->edge[i].dest;
        int w=graph->edge[i].weight;

        if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
            cout<<"There is a negative edge in the graph !!"<<endl;
            return;
        }
    }
    print(dist,V);
}
int main(){
    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;

    struct Graph* graph=createGraph(v,e) ;
    cout<<"Enter the edges:"<<endl;
    for(int i=0;i<e;i++){
        cin>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
    }
    int src;
    cout<<"Enter the source vertex: ";
    cin>> src;

    bellman(graph, src);
    return 0;
}
/*0                0
1                1
2                -1
3                2*/