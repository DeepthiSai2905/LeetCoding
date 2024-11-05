/* If number of nodes are n, create n*n matrix 
for n vertices, m edges
if edge exists between i and j A[i][j]=1 
else                           A[i][j]=0

Adjacency Matrix Representation of Graph
*/ 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
 
    // Given Edges - 4
    vector<vector<int>> arr = { { 1, 2 }, { 2, 3 }, 
            { 4, 5 }, { 1, 5 } };

    int m = arr.size();
    
    int adj[n+1][n+1]={0};

    for(int i=0;i<m;i++){
        int u = arr[i][0];
        int v = arr[i][1];
        adj[u][v]=1;
        adj[v][u]=1; // in case of undirected , erase this line for directed
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}