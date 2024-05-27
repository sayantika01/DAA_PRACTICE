#include<bits/stdc++.h>
using namespace std;
const int MAX_VERT=100;
int minDist(int dist[],bool visited[],int vertices){
    int min=INT_MAX,min_index;
    for(int i=0;i<vertices;i++){
        if(!visited[i] && dist[i]<min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void dij(int adjMatrix[MAX_VERT][MAX_VERT],int src, int vertices){
    int dist[MAX_VERT];
    bool visited[MAX_VERT]={false};

    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i=0;i<=vertices;i++){
        int u=minDist(dist,visited,vertices);
        visited[u]=true;
        for(int v=0;v<=vertices;v++){
            if(adjMatrix[u][v] && !visited[v] && dist[u]!=INT_MAX && dist[u]+adjMatrix[u][v]<dist[v]){
                dist[v]=dist[u]+adjMatrix[u][v];
            }
        }
    }
    cout<<"Vertices\t \t Distance from the source"<<endl;
    for(int i=0;i<vertices;i++){
        cout<<i<<" \t \t \t"<<dist[i]<<endl;
    }

}
int main(){
    int v,e;
    cout<<"Enter the no. of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    int adjMatrix[MAX_VERT][MAX_VERT];
    cout<<"Enter the edges with their weight (u v w): "<<endl;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjMatrix[u][v]=w;
        adjMatrix[v][u]=w;
    }
    int src;
    cout<<"Enter the starting vertex: ";
    cin>>src;
    dij(adjMatrix, src,v);
    return 0;
}