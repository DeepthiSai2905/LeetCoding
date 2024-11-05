/*
Detect cycle in undirected graph

Idea:
if present node is visited and its parent is not stored parent from which it is visited 
then someother node would have visited this node which means there is a cycle.

If from a node 'u' you visit a node 'v', if v is already visited and is not parent of 'u' then there is a cycle
*/

#include <bits/stdc++.h>
using namespace std;


// Detect using DFS
bool isCycleUtilDFS(int src,int parent, vector<int>adj[], vector<int>&vis){
    vis[src]=1;
    for(int node: adj[src]){
        if(!vis[node]){
            if(isCycleUtil(node,src,adj,vis)) return true;
        }
        else{
            if(parent!=node){
                return true;
            }
        }
    }
    return false;
}

bool detectCycleDFS(vector<int>adj[],int V){
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(isCycleUtilDFS(i,-1,adj,vis)){
                return true;
            }
        }
    }
    return false;
}

// Detect using BFS

bool isCycleUtilBFS(int src,int parent,vector<int>adj[],vector<int>&vis){
    vis[src]=1;
    queue<pair<int,int>>Q;
    Q.push({src,parent});
    while(!Q.empty()){
        int node = Q.front().first;
        int parent = Q.front().second;
        for(int adjNode: adj[node]){
            if(!vis[adjNode]){
                vis[adjNode]=1;
                Q.push({adjNode, node});
            }
            else if(adjNode!=parent){
                return true;
            }
        }
    }
    return false;
}

void detectCycleBFS(vector<int>adj[],int V){
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(isCycleUtilBFS(i,-1,adj,vis)) return true;
        }
    }
    return false;
}