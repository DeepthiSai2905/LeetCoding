/*
Detect cycle in directed graph

https://leetcode.com/problems/course-schedule/
*/

#include <bits/stdc++.h>
using namespace std;



/*
Detect using DFS
Depth-First Search (DFS) with a Recursion Stack:

Use a visited array to track nodes that have been fully processed.
Use a path visited array(if path visited or not) (recVis) to track nodes in the current DFS path.
If we encounter a node in the recursion stack during DFS, a cycle exists.
*/ 

bool isCycleUtilDFS(int src,vector<int>adj[], vector<int>&vis,vector<int>&recVis){
    vis[src]=1;
    recVis[src]=1;
    for(int node: adj[src]){
        if(!vis[node]){
            if(isCycleUtilDFS(node,adj,vis)) return true;
        }
        else if(recVis[node]){
                return true;
        }
    }
    recVis[src]=0;
    return false;
}

bool detectCycleDFS(vector<int>adj[],int V){
    vector<int>vis(V,0);
    vector<int>recVis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(isCycleUtilDFS(i,adj,vis)){
                return true;
            }
        }
    }
    return false;
}

/*
Detect using BFS - Kahns algorithm

1. use topological sort BFS logic and find size of sortedVertices
2. if size of topologicalSort = no. of vertices then there is no cycle (as topological sort is applicable only on DAG)
3. else there is cycle
*/ 

bool detectCycleDFS(vector<int>adj[],int V){
    vector<int>inDegree(V,0);
    queue<int>Q;

    for(int i=0;i<V;i++){
        for(auto adjNode:adj[i]){
            inDegree[adjNode]++;
        }
    }

    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            Q.push(i);
        }
    }

    while(!Q.empty()){
        int node=Q.front();
        Q.pop();
        count++;
        for(int adjNode:adj[node]){
            inDegree[adjNode]--;
            if(inDegree[adjNode]==0){
                Q.push(adjNode);
            }
        }
    }

    return count==V ? false: true;
}

