/*

Checking if a graph is bipartite is like trying to color the graph using only two colors, 
so that no two adjacent vertices have the same color. One approach is to 
check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem.

Idea:
1. bipatite - even length cycle or no cycle 
2. not bipatite - odd length cycle

*/
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>color(V,-1);
    queue<int>q;
    for(int i=0;i<V;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int currNode=q.front();
                    q.pop();
                    int currColor=color[currNode];
                    for(int adjNode:adj[currNode]){
                        if(color[adjNode]==-1){
                            color[adjNode]=1-currColor;
                            q.push(adjNode);
                        }
                        else if(color[adjNode]==currColor) return false;
                    }
                }
            }
    }
    return true;
  }