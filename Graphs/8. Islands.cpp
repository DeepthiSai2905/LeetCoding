/*

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) 
consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands 
horizontally or vertically i.e., in all 4 directions.

https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands

*/

#include <bits/stdc++.h>
using namespace std;

/*  
Using DFS approach

1. do dfs when we have grid[i][j]=1
2. inside dfs to make the node visited, make grid[i][j]=0
3. call dfs and check all directions
*/

void dfsUtil(vector<vector<char>>& grid,int i,int j,int r,int c){
        if(i<0 || j<0 || i>=r || j>=c) return ;
        if(grid[i][j]=='0') return ;
        
        grid[i][j]='0';
        
        dfsUtil(grid,i-1,j,r,c); // top
        dfsUtil(grid,i,j+1,r,c); // right
        dfsUtil(grid,i+1,j,r,c); // down
        dfsUtil(grid,i,j-1,r,c); // left
        
        dfsUtil(grid,i-1,j-1,r,c); // left up diagonal
        dfsUtil(grid,i+1,j+1,r,c); // right down diagonal
        dfsUtil(grid,i+1,j-1,r,c); // left down diagonal
        dfsUtil(grid,i-1,j+1,r,c); // right up
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){ // not visited
                    dfsUtil(grid,i,j,r,c);
                    count++;
                }
            }
        }
        return count;
    }

/*
BFS - instead of going to adjacent like in graph -> go to horizoal left,right, verticle top down, diagonal as well

*/


void bfsUtil(vector<vector<char>>& grid,int i,int j){
    int r=grid.size(), c=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';
        while(!q.empty()){
            int node_x=q.front().first;
            int node_y=q.front().second;
            q.pop();
            for(int delx=-1;delx<=1;delx++){
                for(int dely=-1;dely<=1;dely++){
                    int neigh_row = node_x+delx;
                    int neigh_col = node_y+dely;
                    if(neigh_row>=0 && neigh_col>=0 && neigh_row<r && neigh_col<c && grid[neigh_row][neigh_col]=='1'){
                        grid[neigh_row][neigh_col]='0';
                        q.push({neigh_row,neigh_col});
                    }
                }
            }
               
        }
}
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){ // not visited
                    bfsUtil(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }