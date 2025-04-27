class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, int m, int n, vector<vector<bool>>& vis){
        vis[i][j]=true;
        vector<int>dir = {-1,0,1,0,-1};
        for(int k=0;k<4;k++){
            int x=dir[k]+i;
            int y=dir[k+1]+j;
            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y] && heights[x][y]>=heights[i][j]){
                dfs(heights,x,y,m,n,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>res;
        int m=heights.size(), n=heights[0].size();
        vector<vector<bool>> pacVis(m, vector<bool>(n,false));
        vector<vector<bool>> atlVis(m, vector<bool>(n,false));

        for(int i=0;i<m;i++){ 
            dfs(heights, i,0,m,n,pacVis); // fist col
            dfs(heights, i, n-1,m,n,atlVis); // last col
        }
        for(int j=0;j<n;j++){ 
            dfs(heights, 0, j,m,n,pacVis); // fist row
            dfs(heights, m-1, j,m,n,atlVis); // last col
        }

        for(int i=0;i<m;i++){ 
            for(int j=0;j<n;j++){ 
                if(pacVis[i][j] && atlVis[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;




    }
};