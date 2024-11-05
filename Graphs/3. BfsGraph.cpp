/*

Breadth First Search

Idea:
1. Create a queue and push source element into it  
2. create visited array and make source elemented visited
3. while queue is not empty, pop front element and make it visited
4. push all its adjacent elements into queue if they are not yet visited and mark them visited

https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

*/ 


#include <bits/stdc++.h>
using namespace std;

void BFSUtil(int src, vector<int> adj[],vector<bool> &visited){
    queue<int>q;
    visited[src] = true;
    q.push(src);
   
    while(!q.empty()){
        int node = q.front(); 
        cout << node << " ";
        q.pop();
        for (auto x: adj[node]){
            if (!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
// 0-based indexing
void BFS(vector<int> adj[], int V){
    vector<bool>visited(V, false);
    for (int i=0; i<V; i++)
        if (visited[i] == false){
            BFSUtil(i, adj, visited);
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