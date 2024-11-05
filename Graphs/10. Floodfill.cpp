/*

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the new color.

idea:
replace current vertex and adj ones with newcolor

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int r=image.size(),c=image[0].size();
        
        queue<pair<int,int>>q;
        int currColor=image[sr][sc];
        q.push({sr,sc});
        image[sr][sc]=newColor;
        
        if (currColor == newColor) return image;
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0  && image[i-1][j]==currColor){ // down
                image[i-1][j]=newColor;
                q.push({i-1,j});
            }
            if( j+1<c && image[i][j+1]==currColor){ // right
                image[i][j+1]=newColor;
                q.push({i,j+1});
            }
            if(j-1>=0 && image[i][j-1]==currColor){ // left
                image[i][j-1]=newColor;
                q.push({i,j-1});
            }
            if(i+1<r && image[i+1][j]==currColor){ // up
                image[i+1][j]=newColor;
                q.push({i+1,j});
            }
        }
        return image;
    }