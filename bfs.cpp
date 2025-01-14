// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
void bfs(int start, list<int>* adjList, bool* visited){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        
        for(int neighbour: adjList[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
        
    }
}
int main(){
    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    list<int>* adjList= new list<int>[v];
    bool* visited= new bool[v];
    for(int i=0;i<v;i++){
        visited[v]={false};
        }
        
    cout<<"Enter the edges (u v):"<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v); 
        adjList[v].push_back(u);
    }
    int start;
    cout<<"Enter the starting the vertex: ";
    cin>>start;
    cout<<"Result: ";
    bfs(start, adjList, visited);
    cout<<endl;
    delete[] adjList;
    delete[] visited;
    return 0;
}