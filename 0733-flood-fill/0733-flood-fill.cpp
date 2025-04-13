class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;
        queue<pair<int,int>>Q;
        Q.push({sr,sc});
        while(!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second; Q.pop();
            if(x<0 || y<0 || x>m-1 || y>n-1 || image[x][y]==color || 
               image[x][y]!=originalColor) continue;
            image[x][y]=color;
            Q.push({x-1,y});
            Q.push({x+1,y});
            Q.push({x,y-1});
            Q.push({x,y+1});
        }
        return image;

    }
};