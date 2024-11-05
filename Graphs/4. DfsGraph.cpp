/*

Depth First Search

Idea:
1. keep going to adjacent elements untill a visted node appears
2. call the same process recursively


https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

*/ 


#include <bits/stdc++.h>
using namespace std;

void DFSUtil(int src, vector<int> adj[],vector<bool> &visited){
    visited[src]=true;
    cout<< src <<" ";
    for(auto node:adj[src]){
        if(!vis[node]){
            DFSUtil(node,adj,visited);
        }
    }
}
// 0-based indexing
void DFS(vector<int> adj[], int V){
    vector<bool>visited(V, false);
    for (int i=0; i<V; i++)
        if (visited[i] == false){
            DFSUtil(i, adj, visited);
        }
            
}


int main(){
    int n=5;
 
    // Given Edges - 4
    vector<vector<int>> arr = { { 0, 1 }, {0, 2}, 
            { 1, 3 }, { 1, 4 }, {2,4} };

    int m = arr.size();
    
    vector<int>adj[n];

    // use vector<pair<int,int>>adj[n+1];  for weighted graph

    for(int i=0;i<m;i++){
        int u = arr[i][0];
        int v = arr[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); // in case of undirected , erase this line for directed
    }
    
    BFS(adj,n);

    
}