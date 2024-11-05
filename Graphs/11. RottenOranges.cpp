/* 
1 - fresh 2-rotten

Given a matrix of dimension M * N, where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:  

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges
The task is to the minimum time required so that all the oranges become rotten. A rotten orange at index (i,j ) can rot other fresh oranges which are its neighbors (up, down, left, and right). If it is impossible to rot every orange then simply return -1.

*/ 

#include <bits/stdc++.h>
using namespace std;



int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0,mintime=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){ // rotten
                    q.push({i,j});
                }
                else if(grid[i][j]==1){ // fresh
                    fresh++;
                }
            }
        }
        
        while(!q.empty()){
            int size=q.size();
            
           for(int i=0;i<size;i++){
              int x = q.front().first;
              int y = q.front().second;
              q.pop();
              if(x>0 && grid[x-1][y]==1){ // up
                fresh--;
                grid[x-1][y]=2;
                q.push({x-1,y});
              }
             if(x<m-1 && grid[x+1][y]==1){ // down
                fresh--;
                grid[x+1][y]=2;
                q.push({x+1,y});
            }
             if(y>0 && grid[x][y-1]==1){ // left
                fresh--;
                grid[x][y-1]=2;
                q.push({x,y-1});
            }
             if(y<n-1 && grid[x][y+1]==1){ // right
                fresh--;
                grid[x][y+1]=2;
                q.push({x,y+1});
            }
          }
            if(!q.empty()) mintime++;
          
        }
        
        if(fresh==0) return mintime;
        else return -1;
    }
