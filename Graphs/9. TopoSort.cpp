/*
Topological Sort

-  Linear ordering of vertices such that if there is an edge from u to v, u should come before v in this linear ordering
-  Applicable only for directed acyclic graphs

https://www.geeksforgeeks.org/problems/topological-sort/topological-sort
*/

#include <bits/stdc++.h>
using namespace std;


/*
Detect using DFS
Depth-First Search (DFS) with a Recursion Stack:

1. Take a vertex v and do DFS
2. when vertex v is finished dfs, push it into stack
3. now, pop all elements from stack to get the topological order

*/ 

void topologicalUtil(int src,vector<vector<int>>& adj,stack<int>&st,vector<int>&vis){
        vis[src]=1;
        for(auto node:adj[src]){
            if(!vis[node]){
               topologicalUtil(node,adj,st,vis); 
            }
        }
        st.push(src);
    }
    
vector<int> topologicalSortDFS(vector<vector<int>>& adj) {
    // Your code here
    
    int V=adj.size();
    vector<int>topoSort;
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            topologicalUtil(i,adj,st,vis);
        }
    }
    while(!st.empty()){
        topoSort.push_back(st.top());
        st.pop();
    }
    return topoSort;
}

/*
Detect using BFS / Kahn Algorithm

1. calculate indegree for each vertex
2. push elements with indegree=0 into queue (as it shd appear first in order because there is no one before them)
3. now take front element f of queue and remove this f connection=> subtract indeg of adj by 1, 
4. find if adj node's indegree is 0 if so push into queue
*/ 

vector<int> topologicalSortBFS(vector<vector<int>>& adj) {
    // Your code here
    
    int V=adj.size();
    vector<int>topoSort;
    vector<int>inDeg(V,0);
    
    // calculate indegree for each vertex
    for(int i=0;i<V;i++){
        for(auto adjNode:adj[i]){
            inDeg[adjNode]++;
        }
    }
    // push vertex into queue if indeg=0
    for(int i=0;i<V;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto adjNode:adj[node]){
            inDeg[adj]--;
            if(inDeg[adj]==0){
                q.push(adj);
            }
        }
    }


    return topoSort;
}