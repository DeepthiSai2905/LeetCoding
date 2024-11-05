/* 
Adjacency List Representation of Graph
*/ 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
 
    // Given Edges - 4
    vector<vector<int>> arr = { { 1, 2 }, { 2, 3 }, 
            { 4, 5 }, { 1, 5 } };

    int m = arr.size();
    
    vector<int>adj[n+1];

    // use vector<pair<int,int>>adj[n+1];  for weighted graph

    for(int i=0;i<m;i++){
        int u = arr[i][0];
        int v = arr[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); // in case of undirected , erase this line for directed
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}