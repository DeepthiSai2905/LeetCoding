/*
Number of Provinces

https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Idea:
Count number of dfsUtil is running
*/

#include <bits/stdc++.h>
using namespace std;


void DFSUtil(int src, vector<int> adj[],vector<bool> &visited){
    visited[src]=true;
    for(auto node:adj[src]){
        if(!vis[node]){
            DFSUtil(node,adj,visited);
        }
    }
}
// 0-based indexing
void DFS(vector<int> adj[], int V){
    vector<bool>visited(V, false);
    int count=0;
    for (int i=0; i<V; i++)
        if (visited[i] == false){
            count++;
            DFSUtil(i, adj, visited);
        }
      return count;      
}


